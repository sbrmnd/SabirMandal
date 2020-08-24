#pragma once
#include <iostream>

using namespace std;

class MatrixMultiplication
{
private:
public:
	MatrixMultiplication(){}
	int LongestPalindromeSubsequence(string s, int n);
};

class AbsClass
{
public:
	virtual void met() = 0;
};

class Drive : public AbsClass
{

};

