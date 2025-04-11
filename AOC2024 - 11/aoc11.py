import time

# PART 1
t1 = time.time()
infile = open("input.txt")
data = infile.read().split(" ")
total = 0
arr = []
infile.close()

i = 0
while (i < len(data)):
    arr.append(int(data[i]))
    i += 1

for i in range (0, 25):
    j = 0
    while (j < len(arr)):
        if (arr[j] == 0):
            arr[j] = 1
        elif (len(str(arr[j])) % 2 == 0):
            half = 0
            for k in range (0, int(len(str(arr[j])) / 2)):
                half += (int(arr[j]) % 10) * pow(10, k)
                arr[j] /= 10
            arr[j] = int(arr[j])
            arr.append(int(half))
            arr[len(arr) - 1] = arr[j + 1]
            arr[j + 1] = int(half)
            j += 1
        else:
            arr[j] *= 2024
        j += 1

print("Part 1: total =", len(arr))
print("Runtime: %.5lf"%(time.time() - t1))

# PART 2
# Dont store the entire array, just how many times each number appears i guess