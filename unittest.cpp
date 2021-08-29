#include "funct.h"

int unit_test (double a, double b, double c, 
               int rl_n_roots, double rl_first_root,
               double rl_second_root, int ammount)
{
    assert (isfinite(a));
    assert (isfinite(b));
    assert (isfinite(c));
    double x1 = NAN, x2 = NAN;

    if (solve_quadratic_equation (a, b, c, &x1, &x2) == rl_n_roots)
        if ((zero_value (rl_first_root - x1) == 
            zero_value (rl_second_root - x2) == 
            ZERO) || 
            (zero_value (rl_first_root - x2) == 
            zero_value (rl_second_root - x1) == 
            ZERO))
        {
            printf ("%d Test success\n", ammount);
            return CORRECT;
        }
        else 
        {
            printf ("%d Test falled\n", ammount);
            return UNCORRECT;
        }
    else
    {
        printf ("%d Test falled\n", ammount);
        return UNCORRECT;
    }
}