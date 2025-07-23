class Solution {
public:
    bool check_is_self_dividing(int num){
        string number = to_string(num);
        for(int i =0 ;i<number.size();i++){
            if(number[i]=='0'){
                return false;
            }
            int digit = number[i]-'0';
            if(num%digit!=0){
                return false;
            }
        }
        return true ;
    }
    vector<int> selfDividingNumbers(int left, int right) {
      vector<int>ans;
        for(int num = left ;num<=right;num++){
        if(check_is_self_dividing(num)){
            ans.push_back(num);
        }   
      }  
        return ans ;
    }
};