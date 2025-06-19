/* Here we need to find the kth smallest element in a sorted matrix 
  Approach : Binary search on answers (why ????)
  Reason : Both the rows and columns are sorted so we can apply this techinque liek we did in matrix median

  Algo : Define search space i.e. min element -> max element i.e. matrix[0][0] to matrix[n-1][m-1] 
       : take a mid value and check if it can be the kth smallest 
       : If count_k < k then this means we need to look forward (low = mid + 1)
       : Else we need to back up a little (high = mid) not mid - 1: because mid can be an answer as well that is why.
  */
class Solution {
public:
    int helper(vector<vector<int>>&mat,int k)
    {
        // for each row count how many were less than mid
        int n = mat.size();
        int m = mat[0].size();
        int curr = 0;
        for(int i =0;i<n;i++)
        {
            int low = 0;
            int high = m-1;
            int ans = 0;
            while(low<=high)
            {
                int mid = low + (high-low)/2;
                if(mat[i][mid] <= k)
                {
                    low = mid + 1;
                    ans = mid+1;
                }
                else
                    high = mid - 1;
            }
            curr += ans;
        }
        return curr;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int m = matrix[0].size();
        int low = matrix[0][0];
        int high = matrix[n-1][m-1];
        // edge case I
        if(n*m <= k)
        {
            return matrix[n-1][m-1];
        }
        while(low<high)
        {
            int mid = low + (high-low)/2;
            int count = helper(matrix,mid);
            if(count < k)
            {
                // there aren't enough elements
                low = mid + 1;
            }
            else
            {
                high = mid; // not mid -1 as mid might be the answer
            }
        }
        return low;
    }
};

/* Space complexity and Time complexity analysis 
  Space complexity -> O(1) 
  Time Complexity -> O(n * log(m) * log(R) , where R = maximum_element - minimum_element
  */
