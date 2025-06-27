/* 
  need to count the number of homogneous strings i.e. in a string 
  str = "abbcccaa"

  Analysis -> "a" -> 3
              "b" -> 2
              "bb" -> 1
              "c" -> 3
              "cc" -> 2
              "ccc" -> 1
              "aa" -> 1
      total = 3 + 2 + 1 + 3 + 2 + 1 + 1 = 13 

      Time complexity -> O(n)
      Space complexity -> O(1)
  */

//code : 
class Solution {
public:
    int countHomogenous(string s) {
        char curr = s[0];
        int count = 1;
        int ans = 0;
        const int mod = 1e9 + 7;
        for(int i =1;i<s.length();i++)
        {
            if(s[i]==curr)
                count++;
            else
            {
                curr = s[i];
                ans = (ans + (1LL * count * (count + 1) / 2) % mod) % mod;
                count =1;
            }
        }
        ans = (ans + (1LL * count * (count + 1) / 2) % mod) % mod;
        return ans;
    }
};
              
