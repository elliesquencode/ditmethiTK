#include <stdio.h>

void input(float x, int n)
{
    FILE *fp = fopen("donhang.txt", "w");
    if (fp == NULL)
    {
        printf("khong tim thay file.\n");
    }
    else
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
            fprintf(fp, "SP %d: %.4lf\n", i + 1, gia[i]); // Write to file instead of printing
            tonggia += gia[i];
        }
        fprintf(fp, "tong gia : %.4lf\n", tonggia); // Write to file instead of printing
        fclose(fp);
    }
}

void print(char *filename)
{
    FILE *fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("khong tim thay file.\n");
    }
    else
    {
        float x;
        int n;
        double s;
        while (fscanf(fp, "%f %d %lf", &x, &n, &s) != EOF)
        {
            printf("x = %.2f, n = %d, S = %.4lf\n", x, n, s);
        }
        fclose(fp);
    }
}

int main()
{
    int n = 15;
    float x = 0.2;
    char name[] = "donhang.txt";
    input(x, n);
    print(name);
    return 0;
}
