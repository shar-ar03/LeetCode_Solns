// This is the most basic binary search solution 

/* Approach : Take the target and compare with the start and end of each row. 
          : Find the correct row to search in and then the store the index. In case index = -1 still then return false as element is beyond search space given
          : Run classic binary search algo to find the element, if found return true else false.

Time complexity : O(n) + O(log m)
Space complexity : O(1)
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int index = -1;
        int m = matrix[0].size()-1;
        for(int i = 0;i<matrix.size();i++)
        {
            if(target >= matrix[i][0] && target <= matrix[i][m])
            {
                index = i;
                break;
            }
        }
        if(index==-1)
            return false;
        // after finding the row number apply standard binary search on it
        int start = 0;
        int end = m;
        while(start <= end)
        {
            int mid = start + (end - start)/2;
            if(target == matrix[index][mid])
                return true;
            else if(target < matrix[index][mid])
                end = mid - 1;
            else
                start = mid + 1;
        }
        return false;
    }
};




// More Optimized solution : 
/* Approach : Think of the 2d matrix as a single array, like try to think of a flatten array (because it is sorted so might as well).
             : Do not actually flatten is as it will take O(n * m) time to actually flatten is no point, instead run bnary search on the flatten array in the mind. But How ?????

              : There is a conversion formula from 1D array index to 2D array index. 
          e.g. index = 5 (in 1D array) -> for 2D array : Row = index/m  && Column = index%m   (where m = matix[0].size())

Time Complexity : O(log(n*m)) 
Space Complexity : O(1)
*/

// Solution in code 

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int start = 0;
        int end = (matrix.size() * matrix[0].size()) - 1;
        while(start<=end)
        {
            int mid = start + (end - start)/2;
            //convert mid to 2d array indices
            int row = mid/matrix[0].size();
            int col = mid%matrix[0].size();
            if(target==matrix[row][col])
                return true;
            else if(target < matrix[row][col])
                end = mid - 1;
            else
                start = mid + 1;
        }
        return false;
    }
};

/* intuition behind row = index/m and col = index%m is that just look closely (every row starting -> index(1D):{0,4,8} and index(2D):{0,1,2} find a pattern ????
The pattern is the row startis always a multiple of m therfore -> index/m must give the row number
Same goes for column number -> think like in a row how much has been already passed i.e. remainder -> index%m
*/

  
