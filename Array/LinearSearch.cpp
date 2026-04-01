// Linear serach in an Array

#include<bits/stdc++.h>
using namespace std;

int LinearSearch(vector<int> &nums, int target)
{
    int n = nums.size();
    //Approach -------->
    // for loop to iterate through array
    //comparing each element with target element
    for(int i = 0 ; i< n ;i++ )
    {
        if(nums[i] == target)
        {
            return i;              //if found return element
        }
    }
    return -1;                     //if not found return -1
}

//Driver code
int main()
{
    vector<int> nums = {1,2,3,4,5,6};
    int target = LinearSearch(nums,5);
    cout<<target;
}

// Time Complexity: O(n)
// Space COomplexity: O(1)