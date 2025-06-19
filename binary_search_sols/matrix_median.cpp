/* Intuition use Binary search on answers 
Algo : Same as kth smallest value in sorted matrix, as the 2d matrix is sorted about the row and column this means we can try this method.
     : Take a range of answers min_value to max_value in the array.
     : For any mid value check the number of elements before this and then take a call whether this can be the median element or not
     : If count_k > (m*n)/2 this means that the median lies before this element so -> high = mid - 1
     : Else median lies ahead of this element i.e. low = mid + 1

Time complexity : O(n * log(m) * log(max-min))
Space complexity : O(1)
*/

class Solution{
public:
    int count_rows(vector<vector<int>>&matrix,int k)
    {
        int count = 0;
        int cols = matrix[0].size();
        for(int i = 0;i<matrix.size();i++)
        {
            int low = 0;
            int high = cols - 1;
            while(low<=high)
            {
                int mid = low + (high-low)/2;
                if(matrix[i][mid] <= k)
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid -1;
                }
            }
            count = count + low;
        }
        return count;
    }
    int findMedian(vector<vector<int>>&matrix) {

        // VARIABLE DECLERATION
        int n = matrix.size();
        int m = matrix[0].size();
        int low = INT_MAX;
        int high = INT_MIN;

        // GLOBAL MAX AND MIN
        for (int i = 0; i < n; i++) {
            low = min(low, matrix[i][0]);
            high = max(high, matrix[i][m - 1]);
        }

        // BINARY SEARCH ALGO
        while(low<=high)
        {
            int mid = low + (high - low)/2;
            int curr = count_rows(matrix,mid);
            if(curr <= n*m/2)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return low;
    }
};
