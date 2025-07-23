class Solution {
public:
int f(string a,string b,int i,int j){
    //base cases
    if(i==a.size()){
        return b.size()-j;
    }
    if(j==b.size()){
        return a.size()-i;
    }
    int ans=0;
    if(a[i]==b[j]){
      return f(a,b,i+1,j+1);
    }
    else{

    
        int insert=1+f(a,b,i,j+1);
        int Delete=1+f(a,b,i+1,j);
        int replace=1+f(a,b,i+1,j+1);
         ans=min(insert,min(Delete,replace));
    }
        return ans;
    
}
    int minDistance(string word1, string word2) {
        return f(word1,word2,0,0);
    }
};