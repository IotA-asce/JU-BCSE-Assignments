# Let's find all Pythagorean triples whose short sides are numbers smaller than 10. use
# filter and comprehension.


def PythagoreanTriplates(n):
    my_list = [(a,b,c) for a in range(n+1) for b in range(a) for c in range(b) if a*a == b*b + c*c]
    print(my_list)

PythagoreanTriplates(10)
        