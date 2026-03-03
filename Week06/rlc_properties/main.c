#include <stdio.h>
#include <math.h>

void calc_rlc(double R, double L, double C, double frequency, double *Z, double *phi);

int main(void){
    double R, L, C, f;
    double Z, phi;

    printf("Enter R (ohms): ");
    scanf("%lf", &R);

    printf("Enter L (henrys): ");
    scanf("%lf", &L);

    printf("Enter C (farards): ");
    scanf("%lf", &C);

    printf("Enter frequency (Hz): ");
    scanf("%lf", &f);

    calc_rlc(R, L, C, f, &Z, &phi);

    printf("\nImpendence magnitude Z = %.4lf ohms\n", Z);
    printf("Phase angle phi = %.4lf radians\n", phi);
    return 0;
}

void calc_rlc(double R, double L, double C, double frequency, double *Z, double *phi)
{
    const double PI = 3.14159;

    double omega = 2.0 * PI * frequency;

    /* Avoid divide-by-zero */
    if (omega == 0.0 || C == 0.0)
    {
        *Z = 0.0;
        *phi = 0.0;
        return;
    }

    double X = (omega * L) - (1.0 / (omega * C));

    *Z = sqrt((R * R) + (X * X));

    if (*Z == 0.0)
    {
        *phi = 0.0;
        return;
    }

    *phi = acos(R / *Z);
}
