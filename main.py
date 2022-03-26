import graph as G
import input

#x, y, a, b, ad, bd = input.InputLinearLSM ("data/data_lsm.txt")
#G.DrawGraphLine (x, y, a, b, ad, bd, "x", "y")

x, y, a = input.InputPolinomLSM ("data/data_lsm_pol.res")
G.DrawGraphPol (x, y, a, "x", "y")