#include <stdio.h>
#include <ctype.h>
#include <math.h>

#define eps 10e-6

enum type_of_equation
{
    quadratic,
    linear_with_high_coef,
    linear_wihout_high_coef
};

enum number_solutions
{
    two_solutions,
    one_solution,
    no_solutions
};

int check_not_zero_value (float value );

void solve_quadratic_equation (float a, float b, float c, int* ammount_solutions, float* x);

void solve_linear_equation_with_high_coef (float b, float c, int* ammount_solutions, float *x);

void solve_linear_wihout_high_coef ( int* ammount_solutions );

void input_coef (float* firstcoef, float* secondcoef, float* thirdcoef);

void quadraticonesolut (float firstcoef, float secondcoef);

void output_solutions (int* solutions, float* x);

int type_equation (float a, float b, float c, int* equation);

float discr (float a, float b, float c);

void solve_roots (float a,float b, float d, float *x);

int compare_roots_for_similar_value (float *x);

int check_not_zero_value (float value );