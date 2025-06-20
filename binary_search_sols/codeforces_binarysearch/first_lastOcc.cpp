/* Here we have a binary search based solution that solves the problem in log(n)
   time at max. But we also have a brute force solution that takes O(n). I will
   only give approach for O(n) solution

    Approach (O(n) solution) : Run through entire array and maintain the the
   first time you get the element : For last occurence continue and keep
   updating the last_occ until you cross it : Then return the value of las_occ
   and first_occ to the min function
*/

/* Binary search approach -> do normal binary search on the vector and then
   maintain the lastpos of the key when seen
                          -> then return the value to the output driver
*/
// code :
class Solution {
public:
  int first_occ(vector<int> &nums, int key) {
    int store = -1;
    int start = 0;
    int end = nums.size() - 1;
    while (start <= end) {
      int mid = start + (end - start) / 2;
      if (nums[mid] < key) {
        start = mid + 1;
      } else if (nums[mid] >= key) {
        end = mid - 1;
        if (nums[mid] == key) {
          store = mid;
        }
      }
    }
    return store;
  }
  int last_occ(vector<int> &nums, int key) {
    int store = -1;
    int start = 0;
    int end = nums.size() - 1;
    while (start <= end) {
      int mid = start + (end - start) / 2;
      if (nums[mid] > key) {
        end = mid - 1;
      } else if (nums[mid] <= key) {
        start = mid + 1;
        if (nums[mid] == key) {
          store = mid;
        }
      }
    }
    return store;
  }
  vector<int> searchRange(vector<int> &nums, int target) {
    int f = first_occ(nums, target);
    int l = last_occ(nums, target);
    vector<int> result{f, l};
    return result;
  }
};