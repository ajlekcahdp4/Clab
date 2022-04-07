import matplotlib
matplotlib.use('Agg')
import matplotlib.pyplot as plt
from matplotlib.ticker import (MultipleLocator, FormatStrFormatter, AutoMinorLocator)
import numpy as np
import math
#GNUplot

def DrawGraphLine (x, y, a, b, ad, bd, name1, name2):
    
    max_x = max(x)
    min_x = min(x)

    X = np.linspace (min_x - 0.2*(max_x - min_x), max_x + 0.2*(max_x - min_x), 100)
    Y = np.array([a*x_c + b for x_c in X])
    fig, ax = plt.subplots(figsize=(8, 6))

    ax.set_xlabel(name1, fontsize=14)
    ax.set_ylabel(name2, fontsize=14)
    ax.text(min(x) , min(y), 'y = %.4f*x + %.4f' %(a, b))

    ax.grid(which="major", linewidth=1.2)
    ax.grid(which="minor", linestyle="--", color="gray", linewidth=0.5)

    ax.plot(X, Y, c = 'blue', label="График по МНК")
    ax.scatter(x, y, c = 'red', label="Измеренные точки")
    
    ax.legend()

    ax.xaxis.set_minor_locator(AutoMinorLocator())
    ax.yaxis.set_minor_locator(AutoMinorLocator())
    ax.tick_params(which='major', length=10, width=2)
    ax.tick_params(which='minor', length=5, width=1)
    
    plt.savefig(str(input("Enter the name for linear graph picture file\n")))
#=============================================================================================
#=======================================polinomial=graph======================================
#=============================================================================================
def DrawGraphPol (x, y, a, name1, name2):
    max_x = max(x)
    min_x = min(x)
    X = np.linspace (min_x - 0.2*(max_x - min_x), max_x + 0.2*(max_x - min_x), 100)

    Y = []
    cur_y = 0
    for cur_x in X:
        for k in range (0, len(a)):
            cur_y += a[k] * cur_x ** k
        Y.append (cur_y)
        cur_y = 0

        

    fig, ax = plt.subplots(figsize=(8, 6))

    ax.set_xlabel(name1, fontsize=14)
    ax.set_ylabel(name2, fontsize=14)
    
    ax.set_title(r'График №1', fontsize=12)

    ax.grid(which="major", linewidth=1.2)
    ax.grid(which="minor", linestyle="--", color="gray", linewidth=0.5)

    ax.plot(X, Y, c = 'blue', label="График по МНК")
    ax.scatter(x, y, c = 'red', label="Измеренные точки")
    
    ax.legend()

    ax.xaxis.set_minor_locator(AutoMinorLocator())
    ax.yaxis.set_minor_locator(AutoMinorLocator())
    ax.tick_params(which='major', length=10, width=2)
    ax.tick_params(which='minor', length=5, width=1)
    
    plt.savefig(str(input("Enter the name for polinomial graph picture file\n")))

#=============================================================================================
#======================================pexponential=graph=====================================
#=============================================================================================

def DrawGraphExp (x, y, a, b, ad, bd, name1, name2):
    
    max_x = max(x)
    min_x = min(x)
    yn = [math.exp (y_i) for y_i in y]

    X = np.linspace (min_x - 0.2*(max_x - min_x), max_x + 0.2*(max_x - min_x), 100)
    Y = np.array([math.exp(a*x_c + b) for x_c in X])
    fig, ax = plt.subplots(figsize=(8, 6))

    ax.set_xlabel(name1, fontsize=14)
    ax.set_ylabel(name2, fontsize=14)
    ax.text(min(x) , 0.8*min(yn), 'y = exp(%.4f * x)' %(a))

    ax.grid(which="major", linewidth=1.2)
    ax.grid(which="minor", linestyle="--", color="gray", linewidth=0.5)
    
    ax.plot(X, Y, c = 'blue', label="График по МНК")
    ax.scatter(x, yn, c = 'red', label="Измеренные точки")
    
    ax.legend()

    ax.xaxis.set_minor_locator(AutoMinorLocator())
    ax.yaxis.set_minor_locator(AutoMinorLocator())
    ax.tick_params(which='major', length=10, width=2)
    ax.tick_params(which='minor', length=5, width=1)
    
    plt.savefig(str(input("Enter the name for exponential graph picture file\n")))