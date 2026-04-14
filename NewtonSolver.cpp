#include "NewtonSolver.h"
#include <cmath>
#include <iostream>

NewtonSolver::NewtonSolver(double eps, double deltaX) 
    : epsilon(eps), dx(deltaX) {}

double NewtonSolver::derive(std::function<double(double)> f, double x) const {
    return (f(x + dx) - f(x)) / dx;
}

double NewtonSolver::solve(std::function<double(double)> f, double x0, int max_iterations) const {
    double x_n = x0;

    for (int i = 0; i < max_iterations; ++i) {
        double fx = f(x_n);
        double dfx = derive(f, x_n);

        // Перевірка на особливе значення (горизонтальна дотична)
        if (std::abs(dfx) < 1e-12) {
            std::cout << "Похідна близька до нуля. Метод Ньютона не збігається. " << std::endl;;
            exit(1);
        }


        // Формула Ньютона: x_{n+1} = x_n - f(x_n) / f'(x_n)
        double x_next = x_n - fx / dfx;

        if (std::abs(x_next - x_n) < epsilon) {
            std::cout << "Потребувалось ітерацій: " << i + 1 << std::endl;
            
            return x_next;
        }

        x_n = x_next;
    }

    std::cout << "Досягнуто ліміт ітерацій, корінь не знайдено. ";
    exit(1);
}