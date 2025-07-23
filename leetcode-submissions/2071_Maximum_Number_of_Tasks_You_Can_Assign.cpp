class Solution {
public:
    bool check(vector<int>& tasks, vector<int>& workers, int pills, int strength, int mid ){
        int pillsUsed = 0 ;

        multiset<int>st(begin(workers), begin(workers)+mid);
        for(int i = mid-1;i>=0;i--){
            auto it = prev(st.end()); //max strength worker
            if(*it>=tasks[i]){
                st.erase(it);

            }else if(pillsUsed>=pills){
                return false;
            }else{
                 // we need to find the lower bound 
                 auto weakestWorkerIt = st.lower_bound(tasks[i]-strength);
                 if(weakestWorkerIt==st.end()){
                    return false;
                 }
                 st.erase(weakestWorkerIt);
                 pillsUsed++;
            }
        }
        return true ;
    }
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        int m = tasks.size(),  n = workers.size(), result =0  ;
        int l = 0 , r =min(n ,m );
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(),workers.end());
        while(l<=r){
            int mid = l + (r-l)/2;
            if(check(tasks , workers , pills , strength , mid )){
               result  = mid;
                l = mid+1;

            }else{
                r = mid -1;

            }
        }
        return result;
    
    }
};