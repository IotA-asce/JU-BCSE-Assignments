# Write a regular expression to validate a phone number
import re;

phone_number = input("\nenter phone number:")

x = re.findall("\d",phone_number)

if len(phone_number) == 10:
    if(len(x) == 10):
        print("valid phone number\n")
else:
    print("Invalid phone number\n")