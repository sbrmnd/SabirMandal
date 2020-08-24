// DynamicPrograming.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "MinSubSetSumDiff.h"
#include "Knapsack.h"
#include "LongestCommonSubSequence.h"
#include <string>


using namespace std;

//int static t[101][101];

int main()
{
	int sizeofarray;

	cin >> sizeofarray;
	int* a = new int[sizeofarray];
	for (int i = 0; i < sizeofarray; ++i)
	{
		cin >> a[i];
	}
	//delete[] a;

	string str;
	getline(cin, str);
	cout << "Grades are : " << str << endl;

	//string x = "abcdgh";
	//string y = "abcdh";

	//string x = "AGGTAB";
	//string y = "GXTXAYB";
	string s = "agbcba";

	//LongestCommonSubSequence lcs;
	//cout << lcs.LongestPalindromicSubsequence(s) << endl;
 
	int arr[] = {3, 1, 4, 2, 2, 1};
	//int arr[] = {1,6,11,5};
	int n = sizeof(arr) / sizeof(arr[0]);
	
	MinSubSetSumDiff obj;

	cout << "The minimum difference between 2 sets is "
		<< obj.FindMin(arr, n);

	//Input for Knapsack
	/*int wt[] = { 1,3, 4,5 };
	int val[] = {1,4,5,7};

	int W = 7;*/

	////SubSetSub Input.
	//int wt[] = { 2,3, 7,8,10 };
	//int W = 10;

	int wt[] = { 2,3, 5,6,8,10 };
	int W = 10;

	Knapsack ksack;

	cout << "The maximum profit for given arr is " << ksack.SubSetSumCount(wt, W, sizeof(wt) / sizeof(wt[0]))<<endl;

	cout << "Result";


}