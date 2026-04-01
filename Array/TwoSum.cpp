// Two sum

#include<bits/stdc++.h>
using namespace std;


//Approach --> Nested lopp comparing each element with target
vector<int> BruteTwosum(vector<int> &nums, int target)
{
    int n = nums.size();
    for(int i = 0 ; i<n;i++)
    {
        for(int j = i+1;j<n;j++)
        {
            if(nums[i]+nums[j] == target)                               //Time Complexity:O(n^2)
            {                                                           //Space Complexity:O(1)
                return {i,j};
            }
        }
    }

    return {-1,-1};
}

int main()
{
    vector<int> nums = {1,2,3,4,5};
    vector<int> ans = BruteTwosum(nums,3);
    if(ans[0] != -1)
    {
        cout<<"["<<ans[0]<<","<<ans[1]<<"]";
    }
    else
    {
        cout<<"Indices not found";
    }
    return 0;
}