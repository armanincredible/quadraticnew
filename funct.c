#include "quadratic.h"

void branching (float a, float b, float c)
{
    if (a)
    {
        quadraticcheck (a, b, c);
    }
    else
    {
        if (b)
        {
            linear (b, c);
        }
        else
        {
            output (0 , nosolutions);
        }
    }
}

void quadraticcheck (float a, float b, float c)
{
    float discr = 0;
    discr = b * b - 4 * a * c;
    if (discr>=0)
    {
        quadraticbranch (a, b, c, discr);
    }
    else 
    {
        output (0 , nosolutions);
    }
}

void quadraticbranch (float a, float b, float c, float discr)
{
    if (discr > 0)
    {
        quadratictwosolut (a, b, discr);
    }
    else
    {
        quadraticonesolut (a, b);
    }
}

void quadratictwosolut (float a, float b, float discr)
{
    float x[2] = {0};
    *x = (-b + sqrt(discr)) / (2 * a);
    *(x + 1) = (-b - sqrt(discr)) / (2 * a);
    int typesolut = twosolutions;
    output (x, typesolut);
}

void quadraticonesolut (float a, float b)
{
    float x[1] = {0};
    *x = (-b) / (2 * a);
    int typesolut = onesolution;
    output(x, typesolut);
}

void linear (float b, float c)
{
    float x [1] = {0};
    *x = (-b) / (c);
    int typesolut = onesolution;
    output(x, typesolut);
}

void output (float *x, int typesolut)
{
    switch (typesolut)
    {
        case onesolution:
            printf ("%f", *x);
            break;
        case twosolutions:
            printf ("%f %f", *x, *(x + 1));
            break;
        case nosolutions:
            printf ("No solutions\n");
            break;
        default:
            break;
    }
}