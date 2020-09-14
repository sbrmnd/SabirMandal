#include "TreeQuestions.h"
#include <queue>
#include <stack>

void TreeQuestions::LevelOrderTraversal(Node* root)
{
	queue<Node*> queue;

	if (root == nullptr)
		return;

	queue.push(root);

	while (queue.size() > 0)
	{
		Node* temp = queue.front();

		if (temp->left)
		{
			queue.push(temp->left);
		}
		if (temp->right)
		{
			queue.push(temp->right);
		}
		queue.pop();
	}
}

void TreeQuestions::IterativePreOrder(Node* root)
{
	stack<Node*> stack;
	
	do
	{
		while (root != nullptr)
		{

		}

	} while (!stack.empty());
	
}

void TreeQuestions::IterativePostOrder(Node* root)
{
    stack<Node*> s1;
    stack<Node*> s2;
    vector<int> nums;

    s1.push(root);

    while (s1.empty())
    {
		Node* curr = s1.top();
        s1.pop();

        s2.push(curr);

        if (curr->left)
        {
            s1.push(curr->left);
        }
        if (curr->right)
        {
            s1.push(curr->right);
        }
    }
    while (!s2.empty())
    {
        nums.push_back(s2.top()->data);
        //.pop();
    }

    //return nums;
}


//void TreeQuestions::ConnectNodeNr(NodeNr* p)
//{
//	
//}



