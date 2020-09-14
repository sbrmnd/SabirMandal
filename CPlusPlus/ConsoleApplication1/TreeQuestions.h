#pragma once

using namespace std;

//struct NodeNr
//{
//    int data;
//    Node* left;
//    Node* right;
//    Node* nextRight;  // This has garbage value in input trees
//};

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int d) {
        data = d;
        left = nullptr;
        right = nullptr;
    }
};

class TreeQuestions
{
public:
    void LevelOrderTraversal(Node* root);
    void IterativePreOrder(Node* root);
    void IterativePostOrder(Node* root);
    //void ConnectNodeNr(NodeNr* root);

};










