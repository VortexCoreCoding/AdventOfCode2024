import time

# PART 1
t1 = time.time()
infile = open("input.txt")
data = infile.read().split("\n")
infile.close()
total = 0
rules = []
lines = []


for i in range (0, 1176):
    rules.append(data[i].split("|"))
for i in range (1177, len(data)):
    lines.append(data[i].split(","))


for arr in lines:
    ordered = True
    for i in range (0, len(arr)):
        for j in range (i + 1, len(arr)):
            one = arr[i]
            two = arr[j]
            for k in rules:
                if (k[0] == one and k[1] == two):
                    break
                elif (k[0] == two and k[1] == one):
                    ordered = False
                    break
        if (not ordered):
                break
    if (ordered):
        total +=  int(arr[int(len(arr) / 2)])

print("Part 1: total =", total)
print("Runtime: %.5lf"%(time.time() - t1))


# PART 2
t1 = time.time()
infile = open("input.txt")
data = infile.read().split("\n")
infile.close()
total = 0
rules = []
lines = []
incorrect = []


for i in range (0, 1176):
    rules.append(data[i].split("|"))
for i in range (1177, len(data)):
    lines.append(data[i].split(","))


for arr in lines:
    ordered = True
    for i in range (0, len(arr)):
        for j in range (i + 1, len(arr)):
            one = arr[i]
            two = arr[j]
            for k in rules:
                if (k[0] == one and k[1] == two):
                    break
                elif (k[0] == two and k[1] == one):
                    ordered = False
                    break
            if (not ordered):
                    contains = False
                    for l in incorrect:
                        if (l == arr):
                            contains = True
                    if (not contains):
                        incorrect.append(arr)
                    break
            
for arr in incorrect:
    i = 0
    while (i < len(arr)):
        for j in range (i + 1, len(arr)):
            one = arr[i]
            two = arr[j]
            for k in rules:
                if (k[0] == one and k[1] == two):
                    break
                elif (k[0] == two and k[1] == one):
                    arr[i] = two
                    arr[j] = one
                    i = 0
                    break
        i += 1           
    total +=  int(arr[int(len(arr) / 2)])


print("Part 2: total =", total)
print("Runtime: %.5lf"%(time.time() - t1))