import random

n = random.randint(1, 50)
edges = []

for i in range(1, n):
    j = random.randint(0, i - 1)
    edges.append((i, j))

with open("./data.txt", "w") as f:
    f.write(f"{n}\n")
    for v, w in edges:
        f.write(f"{v} {w}\n")
