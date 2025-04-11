import time

# PART 1
t1 = time.time()
infile = open("input2.txt")
data = infile.read().split("\n")
total = 0
arr = []
state = 0
id = 0
sortMax = 0

for i in range (0, len(data)):
    for c in data[i]:
        if (state % 2 == 0):
            for j in range (0, int(c)):
                arr.append(str(id))
            id += 1
        else:
            for j in range (0, int(c)):
                arr.append(".")
                sortMax += 1
        state += 1

sorted = 0
for i in range (len(arr) - 1, 0, -1):
    if (not arr[i] == "."):
        for j in range (0, i):
            if (sorted < sortMax - 2):
                if (arr[j] == "."):
                    arr[j] = arr[i]
                    arr[i] = "."
                    sorted += 1
                    break
            else:
                break

for i in range (0, len(arr)):
    if (not arr[i] == "."):
        total += int(arr[i]) * i

print("Part 1: total =", total)
print("Runtime: %.5lf"%(time.time() - t1))
infile.close()

# PART 2
t1 = time.time()
infile = open("input.txt")
data = infile.read().split("\n")
total = 0
arr = []
state = 0
id = 0
sortMax = 0

for i in range (0, len(data)):
    for c in data[i]:
        if (state % 2 == 0):
            for j in range (0, int(c)):
                arr.append(id)
            id += 1
        else:
            for j in range (0, int(c)):
                arr.append(-1)
                sortMax += 1
        state += 1

sorted = 0
i = len(arr) - 1
while (i > 0):
    count = 0
    if (not arr[i] == -1):
        c = arr[i]
        while (i > -1 and arr[i] == c):
            count += 1
            i -= 1
        j = 0
        while (j < i):
            count2 = 0
            if (arr[j] == -1):
                while (j < i + 1 and arr[j] == -1):
                    count2 += 1
                    j += 1
                if (count2 >= count):
                    for k in range (0, count):
                        arr[j - count2 + k] = arr[i + count - k]
                        arr[i + count - k] = -1
                    break
                j -= 1
            j += 1
        i += 1
    i -= 1

            
            

for i in range (0, len(arr)):
    if (not arr[i] == -1):
        total += int(arr[i]) * i

print("Part 2: total =", total)
print("Runtime: %.5lf"%(time.time() - t1))
infile.close()