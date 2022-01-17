'''Write a simple program which loops over a list of user data (tuples containing a username,
email and age) and adds each user to a directory if the user is at least 16 years old. You do
not need to store the age. Write a simple exception hierarchy which defines a different
exception for each of these error conditions:
 the username is not unique
 the age is not a positive integer
 the user is under 16
 the email address is not valid (a simple check for a username, the @ symbol and a
domain name is sufficient)
Raise these exceptions in your program where appropriate. Whenever an exception occurs,
your program should move onto the next set of data in the list. Print a different error
message for each different kind of exception.'''

import re
from typing import Text

def constructTuple():
    name = input("Enter username : ")
    email = input("Enter email : ")
    age = int(input("Enter age : "))
    x = (name,email,age)
    return x



y_n = 1
l = []
at = "@"
domain = ".com"

for i in range(3):
    a = constructTuple()
    l.append(a)
    
# the username is not unique
for i in range(3):
    for j in range(i+1,3):
        if (l[i][0] == l[j][0]):
            print("\nduplicate names : " + l[i][0])
            print(l[i])
            break
# the age is not a positive integer
for i in l:
    if (i[2] < 0):
        print("\nInvalid age, age cannot be negative : " + str(i[2]))
        print(i)
     
# the email address is not valid (a simple check for a username, the @ symbol and a
#add functionality for checking email validity using regex
for i in l:
    a = re.search(i[1],at)
    b = re.search(i[1],domain)
    m = a and b
    if (m == None):
        print("Invalid email : " + i[1])   