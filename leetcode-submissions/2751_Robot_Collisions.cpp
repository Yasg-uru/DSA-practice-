class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n=positions.size();

        vector<pair<int,int>>index(n);
        for(int i=0;i<n;i++){
            index.push_back({positions[i],i});

        }
        sort(index.begin(),index.end());

        //after that we need to traverse by an index and sorting the positions in ascending order 
        stack<int>st;

        for(auto ele:index){
            int i=ele.second;
            //extracting index from the pair
            if(directions[i]=='R'){
                st.push(i);
            }else{
               while(not st.empty() and healths[i]>0){
                 int topindex=st.top();
                 int x=healths[topindex]-healths[i];
                 if(x>0){
                    healths[topindex]--;
                    healths[i]=0;
                 }else if(x<0){
                    healths[topindex]=0;
                    healths[i]--;
                 }else{
                    //last case in which health of two robot are same 
                    healths[i]=healths[topindex]=0;
                    st.pop();

                 }
               }
                
            }

        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(healths[i]>0){
                ans.push_back(healths[i]);

            }
        }
        return ans;
        
    }
};