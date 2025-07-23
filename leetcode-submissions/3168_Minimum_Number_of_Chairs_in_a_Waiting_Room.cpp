class Solution {
public:
    int minimumChairs(string s) {
         int max_people = 0;
  int current_people = 0;

  for (char c : s) {
    if (c == 'E') {
      current_people++;
      max_people = std::max(max_people, current_people);
    } else {
      current_people--;
    }
  }

  return max_people;
    }
};