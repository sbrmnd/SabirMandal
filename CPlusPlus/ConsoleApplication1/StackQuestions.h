#pragma once
#include <vector>
#include <stack>

using namespace std;
class StackQuestions
{
private:
	//NearestSmallCondition
	void NSC(vector<int>& result, stack<pair<int, int>>& stack, vector<int>& vec, int i);
public:
	vector<int> NGR(vector<int>& vec);
	vector<int> NGL(vector<int>& vec);

	vector<int> NSR(vector<int>& vec);
	vector<int> NSL(vector<int>& vec);

	vector<int> NSLWithIndex(vector<int>& vec);
	vector<int> NSRWithIndex(vector<int>& vec);

	int MaxAreaHistogram(vector<int>& vec);

	
};

