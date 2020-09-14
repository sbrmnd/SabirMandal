// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include "ArraysProblems.h"
#include"StackQuestions.h"
#include "MatrixProblems.h"
#include "GraphsQuestions.h"

using namespace std;

int factorial(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return n * factorial(n - 1);
}

int maxArea(vector<int>& height) {
    int left, right;
    int max = 0;
    int high = 0;
    int wide = 0;
    int area = 0;

    // Setting the initial left and right
    left = 0;
    right = height.size() - 1;


    while (left < right) {
        // Getting the wide
        wide = right - left;

        // Getting the height
        if (height[left] <= height[right]) {
            high = height[left];
            ++left;
        }
        else {
            high = height[right];
            --right;
        }

        // Getting the area
        area = wide * high;

        // Calculating the max area
        max = (max < area ? area : max);
    }

    return max;

}


int main()
{

    ArraysProblems arrprobs;
    //vector<int> v = { 34, 8, 10, 3, 2, 80, 30, 33, 1 };
    //vector<int> v = { 1, 2 ,3 ,2 ,1, 4 };
    //arrprobs.LogestValidParenthesis("()(((()())");
    //int arr[] = { 0, -1, 2, -3, 1 };
    //int n = sizeof(arr) / sizeof(arr[0]);

     vector<int> v = { -1, 0 ,1 ,2 ,-1, -4 };
    arrprobs.threeSumEx(v);
        
    //Test the graph DFS.

    int V = 5;

    //vector<int> adj[V];

    vector<int>* adj = new vector<int>[V];

    GraphsQuestions gq;
    // Vertex numbers should be from 0 to 4. 
    gq.addEdge(adj, 0, 1);
    gq.addEdge(adj, 0, 4);
    gq.addEdge(adj, 1, 2);
    gq.addEdge(adj, 1, 3);
    gq.addEdge(adj, 1, 4);
    gq.addEdge(adj, 2, 3);
    gq.addEdge(adj, 3, 4);
    gq.dfs(adj, V);

    /*Graph g(4);
    g.AddEdges(0,1);
    g.AddEdges(0, 2);
    g.AddEdges(1, 2);
    g.AddEdges(2, 0);
    g.AddEdges(2, 3);
    g.AddEdges(3, 3);

    g.DFS();*/

   
    
    
    
    /*MatrixProblems m;
   int arr[][4] = 
    {
        {1,2,3, 4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16}
    };
    m.RotateThePicture90Degree(arr, 4);

    int val;
    cin >> val;*/
    //vector<int> v =  {13,16,2,7,3,18,19,6,15,11,17 } ;
    //vector<int> v = { 4,5,2,10,8 };
    //StackQuestions sq;
    //sq.NGL(v);




    //vector<int> v = { 2,7,11,15 };
    //vector<int> v = { 1, 8, 6, 2, 5, 4, 8, 3, 7 };

    //vector<int> v = { -1, 0, 1, 2, -1, -4 };

    //vector<int> v = { 13, 16, 2, 7, 3, 18, 19, 6, 15, 11, 17};

   // vector<int> v = { 7,4,14,11,10,13,6,17,7,20 };

   // vector<int> v = { 1,2,3,5};

    //ArraysProblems aProbs;
   // aProbs.MissingNumberInArray(v, 5);


    //std::cout << factorial(4);
}

