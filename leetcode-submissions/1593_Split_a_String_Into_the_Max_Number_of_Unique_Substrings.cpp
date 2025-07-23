class Solution {
public:
void solve(int i,unordered_set<string>&st,int &maxCount,int currentCount,string s){
    //base case if the string is exaushted then we need to compare maxcount with the current count 
    if(i>=s.size()){
        maxCount=max(maxCount ,currentCount);
        return ;

    }
    //we need to iterate from the current index to the last index for finding the substrings that is not present in the current set of the string s
    for(int j=i;j<s.size();j++){
        string sub=s.substr(i,j-i+1);
        if(st.find(sub)==st.end()){
            st.insert(sub);

            solve(j+1,st,maxCount,currentCount+1,s);
            //after that we need to pop all the current inserted substring from the set 
            st.erase(sub);
        }
    }
}
    int maxUniqueSplit(string s) {
        int currentCount=0;
        int maxCount=0;
        unordered_set<string>st;
        //after that we need to pass this parameters to the solve function then we can able to solve that question 
        solve(0,st,maxCount,currentCount,s);
        return maxCount ;
    }
};