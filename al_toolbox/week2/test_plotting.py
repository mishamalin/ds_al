#!/usr/bin/env python3
import matplotlib.pyplot as plt
import numpy as np

n = np.linspace(1, 10)
plt.plot(n, n, label="n")
plt.plot(n, n * n, label="n^2")
plt.plot(n, n * n * n, label="n^3")
plt.legend(loc='upper left')
plt.show()
