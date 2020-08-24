#pragma once
#include <iostream>

using namespace std;

class LongestCommonSubSequence
{
private:
	int t[101][101];
public:
	LongestCommonSubSequence() {
		memset(t, -1, sizeof(t));
	}
	int LCSRecursive(string x, string y, int n, int m);
	int LcsMemoization(string x, string y, int n, int m);
	int LcsTopDown(string x, string y, int n, int m);
	int LongestCommonSubString(string x, string y, int n, int m);

	//Palindrome
	int LongestPalindromicSubsequence(string s);
};

