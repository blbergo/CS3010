# CS3010 Project 2 - Bisection, NR, Secant, FP, Modified Secant Methods
Developed By: Bryan Bergo
Section E01

## Running
To build the program, use the bash script provided:
```sh
./.run
```
This will compile and run the latest version of the program. The binary can be found under `/output/program` if you wish to run it manually.

## Compiling
If you can't grant execute access to the `run` script, or wish to compile on your own machine, use the following command:
```sh
g++ -I ./src/ ./src/*.cpp -o ./output/program && ./output/program
```
Compiler information can be found under `/.vscode/c_cpp_properties.json`

## Precision
For decimal values, I am using  C++ `doubles`. To determine oscillation I am using C++ `numeric_limits<float>::epsilon()` casted as a `double`, 
which I found to be most accurate in determining convergence in only 50 iterations while accounting for oscillation.