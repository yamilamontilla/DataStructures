// File that implements the 2D point ADT

// Data structure for the point
typedef struct {
    float x, y; // Point coordinates
} Point2D;

// Constructor
// Parameters:
// - newX: initial X coordinate we want the point to have
// - newY: initial Y coordinate we want the point to have
// Return: newly created point
Point2D createPoint2D(float newX, float newY);

// Modifies the coordinates of a point by adding a displacement
// to each coordinate
// Parameters:
// - point: pointer to the point whose coordinates we want to modify
// - displacementX: displacement to be added to the current X coordinate of the point
// - displacementY: displacement to be added to the current Y coordinate of the point
// Precondition: point != NULL
void translatePoint(Point2D *point, float displacementX, float displacementY);

// Calculates the distance from the origin (0,0) to a point
// Parameter: point whose distance to the origin we want to calculate
// Return: distance from the point to (0,0)
float calculateDistanceToOrigin(Point2D point);

// Displays the point on the screen in the form (x,y)
// Parameter: point we want to display on screen
void displayPoint(Point2D point);
