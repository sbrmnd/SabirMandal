#include "StackQuestions.h"
#include <algorithm>


vector<int> StackQuestions::NGR(vector<int>& vec)
{
    stack<int> stack;
    vector<int> result;

    //fill the the stack reserve
    for (int i = vec.size() - 1; i > 0; i--)
    {
        if (stack.size() == 0)
        {
            result.push_back(-1);
        }
        else if (stack.size() > 0 && stack.top() > vec[i])
        {
            result.push_back(stack.top());
        }
        else if(stack.size() >0 && stack.top() < vec[i])
        {
            //Pop till we get the greater element.
            while (stack.size() > 0 && stack.top() < vec[i])
            {
                stack.pop();
            }

            //Need to see why while loop got terminate. Two senarios it could terminate.
            //If size =0 or top gets the largest element.
            if (stack.size() == 0)
            {
                result.push_back(-1);
            }
            else
            {
                result.push_back(stack.top());
            }

        }
        stack.push(vec[i]);
    }

    reverse(result.begin(), result.end());
    return result;
}

vector<int> StackQuestions::NGL(vector<int>& vec)
{
    stack<int> stack;
    vector<int> result;

    //fill the the stack reserve
    for(int i = 0; i < vec.size(); i++)
    {
        if (stack.size() == 0)
        {
            result.push_back(-1);
        }
        else if (stack.size() > 0 && stack.top() > vec[i])
        {
            result.push_back(stack.top());
        }
        else if (stack.size() > 0 && stack.top() < vec[i])
        {
            //Pop till we get the greater element.
            while (stack.size() > 0 && stack.top() < vec[i])
            {
                stack.pop();
            }

            //Need to see why while loop got terminate. Two senarios it could terminate.
            //If size =0 or top gets the largest element.
            if (stack.size() == 0)
            {
                result.push_back(-1);
            }
            else
            {
                result.push_back(stack.top());
            }

        }
        stack.push(vec[i]);
    }

    return result;
}

vector<int> StackQuestions::NSR(vector<int>& vec)
{
    vector<int> result;
    stack<int> stack;

    for (int i= vec.size()-1; i > 0; i--)
    {
        if (stack.size() == 0)
        {
            result.push_back(-1);
        }
        else if (stack.size() > 0 && stack.top() < vec[i])
        {
            result.push_back(stack.top());
        }
        else if (stack.size() > 0 && stack.top() > vec[i])
        {
            //Pop the element till we not get the nearest smallest
            while (stack.size() > 0 && stack.top() > vec[i])
            {
                stack.pop();
            }
            //Two senarios while loop could terminate.
            //stack empty
            //top gives the nearest smallest.
            if (stack.size() == 0)
            {
                result.push_back(-1);
            }
            else
            {
                result.push_back(stack.top());
            }

        }
        stack.push(vec[i]);
    }
    reverse(result.begin(), result.end());

    return result;
}
vector<int> StackQuestions::NSL(vector<int>& vec)
{
    vector<int> result;
    stack<int> stack;

    for (int i = 0; i < vec.size(); i++)
    {
        if (stack.size() == 0)
        {
            result.push_back(-1);
        }
        else if (stack.size() > 0 && stack.top() < vec[i])
        {
            result.push_back(stack.top());
        }
        else if(stack.size() > 0 && stack.top() > vec[i])
        {
            //Pop the element till we not get the nearest smallest
            while (stack.size() > 0 && stack.top() > vec[i])
            {
                stack.pop();
            }
            //Two senarios while loop could terminate.
            //stack empty
            //top gives the nearest smallest.
            if (stack.size() == 0)
            {
                result.push_back(-1);
            }
            else
            {
                result.push_back(stack.top());
            }

        }
        stack.push(vec[i]);
    }
    return result;
}

vector<int> StackQuestions::NSLWithIndex(vector<int>& vec)
{
    vector<int> result;
    //first element and second is index.
    stack<pair<int, int>> stack;

    for (int i = 0; i < vec.size(); i++)
    {
        if (stack.size() == 0)
        {
            result.push_back(-1);
        }
        else if (stack.size() > 0 && stack.top().first < vec[i])
        {
            result.push_back(stack.top().second);
        }
        else if (stack.size() > 0 && stack.top().first > vec[i])
        {
            //Pop the element till we not get the nearest smallest
            while (stack.size() > 0 && stack.top().first > vec[i])
            {
                stack.pop();
            }
            //Two senarios while loop could terminate.
            //stack empty
            //top gives the nearest smallest.
            if (stack.size() == 0)
            {
                result.push_back(-1);
            }
            else
            {
                result.push_back(stack.top().second);
            }

        }
        stack.push({ vec[i],i });
    }
    return result;
}

vector<int> StackQuestions::NSRWithIndex(vector<int>& vec)
{
    vector<int> result;
    //first element and second is index.
    stack<pair<int, int>> stack;

    for (int i = vec.size() - 1; i >= 0; i--)
    {
        NSC(result, stack, vec, i);
    }
    reverse(result.begin(), result.end());
    return result;
}

int StackQuestions::MaxAreaHistogram(vector<int>& vec)
{
    vector<int> right = NSRWithIndex(vec);
    vector<int> left = NSLWithIndex(vec);
    vector<int> Area;
   
    for (int i = 0; i < vec.size(); i++)
    {
        int width = abs(right[i] - left[i]) - 1;
        Area.push_back(vec[i] * width);
    }

    int maxarea = 0;
    for (int i = 0; i < Area.size(); i++)
    {
        if (maxarea < Area[i])
        {
            maxarea = Area[i];
        }
    }
    return maxarea;
}

void StackQuestions::NSC(vector<int>& result, stack<pair<int, int>>& stack, vector<int>& vec, int i)
{
    if (stack.size() == 0)
    {
        result.push_back(-1);
    }
    else if (stack.size() > 0 && stack.top().first < vec[i])
    {
        result.push_back(stack.top().second);
    }
    else if (stack.size() > 0 && stack.top().first > vec[i])
    {
        //Pop the element till we not get the nearest smallest
        while (stack.size() > 0 && stack.top().first > vec[i])
        {
            stack.pop();
        }
        //Two senarios while loop could terminate.
        //stack empty
        //top gives the nearest smallest.
        if (stack.size() == 0)
        {
            result.push_back(-1);
        }
        else
        {
            result.push_back(stack.top().second);
        }

    }
    stack.push({ vec[i],i });
}

