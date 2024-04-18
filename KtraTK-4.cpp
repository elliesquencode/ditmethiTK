#include <stdio.h>

void print(float x, int n)
{
    double gia[n], tl = x / 2.0;
    gia[0] = 1.0;
    gia[1] = 1.0 * (1.0 - x);
    for (int i = 2; i < n; i++)
    {
        gia[i] = gia[i - 1] * (1.0 - tl);
        tl /= 2.0;
    }
    double tonggia = 0;
    for (int i = 0; i < n; i++)
    {
        printf("SP %d: %.4lf\n", i + 1, gia[i]);
        tonggia += gia[i];
    }
    printf("tong gia : %.4lf\n", tonggia);
}

int main()
{
    int n = 15;
    float x = 0.2;
    print(x, n);
    return 0;
}