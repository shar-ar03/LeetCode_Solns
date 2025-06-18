/* Binary search solution -> optimized (good solution) but not fully optimized
*/
// Code-> 
class Solution {
public:
bool binary_search(vector<int>nums,int target)
{
    int start = 0;
    int end = nums.size()-1;
    while(start<=end)
    {
        int mid = start + (end - start)/2;
        if(target==nums[mid])
            return true;
        else if(target > nums[mid])
            start = mid + 1;
        else
            end = mid -1;
    }
    return false;
}
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int i =0;i<matrix.size();i++)
        {
            if(binary_search(matrix[i],target))
                return true;
        }
        return false;
    }
};

/* More optimal solution is that we will be using the concept of binary search instead of directly applying it,
    Theory : We know from the problme statement that the rows and columns in themselves are sorted so when we look at the top corner rightmost element
            we can see that in that row and col the entire sequence is sorted in such a manner that we can elimainate by comapring the target with that element
            and for that we can elmiminate row and col in very less time instead of applying binary search in each col or row. How ?? Let's see : 
    */

//Code - 
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = 0;
        int col = matrix[0].size()-1;
        while(row<matrix.size() && col>=0)
        {
            if(matrix[row][col]==target)
                return true;
            else if(matrix[row][col] > target)
                col--;
            else
                row++;
        }
        return false;
    }
};

/* Space Complexity -> O(n)
    Time Complexity -> O(n + m)
*/

/* Concept is that check that element and then if target > element then it can never exist in the same row but maybe in the next row and same col hence row++.
    Similarly if we talk about target < element then it can never lie in the same row but maybe same col so col--
*/
