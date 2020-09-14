#include "MatrixProblems.h"
#include <iostream>

void MatrixProblems::PrintTheMatixInSprialform(int arr[3][3], int n, int m)
{
	int top = 0;
	int down = n-1;
	int left = 0;
	int right = m-1;

	int dir = 0;
	while (top<=down && left<=right)
	{
		if (dir == 0)
		{
			for (int i = left; i <= right; i++)
			{
				cout << arr[left][i];
			}
			top += 1;
		}
		else if (dir == 1)
		{
			for (int i = top; i <= down; i++)
			{
				cout << arr[i][right];
			}
			right -= 1;
		}
		else if (dir == 2)
		{
			for (int i = right; i >= left; i--)
			{
				cout << arr[down][i];
			}
			down -= 1;
		}
		else if (dir == 3)
		{
			for (int i = down; i >= top; i--)
			{
				cout << arr[i][left];
			}
			left += 1;
		}
		dir = (dir + 1) % 4;
	}
}

void MatrixProblems::RotatePic90WithExSpace(int arr[4][4], int size)
{
	int newMatrix[4][4];

	for (int i = 0; i <= size-1; i++)
	{
		for (int j = 0; j <= size-1; j++)
		{
			newMatrix[j][size-1-i] = arr[i][j];
		}
	}

	for (int i = 0; i <= size - 1; i++)
	{
		for (int j = 0; j <= size - 1; j++)
		{
			cout << newMatrix[i][j] << " ";
		}
		cout << endl;
	}
}

void MatrixProblems::RotateThePicture90Degree(int arr[4][4], int size)
{
	//Transpose Matrix
	for (int i = 0; i < size; i++)
	{
		for (int j = i; j < size; j++)
		{
			int temp = arr[i][j];
			arr[i][j] = arr[j][i];
			arr[j][i] = temp;

		}

	}

	//Flip Horizontally.
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < (size / 2); j++)
		{
			int temp = arr[i][j];
			arr[i][j] = arr[i][size-1-j];
			arr[i][size - 1 - j] = temp;

		}
	}

	//Print result
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size ; j++)
		{
			cout<<arr[i][j]<<" ";
		}
		cout << endl;
	}
}
