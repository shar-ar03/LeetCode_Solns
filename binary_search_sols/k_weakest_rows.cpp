/* K Weakest Rows 
  Approach : The main thing is to get the pattern that this is binary search on rows as they are sorted
           : Run a loop through all the rows in the matrix and each matrix gets a binary search for which store count of ones.
           : Store the count of ones wrt to the index of the row in pairs for later requirement
           : Sort the pair wrt to number of ones and extract the top k indexes and return ans
Time complexity : O(n*log(m) + m*log(m))
Space complexity : O(n)
*/

//CODE : 
class Solution {
public:
    vector<pair<int,int>>binary_search(vector<vector<int>>& mat)
    {
        int m = mat[0].size();
        vector<pair<int,int>> result;
        for(int i = 0;i<mat.size();i++)
        {
            int low = 0;
            int high = m-1;
            while(low<=high)
            {
                int mid = low + (high-low)/2;
                if(mat[i][mid]==1)
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }
            result.push_back({i,low});
        }
        sort(result.begin(),result.end());
        return result;
    }
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int,int>>result = binary_search(mat);
        vector<int>ans;
        for(int i = 0;i<k;i++)
        {
            ans.push_back(result[i].first);
        }
        return ans;
    }
};
