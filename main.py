import mnk
import graph
import WriteTex as wt

lab_num = '2.2.4'
N = 4
x = [1, 2, 3, 4]
y = [0.96/2.3, 1.09/2.31, 1.05/2.24, 1.13/2.26]

f = open ("lab_" + lab_num + ".tex", 'w')

wt.MakeStart (f, lab_num)
wt.TabForGraph (f, x, y, 4)
wt.IncludePic (f, "graph.png")
wt.MakeEnd (f)
