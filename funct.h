#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <assert.h>

#define EPS 10e-6

enum correct_uncorrect_input
{
    UNCORRECT_INPUT,
    CORRECT_INPUT
};

enum zero_value 
{
    NO_ZERO,
    ZERO
};

enum number_solutions
{
    TWO_SOLUTIONS,
    ONE_SOLUTIONS,
    NO_SOLUTIONS,
    INFINITY_SOLUTIONS
};

int comparison_on_zero_value (float value);

void solve_quadratic_equation (float a, float b, float c, int* ammount_solutions, float* first_root, float* second_root);

void solve_linear_equation (float b, float c, int* ammount_solutions, float* first_root);

int input_three_coef_check_correct (const float* firstcoef, const float* secondcoef, const float* thirdcoef);

void output_solutions (int ammount_solutions, float first_root, float second_root);

float calc_discr (float a, float b, float c);

void calc_roots_quadratic (float a,float b, float d, float* first_root, float* second_root);