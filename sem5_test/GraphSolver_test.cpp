#include "pch.h"

//#include "../sem5/TreeObj.h" 
#include "../sem5/GraphSolver.h"
#include "../sem5/GraphSolver.cpp"

// Тест на случай, когда индекс Nstrt невалиден (например, отрицательное значение или больше, чем размер массива)
TEST(BuildPredecessorBranchTest, InvalidStartIndex) {
    std::vector<TreeObj*> tree;
    tree.push_back(new TreeObj(0, 1));  // Узел 1
    tree.push_back(new TreeObj(1, 2));  // Узел 2
    tree.push_back(new TreeObj(2, 3));  // Узел 3

    std::vector<TreeObj*> branch;

    // Проверка для невалидного индекса (индекс -1)
    EXPECT_EQ(GraphSolver::BuildPredecessorBranch(&tree, -1, &branch), 0);

    // Проверка для индекса, который больше или равен размеру вектора
    EXPECT_EQ(GraphSolver::BuildPredecessorBranch(&tree, 5, &branch), 0);
}

// Тест на случай, когда узел существует, и функция находит всех предков
TEST(BuildPredecessorBranchTest, ValidStartIndex) {
    std::vector<TreeObj*> tree;
    tree.push_back(new TreeObj(0, 1));  // Узел 1
    tree.push_back(new TreeObj(1, 2));  // Узел 2
    tree.push_back(new TreeObj(2, 3));  // Узел 3
    tree.push_back(new TreeObj(1, 4));  // Узел 4
    tree.push_back(new TreeObj(4, 5));  // Узел 5
    tree.push_back(new TreeObj(4, 6));  // Узел 6

    std::vector<TreeObj*> branch;

    // Запускаем для узла 4 (согласно описанию задачи, это начальный узел)
    EXPECT_EQ(GraphSolver::BuildPredecessorBranch(&tree, 4, &branch), 3);

    // Проверяем, что в векторе branch будут только узлы 4, 5, и 6
    EXPECT_EQ(branch[0]->N(), 4);
    EXPECT_EQ(branch[1]->N(), 5);
    EXPECT_EQ(branch[2]->N(), 6);
}

// Тест на случай, когда дерево не имеет предков
TEST(BuildPredecessorBranchTest, NoPredecessors) {
    std::vector<TreeObj*> tree;
    tree.push_back(new TreeObj(0, 1));  // Узел 1
    tree.push_back(new TreeObj(0, 2));  // Узел 2

    std::vector<TreeObj*> branch;

    // Запускаем для узла 2, который не имеет предков
    EXPECT_EQ(GraphSolver::BuildPredecessorBranch(&tree, 1, &branch), 1);

    // Проверяем, что в ветви будет только узел 2
    EXPECT_EQ(branch[0]->N(), 2);
}

// Тест на случай, когда ветвь построена из нескольких предков
TEST(BuildPredecessorBranchTest, MultiplePredecessors) {
    std::vector<TreeObj*> tree;
    tree.push_back(new TreeObj(0, 1));  // Узел 1
    tree.push_back(new TreeObj(0, 2));  // Узел 2
    tree.push_back(new TreeObj(1, 3));  // Узел 3
    tree.push_back(new TreeObj(1, 4));  // Узел 4
    tree.push_back(new TreeObj(3, 5));  // Узел 5

    std::vector<TreeObj*> branch;

    // Запускаем для узла 4
    EXPECT_EQ(GraphSolver::BuildPredecessorBranch(&tree, 4, &branch), 3);

    // Проверяем, что в ветви будут узлы 4, 1 и 3
    EXPECT_EQ(branch[0]->N(), 4);
    EXPECT_EQ(branch[1]->N(), 1);
    EXPECT_EQ(branch[2]->N(), 3);
}
