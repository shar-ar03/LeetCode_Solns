// Brute force 
//code : 
class Solution {
public:
    int beautifulSubstrings(string s, int k) {
        // brute force approach
        int count = 0;
        for(int i =0;i<s.length();i++)
        {
            int vowel = 0;
            int consonant = 0;
            for(int j =i;j<s.length();j++)
            {
                if(s[j]=='a'||s[j]=='e'||s[j]=='i'||s[j]=='o'||s[j]=='u')
                    vowel++;
                else
                    consonant++;
                count += ((vowel==consonant) && ((vowel*consonant)%k==0))?1:0;
            }
        }
        return count;
    }
};
