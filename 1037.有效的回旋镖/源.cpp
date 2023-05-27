#include<iostream>

bool isBoomerang(int** points, int pointsSize, int* pointsColSize) {
    if ((points[0][0] == points[1][0] && points[0][1] == points[1][1]) || (points[0][0] == points[2][0] && points[0][1] == points[2][1]) || (points[1][0] == points[2][0] && points[1][1] == points[2][1]) || (points[0][0] == points[1][0]) && (points[0][0] == points[2][0]) || (points[0][1] == points[1][1] && points[0][1] == points[2][1]))
        return 0;
    if (((double)(points[0][0] - points[1][0]) / (points[0][1] - points[1][1])) == ((double)(points[1][0] - points[2][0]) / (points[1][1] - points[2][1])))
        return 0;
    return 1;
}
