#include "GraphSolver.h"



//O(N) ����� 3-������� ������.
//������������
//0 <= tr[i]->NPrev() < tr[i]->N()
//���������� ���� - ������
//tr[i]->N() = i

//CHANGED FROM TreeObj to Positionable
template <typename T>
int GSolver::BuildPredecessorBranch(std::vector<T*>& tr, int Nstrt, std::vector<T*>& brnch) { 
    // �������� �� ���������� Nstrt
    if (Nstrt < 0 || Nstrt >= tr.size()) {
        return 0; // ���� ������ �����������, ���������� 0
    }


    tr[Nstrt]->COLOR = 2; //���� - ������

    for (int i = Nstrt + 1; i < tr.size(); i++) {
        tr[i]->COLOR = 0; //��������� - �����
    }

    for (int i = 0; i < Nstrt; i++) { //��� ������ - �����
        tr[i]->COLOR = 1;
    }

    for (int i = tr.size() - 1; i > Nstrt; i--) { //�������� � ����������
        int j = i; // ��� �������� ����� Nstrt
        
        do {
            if (tr[j]->COLOR > 0) {
                break;
            }
            j = tr[j]->NPrev(); // ��������� � ���� �� ������
        } while (tr[j]->COLOR == 0);


        int paint = tr[j]->COLOR;
        j = i;
        do {
            tr[j]->COLOR = paint;
            j = tr[j]->NPrev(); // ��������� � ���� �� ������
        } while (tr[j]->COLOR < 1);
    }

    // ��������� ������ �� ������ ���� � brnch
    brnch.clear(); // ��������, ��� ������ ���� (������ �� �����!!!)
    for (T* obj : tr) {
        if (obj->COLOR == 2) { // ������ ����
            brnch.push_back(obj);
        }
    }

    return brnch.size(); // ���������� ���������� ������ �����

    return brnch.size();
}



