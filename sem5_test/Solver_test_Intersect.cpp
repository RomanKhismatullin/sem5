#include "pch.h"
#include "../sem5/Solver.h"


TEST(SolverTest, CheckSegmentIntersectionTest1) {
	Point p1(0, 0);
	Point p2(0, 1);
	Point g1(0, 0);
	Point g2(0, 2);
	EXPECT_EQ(solver::CheckSegmentIntersection(&p1, &p2, &g1, &g2), 1);
}

TEST(SolverTest, CheckSegmentIntersectionTest1_2) {
	Point p1(0, 0);
	Point p2(0, 1);
	Point g1(0, 1);
	Point g2(0, 2);
	EXPECT_EQ(solver::CheckSegmentIntersection(&p1, &p2, &g1, &g2), 0);
}
TEST(SolverTest, CheckSegmentIntersectionTest1_3) {
	Point p1(0, 0);
	Point p2(0, 1);
	Point g1(0, 1);
	Point g2(1, 2);
	EXPECT_EQ(solver::CheckSegmentIntersection(&p1, &p2, &g1, &g2), 0);
}
TEST(SolverTest, CheckSegmentIntersectionTest2) {
	Point p1(0, 0);
	Point p2(0, 1);
	Point g1(2, 0);
	Point g2(2, 2);
	EXPECT_EQ(solver::CheckSegmentIntersection(&p1, &p2, &g1, &g2), 0);
}

int RUN(int N, double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4, int rs) {
	Point p1(x1, y1);
	Point p2(x2, y2);
	Point g1(x3, y3);
	Point g2(x4, y4);
	return solver::CheckSegmentIntersection(&p1, &p2, &g1, &g2) == rs;
}

TEST(SolerTestSegments, Test1) {
	EXPECT_TRUE(RUN(1, 0, 0, 0, 1, 0, 0, 0, 2, 1));
	EXPECT_TRUE(RUN(2, 0, 0, 0, 1, 2, 0, 2, 2, 0));
	EXPECT_TRUE(RUN(3, 0, 0, 0, 1, 0, 1, 0, 2, 0));
	EXPECT_TRUE(RUN(4, 0, 0, 0, 1, 0, 0, 0, 2, 1));
	EXPECT_TRUE(RUN(5, 0, 0, 0, 1, 0.5, 0, 0, 2, 0));
	EXPECT_TRUE(RUN(6, 0, 0, 2, 0, 1, -1, 1, 1, 1));
	EXPECT_TRUE(RUN(7, 0, 0, 2, 0, 0, 0, 2, 0, 1));
	EXPECT_TRUE(RUN(8, 0, 0, 2, 0, 0, 1, 2.1, 0, 0));
}




