#pragma once
#include <iostream>
class Knapsack
{
public:
	
	Knapsack() {
		memset(t, -1, sizeof(t));
	}
	int t[101][101];

	int KnapsackRecursive(int wt[], int val[], int W, int n );
	int KnapsackMemoization(int wt[], int val[], int W, int n);
	int KnapsackTopDown(int wt[], int val[], int W, int n);

	int SubSetSum(int wt[], int sum, int n);
	int SubSetSumCount(int wt[], int sum, int n);

private:
	//t[n+1][W+1]
	//int static t[101][101];
	
	/*int max(int val1, int val2);*/

};

