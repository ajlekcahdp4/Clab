

def InputLinearLSM (filename):
    f = open (filename, "r")

    N = int(f.readline())
    x = list(map(float, (f.readline()).split()))
    y = list(map(float, (f.readline()).split()))
    a = float(f.readline())
    b = float(f.readline())
    ad = float(f.readline())
    bd = float(f.readline())
    f.close()
    return x, y, a, b, ad, bd

def InputPolinomLSM (filename):
    f = open (filename, "r")

    N = int(f.readline())
    x = list(map(float, (f.readline()).split()))
    y = list(map(float, (f.readline()).split()))
    a = list(map(float, (f.readline()).split()))
    f.close()
    return x, y, a