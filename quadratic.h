#include <stdio.h>
#include <ctype.h>
#include <math.h>

enum solutions
{
    twosolutions,
    onesolution,
    nosolutions
};


void input(float firstcoef, float secondcoef, float thirdcoef);

void branching(float firstcoef, float secondcoef, float thirdcoef);

void quadraticcheck (float firstcoef, float seccoef, float thcoef);

void quadraticbranch(float firstcoef, float secondcoef, float thirdcoef, float discr);

void quadratictwosolut(float firstcoef, float secondcoef, float discriminant);

void quadraticonesolut(float firstcoef, float secondcoef);

void linear(float secondcoef, float thirdcoef);

void output(float *solutions, int numbersolutions);

