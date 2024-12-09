#include "TreeObj.h"
#include <vector>

class GraphSolver
{
public:
	static int BuildPredecessorBranch(std::vector<TreeObj*>* tr, int Nstrt, std::vector<TreeObj*>* brnch);
};
