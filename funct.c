#include "quadratic.h"

int type_equation (float a, float b, float c, int *equation)
{
    if (check_not_zero_value ( fabs (a) ))
    {
        *equation=quadratic;
    }
    else
    {
        if (check_not_zero_value ( fabs (b) ))
        {
            *equation=linear_with_high_coef;
        }
        else
        {
            *equation=linear_wihout_high_coef;
        }
    }
    return *equation;
}

int check_not_zero_value (float value )
{
    if (value > eps)
    {
        return 1;
    }
    else 
    {
        return 0;
    }
}

void solve_quadratic_equation (float a, float b, float c, int* ammount_solutions, float* x)
{
    float d = 0;
    d = discr (a, b, c);
    if (d >= 0)
    {
        solve_roots (a, b, d, x);
        if (compare_roots_for_similar_value (x))
        {
            *ammount_solutions = two_solutions;
        }
        else 
        {
            *ammount_solutions = one_solution;
        }
    }
    else 
    {
        *ammount_solutions = no_solutions;
    }
}

float discr (float a, float b, float c)
{
    float value_of_discr = b*b-4*a*c;

    return value_of_discr;
}

void solve_roots (float a,float b, float d, float *x)
{
    *x = (-b + sqrtf (d)) / (2 * a);
    *(x + 1) = (-b - sqrtf (d)) / (2 * a);
}

int compare_roots_for_similar_value (float *x)
{
    return check_not_zero_value ( fabs (*x-*(x+1)) );
}

void solve_linear_equation_with_high_coef (float b, float c, int* ammount_solutions, float* x)
{
    *ammount_solutions = one_solution;
    *x= -c/b;
}

void solve_linear_wihout_high_coef (int* ammount_solutions)
{
    *ammount_solutions = no_solutions;
}

void output_solutions (int* ammount_solutions, float* x)
{
    switch (*ammount_solutions)
    {
        case one_solution:
            printf ("%f", *x);
            break;
        case two_solutions:
            printf ("%f %f", *x, *(x + 1));
            break;
        case no_solutions:
            printf ("No solutions\n");
            break;
        default:
            break;
    }
}

void input_coef (float* a, float* b, float* c)
{
    scanf ("%f %f %f", a, b, c);
}