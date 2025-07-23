class Solution {
public:
        pair<int , pair<int , int >> getMinSum(vector<int>nums){
            priority_queue<pair<int , pair<int , int >>, vector<pair<int , pair<int , int >>> , greater<pair<int , pair<int , int >>>> pq;
            for(int i=0;i<nums.size();i++){
                for(int j=i+1;j<nums.size();j++){
                    pq.push({nums[i]+nums[j], {i , j}});
                }

            }
            if(pq.empty()){
                return {-1, {-1 , -1}};

            }
            return pq.top();

        }
    bool checkIsSorted(vector<int>nums){
        return is_sorted(nums.begin(), nums.end());
    }
    int minimumPairRemoval(vector<int>& nums) {
        int operations =0 ;
        while(not checkIsSorted(nums)){
            operations++;
            // element , { i , j }
            pair<int , pair<int , int >> p =  getMinSum(nums);
            int i = p.second.first;
            int  j = p.second.second ;
            int sum = p.first;
            if(i==-1 or j==-1){
                break;
            }
            if(i>j){
                swap(i , j );
            }
            nums.erase(nums.begin()+j);
            nums.erase(nums.begin()+i);
            nums.insert(nums.begin()+i , sum);


        }
        return operations ;
    }
};