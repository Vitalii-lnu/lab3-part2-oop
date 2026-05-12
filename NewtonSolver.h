#ifndef NEWTONSOLVER_H
#define NEWTONSOLVER_H

#include <functional>
#include <stdexcept>

class NewtonSolver {
private:
    double epsilon; 
    double dx;      

    
    double derive(std::function<double(double)> f, double x) const;

public:
    NewtonSolver(double eps = 1e-7, double deltaX = 1e-8);

    
    double solve(std::function<double(double)> f, double x0, int max_iterations = 1000) const;
};

#endif