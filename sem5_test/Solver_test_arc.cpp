#include "pch.h"
#include "../sem5/Solver.h"

#define M_PI 3.14159265358979323846

TEST(SolverTestArc, TEST1) {
	EXPECT_TRUE(solver::CheckArcAng(0, 1, 0.5));
	EXPECT_TRUE(solver::CheckArcAng(0, 1, 2*M_PI+0.5));
	EXPECT_FALSE(solver::CheckArcAng(0, 1, -0.5));
	EXPECT_FALSE(solver::CheckArcAng(0, 1, -0.5+2*M_PI));
}

TEST(SolverTestArc, TEST2) {
	EXPECT_TRUE(solver::CheckArcAng(1, -1, M_PI));
	EXPECT_FALSE(solver::CheckArcAng(-1, 1, M_PI));
	EXPECT_TRUE(solver::CheckArcAng(0, 1, 2 * M_PI));
	EXPECT_FALSE(solver::CheckArcAng(0, 1, -0.5));
	EXPECT_FALSE(solver::CheckArcAng(0, 1, -0.5 + 2 * M_PI));
}

TEST(SolverTestArc, TEST3) {
	EXPECT_TRUE(solver::CheckArcAng(1 + 2*M_PI, -1 - 100*M_PI, M_PI));
	EXPECT_FALSE(solver::CheckArcAng(-1, 1, M_PI));
	EXPECT_TRUE(solver::CheckArcAng(0, 1, 2 * M_PI));
	EXPECT_FALSE(solver::CheckArcAng(0, 1 - 13 * M_PI, -0.5));
	EXPECT_FALSE(solver::CheckArcAng(0, 1, -0.5 + 2 * M_PI));
}



TEST(SolverTestArc, TEST4) {
	EXPECT_TRUE(solver::CheckArc(0, 1, 0.5));
	EXPECT_FALSE(solver::CheckArc(0, 1, -0.5));
	EXPECT_FALSE(solver::CheckArc(0+2*M_PI, 1, -0.5));
}

// �������� ����� ��� CheckArc
class CheckArcTest : public ::testing::Test {
protected:
    // ����������� ��� �������� ��������
    const double EPSILON = 1e-9;

    // ��������������� ������� ��� ��������� ��������
    void TestArc(double start, double arcLength, double teta, int expected) {
        EXPECT_EQ(solver::CheckArc(start, arcLength, teta), expected)
            << "Failed for start=" << start << ", arcLength=" << arcLength
            << ", teta=" << teta;
    }
};

// ����� �� ���� �� ������� �������
TEST_F(CheckArcTest, ClockwiseArc) {
    TestArc(1.0, 2.0, 1.5, 1); // ���� ������ ����
    TestArc(1.0, 2.0, 3.0, 1); // ����� ����
    TestArc(1.0, 2.0, 0.5, 0); // ���� ��� ����
    TestArc(1.0, 6.5, 0.5, 1); // ���� ���������� 0
}

// ����� �� ���� ������ ������� �������
TEST_F(CheckArcTest, CounterClockwiseArc) {
    TestArc(5.0, -2.0, 4.0, 1); // ���� ������ ����
    TestArc(5.0, -2.0, 3.0, 1); // ����� ����
    TestArc(5.0, -2.0, 6.0, 0); // ���� ��� ����
    TestArc(5.0, -6.5, 0.5, 1); // ���� ���������� 0
}

// ����� �� ������� ���� (������ 360�)
TEST_F(CheckArcTest, LongArc) {
    TestArc(1.0, 8.0, 3.0, 1);  // ���� ������ ���� (�� �����)
    TestArc(1.0, 8.0, 0.5, 1);  // ���� ������ ���� ����� 0
    TestArc(1.0, -8.0, 0.5, 1); // ���� ������ ���� (������ ������� �������)
    TestArc(1.0, -8.0, 2.0, 1); // ���� ��� ����
}

// ����� �� ����������� ������
TEST_F(CheckArcTest, BoundaryCases) {
    TestArc(0.0, 2.0, 0.0, 1); // ������ ����
    TestArc(0.0, 2.0, 2.0, 1); // ����� ����
    TestArc(0.0, 2.0, 2.1, 0); // �� ��������� ����
    TestArc(0.0, -2.0, 6.28 - 2.0, 0); // ����� ������ ������� �������
}