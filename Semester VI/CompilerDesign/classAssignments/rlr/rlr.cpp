#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <regex>
#include <cctype>
using namespace std;

vector<string> nonterminalArray;
unordered_map<string, vector<vector<string>>> rules;

template<class T> void setify(vector<T> &v) {
    sort(v.begin(), v.end());
    auto end = unique(v.begin(), v.end());
    v.erase(end, v.end());
    v.shrink_to_fit();
}
template<class T> vector<T> difference(vector<T> &v1, vector<T> &v2) {
    setify(v1); setify(v2);
    vector<T> result; result.resize(v1.size());
    auto end = set_difference(v1.cbegin(), v1.cend(), v2.cbegin(), v2.cend(), result.begin());
    result.erase(end, result.end());
    setify(result);
    return result;
}
template<class T> vector<T> addVectors(const vector<T> &v1, const vector<T> &v2) {
    vector<T> result(v1); result.resize(v1.size() + v2.size());
    copy(v2.cbegin(), v2.cend(), result.begin() + v1.size());
    result.shrink_to_fit();
    return result;
}
//This one requires a type argument
template<class T, class In> vector<T> addVectors(In v1_begin, In v1_end, In v2_begin, In v2_end) {
    vector<T> result(v1_begin, v1_end); const auto sz = v1_end - v1_begin;
    result.resize(sz + (v2_end - v2_begin));
    copy(v2_begin, v2_end, result.begin() + sz);
    result.shrink_to_fit();
    return result;
}

string strSubRule(const vector<string> &subRule) {
    string buffer;
    if(subRule.size() < 1) return string("?");
    for(size_t i = 0; i < subRule.size(); i++) {
        buffer += subRule[i];
        if(i < (subRule.size() - 1)) buffer += " ";
    } 
    return buffer;
}
string strrule(const vector<vector<string>> &rule) {
    string buffer;
    for(size_t i = 0; i < rule.size(); i++) {
        buffer += strSubRule(rule[i]);
        if(i < (rule.size() - 1)) buffer += " | ";
    }
    return buffer;
}

string trim(const string &s) {
    string::const_iterator l = s.cbegin(), h = s.cend()-1;
    while(isspace(*l)) l++;
    while(isspace(*h)) h--; h++;
    return string(l, h);
}
string nextLine() {
    string buffer; char ch;
    while(isspace(ch = cin.get())); //Ignore initial whitespace
    do {buffer.push_back(ch);} while((ch = cin.get()) != '\n');
    return buffer;
}
vector<string> split(const string &s, const regex &re) {
    sregex_token_iterator itr(s.begin(), s.end(), re, -1), end;
    vector<string> result;
    for(;itr != end; itr++) result.push_back(trim(*itr));
    result.shrink_to_fit();
    return result;
}

string removeImmediateLeftRecursion(const string &nonterminal) {
    //Remove immediate left-recursion. Returns new terminal if present.
    string newNonterminal; size_t nameGen = 1;
    do {
        newNonterminal = nonterminal + "_new" + to_string(nameGen); nameGen++;
    } while(rules.find(newNonterminal) != rules.end());
    cout<<endl<<"Removing immediate-left recursion for "<<nonterminal<<". New nonterminal will be "<<newNonterminal<<"."<<endl;
    //Separate into rules which result in left-recursion and rules which don't.
    vector<vector<string>> leftRecursionRule, nonLeftRecursionRule, rule = rules[nonterminal], newRule, newRule2;
    for(auto &subRule: rule) {
        if(!(subRule.size() > 0 && subRule[0] == nonterminal)) continue;
        leftRecursionRule.push_back(subRule);
    } 
    if(leftRecursionRule.size() < 1) {
        cout<<"This is not left-recursive.\n";
        return string();
    }
    setify(leftRecursionRule);
    nonLeftRecursionRule = difference(rule, leftRecursionRule);
    cout<<"New rules:"<<endl;
    const vector<string> singleton({newNonterminal});
    for(auto &subRule: nonLeftRecursionRule) {newRule.push_back(addVectors(subRule, singleton));}
    setify(newRule); rules[nonterminal] = newRule;
    cout<<nonterminal<<" ::= "<<strrule(newRule)<<endl;
    for(auto &subRule: leftRecursionRule) {newRule2.push_back(addVectors<string>(subRule.cbegin()+1, subRule.cend(), singleton.cbegin(), singleton.cend()));}
    newRule2.push_back(vector<string>()); //Add epsilon specifier
    setify(newRule2); rules[newNonterminal] = newRule2;
    cout<<newNonterminal<<" ::= "<<strrule(newRule2)<<endl;
    return newNonterminal;
    //Add it later to nonterminalArray
}

void removeChainedLeftRecursion() {
    unordered_map<size_t, string> newNonterminals;
    for(size_t i = 0; i < nonterminalArray.size(); i++) {
        cout<<"\nRemoving chained-left recursion for "<<nonterminalArray[i]<<endl;
        for(size_t j = 0; j < i; j++) {
            cout<<"Trying substituting in "<<nonterminalArray[j]<<endl;
            vector<vector<string>> newRuleSet;
            for(auto &subRule : rules[nonterminalArray[i]]) 
                if(subRule.size() > 0 && subRule[0] == nonterminalArray[j]) 
                    for(auto &jSubRule : rules[nonterminalArray[j]]) 
                        newRuleSet.push_back(addVectors<string>(jSubRule.cbegin(), jSubRule.cend(), subRule.cbegin()+1, subRule.cend()));
                else newRuleSet.push_back(subRule);
            setify(newRuleSet);
            rules[nonterminalArray[i]] = newRuleSet;
            cout<<nonterminalArray[i]<<" ::= "<<strrule(rules[nonterminalArray[i]])<<endl;
        }
        string newNonterminal = removeImmediateLeftRecursion(nonterminalArray[i]);
        if(newNonterminal.size() > 0) 
            newNonterminals[i] = newNonterminal; //Insert newNonterminal after index i
    }

    //Regenerate nonterminalArray
    vector<string> newNonterminalArray; newNonterminalArray.reserve(nonterminalArray.size() + newNonterminals.size());
    for (size_t i = 0; i < nonterminalArray.size(); i++) {
        newNonterminalArray.push_back(nonterminalArray[i]);
        if(newNonterminals.find(i) != newNonterminals.end()) newNonterminalArray.push_back(newNonterminals[i]);
    }
    nonterminalArray = newNonterminalArray;
}

int main() {
    const regex ws("\\s+", regex::ECMAScript | regex::optimize);
    const regex bar("\\|+", regex::ECMAScript | regex::optimize);
    cout<<"Enter nonterminal symbols separated by space.\nThese must be entered in the correct precedence order desired (low to high).\n-> ";
    nonterminalArray = split(nextLine(), ws);
    cout<<"Rules for nonterminals should be sequences of terminals and nonterminals separated by space. Multiple possible options for"<<endl<<
    "a nonterminal should be separated by |. Spaces around \'|\' are not required. An empty string option is indicated by \'?\'."<<endl;
    for(const string &nonterminal : nonterminalArray) {
        vector<vector<string>> rule;
        cout<<"Enter rules for "<<nonterminal<<": ";
        vector<string> rawRule = split(nextLine(), bar); rule.reserve(rawRule.size());
        for(const string &subRule: rawRule) {
            if(subRule == "?") rule.push_back(vector<string>());
            else rule.push_back(split(subRule, ws));
        }
        setify(rule);
        rules[nonterminal] = rule;
    }
    cout<<"\nRules before left-recursion removal:\n";
    for(const string &nonterminal : nonterminalArray) 
        cout<<nonterminal<<" ::= "<<strrule(rules[nonterminal])<<endl;

    removeChainedLeftRecursion();

    cout<<"\nRules after left-recursion removal:\n";
    for(const string &nonterminal : nonterminalArray) 
        cout<<nonterminal<<" ::= "<<strrule(rules[nonterminal])<<endl;
}