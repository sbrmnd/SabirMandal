#include "ArraysProblems.h"
#include <unordered_map>
#include<algorithm>
#include<map>
#include <queue>
#include<unordered_map>
#include<stack>


vector<int> ArraysProblems::twoSum(vector<int>& nums, int target) {
    vector<int> result;
    map<int, int> store;
    for (size_t i = 0; i < nums.size(); i++)
    {
        store[nums[i]] = i;
    }

    for (int i = 0; i < nums.size(); i++)
    {
        int rem = target - nums[i];
        auto itr = store.find(rem);
        if (itr != store.end() && itr->second != i)
        {
            result = { i,itr->second };
        }
    }
    return result;
}

vector<vector<int>> ArraysProblems::threeSum(vector<int>& nums) {

    int n = nums.size();
    sort(nums.begin(), nums.end());

    vector<vector<int>> result;

    //stores the lastIndex where a value is present.
    unordered_map <int, int> lastIndex;
    for (int i = 0; i < n; i++)
        lastIndex[nums[i]] = i;

    for (int i = 0; i < n; i++)
    {
        //already processed this i
        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        for (int j = i + 1; j < n; j++)
        {
            // already processed this combo (i,j)
            if (j > i + 1 && nums[j] == nums[j - 1])
                continue;

            // only the last index matters for us and it should be after j
            if (lastIndex[-(nums[i] + nums[j])] > j)
            {
                result.push_back({ nums[i], nums[j], -(nums[i] + nums[j]) });
            }
        }
    }

    return result;
}

vector<vector<int>> ArraysProblems::threeSumEx(vector<int>& nums)
{
    vector<vector<int>> result;
    //Sort the array, so that we use two pointer approch.
    sort(nums.begin(), nums.end());
    int len = nums.size();

    //To avoid out of array out of bound for left and right pointer.
    for (int i = 0; i < len - 2 ;i++)
    {
        //handle duplicate.
        if (i > 0 && nums[i] == nums[i + 1])
            continue;

        int left = i + 1;
        int right = len - 1;

        while (left<right)
        {
            int target = nums[i] + nums[left] + nums[right];

            if (target < 0)
            {
                //Since it sorted array, going forward will increase the value. [increasing order.]
                left++;
            }
            else if (target > 0)
            {
                //Going left value will be dec.
                right--; 
            }
            else
            {
                result.push_back({ nums[i] , nums[left] , nums[right] });

                //remove the duplicate for left and right
                while (left < right && nums[left] == nums[left + 1])
                    left + 1;
                while (left < right && nums[right] == nums[right - 1])
                    right - 1;

                left++;
                right--;
            }

        }
    }
    return result;
}

bool ArraysProblems::findTripletsZero(int arr[], int n)
{
    queue<int> queue;
    for (int i = 0; i < n; i++)
    {
        queue.push(arr[i]);
        if (queue.size() > 3)
        {
            queue.pop();
        }
        int sum = INT_MIN;
        if (queue.size() == 3)
        {
          //sum+= queue.
        }     
    }
    return false;
}

int ArraysProblems::tripleSum(vector<int>& nums)
{
    //queue<int> val;

    ///val.push()
    int result = -1;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    //Find the maximum index
    int max = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        if (max < nums[i])
            max = nums[i];
    }

    //since we need to take the first largest, second largest and third largest, such that
    //first< second< third.

    int k = 2;

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == max)
            break;

        minHeap.push(nums[i]);
        if (i >= k)
        {
            minHeap.pop();
        }
    }

    if (minHeap.size() == k)
    {
        int secvalue = minHeap.top();
        minHeap.pop();
        int thirdvalue = minHeap.top();
        minHeap.pop();

        result = secvalue + (thirdvalue * max);
    }
    
    return result;
}
int ArraysProblems::maxSubarraySum(vector<int> nums)
{
    int currentSum = 0;
    int sum_so_far = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        currentSum = nums[i];
        sum_so_far += nums[i];

        sum_so_far = max(sum_so_far, currentSum);

        /*if (sum_so_far <= currentSum)
        {
            sum_so_far = currentSum;
        }*/

    }
    return sum_so_far;
}
int ArraysProblems::MissingNumberInArray(vector<int> nums, int n)
{
    int sum = 0;
    //int n = nums.size();
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
    }
    int result = (n * (n + 1) )/ 2 - sum;// interger overflow
    return result;
}
int ArraysProblems::maxIndexDiff(vector<int> nums, int n)
{
    vector<int>increasing(n, nums[n - 1]);
    vector<int> decreasing(n, nums[0]);

    for (int i = 1; i < n; i++)
    {
        decreasing[i] = min(nums[i], decreasing[i - 1]);
    }

    for (int i = n-2; i >= 0; i--)
    {
        increasing[i] = max(nums[i], increasing[i + 1]);
    }
    int answer = 0;
    int i = 0, j = 0;

    while (i < n && j < n)
    {

        if (increasing[i]  >= decreasing[j]) {
            answer = max(answer, i - j);
            i++;
        }
        else 
        {
            j++;
        }
    }
    return answer;
}
vector<int> ArraysProblems::singleNumber(vector<int>& nums)
{
    unordered_map<int,int> mapfre;
    vector<int> result;
    
    for (int i = 0; i < nums.size(); i++)
    {
        auto itr = mapfre.find(nums[i]);
        if (itr != mapfre.end())
        {
            mapfre[nums[i]] =  itr->second + 1 ;
        }
        else
        {
            mapfre[nums[i]]=  1;
        }
    }

    for (auto itr1 = mapfre.begin(); itr1 != mapfre.end(); itr1++)
    {
        if (itr1->second == 1)
        {
            result.push_back(itr1->first);
        }
    }

    sort(result.begin(), result.end());

    return result;
}

int ArraysProblems::LogestValidParenthesis(string str)
{
    int n = str.length();

    stack<char> chS;
    stack<int> indexS;

    //Initialize the index with -1, to calulate the length in case the input sting contains all valid parenthesis.
    indexS.push(-1);

    int maxVal = 0;

    for (int i = 0; i < n; i++)
    {
        //Two case 
        if (str[i] == '(')
        {
            //Insert ( into the char stack and upate the associated index.
            chS.push(str[i]);
            indexS.push(i);
        }
        else
        {//Two sub case
            if (!chS.empty() && !indexS.empty() && chS.top() == '(')
            {
                chS.pop();
                indexS.pop();
                maxVal = max(maxVal, i - indexS.top());
            }
            else
            {
                indexS.push(i);
            }
        }
    }
    return maxVal;
}
int ArraysProblems::maxArea(vector<int>& height)
{
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
