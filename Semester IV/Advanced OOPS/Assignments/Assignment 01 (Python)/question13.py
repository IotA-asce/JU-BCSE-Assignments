#Write a code which yields all terms of the geometric progression a, aq, aq2, aq3, .... When the progression produces a term that is greater than 100,000, the generator stops (with a return statement). Compute total time and time within the loop.
import math
import time

def GeometricProgression(a,q):
    x = 0
    i = 0
    while x < 100000:
        x = a * pow(q,i)
        print("aq^" + str(i) + " : " + str(math.floor(x)))
        i += 1
    return "overflow"

a = input("a : ")
q = input("q : ")
a = float(a)
q = float(q)    

t1 = time.time()
print(GeometricProgression(a,q))
print("\n\nFunction runtime : " + str(time.time() - t1) + " seconds\n")