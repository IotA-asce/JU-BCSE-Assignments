# Write a prime generator program using only primes and using python loops.

isCoPrime = False
z = int(input("Enter the upper limit : "))
for x in range(2,z):
    for y in range(2,((int)(x/2)+1)):
        if ((x%y) == 0):
            isCoPrime = True
    if not isCoPrime:
        print(x)
    isCoPrime = False
            