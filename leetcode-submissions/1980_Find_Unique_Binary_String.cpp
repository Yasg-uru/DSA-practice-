class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<int>s;
        for(int i=0;i<nums.size();i++){
            int n =stoi(nums[i], nullptr, 2);
            s.insert(n);
        }
        for(int num =0;num<= nums.size();num++){
            if(not s.count(num)){
                string temp = bitset<16>(num).to_string();
                return temp.substr(16-nums.size());
            }
        }
        return "";
    }
};