class Solution {
public:
    bool rotateString(string s, string goal) {
      int i=0;
      while(i<s.size()){
        char firstchar=s[0];
        s.erase(0,1);
        s.push_back(firstchar);
        if(s==goal){
            return true;
        }
        i++;
      }  
      return false;
    }
};