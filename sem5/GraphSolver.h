#pragma once
#include "TreeObj.h"
#include <vector>

class GSolver
{
public:
    template <typename T>
    static int BuildPredecessorBranch(std::vector<T*>& tr, int Nstrt, std::vector<T*>& brnch);

};
