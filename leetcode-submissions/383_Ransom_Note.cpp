class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
     
    
     bool flag=false;
     map<char,int>m1;
     map<char,int>m2;
     for(auto ele:ransomNote){
         m1[ele]++;
     }
     for(auto ele:magazine){
         m2[ele]++;
     }
     for(auto i:ransomNote){
         if(m1[i]>m2[i]){
             flag=true;
             break;
         }
     }
     if(flag){
         return false;
     }
     return  true;


    }
};