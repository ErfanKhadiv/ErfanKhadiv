from cs50 import get_int

while True:
    height = get_int("Height: ")
    if 0 < height < 9:
        break

for i in range(1, height + 1):
    n = height - i
    for j in range(n):
        print(" ", end="")
    for k in range(i):
        print("#", end="")
    print("")
