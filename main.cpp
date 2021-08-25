#include "funct.h"

int main ()
{
    float a = 0;
    float b = 0;
    float c = 0;
    int type_equation = 0;
    int ammount_solutions = 0;
    float first_root = 0;
    float second_root = 0;

    if (input_three_coef_check_correct (&a, &b, &c) == correct_input)
    {
        spot_type_equation (a, b, c, &type_equation);
        
        solve_equation (type_equation, a, b, c, &ammount_solutions, &first_root, &second_root);

        output_solutions (ammount_solutions, first_root, second_root);
    }

    return 0;
}