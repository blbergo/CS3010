# CS3010 Project 1 - Gaussian Elimination with Scale Partial Pivoting
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
