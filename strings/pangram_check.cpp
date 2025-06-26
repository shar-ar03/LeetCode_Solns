/*
    Check for pangram
*/
// code :
class Solution {
public:
  bool checkIfPangram(string sentence) {
    if (sentence.length() < 26)
      return false;
    vector<int> count(26);
    for (int i = 0; i < sentence.length(); i++) {
      count[sentence[i] - 'a']++;
    }
    for (int i = 0; i < count.size(); i++) {
      if (count[i] < 1)
        return false;
    }
    return true;
  }
};