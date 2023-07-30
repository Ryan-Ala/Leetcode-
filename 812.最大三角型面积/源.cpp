#include<iostream>
static inline double cmp(double a, double b)
{
    return a > b ? a : b;
}
double largestTriangleArea(int** points, int pointsSize, int* pointsColSize) {
    double area = 0.0, max = 0.0;
    for (int i = 0; i < pointsSize - 2; i++)
    {
        for (int j = i + 1; j < pointsSize - 1; j++)
        {
            for (int k = j + 1; k < pointsSize; k++)
            {
                area = 0.5 * abs(points[j][0] * points[k][1] - points[k][0] * points[j][1] - points[i][0] * points[k][1] + points[k][0] * points[i][1] + points[i][0] * points[j][1] - points[j][0] * points[i][1]);
                max = cmp(area, max);
            }
        }
    }
    return max;
}