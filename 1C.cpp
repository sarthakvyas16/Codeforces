// C. Ancient Berland Circus
// time limit per test2 seconds
// memory limit per test64 megabytes
// Nowadays all circuses in Berland have a round arena with diameter 13 meters, but in the past things were different.

// In Ancient Berland arenas in circuses were shaped as a regular (equiangular) polygon, the size and the number of angles could vary from one circus to another. In each corner of the arena there was a special pillar, and the rope strung between the pillars marked the arena edges.

// Recently the scientists from Berland have discovered the remains of the ancient circus arena. They found only three pillars, the others were destroyed by the time.

// You are given the coordinates of these three pillars. Find out what is the smallest area that the arena could have.

// Input
// The input file consists of three lines, each of them contains a pair of numbers –– coordinates of the pillar. Any coordinate doesn't exceed 1000 by absolute value, and is given with at most six digits after decimal point.

// Output
// Output the smallest possible area of the ancient arena. This number should be accurate to at least 6 digits after the decimal point. It's guaranteed that the number of angles in the optimal polygon is not larger than 100.

// Examples
// InputCopy
// 0.000000 0.000000
// 1.000000 1.000000
// 0.000000 1.000000
// OutputCopy
// 1.00000000

#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>

using namespace std;

const double PI = acos(-1.0);
const int MAX_SIDES = 100;

// Function to calculate the distance between two points
double distance(double x1, double y1, double x2, double y2) {
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

// Function to calculate the area of a regular polygon with circumradius R and k sides
double regular_polygon_area(double R, int k) {
    return (k * R * R * sin(2 * PI / k)) / 2;
}

// Function to calculate the circumradius given three side lengths of a triangle
double calculate_circumradius(double a, double b, double c) {
    // Semi-perimeter
    double s = (a + b + c) / 2.0;
    // Area of the triangle using Heron's formula
    double area = sqrt(s * (s - a) * (s - b) * (s - c));
    // Circumradius formula
    return (a * b * c) / (4.0 * area);
}

int main() {
    vector<pair<double, double>> points(3);

    // Read input coordinates
    for (int i = 0; i < 3; ++i) {
        cin >> points[i].first >> points[i].second;
    }

    // Calculate distances between each pair of points
    vector<double> d(3);
    d[0] = distance(points[0].first, points[0].second, points[1].first, points[1].second);
    d[1] = distance(points[1].first, points[1].second, points[2].first, points[2].second);
    d[2] = distance(points[2].first, points[2].second, points[0].first, points[0].second);

    // Sort distances to ensure consistency
    sort(d.begin(), d.end());

    double min_area = 1e9; // Initialize with a large number

    // Iterate over possible number of sides of the polygon
    for (int k = 3; k <= MAX_SIDES; ++k) {
        // Calculate the circumradius of the regular polygon that could enclose these distances
        double R = calculate_circumradius(d[0], d[1], d[2]);
        double area = regular_polygon_area(R, k);
        min_area = min(min_area, area);
    }

    // Output the result with required precision
    cout << fixed;
    cout.precision(8);
    cout << min_area << endl;

    return 0;
}
