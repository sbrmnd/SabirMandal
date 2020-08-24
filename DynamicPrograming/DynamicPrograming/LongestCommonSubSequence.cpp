#include "LongestCommonSubSequence.h"
#include <algorithm>

int LongestCommonSubSequence::LCSRecursive(string x, string y, int n, int m)
{
	//Base condition
	if (n == 0 || m == 0)
	{
		return 0;
	}

	//If last element of x and y are equal then add 1.
	if (x[n - 1] == y[m - 1])
	{
		return 1 + LCSRecursive(x, y, n - 1, m - 1);
	}
	else
	{
		//Choice available max.
		return max(LCSRecursive(x, y, n - 1, m), (x, y, n, m - 1));
	}
	
}

int LongestCommonSubSequence::LcsMemoization(string x, string y, int n, int m)
{
	//base condition

	if (n == 0 || m == 0)
	{
		return 0;
	}
	//Check if value already processed and saved into the table.

	if (t[n][m] != -1)
	{
		return t[n][m];
	}

	//Choice diagram
	if (x[n - 1] == y[m - 1])
	{
		//n-1 --> n- Going from back to start. 
		//m-1 --> n
		return t[n][m] = 1 + LcsMemoization(x, y, n - 1, m - 1);
	}
	else
	{
		//Both are not matches. max Choice from two options. n-1 to n: m or m-1 to m : n
		return t[n][m] = max(LcsMemoization(x, y, n-1,m),LcsMemoization(x, y, n, m-1));

	}
	
}

int LongestCommonSubSequence::LcsTopDown(string x, string y, int n, int m)
{
	int result;
	//Base condition.
	if (n == 0 || m == 0)
		return 0;

	//Create table.
	int ** dp = new int*[n + 1];
	for (int row = 0; row < n + 1; row++)
	{
		dp[row] = new int[m + 1];
	}

	//Initialization of Matrix dp, first row and 1 col
	for (int i = 0; i < n + 1; i++)
	{
		for (int j = 0; j < m + 1; j++)
		{
			if (i == 0 || j == 0)
				dp[i][j] = 0;
		}
	}

	//Fill the rest of the matrix. Since, we have already filled the first row and the col. Hence start it with row:col 1.
	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < m + 1; j++)
		{
			if (x[i - 1] == y[j - 1])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else
			{
				//Max x full sting m-1 y string , y full string n-1 x string.
				dp[i][j] = max(dp[i - 1][j], dp[i][j-1]);
			}
		}
	}

	result = dp[n][m];

	//Deallocation of memory for dp table.
	for (int row = 0; row < n + 1; row++)
	{
		delete[] dp[row];
	}
	delete[] dp;

	return result;
}

int LongestCommonSubSequence::LongestCommonSubString(string x, string y, int n, int m)
{
	//To store length of the longest common substring 
	int result=0;
	//Base condition.
	if (n == 0 || m == 0)
		return 0;

	//Create table.
	int ** dp = new int*[n + 1];
	for (int row = 0; row < n + 1; row++)
	{
		dp[row] = new int[m + 1];
	}

	//Initialization of Matrix dp, first row and 1 col
	for (int i = 0; i < n + 1; i++)
	{
		for (int j = 0; j < m + 1; j++)
		{
			if (i == 0 || j == 0)
				dp[i][j] = 0;
		}
	}

	//Fill the rest of the matrix. Since, we have already filled the first row and the col. Hence start it with row:col 1.
	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < m + 1; j++)
		{
			//if match increase the length and continue else make the length zero and start again.
			if (x[i - 1] == y[j - 1])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;

				result = max(result, dp[i][j]);

				//dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
			}
			else
			{
				dp[i][j] = 0;
			}
		}
	}

	//result = dp[n][m];

	//Deallocation of memory for dp table.
	for (int row = 0; row < n + 1; row++)
	{
		delete[] dp[row];
	}
	delete[] dp;

	return result;
}

int LongestCommonSubSequence::LongestPalindromicSubsequence(string s)
{
	
	string rev_s = s;

	reverse(rev_s.begin(), rev_s.end());

	return LcsTopDown(s, rev_s, s.length(), s.length());
}

