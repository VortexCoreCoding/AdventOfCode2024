import time

# PART 1
t1 = time.time()
infile = open("input.txt")
data = infile.read().split("\n")
total = 0
arr = []
infile.close()

def explore(arr, x, y, nines) -> int:
    value = arr[x][y]
    rVal = 0
    if (value == 9):
        found = 0
        for i in range (0, len(nines)):
            if (nines[i][0] == x and nines[i][1] == y):
                found = 1
        if (found == 0):
            nines.append([x, y])
            return 1
    elif (not value == 9):
        if (x - 1 >= 0):
            if (arr[x - 1][y] == value + 1):
                rVal += explore(arr, x - 1, y, nines)
        if (y - 1 >= 0):
            if (arr[x][y - 1] == value + 1):
                rVal += explore(arr, x, y - 1, nines)
        if (x + 1 < len(arr)):
            if (arr[x + 1][y] == value + 1):
                rVal += explore(arr, x + 1, y, nines)
        if (y + 1 < len(arr)):
            if (arr[x][y + 1] == value + 1):
                rVal += explore(arr, x, y + 1, nines)
    return rVal

for i in range (0, len(data)):
    arr.append([])
    for j in data[i]:
        arr[i].append(int(j))

for i in range (0, len(arr)):
    for j in range (0, len(arr[i])):
        if (arr[i][j] == 0):
            nines = []
            total += explore(arr, i, j, nines)

print("Part 1: total =", total)
print("Runtime: %.5lf"%(time.time() - t1))


# PART 2
t1 = time.time()
infile = open("input.txt")
data = infile.read().split("\n")
total = 0
arr = []
infile.close()

def explore2(arr, x, y) -> int:
    value = arr[x][y]
    rVal = 0
    if (value == 9):
        return 1
    elif (not value == 9):
        if (x - 1 >= 0):
            if (arr[x - 1][y] == value + 1):
                rVal += explore2(arr, x - 1, y)
        if (y - 1 >= 0):
            if (arr[x][y - 1] == value + 1):
                rVal += explore2(arr, x, y - 1)
        if (x + 1 < len(arr)):
            if (arr[x + 1][y] == value + 1):
                rVal += explore2(arr, x + 1, y)
        if (y + 1 < len(arr)):
            if (arr[x][y + 1] == value + 1):
                rVal += explore2(arr, x, y + 1)
    return rVal

for i in range (0, len(data)):
    arr.append([])
    for j in data[i]:
        arr[i].append(int(j))

for i in range (0, len(arr)):
    for j in range (0, len(arr[i])):
        if (arr[i][j] == 0):
            total += explore2(arr, i, j)

print("Part 2: total =", total)
print("Runtime: %.5lf"%(time.time() - t1))