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



using std::max;
using std::min;
int solver::CheckBetween(double d3, double d1, double d2)
{
    auto mx = max(d1, d2);
    auto mn = min(d1, d2);
    return d3 <= mx - CB_EPS && d3 >= mn + CB_EPS;
}

int solver::CheckBetween(double d3)
{
    auto mx = 1;
    auto mn = 0;
    return d3 <= mx - CB_EPS && d3 >= mn + CB_EPS;
}


#define Pi 3.14159265358979323846
#define ME_EPS 1e-9
int solver::MyEQ(double f1, double f2)
{
    if (fabs((f1 - f2) / 2 / Pi) < ME_EPS) {
        return 1;
    }
    else {
        return 0;
    }
}



#define CS_EPS 1e-9/*
int solver::CheckSegmentIntersection(Point* p1, Point* p2, Point* g1, Point* g2) {
    // ������������ �������
    Point d1 = *p2 - *p1; // ������ ��� ������� �������
    Point d2 = *g2 - *g1; // ������ ��� ������� �������

    // ��������� ����������� �������
    double det = d1.real() * d2.imag() - d1.imag() * d2.real();

    // ���� ������������ ����� 0, ������ ����������� ��� �����������
    if (std::abs(det) < CS_EPS) {
        // ���������, ��� ������� �����������
        Point delta = *g1 - *p1;
        if (std::abs(delta.real() * d1.imag() - delta.imag() * d1.real()) > CS_EPS) {
            return 0; // ������� �� ����� �� ����� ������
        }

        // �������� ������ ������� ������� �� ������ �������
        auto proj = [](Point a, Point b, Point p) {
            return (std::real(p - a) * std::real(b - a) + std::imag(p - a) * std::imag(b - a)) /
                std::norm(b - a);
            };

        // ��������� ��������� �������� ������ ������� ������� �� ������
        double t1 = proj(*p1, *p2, *g1);
        double t2 = proj(*p1, *p2, *g2);

        // ��������� ���������
        if (t1 > t2) std::swap(t1, t2);

        // ��������� ����������� �� �������� ������
        if ((t1 <= CB_EPS && t2 <= CB_EPS) || (t1 >= 1 - CB_EPS && t2 >= 1 - CB_EPS)) {
            return 0; // ������ ����������� ������ ������������
        }

        // ��������� ������� ����������� ��������
        if (t2 >= -CB_EPS && t1 <= 1 + CB_EPS) {
            return 1; // ���� ����������� ��������
        }

        return 0; // ����������� ���
    }

    // ������ ������� ��������� ��� ���������� ����� �����������
    Point delta = *g1 - *p1;
    double t1 = (delta.real() * d2.imag() - delta.imag() * d2.real()) / det;
    double t2 = (delta.real() * d1.imag() - delta.imag() * d1.real()) / det;

    // ������� ����� �����������
    Point intersection = *p1 + d1 * t1;

    // ���������, ��� ����������� ��������� � �������� ��������
    if (solver::CheckBetween(t1) && solver::CheckBetween(t2)) {
        return 1;
    }

    return 0; // ������� �� ������������
}
*/

int solver::CheckSegmentIntersection(Point* p1, Point* p2, Point* g1, Point* g2) {
    // ������������ �������
    Point d1 = *p2 - *p1; // ������ ��� ������� �������
    Point d2 = *g2 - *g1; // ������ ��� ������� �������

    // ��������� ����������� �������
    double det = d1.real() * d2.imag() - d1.imag() * d2.real();

    // ���� ������������ ����� 0, ������ ����������� ��� ���������
    if (std::abs(det) < ME_EPS) {
        // ���������, ��� ������� �����������
        Point delta = *g1 - *p1;
        if (std::abs(delta.real() * d1.imag() - delta.imag() * d1.real()) > ME_EPS) {
            return 0; // ������� �� ����� �� ����� ������
        }

        // �������� ������ ������� ������� �� ������ �������
        auto proj = [](Point a, Point b, Point p) {
            return (std::real(p - a) * std::real(b - a) + std::imag(p - a) * std::imag(b - a)) /
                std::norm(b - a);
            };

        // ��������� ��������� �������� ������ ������� ������� �� ������
        double t1 = proj(*p1, *p2, *g1);
        double t2 = proj(*p1, *p2, *g2);

        // ��������� ���������
        if (t1 > t2) std::swap(t1, t2);

        // ��������� ����������� ������ �� �������� ������
        if ((t1 <= CB_EPS && t2 <= CB_EPS) || (t1 >= 1 - CB_EPS && t2 >= 1 - CB_EPS)) {
            return 0; // ������ ����� ������������
        }

        // ��������� ������� ����������� ��������
        if (t2 >= -CB_EPS && t1 <= 1 + CB_EPS) {
            return 1; // ���� ����������� ��������
        }

        return 0; // ����������� ���
    }

    // ������ ������� ��������� ��� ���������� ����� �����������
    Point delta = *g1 - *p1;
    double t1 = (delta.real() * d2.imag() - delta.imag() * d2.real()) / det;
    double t2 = (delta.real() * d1.imag() - delta.imag() * d1.real()) / det;

    // ������� ����� �����������
    Point intersection = *p1 + d1 * t1;

    // ���������, ��� ����������� ��������� � �������� ��������
    if (t1 < 0 || t1 > 1 || t2 < 0 || t2 > 1) {
        return 0; // ����������� �� ����� �� ����� ��������
    }


    // ��������� ����������� ������ � ����� �������
    auto isCloseToEnd = [](Point p, Point a, Point b) {
        return std::abs(p - a) <= CB_EPS || std::abs(p - b) <= CB_EPS;
        };

    if (isCloseToEnd(intersection, *p1, *p2) || isCloseToEnd(intersection, *g1, *g2)) {
        return 0; // ����������� ���������� ������ �� �������� �����
    }

    return 1; // ������� ������������
}



// ������� ��� ��������, ����� �� ���� teta �� ���� (f1, f2)
int solver::CheckArcAng(double f1, double f2, double teta) {

    // ����������� ���� � �������� [0, 2*PI)
    auto normalize = [](double angle) {
        while (angle < 0) angle += 2 * Pi;
        while (angle >= 2 * Pi) angle -= 2 * Pi;
        return angle;
        };

    f1 = normalize(f1);
    f2 = normalize(f2);
    teta = normalize(teta);

    // ���� f1 <= f2, ���� ����� � �������� ������ �������
    if (f1 <= f2) {
        return (teta >= f1 && teta <= f2) ? 1 : 0;
    }
    else {
        // ���� f1 > f2, ���� ���������� 0 � ����� �� ���� ����������
        return (teta >= f1 || teta <= f2) ? 1 : 0;
    }
}


#define PI 3.141592653589793
#define TWO_PI 2 * PI
// ������� ��� ��������, ����� �� ���� teta �� ����, �������� ������� � ������
int solver::CheckArc(double start, double arcLength, double teta) {
    // ����������� ���� � �������� [0, 2*PI)
    auto normalize = [](double angle) {
        while (angle < 0) angle += TWO_PI;
        while (angle >= TWO_PI) angle -= TWO_PI;
        return angle;
        };

    // ����������� teta � ������ ����
    start = normalize(start);
    teta = normalize(teta);

    // ����� ���� ����� ���� ������ ������ �������
    if (std::abs(arcLength) >= TWO_PI) {
        return 1; // ����� ���� ����������� ����, ��� ��� ��� ��������� ���� ����
    }

    // �������� ���� ����
    double end = normalize(start + arcLength);

    if (arcLength > 0) {
        // �� ������� �������: [start, end]
        if (start <= end) {
            return (teta >= start && teta <= end) ? 1 : 0;
        }
        else {
            // ���� ���������� 0
            return (teta >= start || teta <= end) ? 1 : 0;
        }
    }
    else {
        // ������ ������� �������: [end, start]
        if (end <= start) {
            return (teta >= end && teta <= start) ? 1 : 0;
        }
        else {
            // ���� ���������� 0
            return (teta >= end || teta <= start) ? 1 : 0;
        }
    }
}
