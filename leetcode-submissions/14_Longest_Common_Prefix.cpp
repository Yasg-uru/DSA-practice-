class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
sort(strs.begin(),strs.end());
string str1=strs[0];
string str2=strs[strs.size()-1];
//now we need to compare this strings and then put answers
int j=0;
for(int i=0;i<str1.size();i++){
    if(str1[i]==str2[i]){
        j++;
    }else{
        break;
    }
}
return str1.substr(0,j);

    }
};