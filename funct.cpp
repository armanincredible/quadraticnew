#include "funct.h"

int spot_type_equation (float a, float b, float c, int *type_equation)
{
    if (comparison_on_zero_value (a) == no_zero)
    {
        *type_equation = quadratic;
    }
    else
    {
        *type_equation = linear;
    }
    return *type_equation;
}

int comparison_on_zero_value (float value)
{
    if (fabs(value) > eps)
    {
        return no_zero;
    }
    else 
    {
        return zero;
    }
}

void solve_quadratic_equation (float a, float b, float c, int* ammount_solutions, float *x1, float *x2)
{
    float d = 0;
    d = calc_discr (a, b, c);
    if (d > eps)
    {
        calc_roots_quadratic (a, b, d, x1, x2);
        *ammount_solutions = two_solutions;
    }
    else if (comparison_on_zero_value(d) == zero)
    {
        calc_roots_quadratic (a, b, d, x1, x2);
        *ammount_solutions = one_solution;
    }
    else 
    {
        *ammount_solutions = no_solutions;
    }
}

float calc_discr (float a, float b, float c)
{
    float value_of_discr = b*b-4*a*c;

    return value_of_discr;
}

void calc_roots_quadratic (float a, float b, float d, float* x1, float* x2)
{
    assert (a);
    assert (d >= eps);
    float sqrt_d = sqrtf(d);
    *x1 = (-b + sqrt_d) / (2 * a);
    *x2 = (-b - sqrt_d) / (2 * a);
}

void solve_linear_equation (float b, float c, int* ammount_solutions, float* x1)
{   
    if (comparison_on_zero_value (b) == no_zero)
    {
        *ammount_solutions = one_solution;

        if (comparison_on_zero_value (c) == no_zero)
        {
            *x1 = -c / b;
        }
        else 
        {
            *x1 = 0;
        }
    }
    else 
    {
        *ammount_solutions = infinity_solutions;
    }
}

void output_solutions (int ammount_solutions, float x1, float x2)
{   
    switch (ammount_solutions)
    {
        case one_solution:
            printf ("%f", x1);
            break;
        case two_solutions:
            printf ("%f %f", x1, x2);
            break;
        case no_solutions:
            printf ("No solutions\n");
            break;
        case infinity_solutions:
            printf ("Infinity solutions\n");
            break;
        default:
            printf ("unexpected ammount solution\n");
            break;
    }
}

int input_three_coef_check_correct (const float* a, const float* b, const float* c)
{
    char symbol = '0';

    scanf ("%f %f %f", a, b, c);

    symbol= getchar();

    for (;;symbol= getchar())
    {
        if (symbol == ' ')
        {
            continue;
        }

        if (symbol == '\n')
        {
            return correct_input;
        }
        else
        {
            printf ("uncorrect input\n");
            return uncorrect_input;
        }
    }
}

void solve_equation (int type_equation, float a, float b, float c, int *ammount_solutions, float *first_root, float *second_root)
{
     switch (type_equation)
    {
        case quadratic:
            solve_quadratic_equation (a, b, c, ammount_solutions, first_root, second_root);
            break;
        case linear:
            solve_linear_equation (b, c, ammount_solutions, first_root);
            break;
        default:
            printf ("unexpected type of equation\n");
            break;
    }
}