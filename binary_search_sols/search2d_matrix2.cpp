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
