/* Leetcode 370 - Range Addition 
  Here we are given a bunch of querries where we have to update sum from left index to right index and then return the final vector/array after all querries are done
  Algo : The brute force algo says that we need to update all querries one by one which is the logical way to do it but the solution goes to O(querries * n) i.e. almost order of O(n^2)

  A better solution is using the difference array technique. 
    Technique : for each querry -> nums[left_index] += value && nums[right_index + 1] -=value (given that right_index + 1 is not out of bounds)
              : Then do cumulative sum of the final array to get the final array to return as answer
*/
#include <bits/stdc++.h>
using namespace std;
int main() {
    vector<int> nums = {0,0,0,0,0};
    vector<vector<int>> querries = {{1,3,2},{2,4,3},{0,2,-2}};
    for(int i =0;i<querries.size();i++)
    {
        int left_index = querries[i][0];
        int right_index = querries[i][1];
        int value = querries[i][2];
        
        // addition part 
        nums[left_index] += value;
        if(right_index < nums.size()-1)
            nums[right_index+1] -= value;
    }
    // take cumulative sum
    for(int i = 1;i<nums.size();i++)
    {
        nums[i] = nums[i-1] + nums[i];
    }
    for(int i = 0;i<nums.size();i++)
    {
        cout<<nums[i]<<" ";
    }
}
/* 
  Time complexity : O(querries) + O(n) ~ O(n) 
  Space complexity : O(1)
*/
