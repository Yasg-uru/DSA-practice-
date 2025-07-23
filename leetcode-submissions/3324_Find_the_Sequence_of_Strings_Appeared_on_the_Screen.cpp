class Solution {
public:
    vector<string> stringSequence(string target) {
        vector<string>ans ;
        int  i =0, n = target.size() ;

       string str = "";
       while(str!=target and i<n){
        // a 
        // [a]
       str.push_back('a');
        ans.push_back(str);
        while(str.back()!=target[i]){
            str.back()+=1;
            ans.push_back(str);
        }
        i++;
       }
       cout<<str;
        return ans ;
    }
};