import graph

f = open ("data/data_mnk.txt", "r")
N = int(f.readline ())
x = list(map(float, (f.readline()).split()))
y = list(map(float, (f.readline()).split()))
a = float(f.readline())
b = float(f.readline())
ad = float(f.readline())
bd = float(f.readline())

graph.DrawGraph (N, x, y, a, b, ad, bd, "x", "y")
f.close()
