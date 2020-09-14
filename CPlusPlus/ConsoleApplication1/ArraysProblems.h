#pragma once
#include <vector>
#include <string>
using namespace std;
class ArraysProblems
{
public:
	int maxArea(vector<int>& height);
	vector<int> twoSum(vector<int>& nums, int target);
	vector<vector<int>> threeSum(vector<int>& nums);
	//Solution i understand.
	vector<vector<int>> threeSumEx(vector<int>& nums);

	bool findTripletsZero(int arr[], int n);
	int tripleSum(vector<int>& nums);
	int maxSubarraySum(vector<int> nums);
	int MissingNumberInArray(vector<int> nums, int n);
	int maxIndexDiff(vector<int> nums, int n); 
	vector<int> singleNumber(vector<int>& nums);


	//String Question.
	int LogestValidParenthesis(string str);
};

