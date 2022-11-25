#include <stdio.h>
#include <math.h>
const double cm = 0.02;
const double km = 0.1;
const double um = 1;
double g(double t, double x, double z);

double f(double t, double x, double z)
{
    return z;
}
double g(double t, double x, double z)
{
    return -cm * z - km * x + um;
}
int main(void)
{
    const double t_beg = 0.0;
    const double t_end = 500.0;
    const double x0 = 0;
    const double z0 = (/* Any */);
    const double h = 1;
    double t, x;
    double z;
    FILE* fpo;
    fpo = fopen("filename.csv","w");
    t = t_beg;
    x = x0;
    z = z0;
    double k0, k1, k2, k3, k,l0, l1, l2, l3, l;
    fprintf(fpo,"%lf,  %lf\n", t, x);
    do {
        k0 = f(t,     x,        z       );
        l0 = g(t,     x,        z       );
        k1 = f(t+h/2, x+k0*h/2, z+l0*h/2);
        l1 = g(t+h/2, x+k0*h/2, z+l0*h/2);
        k2 = f(t+h/2, x+k1*h/2, z+l1*h/2);
        l2 = g(t+h/2, x+k1*h/2, z+l1*h/2);
        k3 = f(t+h,   x+k2*h,   z+l2*h  );
        l3 = g(t+h,   x+k2*h,   z+l2*h  );
        k = h/6.0 * (k0 + 2*k1 + 2*k2 + k3);
        l = h/6.0 * (l0 + 2*l1 + 2*l2 + l3);
        t = t + h;
        x = x + k;
        z = z + l;
        fprintf(fpo,"%lf,  %lf\n", t, x);
    } while(t <= t_end);
    fclose(fpo);
    return 0;
}
