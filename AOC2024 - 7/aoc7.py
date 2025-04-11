import time
from itertools import product

# PART 1 #
t1 = time.time()
infile = open("input.txt")
data = infile.read().split("\n")
operators = ["*", "+"]
total = 0

for i in range (0, len(data)):
    splitted = data[i].split(":")
    goal = int(splitted[0])
    factors = splitted[1].split(" ")
    factors.remove('')
    added = False
    for p in product (operators, repeat = len(factors) - 1):
        subtotal = 0
        for j in range(0, len(p)):
            if (subtotal == 0 and p[j] == "*"):
                subtotal += int(factors[j]) * int(factors[j + 1])
            elif (subtotal == 0 and p[j] == "+"):
                subtotal += int(factors[j]) + int(factors[j + 1])
            elif (p[j] == "*"):
                subtotal *= int(factors[j + 1])
            elif (p[j] == "+"):
                subtotal += int(factors[j + 1])
        if (not added and subtotal == goal):
            total += goal
            added = True
print("Part 1: total =", total)
print("Runtime: %.3lf"%(time.time() - t1), end= "\n\n")
infile.close()

# PART 2 #
t1 = time.time()
infile = open("input.txt")
data = infile.read().split("\n")
operators = ["*", "+", "|"]
total = 0

for i in range (0, len(data)):
    splitted = data[i].split(":")
    goal = int(splitted[0])
    factors = splitted[1].split(" ")
    factors.remove('')
    added = False
    for p in product (operators, repeat = len(factors) - 1):
        subtotal = 0
        factors2 = factors.copy()
        subtracted = 0
        for j in range(0, len(p)):
            if (subtotal == 0 and p[j] == "*"):
                subtotal += int(factors2[j]) * int(factors2[j + 1])
            elif (subtotal == 0 and p[j] == "+"):
                subtotal += int(factors2[j]) + int(factors2[j + 1])
            elif (subtotal == 0 and p[j] == "|"):
                subtotal = int(factors2[j] + factors2[j + 1])
                factors2[0] = subtotal
                factors2.remove(factors2[j + 1])
                subtracted += 1
            elif (p[j] == "*"):
                subtotal *= int(factors2[j + 1 - subtracted])
            elif (p[j] == "+"):
                subtotal += int(factors2[j + 1 - subtracted])
            elif (p[j] == "|"):
                subtotal = int(str(subtotal) + factors2[j + 1 - subtracted])
                factors2.remove(factors2[j + 1 - subtracted])
                subtracted += 1
        if (not added and subtotal == goal):
            total += goal
            added = True
print("Part 2: total =", total)
print("Runtime: %.3lf"%(time.time() - t1))
infile.close()