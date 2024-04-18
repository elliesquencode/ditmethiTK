#include <stdio.h>
#include <stdlib.h>

void luong(int n)
{
    double A = 100000;
    int x = 1000, cnt1 = 0, cnt2 = 0;
    for (int i = 0; i <= n; i++)
    {
        if (i == 0)
        {
            printf("luong nam thu %d: %.2lf\n", i, A * 0.8);
        }
        else if (i > 0 && i <= 20)
        {
            printf("luong nam thu %d: %.2lf\n", i, A);
            ++cnt1;
            if (cnt1 == 3)
            {
                A *= 1.1;
                cnt1 = 0;
            }
        }
        else if (i > 20)
        {
            printf("luong nam thu %d: %.2lf\n", i, A + x * i);
            ++cnt2;
            if (cnt2 == 2)
            {
                A *= 1.1;
                cnt2 = 0;
            }
        }
    }
}
int main()
{
    int n = 23;
    luong(n);
    return 0;
}