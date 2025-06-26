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
