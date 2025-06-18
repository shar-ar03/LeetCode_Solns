/* Brute force approach is that find the maximum in the entire 2d Matrix then return that element 
  But : O(n * m) time complexity -> Due to search in entire 2d matrix.
*/

/* More optimal way is that use of binary search
  Algo : take the col= 0 as low and col = m-1 as high 
       : now compute the mid and find the max in the entire column 
       : now check for the max element whether this is the answer as highest chances of this one only in that column
       : if yes return {row,column} 
       : else if(max_el < right_side) -> low = mid + 1 (explore the right side of the matrix)
       : else explore left side of the matrix
*/

//CODE : 
  class Solution {
public:
    pair<int, int> maxInColumn(const vector<vector<int>>& matrix, int col) {
        int maxElem = matrix[0][col];
        int rowIndex = 0;

        for (int i = 1; i < matrix.size(); i++) {
            if (matrix[i][col] > maxElem) {
                maxElem = matrix[i][col];
                rowIndex = i;
            }
        }

        return {maxElem, rowIndex};
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int low = 0;
        int high = m - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            auto [max_el, index] = maxInColumn(mat, mid);

            int left = -1, right = -1;
            if (mid > 0)
                left = mat[index][mid - 1];
            if (mid < m - 1)
                right = mat[index][mid + 1];

            if (max_el > left && max_el > right)
                return {index, mid};
            else {
                // Use pre-computed left/right values
                if (left > max_el)
                    high = mid - 1;
                else
                    low = mid + 1;
            }
        }

        return {-1, -1}; 
    }
};


/* Time complexity -> O(n * log(m))
  Space Complexity -> O(1)
*/

/* SLIGHTLY OPTIMISED APPROACH : Instead of returning the element and row_num we can return row_num only 
                               : Now need to make variables -> right,left just compare on the spot with bound checks
*/
class Solution {
public:
    int maxInColumn(const vector<vector<int>>& matrix, int col) {
        int maxElem = matrix[0][col];
        int rowIndex = 0;

        for (int i = 1; i < matrix.size(); i++) {
            if (matrix[i][col] > maxElem) {
                maxElem = matrix[i][col];
                rowIndex = i;
            }
        }
        return rowIndex;
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int low = 0;
        int high = m - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            auto index = maxInColumn(mat, mid);

            bool leftIsGreater = (mid - 1 >= 0) && (mat[index][mid - 1] > mat[index][mid]);
            bool rightIsGreater = (mid + 1 < m) && (mat[index][mid + 1] > mat[index][mid]);
            if(leftIsGreater)
                high = mid - 1;
            else if(rightIsGreater)
                low = mid + 1;
            else
                return {index,mid};
        }
        return {-1, -1}; 
    }
};

/* Time complexity -> O(n * log(m))
  Space Complexity -> O(1)
*/
