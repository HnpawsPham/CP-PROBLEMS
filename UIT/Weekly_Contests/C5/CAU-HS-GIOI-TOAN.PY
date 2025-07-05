import numpy as np

PI = np.float32(3.141592654)
ep = np.float32(0.0001)

def ssin(x):
    x = x * PI / np.float32(180)

    if x > PI:
        x -= np.float32(2) * PI
    sum = x
    m = x
    k = 1

    while True:
        tmp = -m * x * x / (np.float32(2 * k) * np.float32(2 * k + 1))
        if abs(tmp) < ep:
            break
        sum += tmp
        m = tmp
        k += 1
    return sum

x = np.float32(float(input()))
print("{:.6f}".format(ssin(x)))