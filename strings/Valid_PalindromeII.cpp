class Solution {
private: 
    bool isPalindrome(string s,int left,int right)
    {
        while(left < right)
        {
            if(s[left]!=s[right])
                return false;
            left++;
            right--;
        }
        return true;
    }
public:
    bool validPalindrome(string s) {
        int ptr1 = 0;
        int ptr2 = s.length()-1;
        while(ptr1 < ptr2)
        {
            if(s[ptr1]!=s[ptr2])
                return isPalindrome(s,ptr1+1,ptr2) || isPalindrome(s,ptr1,ptr2-1);
            ptr1++;
            ptr2--;
        }
        return true;
    }
};
