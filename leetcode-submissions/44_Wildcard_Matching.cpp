class Solution {
public:
bool f(string &s,string &p,int i,int j){
    //base cases
    if(i<0 and j<0){
        return true;
        //because we are perfecly reached at 0 index
    }

    if(i>=0 and j<0){
       return false;//because there is  pattern is left 
    }
    if(i<0 and j>=0){
        for(int k=0;k<=j;k++){
            if(p[k]!='*'){
                return false;
            }
        }
        return true;
    }
    //now we have checking matching pattern 
    if(s[i]==p[j] or p[j]=='?')
        return f(s,p,i-1,j-1);
    
    else if(p[j]=='*')
        return f(s,p,i-1,j) or f(s,p,i,j-1);
    else
        return  false;
    
}
    bool isMatch(string s, string p) {
        return f(s,p,s.size()-1,p.size()-1);
    }
};