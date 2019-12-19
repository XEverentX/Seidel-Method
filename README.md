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
## Seidel Method
In case of this method you can solve System of equtions like Ax=b, there:  
    * A - is a coeficent's matrix:  
    * x - is a unknown members column  
    * b - is acolumn of the free members  
## Problem statement
---
$$u(x, y) = 1 - x^2 - y^2$$
$$x \in [-1, 1],   y \in [-1, 1]$$
---
$$u(-1, y) = \mu_1(y) = -y^2, u(1, y) = \mu_2(y) = -y^2$$
$$u(x, -1) = \mu_3(x) = -x^2, u(x, 1) = \mu_4(x) = -x^2$$
$$\Delta u = -4$$
---
$$ n = 4, m = 4$$  
## Table of value of chain function
| | x0 | x1 | x2 | x3 | x4 |
|:---:|:---:|:---:|:---:|:---:|:---:|
| y4| -1 | -0.25 | -0 | -0.25 | -1 |
| y3| -0.25 | 0.5 | 0.75 | 0.5 | -0.25 |
| y2| -0 | 0.75 | 1 | 0.75 | -0 |
| y1| -0.25 | 0.5 | 0.75 | 0.5 | -0.25 |
| y0| -1 | -0.25 | -0 | -0.25 | -1 |

#### Executing with maxAproximationCount = 1

| | x0 | x1 | x2 | x3 | x4 |
|:---:|:---:|:---:|:---:|:---:|:---:|
| y4| -1 | -0.25 | -0 | -0.25 | -1 |
| y3| -0.25 | 0.195313 | 0.396484 | 0.323242 | -0.25 |
| y2| -0 | 0.28125 | 0.390625 | 0.396484 | -0 |
| y1| -0.25 | 0.125 | 0.28125 | 0.195313 | -0.25 |
| y0| -1 | -0.25 | -0 | -0.25 | -1 |

#### Executing with maxAproximationCount = 2
| | x0 | x1 | x2 | x3 | x4 |
|:---:|:---:|:---:|:---:|:---:|:---:|
| y4| -1 | -0.25 | -0 | -0.25 | -1 |
| y3| -0.25 | 0.339844 | 0.585693 | 0.417847 | -0.25 |
| y2| -0 | 0.462891 | 0.679688 | 0.585693 | -0 |
| y1| -0.25 | 0.265625 | 0.462891 | 0.339844 | -0.25 |
| y0| -1 | -0.25 | -0 | -0.25 | -1 |

