import time

# PART 1
t1 = time.time()
infile = open("input.txt")
data = infile.read().split("\n")
total = 0
map = []
nodemap = []

for i in range (0, len(data)):
    map.append([])
    nodemap.append([])
    for char in data[i]:
        map[i].append(char)
        nodemap[i].append(".")

for i in range (0, len(map)):
    for j in range (0, len(map[i])):
        c = map[i][j]
        if (not c == "." and not c == "#"):
            for k in range (0, len(map)):
                for l in range (0, len(map)):
                    c2 = map[k][l]
                    if (c2 == c and not (i == k and j == l)):
                        x = k - i
                        y = l - j
                        if (k + x < len(map) and l + y < len(map) and k + x >= 0 and l + y >= 0):
                            if (map[k + x][l + y] == "."):
                                map[k + x][l + y] = "#"
                                nodemap[k + x][l + y] = "#"
                            elif (not map[k + x][l + y] == "#" and nodemap[k + x][l + y] == "."):
                                nodemap[k + x][l + y] == "#"
                        if (i - x >= 0 and j - y >= 0 and i - x < len(map) and j - y < len(map)):
                            if (map[i - x][j - y] == "."):
                                map[i - x][j - y] = "#"
                                nodemap[i - x][j - y] = "#"
                            elif (not map[i - x][j - y] == "#" and nodemap[i - x][j - y] == "."):
                                nodemap[i - x][j - y] = "#"

for i in range (0, len(nodemap)):
    for j in nodemap[i]:
        if (j == "#"):
            total += 1

print("Part 1: total =", total)
print("Runtime: %.5lf"%(time.time() - t1))
infile.close()


# PART 2
t1 = time.time()
infile = open("input.txt")
data = infile.read().split("\n")
total = 0
map = []
nodemap = []

for i in range (0, len(data)):
    map.append([])
    nodemap.append([])
    for char in data[i]:
        map[i].append(char)
        nodemap[i].append(".")

for i in range (0, len(map)):
    for j in range (0, len(map[i])):
        c = map[i][j]
        if (not c == "." and not c == "#"):
            for k in range (0, len(map)):
                for l in range (0, len(map)):
                    c2 = map[k][l]
                    if (c2 == c and not (i == k and j == l)):
                        nodemap[k][l] = "#"
                        nodemap[i][j] = "#"
                        x = k - i
                        y = l - j
                        x1 = x
                        y1 = y
                        x2 = x
                        y2 = y
                        while (k + x1 < len(map) and l + y1 < len(map) and k + x1 >= 0 and l + y1 >= 0):
                            if (map[k + x1][l + y1] == "."):
                                map[k + x1][l + y1] = "#"
                                nodemap[k + x1][l + y1] = "#"
                            elif (not map[k + x1][l + y1] == "#" and nodemap[k + x1][l + y1] == "."):
                                nodemap[k + x1][l + y1] == "#"
                            x1 += x
                            y1 += y
                        while (i - x2 >= 0 and j - y2 >= 0 and i - x2 < len(map) and j - y2 < len(map)):
                            if (map[i - x2][j - y2] == "."):
                                map[i - x2][j - y2] = "#"
                                nodemap[i - x2][j - y2] = "#"
                            elif (not map[i - x2][j - y2] == "#" and nodemap[i - x2][j - y2] == "."):
                                nodemap[i - x2][j - y2] = "#"
                            x2 -= x
                            y2 -= y

for i in range (0, len(nodemap)):
    for j in nodemap[i]:
        if (j == "#"):
            total += 1

print("Part 2: total =", total)
print("Runtime: %.5lf"%(time.time() - t1))
infile.close()