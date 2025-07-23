class Solution {
public:
void helper(string s , int start,vector<string>&temp,vector<vector<string>>&arr){
  if(start==s.size()){
arr.push_back(temp);
return ;
  }  
  //now iterating through the loop
  for(int i=start;i<s.size();i++){
      if(ispalindrome(s,start,i)){
          temp.push_back(s.substr(start,i-start+1));
          helper(s,i+1,temp,arr);
          temp.pop_back();
      }
  }


}
bool ispalindrome(string s,int left,int right){
    while(left<right){
        if(s[left]!=s[right]){
            return false;
        }
        left++;
        right--;

    }
    return true;
}
    vector<vector<string>> partition(string s) {
        vector<vector<string>>arr;
        vector<string>temp;
        helper(s,0,temp,arr);
        return arr;
    }
};