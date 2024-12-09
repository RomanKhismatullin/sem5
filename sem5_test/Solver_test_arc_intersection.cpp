#include "pch.h"
#include "../sem5/Solver.h"
#define M_PI 3.14159265358979323846

TEST(SolverTest, ArchIntersectionTest) {
	Point p1 (-1, 1); 
	Point p2(+1, 1);
	Point c(0, 0);
	Point r(1, 0);
	double alpha = 5* M_PI / 6;
	EXPECT_EQ(solver::CheckArchIntersection(&p1, &p2, &c, &r, alpha), 1);
}

TEST(SolverTest, ArchIntersectionTest2) {
	Point p1(-1, 1);
	Point p2(+1, 1);
	Point c(0, 0);
	Point r(1, 0);
	double alpha = - 5 * M_PI / 6;
	EXPECT_EQ(solver::CheckArchIntersection(&p1, &p2, &c, &r, alpha), 0);
}


TEST(SolverTest, ArchIntersectionTest3) {
	Point p1(-1, 0.75);
	Point p2(+1, 0.75);
	Point c(0, 0);
	Point r(1, 0);
	double alpha = 5 * M_PI / 6;
	EXPECT_EQ(solver::CheckArchIntersection(&p1, &p2, &c, &r, alpha), 1);
}
#include <complex>
TEST(SolverTest, ArchIntersectionTest4) {

	Point rr = std::polar(1.0, M_PI / 4);
	Point p1(-1, 1);
	Point p2(+1, 1);
	Point c(0, 0);
	Point r(1, 0);
	p1 *= rr;
	p2 *= rr;
	double alpha = 5 * M_PI / 6;
	EXPECT_EQ(solver::CheckArchIntersection(&p1, &p2, &c, &r, alpha), 1);
}

TEST(SolverTest, ArchIntersectionTest5) {

	Point rr = std::polar(1.0, M_PI / 4);
	Point p1(-1, 1);
	Point p2(+1, 1);
	Point c(0, 0);
	Point r(1, 0);
	p1 *= rr;
	p2 *= rr;
	double alpha = M_PI / 2;
	EXPECT_EQ(solver::CheckArchIntersection(&p1, &p2, &c, &r, alpha), 0);
}

TEST(SolverTest, ArchIntersectionTest6_1) {
	Point p1(0, 0);
	Point p2(2, 2);
	Point c(0, 0);
	Point r(1, 0);
	double alpha = 5 * M_PI / 6;
	EXPECT_EQ(solver::CheckArchIntersection(&p1, &p2, &c, &r, alpha), 1);
}

TEST(SolverTest, ArchIntersectionTest6_2) {
	Point p2(0, 0);
	Point p1(2, 2);
	Point c(0, 0);
	Point r(1, 0);
	double alpha = 5 * M_PI / 6;
	EXPECT_EQ(solver::CheckArchIntersection(&p1, &p2, &c, &r, alpha), 1);
}


TEST(SolverTest, ArchIntersectionTest7_1) {
	Point p1(0, 1);
	Point p2(0, 2);
	Point c(0, 0);
	Point r(1, 0);
	double alpha = 5 * M_PI / 6;
	EXPECT_EQ(solver::CheckArchIntersection(&p1, &p2, &c, &r, alpha), 0);
}

TEST(SolverTest, ArchIntersectionTest7_2) {
	Point p2(0, 1);
	Point p1(0, 2);
	Point c(0, 0);
	Point r(1, 0);
	double alpha = 5 * M_PI / 6;
	EXPECT_EQ(solver::CheckArchIntersection(&p1, &p2, &c, &r, alpha), 0);
}


TEST(SolverTest, ArchIntersectionTest8) {
	Point p2(10, 1);
	Point p1(10, 2);
	Point c(0, 0);
	Point r(1, 0);
	double alpha = 5 * M_PI / 6;
	EXPECT_EQ(solver::CheckArchIntersection(&p1, &p2, &c, &r, alpha), 0);
}



/*
TEST(SolverTest, ArchIntersectionTest) {
	Point p1;
	Point p2;
	Point c;
	Point r;
	double alpha;
	EXPECT_EQ(solver::CheckArchIntersection(&p1, &p2, &c, &r, alpha), )

}
*/
