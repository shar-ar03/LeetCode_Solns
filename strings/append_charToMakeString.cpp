class Solution {
public:
    int appendCharacters(string s, string t) {
        int i =0,j=0;
        int index = 0;
        while(i < s.length() && j<t.length())
        {
            if(s[i]==t[j])
                j++;
            i++;
        }
        return t.length()-j;
    }
};
