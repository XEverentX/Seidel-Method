![Build status](https://travis-ci.org/XEverentX/Seidel-Method.svg?branch=master)

# Dirichlet problem for Puasson's equation with Seidel method
## Build & Run
To build application simply follow a few steps:
```bash
mkdir build
cd build
cmake ..
cmake --build . --config RELEASE
```
To run under `linux` use:
```bash
./application/seidel
```

To run under `windows` use:
```bash
.\application\Release\seidel.exe
```
### Keys
Also you can set the keys to setup parametrs of the method.
List of keys:
*TODO*


## Difference Scheme
This module is intended for constructing a difference scheme and solving the Dirichlet problem using the Seidel iterative method.  

## Statistic
This module is intended to accumulate statistics and issue it to the user. It is also the output type for the Seidel method.
## Problem statement
```
u(x,y)=1−x 
x∈[−1,1],y∈[−1,1]
```
```
u(−1,y) = μ1(y) = -y, u(1,y) = μ2(y) = -y 
u(x,−1) = μ(x) = −x, u(x,1) = μ(x) = −x 
Δu = −4
```
```
n = 4, m = 4  
```
## Table of value of chain function
| | x0 | x1 | x2 | x3 | x4 |
|:---:|:---:|:---:|:---:|:---:|:---:|
| y4| -1 | -0.25 | -0 | -0.25 | -1 |
| y3| -0.25 | 0.5 | 0.75 | 0.5 | -0.25 |
| y2| -0 | 0.75 | 1 | 0.75 | -0 |
| y1| -0.25 | 0.5 | 0.75 | 0.5 | -0.25 |
| y0| -1 | -0.25 | -0 | -0.25 | -1 |
