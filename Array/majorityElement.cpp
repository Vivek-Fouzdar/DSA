// Majority element - 1 (leetcode #169)

#include<bits/stdc++.h>
using namespace std;


 int BrutemajorityElement(vector<int>& nums) {
        
        // Size of the given array
        int n = nums.size();
        
        // Iterate through each element of the array
        for (int i = 0; i < n; i++) {
            
            // Counter to count occurrences of nums[i]
            int cnt = 0; 
            
            // Count the frequency of nums[i] in the array
            for (int j = 0; j < n; j++) {                           //Time complexity: O(n^2)
                if (nums[j] == nums[i]) {                           //Space Complexity:O(1)        
                    cnt++;
                }
            }
            
            // Check if frequency of nums[i] is greater than n/2
            if (cnt > (n / 2)) {
                // Return the majority element
                return nums[i]; 
            }
        }
        
        // Return -1 if no majority element is found
        return -1; 
    }


// Approach------------> Use a Hashmap to count the frequency and return the most frequent element
int BettermajorityElement(vector<int>& nums) {
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

    //Approach --------->  Use count and element variables 
    // increment count if nums[i] == element otherwise decrement 
    // if nums[i] != element and count == 0 replace element with nums[i]
int OptimalmajorityElement(vector<int>& nums) {
        int n = nums.size();
        int count =0;
        int element = nums[0];
        for(int i = 0 ;i<n;i++)
        {
            if(nums[i] == element)
            {
                count++;
            }
            else if(nums[i] != element && count == 0)
            {
                element = nums[i];
                count++;
            }

            else                            //Time Complexity: O(n)
                                            //Space Complexity:O(1)
            {
                count--;
            }
        }

        return element;
            }

    // Driver code
    int main()
    {
        vector<int> nums = {3,2,3};
        cout<<BrutemajorityElement(nums);
        return 0;
    }