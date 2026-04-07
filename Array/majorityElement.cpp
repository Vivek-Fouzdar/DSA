// Majority element - 1 (leetcode #169)

#include<bits/stdc++.h>
using namespace std;

// Approach------------> Use a Hashmap to count the frequency and return the most frequent element
int majorityElement(vector<int>& nums) {
        unordered_map<int, int> hashmap;
        int n = nums.size();
        int max = 0 ;
        int ele =0;

        for(int i = 0; i<n;i++)
        {
            hashmap[nums[i]]++;
        }

        for(auto num:hashmap)
        {
            if(num.second>max)
            {
                max = num.second;
                ele = num.first;
            }
        }
        return ele;
    }

    // Driver code
    int main()
    {
        vector<int> nums = {3,2,3};
        cout<<majorityElement(nums);
        return 0;
    }