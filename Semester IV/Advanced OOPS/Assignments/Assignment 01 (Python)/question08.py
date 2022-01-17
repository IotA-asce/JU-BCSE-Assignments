# Create a list of all the numbers up to N=50 which are multiples of five using anonymous
# function.

# x = lambda a, b : a * b
# print(x(5, 6))

x = lambda a : a%5

for i in range(51):
    if(x(i) == 0):
        print(i)