import numpy as np

def sum_numb(numbers):
    S = 0
    for i in numbers:
        S += i
    return S

def dot (A, B):
    S = []
    for i in range (0, len(A)):
        S.append(A[i]*B[i])
    return S 
def SumSq(A):
    S = 0
    for i in A:
        S += i**2
    return S

def Get_a (x, y, N):
    a = (N*sum_numb(dot(x, y)) - sum_numb(x)*sum_numb(y))/(N*SumSq(x) - (sum_numb(x))**2)
    return a
def Get_b (x, y, N):
    b = (sum_numb(y) - Get_a(x, y, N)*sum_numb(x))/N
    return b
def Get_ad (x, y, N):
    ad = (1/N**0.5) * (N*(SumSq(y) - (sum_numb(y))**2)/(N*(SumSq(x) - (sum_numb(x))**2) - (Get_a (x, y, N))**2))**0.5
    return ad
def Get_bd (x, y, N):
    bd = Get_ad (x, y, N) * (1/N) * (N*SumSq(x) - (sum_numb(x))**2)**0.5
    return bd
