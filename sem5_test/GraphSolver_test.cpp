#include "pch.h"
//
////#include "../sem5/TreeObj.h" 
#include "../sem5/GraphSolver.h"
#include "../sem5/GraphSolver.cpp"
#include "../sem5/Positionable.h"

// Базовый тест для корректного дерева
TEST(BuildPredecessorBranchTest, BasicTreeStructure) {
    // Дерево: 0 -> 1 -> 2
    std::vector<TreeObj*> tree;
    tree.push_back(new TreeObj(0, 0)); // Узел 0
    tree.push_back(new TreeObj(0, 1)); // Узел 1
    tree.push_back(new TreeObj(1, 2)); // Узел 2

    std::vector<TreeObj*> branch;
    std::vector<TreeObj*> rst;

    // Проверяем, что для Nstrt = 1 программа захватывает узлы 1 и 2
    EXPECT_EQ(GSolver::BuildPredecessorBranch(tree, 1, branch, rst), 2);

    // Проверяем содержимое branch
    ASSERT_EQ(branch.size(), 2);
    EXPECT_EQ(branch[0]->N(), 1);
    EXPECT_EQ(branch[1]->N(), 2);

    // Освобождение памяти
    for (auto obj : tree) {
        delete obj;
    }
}

// Тест дерева с одним узлом
TEST(BuildPredecessorBranchTest, SingleNodeTree) {
    // Дерево: 0
    std::vector<TreeObj*> tree;
    tree.push_back(new TreeObj(0, 0)); // Узел 0


    std::vector<TreeObj*> rst;
    std::vector<TreeObj*> branch;

    // Проверяем, что для Nstrt = 0 программа захватывает только узел 0
    EXPECT_EQ(GSolver::BuildPredecessorBranch(tree, 0, branch, rst), 1);

    // Проверяем содержимое branch
    ASSERT_EQ(branch.size(), 1);
    ASSERT_EQ(rst.size(), 0);
    EXPECT_EQ(branch[0]->N(), 0);

    // Освобождение памяти
    for (auto obj : tree) {
        delete obj;
    }
}

// Тест дерева с несколькими уровнями
TEST(BuildPredecessorBranchTest, MultiLevelTree) {
    // Дерево:
    //        0
    //       / \
    //      1   2
    //     / \
    //    3   4
    std::vector<TreeObj*> tree;
    tree.push_back(new TreeObj(0, 0)); // Узел 0
    tree.push_back(new TreeObj(0, 1)); // Узел 1
    tree.push_back(new TreeObj(0, 2)); // Узел 2
    tree.push_back(new TreeObj(1, 3)); // Узел 3
    tree.push_back(new TreeObj(1, 4)); // Узел 4

    std::vector<TreeObj*> rst;
    std::vector<TreeObj*> branch;

    // Проверяем, что для Nstrt = 1 программа захватывает узлы 1, 3, и 4
    EXPECT_EQ(GSolver::BuildPredecessorBranch(tree, 1, branch, rst), 3);

    // Проверяем содержимое branch
    ASSERT_EQ(branch.size(), 3);
    EXPECT_EQ(branch[0]->N(), 1);
    EXPECT_EQ(branch[1]->N(), 3);
    EXPECT_EQ(branch[2]->N(), 4);
    ASSERT_EQ(rst.size(), 2);



    // Освобождение памяти
    for (auto obj : tree) {
        delete obj;
    }
}

// Тест дерева, где Nstrt — корень
TEST(BuildPredecessorBranchTest, RootNodeStart) {
    // Дерево:
    //        0
    //       / \
    //      1   2
    std::vector<TreeObj*> tree;
    tree.push_back(new TreeObj(0, 0)); // Узел 0
    tree.push_back(new TreeObj(0, 1)); // Узел 1
    tree.push_back(new TreeObj(0, 2)); // Узел 2

    std::vector<TreeObj*> rst;
    std::vector<TreeObj*> branch;

    // Проверяем, что для Nstrt = 0 программа захватывает только узел 0
    EXPECT_EQ(GSolver::BuildPredecessorBranch(tree, 0, branch, rst), 3);

    // Проверяем содержимое branch
    ASSERT_EQ(branch.size(), 3);
    EXPECT_EQ(branch[0]->N(), 0);

    // Освобождение памяти
    for (auto obj : tree) {
        delete obj;
    }
}

TEST(BuildPredecessorBranchTest, RootNodeStart2) {
    // Дерево:
    // 0
    // ├── 1
    // │   ├── 3
    // │   └── 4
    // └── 2

    std::vector<TreeObj*> tree;
    tree.push_back(new TreeObj(0, 0));  // Узел 0 (корень)
    tree.push_back(new TreeObj(0, 1));  // Узел 1
    tree.push_back(new TreeObj(0, 2));  // Узел 2
    tree.push_back(new TreeObj(1, 3));  // Узел 3
    tree.push_back(new TreeObj(1, 4));  // Узел 4

    std::vector<TreeObj*> branch;
    std::vector<TreeObj*> rst;

    // Ожидаем, что все узлы включены
    EXPECT_EQ(GSolver::BuildPredecessorBranch(tree, 0, branch, rst), 5);
    EXPECT_EQ(GSolver::BuildPredecessorBranch(tree, 1, branch, rst), 3);
    EXPECT_EQ(branch.size(), 3);

}



#include "../sem5/Camera.h"
#include "../sem5/Element.h"

TEST(BuildPredecessorBranchTest, PositionablesAsLeavs) {
    // Дерево:
    //        0
    //       / \
    //      1   2
    //     / \
    //    3   4
    std::vector<Positionable*> tree;
    tree.push_back(new Element(0, 0)); // Узел 0
    tree.push_back(new Camera(0, 1)); // Узел 1
    tree.push_back(new Element(0, 2)); // Узел 2
    tree.push_back(new Element(1, 3)); // Узел 3
    tree.push_back(new Element(1, 4)); // Узел 4

    std::vector<Positionable*> branch;
    std::vector<Positionable*> rst;
    
    // Проверяем, что для Nstrt = 1 программа захватывает узлы 1, 3, и 4
    EXPECT_EQ(GSolver::BuildPredecessorBranch(tree, 1, branch, rst), 3);

    // Проверяем содержимое branch
    ASSERT_EQ(branch.size(), 3);
    EXPECT_EQ(branch[0]->N(), 1);
    EXPECT_EQ(branch[1]->N(), 3);
    EXPECT_EQ(branch[2]->N(), 4);
}