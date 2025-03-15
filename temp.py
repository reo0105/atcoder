import numpy as np

p = [0.8, 0.18, 0.02]

print(p)

new_p0 = np.power(p, 0.75)

print(new_p0)

new_sum = np.sum(new_p0)

print(new_sum)

new_p1 = new_p0 / new_sum

print(new_p1)

print(np.sum(new_p1))
