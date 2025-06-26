/* Tokenization technique used for solution
*/
class Solution {
public:
    int compareVersion(string version1, string version2) {
        stringstream ss1(version1), ss2(version2);
        string token1, token2;

        vector<int> token_parts1, token_parts2;

        while (getline(ss1, token1, '.')) {
            token_parts1.push_back(stoi(token1));
        }

        while (getline(ss2, token2, '.')) {
            token_parts2.push_back(stoi(token2));
        }

        int size_token1 = token_parts1.size();
        int size_token2 = token_parts2.size();

        // Pad the shorter version with zeros
        while (size_token1 < size_token2) {
            token_parts1.push_back(0);
            size_token1++;
        }

        while (size_token2 < size_token1) {
            token_parts2.push_back(0);
            size_token2++;
        }

        for (int i = 0; i < token_parts1.size(); i++) {
            if (token_parts1[i] < token_parts2[i])
                return -1;
            if (token_parts1[i] > token_parts2[i])
                return 1;
        }

        return 0;
    }
};
