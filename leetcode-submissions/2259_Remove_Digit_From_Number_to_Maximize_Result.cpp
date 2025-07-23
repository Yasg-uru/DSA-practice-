class Solution {
public:
    string removeDigit(string number, char digit) {
     vector<char>arr(number.begin(),number.end());

     for(int i=0;i<number.size();i++){
         if(arr[i]==digit){
            arr[i]='*';
             break;
         }
     }
    string ans="";
    for(char ele:arr){
        if(ele!='*'){
            ans.push_back(ele);
        }
    }
    return ans;
    }

};