'''Write a discount coupon code using dictionary in Python with different rate coupons for
each day of the week.'''

couponsPerDay = {
    "monday" : 25,
    "tuesday" : 30,
    "wednesday" : 15,
    "thursday" : 20,
    "friday" : 5,
    "saturday" : 2,
    "sunday" : 3
}

x = input("Enter day of week : ")
x = str.casefold(x)

found = False
try:
    print(couponsPerDay[x])
except:
    print("Invalid day")