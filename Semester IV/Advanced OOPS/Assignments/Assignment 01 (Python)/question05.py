'''Write first seven Fibinacci numbers using generator next function/ yield in python. Trace
and memorize the function.'''

# 1 1 2 3 5 8 13

def fibo_num():
    x2 = 1
    x1 = 0
    num1 = x2 + x1
    yield num1 
    num1 = x2 + x1
    x1 = x2
    x2 = num1
    yield num1
    num1 = x2 + x1
    x1 = x2
    x2 = num1
    yield num1
    num1 = x2 + x1
    x1 = x2
    x2 = num1
    yield num1
    num1 = x2 + x1
    x1 = x2
    x2 = num1
    yield num1
    num1 = x2 + x1
    x1 = x2
    x2 = num1
    yield num1
    num1 = x2 + x1
    x1 = x2
    x2 = num1
    yield num1

for num in fibo_num():
    print(num)