#include "pch.h"

//#include "../sem5/TreeObj.h" 
#include "../sem5/GraphSolver.h"
#include "../sem5/GraphSolver.cpp"

// ���� �� ������, ����� ������ Nstrt ��������� (��������, ������������� �������� ��� ������, ��� ������ �������)
TEST(BuildPredecessorBranchTest, InvalidStartIndex) {
    std::vector<TreeObj*> tree;
    tree.push_back(new TreeObj(0, 1));  // ���� 1
    tree.push_back(new TreeObj(1, 2));  // ���� 2
    tree.push_back(new TreeObj(2, 3));  // ���� 3

    std::vector<TreeObj*> branch;

    // �������� ��� ����������� ������� (������ -1)
    EXPECT_EQ(GraphSolver::BuildPredecessorBranch(&tree, -1, &branch), 0);

    // �������� ��� �������, ������� ������ ��� ����� ������� �������
    EXPECT_EQ(GraphSolver::BuildPredecessorBranch(&tree, 5, &branch), 0);
}

// ���� �� ������, ����� ���� ����������, � ������� ������� ���� �������
TEST(BuildPredecessorBranchTest, ValidStartIndex) {
    std::vector<TreeObj*> tree;
    tree.push_back(new TreeObj(0, 1));  // ���� 1
    tree.push_back(new TreeObj(1, 2));  // ���� 2
    tree.push_back(new TreeObj(2, 3));  // ���� 3
    tree.push_back(new TreeObj(1, 4));  // ���� 4
    tree.push_back(new TreeObj(4, 5));  // ���� 5
    tree.push_back(new TreeObj(4, 6));  // ���� 6

    std::vector<TreeObj*> branch;

    // ��������� ��� ���� 4 (�������� �������� ������, ��� ��������� ����)
    EXPECT_EQ(GraphSolver::BuildPredecessorBranch(&tree, 4, &branch), 3);

    // ���������, ��� � ������� branch ����� ������ ���� 4, 5, � 6
    EXPECT_EQ(branch[0]->N(), 4);
    EXPECT_EQ(branch[1]->N(), 5);
    EXPECT_EQ(branch[2]->N(), 6);
}

// ���� �� ������, ����� ������ �� ����� �������
TEST(BuildPredecessorBranchTest, NoPredecessors) {
    std::vector<TreeObj*> tree;
    tree.push_back(new TreeObj(0, 1));  // ���� 1
    tree.push_back(new TreeObj(0, 2));  // ���� 2

    std::vector<TreeObj*> branch;

    // ��������� ��� ���� 2, ������� �� ����� �������
    EXPECT_EQ(GraphSolver::BuildPredecessorBranch(&tree, 1, &branch), 1);

    // ���������, ��� � ����� ����� ������ ���� 2
    EXPECT_EQ(branch[0]->N(), 2);
}

// ���� �� ������, ����� ����� ��������� �� ���������� �������
TEST(BuildPredecessorBranchTest, MultiplePredecessors) {
    std::vector<TreeObj*> tree;
    tree.push_back(new TreeObj(0, 1));  // ���� 1
    tree.push_back(new TreeObj(0, 2));  // ���� 2
    tree.push_back(new TreeObj(1, 3));  // ���� 3
    tree.push_back(new TreeObj(1, 4));  // ���� 4
    tree.push_back(new TreeObj(3, 5));  // ���� 5

    std::vector<TreeObj*> branch;

    // ��������� ��� ���� 4
    EXPECT_EQ(GraphSolver::BuildPredecessorBranch(&tree, 4, &branch), 3);

    // ���������, ��� � ����� ����� ���� 4, 1 � 3
    EXPECT_EQ(branch[0]->N(), 4);
    EXPECT_EQ(branch[1]->N(), 1);
    EXPECT_EQ(branch[2]->N(), 3);
}
