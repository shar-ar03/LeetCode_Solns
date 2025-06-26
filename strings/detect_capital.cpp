class Solution {
public:
    bool capital(string &s)
    {
        for(int i=0;i<s.length();i++)
        {
            if(!isupper(s[i]))
                return false;
        }
        return true;
    }
    bool small (string &s)
    {
        for(char c : s)
        {
            if(!islower(c))
                return false;
        }
        return true;
    }
    bool firstCap(string &s)
    {
        if(!isupper(s[0]))
            return false;
        for(int i =1;i<s.length();i++)
        {
            if(isupper(s[i]))
                return false;
        }
        return true;
    }

    bool detectCapitalUse(string word) {
        return (capital(word) || small(word) || firstCap(word)) ? true : false;
    }
};
