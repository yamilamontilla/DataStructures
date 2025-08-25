#include "Point2D.h"
#include "math.h"
#include "stdio.h"

Point2D createPoint2D(float newX, float newY) {
    Point2D point;
    point.x = newX;
    point.y = newY;
    return(point);
}

void translatePoint(Point2D* point, float displacementX, float displacementY) {
    assert(point != NULL);
    point->x = point->x + displacementX;
    point->y = point->y + displacementY;
}

float calculateDistanceToOrigin(Point2D point) {
    float distance; // Will contain the distance from the point to the origin
    distance = sqrt(point.x * point.x + point.y * point.y);
    return(distance);
}

void displayPoint(Point2D point) {
    printf("(%f,%f)", point.x, point.y);
}
