#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <assert.h>

#define eps 10e-6

enum correct_uncorrect_input
{
    uncorrect_input,
    correct_input
};

enum zero_value //!TODO rename enum and his fields//
{
    no_zero,
    zero
};

enum type_of_equation
{
    quadratic,
    linear
};

enum number_solutions
{
    two_solutions,
    one_solution,
    no_solutions,
    infinity_solutions
};

int comparison_on_zero_value (float value);

void solve_quadratic_equation (float a, float b, float c, int* ammount_solutions, float* first_root, float* second_root);

void solve_linear_equation (float b, float c, int* ammount_solutions, float* first_root);

int input_three_coef_check_correct (const float* firstcoef, const float* secondcoef, const float* thirdcoef);

void output_solutions (int ammount_solutions, float first_root, float second_root);

int spot_type_equation (float a, float b, float c, int* type_equation);

float calc_discr (float a, float b, float c);

void calc_roots_quadratic (float a,float b, float d, float* first_root, float* second_root);

void solve_equation (int type_equation, float a, float b, float c, int* ammount_solutions, float* first_root, float* second_root);