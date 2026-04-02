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

// using extra space - HashMap
vector<int> BetterTwosum(vector<int>& nums, int target) {
     int n  = nums.size();
     unordered_map<int,int> hashmap;

     for(int i = 0 ; i<n; i++)
     {
        int complement = target - nums[i];
        if(hashmap.find(complement) != hashmap.end())           //Time Complexity:O(n)
        {                                                        //Space Complexity:O(n)
            return {hashmap[complement],i};
        }

        hashmap[nums[i]] = i;
     }   

     return {-1,-1};

     
    }

 // Two pointers + greedy
vector<int> OptimalTwosum(vector<int>& nums, int target)
{
    int n  = nums.size();

    vector<pair<int, int>> numsWithIndex;  // store elements with indices 

    for(int i = 0 ; i <n;i++)
    {
        numsWithIndex.push_back({nums[i],i});
    }

    sort(numsWithIndex.begin(),numsWithIndex.end());       // sort elements by value 

    int left = 0 ;
    int right = n-1; 

    while(left < right )
    {
        int sum = numsWithIndex[left].first + numsWithIndex[right].first;
        if(sum == target)
        {   //Return Original Indices
            return {numsWithIndex[left].second,numsWithIndex[right].second};
        }
        else if (sum < target)
        {
            left++;
        }                                                                              //Time Complexity:O(nlogn)
        else{                                                                          //Space Complexity:O(n)
            right++;
        }
    }
    return {-1,-1};

}


    
int main()
{
    vector<int> nums = {1,2,3,4,5};
    vector<int> ans = BetterTwosum(nums,3);
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