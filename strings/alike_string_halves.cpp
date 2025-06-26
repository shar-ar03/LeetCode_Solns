class Solution {
    private :
        bool vowel_check(char c)
        {
            c = tolower(c);
            if(c=='a' || c=='e'|| c=='i' || c=='o' || c=='u')
                return true;
            return false;
        }
public:
    bool halvesAreAlike(string s) {
        int len = s.length();
        int count_left = 0;
        int count_right = 0;
        for(int i =0;i<len/2;i++)
        {
            if(vowel_check(s[i]))
                count_left++;
        }
        for(int i =len/2;i<len;i++)
        {
            if(vowel_check(s[i]))
                count_right++;
        }
        return (count_left==count_right) ? true : false;
    } 
};
