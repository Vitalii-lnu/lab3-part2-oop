#include <iostream>
#include <iomanip>
#include <cmath>
#include "NewtonSolver.h"

int main() {

    setlocale(0, ".1251");


    
    auto myFunction = [](double x) {
        return std::exp(x) - std::exp(-x) - 2;
    };

    NewtonSolver solver(0.01); 
    double initialGuess = 1.0;

    
    double root = solver.solve(myFunction, initialGuess);
    
    std::cout << std::fixed << std::setprecision(9);
    std::cout << "Function result: " << root << std::endl;
    
    std::cout << "f(x) is within tolerance = " << myFunction(root) << std::endl;


    return 0;
}