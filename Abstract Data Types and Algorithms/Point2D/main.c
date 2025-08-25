#include "Point2D.h" 
#include "stdio.h"

void main() {
    float x, y; // Coordinates to be entered from the keyboard
    
    printf("Enter the two coordinates of a point, separated by a space: ");
    scanf("%f", &x);
    scanf("%f", &y);

    Point2D myPoint = createPoint2D(x, y);
    printf("The entered point is: ");
    displayPoint(myPoint);
    printf("\n");
    printf("The distance to the origin is: %f\n", calculateDistanceToOrigin(myPoint));

    float displacementX, displacementY;
    printf("Enter the x displacement: ");
    scanf("%f", &displacementX);
    printf("Enter the y displacement: ");
    scanf("%f", &displacementY);

    translatePoint(&myPoint, displacementX, displacementY);
    printf("The new translated point is: ");
    displayPoint(myPoint);
    printf("\n");
}
