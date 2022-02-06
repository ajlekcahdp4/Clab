import matplotlib
matplotlib.use('Agg')
import matplotlib.pyplot as plt
import numpy as np
import mnk

def DrawGraph (x, y, N, name):
    a = mnk.Get_a (x, y, 4)
    b = mnk.Get_b (x, y, 4)
    ad = mnk.Get_ad (x, y, 4)
    bd = mnk.Get_bd (x, y, 4)
    line = np.array([a*z + b for z in range(x[-1] * int(1 + 0.1) + 1)])
    plt.grid()
    plt.plot(line, c = 'red')
    plt.scatter(x, y, c = 'red')
    plt.xlabel('ось x', fontsize=14)
    plt.ylabel('ось y', fontsize=14)
    plt.text(min(x), min(y), 'y = %.4f*x + %.4f' %(a, b))
    plt.title(r'График функции $y = x^2$', fontsize=16, y=1.05)
    plt.savefig(name)