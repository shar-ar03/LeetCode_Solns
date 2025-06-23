/*
    Problem: Subarray Sum Equals K (LC 560)
    Given an integer array nums and an integer k, return the total number of
   continuous subarrays whose sum equals to k.
*/

/*
    Approach : Most important keep a map for tracking current prefix_sum
             : At every index post calculating the sum check for whether
   curr_sum - k was seen or not : Because if yes then this means apart from that
   portion the remaining part till the index is having sum==k
*/

// CODE :
class Solution {
public:
  int subarraySum(vector<int> &nums, int k) {
    int curr_sum = 0;
    int result = 0;
    unordered_map<int, int> prefix_count;
    prefix_count[curr_sum] = 1;
    for (int i = 0; i < nums.size(); i++) {
      curr_sum = curr_sum + nums[i];
      if (prefix_count[curr_sum - k] > 0) {
        // already seen this
        result += prefix_count[curr_sum - k];
      }
      prefix_count[curr_sum]++;
    }
    return result;
  }
};

/*
    Time complexity : O(n)
    Space complexity : O(n) (due to hashmap use)
*/