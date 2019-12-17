![Build status](https://travis-ci.org/XEverentX/Seidel-Method.svg?branch=master)

# Dirichlet task for Puasson's equation with Seidel method
## Build && Run
To build application simply follow a few steps:
```bash
mkdir build
cd build
cmake ..
cmake --build . --config RELEASE
```
To run under `linux` use:
```bash
./application/Release/seidel
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
## Current task
```
Δu = - sin(pi*x*y)^2  
x, y э (0,1)  
u(0,y) = sin(pi*y)   u(1,y) = sin(pi*y)  
u(x,0) = x - x^2    u(x,0) = x - x^2  
```


 
