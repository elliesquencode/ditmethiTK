#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char t1;
    char t2;
    int g1;
    int g2;
} match;
typedef struct
{
    char name;
    int score;
    int g1;
    int g0;
} team;
void input(char *filename)
{
    FILE *fp = fopen(filename, "w");
    match m;
    if (fp == NULL)
    {
        printf("Khong tim thay file.\n");
        exit(1);
    }
    else
    {
        printf("Nhap doi nha: ");
        scanf(" %c", &m.t1);
        printf("Nhap doi khach: ");
        scanf(" %c", &m.t2);
        printf("Nhap ti so tran bong: ");
        scanf("%d %d", &m.g1, &m.g2);
    }
    fprintf(fp, "%c %c %d %d\n", m.t1, m.t2, m.g1, m.g2);

    fclose(fp);
}

void football(char *filename)
{
    FILE *fp = fopen(filename, "r");
    match m;
    if (fp == NULL)
    {
        printf("Khong tim thay file.\n");
        exit(1);
    }
    printf("Du lieu tran dau:\n");
    while (fscanf(fp, " %c %c %d %d", &m.t1, &m.t2, &m.g1, &m.g2) != EOF)
    {
        printf("%c %c %d %d\n", m.t1, m.t2, m.g1, m.g2);
    }
    fclose(fp);
}
void Team(char *filename)
{
    FILE *fp = fopen(filename, "w");
    if (fp == NULL)
    {
        printf("Khong tim thay file.\n");
        exit(1);
    }
    int n;
    printf("nhap so team: ");
    scanf("%d", &n);
    team t[n];
    for (int i = 0; i < n; i++)
    {
        printf("nhap thong tin doi thu %d: \n", i + 1);
        printf("ten doi: ");
        scanf(" %c", &t[i].name);
        printf("so diem: ");
        scanf("%d", &t[i].score);
        printf("so ban thang: ");
        scanf("%d", &t[i].g1);
        printf("so ban thua: ");
        scanf("%d", &t[i].g0);
        fprintf(fp, "%c %d %d %d\n", t[i].name, t[i].score, t[i].g1, t[i].g0);
    }

    fclose(fp);
}
void printTeam(char *filename)
{
    char name;
    int score, g1, g0;
    FILE *fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("Khong tim thay file.\n");
        exit(1);
    }
    else
    {
        while (fscanf(fp, " %c %d %d %d", &name, &score, &g1, &g0) != EOF)
        {
            printf("%c %d %d %d\n", name, score, g1, g0);
        }
    }
    fclose(fp);
}
int main()
{
    char name[] = "match.txt";
    // input(name);
    // football(name);
    char team[] = "Team.txt";
    // Team(team);
    printTeam(team);
    return 0;
}