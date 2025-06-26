class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // base case 
        if(strs.empty())
            return "";
        string lcp = "";
        for(int i = 0;i<strs[0].size();i++)
        {
            char curr_char = strs[0][i];
            // match this char with all the other chars 

            for(int j = 1;j<strs.size();j++)
            {
                // check that i is not out of bound for that string length
                if(i >= strs[j].length() || strs[j][i]!= curr_char)
                    return lcp;
            }
            lcp += curr_char;
        }
        return lcp;  
    }
};
