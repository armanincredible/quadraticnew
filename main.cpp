#include "funct.h"

int main ()
{
    double a, b, c = NAN;
    double first_root = NAN;
    double second_root = NAN;
    int test_status = 0;
    
    test_status = run_unit_test ();

    int input_status = 0;

    while (input_status == UNCORRECT)
    {
        input_status = input_three_coef (&a, &b, &c);
        if (input_status == UNCORRECT)
        {
            printf ("Try one more\n");
            clear_stdin ();
        }
    }

    if (input_status == test_status == CORRECT)
    {
        int ammount_solutions = solve_quadratic_equation (a, b, c, &first_root, &second_root);

        output_solutions (ammount_solutions, first_root, second_root);
    }
    else 
    {
        output_error (input_status);
    }

    return 0;
}