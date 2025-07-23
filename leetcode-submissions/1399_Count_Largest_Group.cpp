class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map<int , int >mp ;
        int maxSize =0, count =0  ;

        for(int i=1;i<=n;i++){
            int num = i ;
            int sum =0 ;

            while(num>0){
                sum+=(num%10);
                num/=10;
            }
            mp[sum]++;
            maxSize = max(maxSize , mp[sum]);
        }
        for(auto& ele:mp){
            if(ele.second==maxSize){
                count++;
            }
        }
        return count ;

    }
};