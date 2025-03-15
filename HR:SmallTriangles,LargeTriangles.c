#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double countArea(int a, int b, int c)
{
    double p = (a + b + c) / 2.0;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}
struct triangle
{
    int a;
    int b;
    int c;
};

typedef struct triangle triangle;
void sort_by_area(triangle *tr, int n)
{
    /**
     * Sort an array a of the length n
     */

    int lastSortedIndex = n - 1;
    for (int i = 0; i < n; i++)
    {
        int isSorted = 1;
        int currentSortedIndex = -1;
        for (int j = 0; j < lastSortedIndex; j++)
        {
            if (countArea(tr[j].a, tr[j].b, tr[j].c) > countArea(tr[j + 1].a, tr[j + 1].b, tr[j + 1].c))
            {
                triangle temp = tr[j];
                tr[j] = tr[j + 1];
                tr[j + 1] = temp;
                isSorted = 0;
                currentSortedIndex = j;
            }
        }
        if (isSorted)
        {
            return;
        }
        lastSortedIndex = currentSortedIndex;
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    triangle *tr = malloc(n * sizeof(triangle));
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
    }
    sort_by_area(tr, n);
    printf("Sorted triangles by area:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d %d %d, area: %f\n", tr[i].a, tr[i].b, tr[i].c, countArea(tr[i].a, tr[i].b, tr[i].c));
    }
    return 0;
}