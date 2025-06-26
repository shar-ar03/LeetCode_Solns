class Solution {
public:
    string makeGood(string s) {
        string ans ="";
        for(int i =0;i<s.length();i++)
        {
            if(ans=="")
                ans+=s[i];
            else
            {
                char curr = ans.back();
                if((curr==s[i]-32) || (curr==s[i]+32))
                    ans.pop_back();
                else
                    ans += s[i];
            }
        }
        return ans;
    }
};
