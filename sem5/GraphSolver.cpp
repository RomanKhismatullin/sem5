#include "GraphSolver.h"



//O(N) линия 3-цветное дерево.
//КОРРЕКТНОСТЬ
//0 <= tr[i]->NPrev() < tr[i]->N()
//записанный граф - дерево
//tr[i]->N() = i

//CHANGED FROM TreeObj to Positionable
template <typename T>
int GSolver::BuildPredecessorBranch(std::vector<T*>& tr, int Nstrt, std::vector<T*>& brnch) { 
    // Проверка на валидность Nstrt
    if (Nstrt < 0 || Nstrt >= tr.size()) {
        return 0; // Если индекс некорректен, возвращаем 0
    }


    tr[Nstrt]->COLOR = 2; //дети - черные

    for (int i = Nstrt + 1; i < tr.size(); i++) {
        tr[i]->COLOR = 0; //непонятно - белые
    }

    for (int i = 0; i < Nstrt; i++) { //все плохие - серые
        tr[i]->COLOR = 1;
    }

    for (int i = tr.size() - 1; i > Nstrt; i--) { //начинаем с последнего
        int j = i; // оно гарантом боьше Nstrt
        
        do {
            if (tr[j]->COLOR > 0) {
                break;
            }
            j = tr[j]->NPrev(); // Двигаемся в лево по списку
        } while (tr[j]->COLOR == 0);


        int paint = tr[j]->COLOR;
        j = i;
        do {
            tr[j]->COLOR = paint;
            j = tr[j]->NPrev(); // Двигаемся в лево по списку
        } while (tr[j]->COLOR < 1);
    }

    // Добавляем ссылки на черные узлы в brnch
    brnch.clear(); // Убедимся, что вектор пуст (ПАМЯТб НЕ ТЕЧЕТ!!!)
    for (T* obj : tr) {
        if (obj->COLOR == 2) { // Черные узлы
            brnch.push_back(obj);
        }
    }

    return brnch.size(); // Возвращаем количество черных узлов

    return brnch.size();
}



