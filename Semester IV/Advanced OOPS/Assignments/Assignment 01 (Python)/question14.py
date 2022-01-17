# Search for palindrome and unique words in a text using class method and stringmethod.


def PalindromeCheck(s):
    return s == s[::-1]

inputStream = input("\nEnter string : ")
ls = inputStream.split()

for i in ls:
    print( i + " : " + str(PalindromeCheck(i)))

# print(ls)