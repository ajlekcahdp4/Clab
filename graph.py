import matplotlib
matplotlib.use('Agg')
import matplotlib.pyplot as plt
from matplotlib.ticker import (MultipleLocator, FormatStrFormatter, AutoMinorLocator)
import numpy as np
import mnk

def DrawGraph (N, x, y, a, b, ad, bd, filename, name1, name2):
    line = np.array([a*z + b for z in range ( int(max(x) * (1 + 0.1) + 1))])

    fig, ax = plt.subplots()

    ax.grid(which="major", linewidth=1.2)
    ax.grid(which="minor", linestyle="--", color="gray", linewidth=0.5)

    ax.plot(line, c = 'blue')
    ax.scatter(x, y, c = 'red')
    
    #Xs = list((int(i) for i in range (int(min(x)), int(max(x) * (1 + 0.1) + 1), 5)))
    #ax.set_xticks(Xs)

    ax.set_xlabel(name1, fontsize=14)
    ax.set_ylabel(name2, fontsize=14)
    
    ax.xaxis.set_minor_locator(AutoMinorLocator())
    ax.yaxis.set_minor_locator(AutoMinorLocator())

    ax.text(min(x) , min(y), 'y = %.4f*x + %.4f' %(a, b))
    ax.set_title(r'График №1', fontsize=12)


    plt.savefig('graph.png')