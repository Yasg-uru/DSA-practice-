class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        stack<string>st;
        int i=0;
        int j=1;
        while(j<=n and i<target.size()){
            if(j==target[i]){

            st.push("Push");
            i++;
           
            }else{
                st.push("Push");
                st.push("Pop");
              
            }
            j++;
           // j++;
        }
        vector<string>ans;
        while(not st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};