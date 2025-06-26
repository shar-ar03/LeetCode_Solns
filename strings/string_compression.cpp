/*
    compress string such that if characters are repeating then store the count
   in front of them e.g. s = "aabccc" -> o/p = "a2b1c3"
*/
class Solution {
public:
  int compress(vector<char> &chars) {
    int index = 0;
    char current_char = chars[0];
    int count = 1;

    for (int i = 1; i < chars.size(); i++) {
      if (chars[i] == current_char) {
        count++;
      } else {
        chars[index++] = current_char;
        if (count > 1) {
          string count_str = to_string(count);
          for (char c : count_str) {
            chars[index++] = c;
          }
        }
        current_char = chars[i];
        count = 1;
      }
    }
    chars[index++] = current_char;
    if (count > 1) {
      string count_str = to_string(count);
      for (char c : count_str) {
        chars[index++] = c;
      }
    }

    return index;
  }
};
/*
    Time complexity : O(n)
    Space Complexity : O(1)
*/