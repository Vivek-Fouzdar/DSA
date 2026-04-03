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
        {
            nums[currIndex++] = 0;
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