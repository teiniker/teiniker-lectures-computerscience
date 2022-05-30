# importing the required modules
import matplotlib.pyplot as plt
import numpy as np
import math


# setting the x - coordinates
X_MAX = 10
Y_MAX = 100

n = np.arange(0, X_MAX, 0.1)

def o_1(n):
    return np.full(n.shape, 1) 

def o_log(n):
    return np.log2(n)

def o_n(n):
    return n

def o_n_log(n):
    return np.log2(n)*n

def o_n_2(n):
    return np.square(n)

def o_exp(n):
    return np.exp2(n)

# plotting the points
plt.plot(n, o_1(n), label='O(1)', color='lightsteelblue')
plt.plot(n, o_log(n), label='O(log(N))', color='royalblue')
plt.plot(n, o_n(n), label='O(N)', color='blue')
plt.plot(n, o_n_log(n), label='O(N log(N))', color='blueviolet')
plt.plot(n, o_n_2(n), label='O(N^2)', color='red')
plt.plot(n, o_exp(n), label='O(2^N)', color='brown')


# function to show the plot
plt.xlim([0,X_MAX])
plt.ylim([0,Y_MAX])
plt.grid(linestyle='-')
plt.legend()
plt.show()