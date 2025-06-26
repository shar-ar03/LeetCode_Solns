class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string token = "";
        string result = "";
        vector<string>token_store;
        while(ss >> token)
        {
            token_store.push_back(token);
        }
        reverse(token_store.begin(),token_store.end());
        for(int i =0;i<token_store.size();i++)
        {
            result = result + token_store[i] + " ";
        }
        return result.substr(0,result.length()-1);
    }
};
