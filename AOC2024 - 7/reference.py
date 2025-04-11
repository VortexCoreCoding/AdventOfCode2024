import os
import time
import math
from itertools import product, combinations, permutations

name = ["skibid", 564, "skibid"]
# name.append()
# name.remove()
print(name + ["sk"])
print("lame", "game", end = 'e')
print(len(name), len("lame"))

lame = set(name) # no dupes list (can only contain hashable elements, lists do not have hashes)
# lame.add()
# lame.remove()
infile = open("input.txt", 'r')
game = infile.read().split("\n") # splits at new line, game becomes an array with each line in infile as an element
j = 0

for i in range(2, 5, 2):
    pass

while j < 12:
    j += 1

print(int("1234568"))
print(ord("e")) # converts string to ascii code
print(chr(48)) # converts ascii to string

arr = [532, 234, 76, 12396, "438174", "sfnjdsk"]
print(arr[2:-1]) # lowerbound:upper(exclusive), -1 gives element at end

print(arr[::-1]) # prints in reverse

peter = input("Please help me ")

# comparators && = and, || = or, ! = not
234 in arr # returns true because 234 is present in arr

if ("statement" == "statement"):
    print(True) # first letter of True and False is caps

None # NULL

tuple # data type: const array, but can be hashed and put into sets yippee
tuplet = ("item1", "item2", 5400) # "you can put arrays in tuples i think"

dictionary = { 2:3, "eat":2, 5:arr } # {} define a dict, keys must be hashable, the values they are assigned to dont have to be
# dicts cannot be hashed by default, but you can assign a dict to a value in another dict
dictionary["eat"] # returns 2

# repeats alot of shit
for p in product ([1, 2, 3], repeat = 4):
     print(p)

# every permutation, cares about order
for p in permutations ([1, 2, 3], r = 2):
    print(p)

# every combination, doesnt care about order
for p in combinations ([1, 2, 3], r = 2):
    print(p)