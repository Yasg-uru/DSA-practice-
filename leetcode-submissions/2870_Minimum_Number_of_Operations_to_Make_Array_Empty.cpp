class Solution {
public:
    int minOperations(vector<int>& tasks) {
         unordered_map<int ,int >mp;
        int n = tasks.size();
        for(int i=0;i<n;i++){
            mp[tasks[i]]++;
        }
        int ans =0 ;

        for(auto& ele : mp){
            int count = ele.second ;
            if(count==1){
                return -1;
            }
            if(count%3==0){
                ans+=(count/3);
            }else{
                ans+=(count/3)+1;
            }
        }
        return ans ;
    }
};