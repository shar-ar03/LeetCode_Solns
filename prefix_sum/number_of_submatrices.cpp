/*
    Problem Name - Number of Submatrices That Sum to Target (LC 1074)
    Given a 2D matrix of integers and a target value k, your task is to count
   the number of submatrices (i.e., rectangular regions in the matrix) whose
   elements sum up to exactly k. This is an extension of the classic 1D prefix
   sum problem (Subarray Sum Equals K) into two dimensions. The challenge lies
   in efficiently handling all possible submatrices without brute-force
   enumeration.
*/

/*
    Brute force is that check for all submatrices if the sum is valid or not but
   this will take O(n^6) which is way beyond our scope by all means very much
   inefficient
*/

/*
    Optimal Approach using prefix sum and hashmap : Implementation of LC 560
   Subarray Sum Equals K

    Approach : First take a prefix_sum accross rows in O(rows * cols) time
             : Take s_c = 0, col = 0, row = 0 and then traverse column wise and
   apply logic of LC 560 (it will be much clear in the code) : Maintain a result
   variable and at last return that as your final answer
*/

// CODE :
class Solution {
public:
  int numSubmatrixSumTarget(vector<vector<int>> &matrix, int target) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    // first find the prefix sum for all rows
    for (int row = 0; row < rows; row++) {
      for (int col = 1; col < cols; col++) {
        matrix[row][col] += matrix[row][col - 1];
      }
    }

    // apply the concept of map and cum_sum - target concept
    int result = 0;
    for (int s_c = 0; s_c < cols; s_c++) {
      for (int j = s_c; j < cols; j++) {
        unordered_map<int, int> prefix_count;
        int curr_sum = 0;
        prefix_count[0] = 1;

        for (int row = 0; row < rows; row++) {
          curr_sum += matrix[row][j] - (s_c > 0 ? matrix[row][s_c - 1] : 0);
          if (prefix_count[curr_sum - target] > 0) {
            result += prefix_count[curr_sum - target];
          }
          prefix_count[curr_sum]++;
        }
      }
    }
    return result;
  }
};

/*
    Time complexity : O(rows * cols ) + O(cols * cols * rows) ~ O(cols * cols *
   rows) Space complexity : O(n) i.e. hashmap application only
*/