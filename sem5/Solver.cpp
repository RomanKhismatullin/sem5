#include "Solver.h"
#define Point std::complex<double>

const double EPSILON = 1e-9;

int solver::GetIntersect(Point* L_p1, Point* L_p2, Point* Center, Point* OnRadius, double* f1, double* f2, double* t_f1, double*t_f2) {
    // Extract coordinates
    Point p1 = *L_p1;
    Point p2 = *L_p2;
    Point center = *Center;
    Point onRadius = *OnRadius;

    // Calculate circle radius
    double radius = std::abs(onRadius - center);

    // Line equation: p(t) = p1 + t * (p2 - p1)
    Point dir = p2 - p1;

    // Translate line and circle to origin-centered coordinates
    Point p1_rel = p1 - center;
    Point p2_rel = p2 - center;

    // Quadratic equation coefficients: At^2 + Bt + C = 0
    double A = std::norm(dir);                          // A = (dx^2 + dy^2)
    double B = 2.0 * std::real(std::conj(p1_rel) * dir); // B = 2 * (x1 * dx + y1 * dy)
    double C = std::norm(p1_rel) - radius * radius;      // C = (x1^2 + y1^2 - r^2)

    // Calculate the discriminant
    double D = B * B - 4 * A * C;

    if (D < -EPSILON) {
        // No intersection
        return 0;
    }

    if (std::abs(D) < EPSILON) {
        // One intersection (tangent to the circle)
        double t = -B / (2 * A);
        Point intersection = p1 + t * dir;
        double angle = std::arg(intersection - center);

        *f1 = angle;
        *t_f1 = t;

        return 1;
    }

    // Two intersections
    double sqrtD = std::sqrt(D);
    double t1 = (-B - sqrtD) / (2 * A);
    double t2 = (-B + sqrtD) / (2 * A);

    Point intersection1 = p1 + t1 * dir;
    Point intersection2 = p1 + t2 * dir;

    // Calculate angles
    *f1 = std::arg(intersection1 - center);
    *f2 = std::arg(intersection2 - center);


    *t_f1 = t1;
    *t_f2 = t2;

    return 2;
}
#define CB_EPS 1e-5
using std::max;
using std::min;
int solver::CheckBetween(double d3, double d1, double d2)
{
    auto mx = max(d1, d2);
    auto mn = min(d1, d2);
    return d3< mx + CB_EPS && d3 > mn- CB_EPS;
}
