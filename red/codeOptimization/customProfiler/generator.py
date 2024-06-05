import numpy as np
# using: python generator.py > input.txt

size_t = 25000
x = np.random.randint(0, size_t, size=size_t)
y = np.random.randint(0, size_t, size=size_t)

xx = " ".join(str(num) for num in x)
yy = " ".join(str(num) for num in y)

print(size_t)
print(xx)
print(size_t)
print(yy)