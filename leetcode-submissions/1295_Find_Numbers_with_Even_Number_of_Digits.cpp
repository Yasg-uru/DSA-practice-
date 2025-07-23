class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count =0 ;
        for(int& n : nums){
            string str = to_string(n);
            if(str.length()%2==0){
                count++;
            }
        }
        return count ;
    }
};