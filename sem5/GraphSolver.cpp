#include "GraphSolver.h"

int GraphSolver::BuildPredecessorBranch(std::vector<TreeObj*>* tr, int Nstrt, std::vector<TreeObj*>* brnch) {
    // Проверка на валидность Nstrt
    if (Nstrt < 0 || Nstrt >= tr->size()) {
        return 0; // Если индекс некорректен, возвращаем 0
    }

    // Начинаем с узла Nstrt
    TreeObj* startObj = (*tr)[Nstrt];

    // Добавляем Nstrt в ветвь
    brnch->push_back(startObj);

    // Проходим по всем узлам и ищем все, которые ссылаются на Nstrt через NPrev()
    bool added = true;
    while (added) {
        added = false; // флаг для проверки, были ли добавлены новые узлы в текущем цикле
        for (int i = 0; i < tr->size(); ++i) {
            TreeObj* currentObj = (*tr)[i];
            // Если NPrev текущего объекта указывает на один из найденных узлов, добавляем его
            for (TreeObj* node : *brnch) {
                if (currentObj->NPrev() == node->N()) {
                    brnch->push_back(currentObj);
                    added = true; // Если мы добавили узел, продолжим проверку
                    break;
                }
            }
        }
    }

    // Возвращаем количество элементов в ветви
    return brnch->size();
}