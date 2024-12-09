#include "GraphSolver.h"

int GraphSolver::BuildPredecessorBranch(std::vector<TreeObj*>* tr, int Nstrt, std::vector<TreeObj*>* brnch) {
    // �������� �� ���������� Nstrt
    if (Nstrt < 0 || Nstrt >= tr->size()) {
        return 0; // ���� ������ �����������, ���������� 0
    }

    // �������� � ���� Nstrt
    TreeObj* startObj = (*tr)[Nstrt];

    // ��������� Nstrt � �����
    brnch->push_back(startObj);

    // �������� �� ���� ����� � ���� ���, ������� ��������� �� Nstrt ����� NPrev()
    bool added = true;
    while (added) {
        added = false; // ���� ��� ��������, ���� �� ��������� ����� ���� � ������� �����
        for (int i = 0; i < tr->size(); ++i) {
            TreeObj* currentObj = (*tr)[i];
            // ���� NPrev �������� ������� ��������� �� ���� �� ��������� �����, ��������� ���
            for (TreeObj* node : *brnch) {
                if (currentObj->NPrev() == node->N()) {
                    brnch->push_back(currentObj);
                    added = true; // ���� �� �������� ����, ��������� ��������
                    break;
                }
            }
        }
    }

    // ���������� ���������� ��������� � �����
    return brnch->size();
}