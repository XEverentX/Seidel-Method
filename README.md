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
## Tables
### Table №1
|       |     x0|     x1|     x2|     x3|     x4|
|:-----:|:-----:|:-----:|:-----:|:-----:|:-----:|
|     y4| -1.000| -0.250| -0.000| -0.250| -1.000|
|     y3| -0.250|  0.500|  0.750|  0.500| -0.250|
|     y2| -0.000|  0.750|  1.000|  0.750| -0.000|
|     y1| -0.250|  0.500|  0.750|  0.500| -0.250|
|     y0| -1.000| -0.250| -0.000| -0.250| -1.000|

