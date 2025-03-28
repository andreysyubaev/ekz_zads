#include "point.h"
#include <iostream>

double distance(const Point *p);

int main()
{
    const char *pointsFile = "C:\\Users\\andre\\source\\repos\\ekz\\z9\\points.txt";
    const char *nearest_pointFile = "C:\\Users\\andre\\source\\repos\\ekz\\z9\\nearest_point.txt";
    FILE *file = fopen(pointsFile, "r");
    if (!file)
    {
        perror("Ошибка открытия points.txt");
        return 1;
    }

    Point points[100];
    int n = 0;
    while (fscanf(file, "%lf %lf", &points[n].x, &points[n].y) == 2)
    {
        n++;
    }
    fclose(file);

    Point nearest = points[0];
    double min_dist = distance(&nearest);
    for (int i = 0; i < n; i++)
    {
        double d = distance(&points[i]);
        if (d < min_dist)
        {
            min_dist = d;
            nearest = points[i];
        }
    }

    FILE *file2 = fopen(nearest_pointFile, "w");
    if (!file2)
    {
        perror("Ошибка открытия nearest_point.txt");
        return 0;
    }

    fprintf(file2, "ближайшая точка: %.2f %.2f\n", nearest.x, nearest.y);
    fclose(file2);

    return 0;
}

double distance(const Point *p)
{
    return p->x * p->x + p->y * p->y;
}