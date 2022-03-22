
# <p align="center"> Clab </p>

## Make your lab creating process more easier
## Table of contents:

[How to clone](#How_to_clone)

[Dependencies](#Dependencies)
## How to clone
To clone this repo run:
```
git clone https://github.com/ajlekcahdp4/lab_calc
cd lab_calc
```
## Dependencies
Here is the list of progs you need to use my program:
### gcc compiler
You can install [gcc compiller](https://gcc.gnu.org) by running:
```
sudo apt install gcc
```
### python3
You can install [python3](https://www.python.org/downloads/) by running:
```
sudo apt install python3
```
### matplotlib
To use graph plotting you need to install [matplotlib](https://matplotlib.org)
You can install* matplotlib by pip installer:
```
pip install matplotlib
```
Or by using conda:
```
conda install matplotlib
```
* [Usefull link](https://matplotlib.org/stable/users/getting_started/)
## To construct your own tex file open "main.c" and use functions:

## To get lsm results and draw graph:
Enter your dots for graph in text file (you will be asked of the name of this file) by the way:
```
4 //number of measurements
1 2 3 4 //first row
1 2 3 4 //second row
```
## To run only lsm (least squares method) and graph plotting:

```
$ make Graph
```
