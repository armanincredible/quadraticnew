#include "funct.h"

int comparison_on_zero_value (float value)
{
    if (fabs(value) > EPS)
    {
        return NO_ZERO;
    }
    else 
    {
        return ZERO;
    }
}

void solve_quadratic_equation (float a, float b, float c, int* ammount_solutions, float *x1, float *x2)
{
    if (comparison_on_zero_value (a) == NO_ZERO)
    {
        float d = 0;
        d = calc_discr (a, b, c);
        if (d > EPS)
        {
            calc_roots_quadratic (a, b, d, x1, x2);
            *ammount_solutions = TWO_SOLUTIONS;
        }
        else if (comparison_on_zero_value(d) == ZERO)
        {  
            calc_roots_quadratic (a, b, d, x1, x2);
            *ammount_solutions = ONE_SOLUTIONS;
        }
        else 
        {
            *ammount_solutions = NO_SOLUTIONS;
        }
    }
    else solve_linear_equation (b, c, ammount_solutions, x1);
}

float calc_discr (float a, float b, float c)
{
    float value_of_discr = b*b-4*a*c;

    return value_of_discr;
}

void calc_roots_quadratic (float a, float b, float d, float* x1, float* x2)
{
    assert (a);
    assert (d >= EPS);
    float sqrt_d = sqrtf(d);
    *x1 = (-b + sqrt_d) / (2 * a);
    *x2 = (-b - sqrt_d) / (2 * a);
}

void solve_linear_equation (float b, float c, int* ammount_solutions, float* x1)
{   
    if (comparison_on_zero_value (b) == NO_ZERO)
    {
        *ammount_solutions = ONE_SOLUTIONS;

        if (comparison_on_zero_value (c) == NO_ZERO)
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
        *ammount_solutions = INFINITY_SOLUTIONS;
    }
}

void output_solutions (int ammount_solutions, float x1, float x2)
{   
    switch (ammount_solutions)
    {
        case ONE_SOLUTIONS:
            printf ("%f", x1);
            break;
        case TWO_SOLUTIONS:
            printf ("%f %f", x1, x2);
            break;
        case NO_SOLUTIONS:
            printf ("No solutions\n");
            break;
        case INFINITY_SOLUTIONS:
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
            return CORRECT_INPUT;
        }
        else
        {
            printf ("uncorrect input\n");
            return UNCORRECT_INPUT;
        }
    }
}