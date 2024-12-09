#include "pch.h"
#include "../sem5/Solver.h"
#include "../sem5/Solver.cpp"

#define M_PI 3.14159265358979323846

TEST(SolverTest, OneIntersections) {
    solver solverInstance;

    std::complex<double> L_p1(0.0, 0.0);
    std::complex<double> L_p2(4.0, 0.0);
    std::complex<double> Center(2.0, 2.0);
    std::complex<double> OnRadius(4.0, 2.0);
    double f1 = 0.0, f2 = 0.0;
    double t_f1 = 0.0, t_f2 = 0.0;

    // Call the function
    int intersections = solverInstance.GetIntersect(&L_p1, &L_p2, &Center, &OnRadius, &f1, &f2, &t_f1, &t_f2);

    // Assertions
    EXPECT_EQ(intersections, 1);
    EXPECT_EQ(f1, -M_PI / 2);
    EXPECT_EQ(f2, 0);
    EXPECT_EQ(t_f1, 0.5);
    EXPECT_EQ(t_f2, 0);
}

TEST(SolverTest, TwoIntersection) {
    solver solverInstance;

    std::complex<double> L_p1(0, 0);
    std::complex<double> L_p2(-1, -1);
    std::complex<double> Center(0, 0);
    std::complex<double> OnRadius(1, 0);
    double f1 = 0.0, f2 = 0.0;
    double t_f1 = 0.0, t_f2 = 0.0;

    // Call the function
    int intersections = solverInstance.GetIntersect(&L_p1, &L_p2, &Center, &OnRadius, &f1, &f2, &t_f1, &t_f2);

    // Assertions
    EXPECT_EQ(intersections, 2);              // Tangent to the circle, 1 intersection
    EXPECT_GE(f1, M_PI/4);                       // Angle should be valid
    EXPECT_LE(f2, -3*M_PI/4);
    EXPECT_TRUE(fabs(t_f1-( - 1 / std::sqrt(2)))<1e-5);
    EXPECT_TRUE(fabs(t_f2-(  1 / std::sqrt(2)))<1e-5);
    //EXPECT_EQ(t_f2, 1 / std::sqrt(2));
}

TEST(SolverTest, NoIntersection) {
    solver solverInstance;

    std::complex<double> L_p1(3, 3);
    std::complex<double> L_p2(3, 6);
    std::complex<double> Center(0, 0);
    std::complex<double> OnRadius(1, 1);
    double f1 = 0.0, f2 = 0.0;
    double t_f1 = 0.0, t_f2 = 0.0;

    // Call the function
    int intersections = solverInstance.GetIntersect(&L_p1, &L_p2, &Center, &OnRadius, &f1, &f2, &t_f1, &t_f2);

    // Assertions
    EXPECT_EQ(intersections, 0);              // No intersection points
}

TEST(SolverTest, CheckBtw) {
    EXPECT_TRUE(solver::CheckBetween(0.5, 1, 0));
    EXPECT_TRUE(solver::CheckBetween(0.5));
    EXPECT_FALSE(solver::CheckBetween(2));
    EXPECT_FALSE(solver::CheckBetween(1.1));
    EXPECT_FALSE(solver::CheckBetween(1));
}

TEST(SolverTest, TwoIntersectionBtw) {
    solver solverInstance;

    std::complex<double> L_p1(0, 0);
    std::complex<double> L_p2(-1, -1);
    std::complex<double> Center(0, 0);
    std::complex<double> OnRadius(1, 0);
    double f1 = 0.0, f2 = 0.0;
    double t_f1 = 0.0, t_f2 = 0.0;

    // Call the function
    int intersections = solverInstance.GetIntersect(&L_p1, &L_p2, &Center, &OnRadius, &f1, &f2, &t_f1, &t_f2);

    // Assertions
    EXPECT_EQ(intersections, 2);              // Tangent to the circle, 1 intersection
    EXPECT_GE(f1, M_PI / 4);                       // Angle should be valid
    EXPECT_LE(f2, -3 * M_PI / 4);
    EXPECT_TRUE(fabs(t_f1 - (-1 / std::sqrt(2))) < 1e-5);
    EXPECT_TRUE(fabs(t_f2 - (1 / std::sqrt(2))) < 1e-5);
    EXPECT_FALSE(solver::CheckBetween(t_f1));
    EXPECT_TRUE(solver::CheckBetween(t_f2));
    //the line below is used in manipulator?
    
    // проверено, все ок
     
    //EXPECT_FALSE(solver::CheckBetween(t_f1) && solver::CheckBetween(M_PI / 4, f1, 0) || solver::CheckBetween(t_f2) && solver::CheckBetween(M_PI / 4, f1, 0));
    //EXPECT_FALSE(solver::CheckBetween(t_f1) && solver::CheckBetween(-5 * M_PI / 6, f1, 0) || solver::CheckBetween(t_f2) && solver::CheckBetween(-5 * M_PI / 6, f1, 0));

}
