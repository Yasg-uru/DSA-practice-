class Solution {
public:
    string clearStars(string s) {
         std::stack<char> stack;
  for (char c : s) {
    if (c != '*') {
      stack.push(c);
    } else {
      if (!stack.empty() && stack.top() != 'a') {
        stack.pop();
      }
    }
  }

  std::string result;
  while (!stack.empty()) {
    result.push_back(stack.top());
    stack.pop();
  }

  // Reverse the result string since characters were pushed in stack order.
  std::reverse(result.begin(), result.end());
  return result;
    }
};