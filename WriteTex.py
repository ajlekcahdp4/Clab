def TabForGraph (f, x, y, N):
    f.write ('$$\n')
    f.write (r'\begin {tabular}{|c|')
    for i in range (0, N):
        f.write ('c|')
    f.write ('}\n')
    f.write (r'\hline' + '\n')
    
    f.write('&&')
    for i in range (0, N):
        f.write ("%.4f&" %x[i])
    f.write (r'\\\hline' + '\n')

    f.write('&&')
    for i in range (0, N):
        f.write ("%.4f&" %y[i])
    f.write (r'\\\hline' + '\n')
    f.write (r'\hline' + '\n')
    f.write (r'\end{tabular}')
    f.write ('$$\n\n')


def IncludePic(f, name):
    f.write (r"\begin{center}" + "\n")
    f.write (r"  \includegraphics[width=\textwidth]{" + name + "}\n")
    f.write (r"\end{center}" + "\n\n")

def MakeStart (f, lab_num):
    f.write ('\documentclass{article}' + '\n' + r'\usepackage[T2A]{fontenc}' + '\n' + r'\usepackage[utf8]{inputenc}' + '\n' + r'\usepackage[russian]{babel}' + '\n')
    f.write (r'\usepackage{graphicx}' + '\n' + r'\graphicspath{ {./images/} }' + '\n')
    f.write (r'\title{' + 'Лабораторная работа № ' + lab_num + '}\n')
    f.write (r'\author{Александр Романов Б01-107}' + '\n\n')
    f.write (r'\begin{document}' + '\n')
    f.write (r'\maketitle' + '\n')
    f.write (r'\section{Введение}' + '\n')
    f.write (r'\textbf{Цель работы:}' + '\n\n')
    f.write (r'\textbf{Используемое оборудование:}' + '\n\n')

def MakeEnd (f):
    f.write(r"\textbf{Краткие выводы:}" + "\n")
    f.write ('\n' + r'\end{document}' + '\n')
