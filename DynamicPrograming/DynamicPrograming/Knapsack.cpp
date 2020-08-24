#include "Knapsack.h"
#include<math.h>
#include<algorithm>


using namespace std;

//Recursive version.
int Knapsack::KnapsackRecursive(int wt[], int val[], int W, int n)
{
	//Base condition.

	if (n == 0 || W == 0)
		return 0;

	//Choice Diagram.

	if (wt[n - 1] <= W)
	{
		return max(val[n - 1] + KnapsackRecursive(wt, val, W - wt[n - 1], n - 1),
				KnapsackRecursive(wt, val, W, n - 1));
	}
	else if(wt[n-1]>W)
	{
		return KnapsackRecursive(wt, val, W, n - 1);
	}

	return 0;
}

//Memoization
int Knapsack::KnapsackMemoization(int wt[], int val[], int W, int n)
{
	//Base Condition

	if (n == 0 || W == 0)
		return 0;

	//Check the value present in the table.
	if(t[n][W]!= -1)
		return t[n][W];
	if (wt[n - 1] <= W)
	{
		//Inclueded
		return t[n][W] = max(val[n-1]+ KnapsackMemoization(wt, val, W-wt[n-1], n-1), KnapsackMemoization(wt, val, W,n-1));
	}
	else
	{
		//Excluded.
		return t[n][W] = KnapsackMemoization(wt, val, W, n - 1);
	}
}

int Knapsack::KnapsackTopDown(int wt[], int val[], int W, int n)
{
	int result = 0;
	//Base condition
	if (n == 0 || W == 0)
		return 0;

	//Create table.
	int ** dp = new int*[n + 1];
	for (int row = 0; row < n + 1; row++)
	{
		dp[row] = new int[W+1];
	}

	//Initialization of Matrix dp, first row and 1 col
	for (int i = 0; i < n + 1; i++)
	{
		for (int j = 0; j < W + 1; j++)
		{
			if (i == 0 || j == 0)
				dp[i][j] = 0;
		}
	}

	//Fill the rest of the table staring from row 2 and col 2, since we have already
	// intialize the first row and col.
	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < W+1; j++)
		{
			if (wt[i - 1] <= j)
			{
				dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);
			}
			else
			{
				dp[i][j] = dp[i - 1][j];
			}
		}
	}
	result = dp[n][W];

	//Deallocate the dp matrix
	for (int row = 0; row < n + 1; row++)
	{
		delete[] dp[row];
	}
	delete[] dp;

	return result;
}

int Knapsack::SubSetSum(int wt[], int sum, int n)
{
	bool result;
	if (n == 0 || sum == 0)
		return 0;

	//Create the dp table
	int ** dp = new int*[n + 1];
	for (int row = 0; row < n + 1; row++)
	{
		dp[row] = new int[sum + 1];
	}

	//Initialization , true and false
	for (int i = 0; i < n+1; i++)
	{
		for (int j = 0; j < sum + 1; j++)
		{
			if (i == 0)
				dp[i][j] = false;
			if (j == 0)
				dp[i][j] = true;
		}
	}

	//Fill the rest of the table; with values. And since the we have already initialize the matrix for row 0, col 0
	//Hence we start here with row 1 col 1.

	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < sum + 1; j++)
		{
			if (wt[i - 1] <= j)
			{
				dp[i][j] = dp[i - 1][j - wt[i - 1]] || dp[i - 1][j];
			}
			else
			{
				dp[i][j] = dp[i - 1][j];
			}
		}
	}

	result = dp[n][sum];

	//Deallocate the dp table.
	for (int row = 0; row < n + 1; row++)
	{
		delete[] dp[row];
	}

	delete[] dp;
	
	return result;
}

int Knapsack::SubSetSumCount(int wt[], int sum, int n)
{
	int result;
	if (n == 0 || sum == 0)
		return 0;

	//Create the dp table
	int ** dp = new int*[n + 1];
	for (int row = 0; row < n + 1; row++)
	{
		dp[row] = new int[sum + 1];
	}

	//Initialization , 0 and 1
	for (int i = 0; i < n + 1; i++)
	{
		for (int j = 0; j < sum + 1; j++)
		{
			if (i == 0)
				dp[i][j] = 0;
			if (j == 0)
				dp[i][j] = 1;
		}
	}

	//Fill the rest of the table; with values. And since the we have already initialize the matrix for row 0, col 0
	//Hence we start here with row 1 col 1.

	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < sum + 1; j++)
		{
			if (wt[i - 1] <= j)
			{
				dp[i][j] = dp[i - 1][j - wt[i - 1]] + dp[i - 1][j];
			}
			else
			{
				dp[i][j] = dp[i - 1][j];
			}
		}
	}

	result = dp[n][sum];

	//Deallocate the dp table.
	for (int row = 0; row < n + 1; row++)
	{
		delete[] dp[row];
	}

	delete[] dp;

	return result;
}

//int Knapsack::max(int val1, int val2)
//{
//	return val1>val2?val1:val2;
//}
