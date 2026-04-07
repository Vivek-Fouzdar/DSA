#include<bits/stdc++.h>
using namespace std;

//Approach count ---> Number of 0's,1's,2's and overwrite the Array
void  BrutesortColors(vector<int> &nums) {
      int n = nums.size();
      int cnt0 = 0,cnt1= 0,cnt2 =0;
      for (int i = 0 ; i < n;i++)
      {
        if(nums[i] == 0) {cnt0++;}
        else if(nums[i] == 1){cnt1++;}
        else{cnt2++;}
      }
       int  currIndex = 0;
        while(cnt0--)
        {                                                                  //Time Complexity: O(n)
            nums[currIndex++] = 0;                                         //Time Complexity:O(1)
        }
        while(cnt1--)
        {
            nums[currIndex++] = 1;
        }
        while(cnt2--)
        {
            nums[currIndex++] = 2;
        }
     
        
    } 

    //Approach ---------> count 0,1,2 and use for loop ranges to overwrite array
      void BetttersortColors(vector<int>& nums) {
      int n = nums.size();
      int cnt0 = 0,cnt1= 0,cnt2 =0;
      for (int i = 0 ; i < n;i++)
      {
        if(nums[i] == 0) {cnt0++;}
        else if(nums[i] == 1){cnt1++;}
        else{cnt2++;}
      }

      for (int i = 0; i < cnt0; i++) {
            nums[i] = 0;
        }

        // Fill the next 'cnt1' elements with 1
        for (int i = cnt0; i < cnt0 + cnt1; i++) {
            nums[i] = 1;
        }

        // Fill the remaining elements with 2
        for (int i = cnt0 + cnt1; i < nums.size(); i++) {
            nums[i] = 2;
         }
    }

int main()
{
    vector<int> nums = { 2,2,0,1,0,2};
     BrutesortColors(nums);
    for(auto num:nums)
    {
        cout<<num<<" ";
    }
    return 0;
}