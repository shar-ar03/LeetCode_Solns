class Solution {
public:
    string countAndSay(int n) {
        if(n==1)
            return "1";
        
        string say = countAndSay(n-1);
        //processing
        string result ="";
        char curr = say[0];
        int count = 1;

        for(int i = 1;i<say.length();i++)
        {
            if(say[i]==curr)
                count++;
            else
            {
                result += to_string(count) + curr;
                curr = say[i];
                count = 1;
            }
        }
        result += to_string(count) + curr;
        return result;
    }
};
