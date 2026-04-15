#include "NewtonSolver.h"
#include <cmath>
#include <iostream>

NewtonSolver::NewtonSolver(double eps, double deltaX) 
    : epsilon(eps), dx(deltaX) {}


// 🔹 Центральна різницева схема — точніша ніж одностороння
double NewtonSolver::derive(std::function<double(double)> f, double x) const {
    return (f(x + dx) - f(x)) / dx;
}


double NewtonSolver::solve(std::function<double(double)> f, double x0, int max_iterations) const {
    double x_n = x0;

    for (int i = 0; i < max_iterations; ++i) {
        double fx = f(x_n);
        double dfx = derive(f, x_n);

        if (std::abs(dfx) < 1e-12) {
            std::cout << "Derivative is almost zero. Newton's method could not be used. ";
            exit(-1);
        }

        double x_next = x_n - fx / dfx;

        if (std::abs(fx) < epsilon) {
            std::cout << "Amount of iterations: " << i + 1 << std::endl;
            return x_n;
        }


        if (std::abs(x_next - x_n) < epsilon) {
            std::cout << "Amount of iterations: " << i + 1 << std::endl;
            return x_next;
        }

        x_n = x_next;
    }

    std::cout << "Iteration limit was reached, could not be solved. " << std::endl;
    exit(-1);
}