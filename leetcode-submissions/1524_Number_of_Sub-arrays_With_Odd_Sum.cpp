class Solution {
public:
    int M =1e9+7;
    int numOfSubarrays(vector<int>& arr) {
        // as we know odd+even = odd pr vice versa
        vector<int>prefix(arr.size(), 0);
        prefix[0]= arr[0];
        int even =1;
        int odd= 0 ;
        for(int i=1;i<arr.size();i++){
            prefix[i]= prefix[i-1]+arr[i];
        }
        int count = 0;
        for(int i=0;i<prefix.size();i++){
            if(prefix[i]%2==1){
                count = (count+even)%M;
                odd++;
            }else{
                count = (count+odd)%M;
                even++;
            }
        }
    return count ;
    }
};