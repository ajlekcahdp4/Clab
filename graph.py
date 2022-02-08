import matplotlib
matplotlib.use('Agg')
import matplotlib.pyplot as plt
import numpy as np
import mnk

def DrawGraph (N, x, y, a, b, ad, bd, filename, name1, name2):
    line = np.array([a*z + b for z in range(int(max(x)) * int(1 + 0.1) + 1)])

    plt.grid()
    plt.plot(line, c = 'blue')
    plt.scatter(x, y, c = 'red')
    plt.xlabel(name1, fontsize=14)
    plt.ylabel(name2, fontsize=14)
    plt.text(min(x) *1.5 , min(y), 'y = %.4f*x + %.4f' %(a, b))
    plt.title(r'График №1', fontsize=12)

    #plt.subplots_adjust(left=0.2, bottom=0.2)

    plt.savefig('graph.png')