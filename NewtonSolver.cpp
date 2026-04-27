#include "NewtonSolver.h"
#include <cmath>
#include <iostream>


double NewtonSolver::derive(std::function<double(double)> f, double x) const {
    return (f(x + dx) - f(x - dx)) / (2.0 * dx);
}

double NewtonSolver::solve(std::function<double(double)> f, double x0, int max_iterations) const {
    double x = x0;

    std::cout << "Newton method iterations:\n";
    std::cout << "----------------------------------------\n";

    for (int i = 0; i < max_iterations; ++i) {

        double fx = f(x);
        double dfx = derive(f, x);

        double x_next;

        if (std::abs(dfx) < 1e-12) {
            std::cout << "Step " << i + 1 << ": derivative too small -> stop\n";
            return x;
        }

        x_next = x - fx / dfx;

        std::cout << "Step " << i + 1
                  << " | x = " << x
                  << " | f(x) = " << fx
                  << " | f'(x) = " << dfx
                  << " | next x = " << x_next
                  << std::endl;

        if (std::abs(fx) < epsilon) {
            std::cout << "----------------------------------------\n";
            std::cout << "Converged (|f(x)| < eps)\n";
            return x;
        }

        if (std::abs(x_next - x) < epsilon) {
            std::cout << "----------------------------------------\n";
            std::cout << "Converged (|x_next - x| < eps)\n";
            return x_next;
        }

        x = x_next;
    }

    std::cout << "----------------------------------------\n";
    std::cout << "Max iterations reached\n";
    return x;
}