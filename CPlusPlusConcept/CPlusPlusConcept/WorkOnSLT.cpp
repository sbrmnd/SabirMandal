#include "WorkOnSLT.h"
#include <vector>
#include<set>
#include<map>
#include <unordered_map>
#include<algorithm>

using namespace std;

void WorkOnSLT::TestVector()
{
	vector<int> vtest{ 1,4,2,5,9,5,4 };

	//Get the second element.
	int vtro = vtest[2];

	sort(vtest.begin(), vtest.end()); //O(NLogN)

	//O(logN)

	bool psent = binary_search(vtest.begin(), vtest.end(), 4);
	bool notPrest =  binary_search(vtest.begin(), vtest.end(), 4);

	vtest.push_back(23);
	vtest.push_back(23);
	vtest.push_back(100);
	vtest.push_back(123);

	//Find number of time 9 comes in the vector.
	int c = count(vtest.begin(), vtest.end(), 9);

	//If vector is sorted then we can do the upper_bound and lower_bound
	//Uppper> than the number--> lower_bound equal to or greater--First occurence of the number

	vector<int>::iterator it2 = lower_bound(vtest.begin(), vtest.end(), 23);

	vector<int>::iterator it = upper_bound(vtest.begin(), vtest.end(),100);


	//sort in reverse order.
	reverse(vtest.begin(), vtest.end());
	//sort(vtest.begin(), vtest.end(), func);//not working.

	vector<int>::iterator iterator = vtest.begin();

	for (iterator ; iterator< vtest.end(); iterator++)
	{
		cout << *iterator << endl;
	}

	//Syntical sugar.

	auto it3 = lower_bound(vtest.begin(), vtest.end(), 23);

	//iterating 
	for (int x : vtest)
	{
		cout << x;
	}
	

}
void WorkOnSLT::TestSets()
{
	//Insert elements in assending order. Where as vector you need to sort.
	//In Set Complete collection is sorted.

	//Insert in O(Log(N))
	//Erase in O(Log(N))

	set<int> lSet;
	lSet.insert(10);
	lSet.insert(5);
	lSet.insert(9);
	lSet.insert(9);
	lSet.insert(1);

	for (int x : lSet)
		cout << x << endl;

	//Find element in set. If element is not found then it will
	//return lset.end

	auto iter = lSet.find(3);
	if (iter == lSet.end())
	{
		cout << "Not present" << endl;
	}
	else
	{
		cout << "Present." << endl;
	}

	//Since set is sorted, hence it has upper_bound and lower_bound method in the set.
	//Next greatest element. Log(N) times.
	auto it1 = lSet.upper_bound(9);
	
}
void WorkOnSLT::TestMaps()
{

	//Log(N) times.
	map<int, int> mapL;
	mapL.insert(1, 20);
	mapL.insert(2, 40);
	mapL.insert(3, 60);

	//or
	mapL[4] = 70;
	mapL[5] = 80;
}

void WorkOnSLT::TestUnOrderedMap()
{
}

