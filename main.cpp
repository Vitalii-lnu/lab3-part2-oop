#include <iostream>
#include <iomanip>
#include <cmath>
#include "NewtonSolver.h"

int main() {

    setlocale(0, ".1251");

    // Визначаємо функцію f(x) = x^2 - 2
    auto myFunction = [](double x) {
        return std::exp(x) - std::exp(-x) - 2;
    };

    NewtonSolver solver(0.01); // Створюємо об'єкт з заданою точністю
    double initialGuess = 1.0;  // Початкове наближення

    
    double root = solver.solve(myFunction, initialGuess);
    
    std::cout << std::fixed << std::setprecision(7);
    std::cout << "Function result: " << root << std::endl;
    std::cout << "Check f(x) = " << myFunction(root) << std::endl;


    return 0;
}