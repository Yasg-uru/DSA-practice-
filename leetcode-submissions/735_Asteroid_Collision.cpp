class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        for(int i=0;i<asteroids.size();i++){
            bool isdestroid = false;
            while(not st.empty() and asteroids[i]<0 and st.top()>0){
              if(abs(asteroids[i])>st.top()){
                st.pop();
                continue;// we want to cancel previous as well if they meet next time 
              }else if (st.top()==abs(asteroids[i])){
                st.pop();
                
              }
              isdestroid= true;
              break;
            }
            if(not isdestroid){
                st.push(asteroids[i]);
            }
        }
        vector<int>res;
        while(not st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};