#include "quadratic.h"

int main ( )
{
    float a = 0;
    float b = 0;
    float c = 0;
    int equation=0;
    int ammount_solutions=0;
    float x[2]={0};

    input_coef (&a, &b, &c);

    type_equation (a, b, c, &equation);

    switch(equation)
    {
        case quadratic:
            solve_quadratic_equation (a, b, c, &ammount_solutions, x);
            break;
        case linear_with_high_coef:
            solve_linear_equation_with_high_coef (b, c, &ammount_solutions, x);
            break;
        case linear_wihout_high_coef:
            solve_linear_wihout_high_coef (&ammount_solutions);
            break;
        default:
            break;
    }

    output_solutions (&ammount_solutions, x);
}