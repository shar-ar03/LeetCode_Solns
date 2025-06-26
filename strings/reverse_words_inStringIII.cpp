class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string token = "";
        string result = "";

        while(ss >> token)
        {
            reverse(token.begin(),token.end());
            result = result + token + " ";
        }
        result = result.substr(0,result.length()-1);
        return result;
    }
};
