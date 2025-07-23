class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<pair<pair<int , int >, int>>arr(n );
        for(int i =0 ;i<n; i++){
            int sum =0 ;
            string num = to_string(nums[i]);
            for(char ch : num){
                sum+=(ch-'0');
            }
            arr[i] = {{sum , nums[i]} , i };
        }
        int count =0 ;
        sort(arr.begin(), arr.end());
        vector<bool>visited(n , false);
        for(int i =0 ;i<n;i++){
            if(visited[i] or arr[i].second==i){
                continue;
            }
            int j =i ;
            int cycle_size =0 ;
            while(not visited[j]){
                visited[j] = true ;
                j = arr[j].second;
                cycle_size++;
            }
            if(cycle_size>1){
                count+=(cycle_size-1);
            }
        }
        return count ;
    }
};