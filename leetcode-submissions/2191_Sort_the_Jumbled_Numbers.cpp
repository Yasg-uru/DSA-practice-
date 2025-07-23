class Solution {
public:
int findIndex(vector<int>&nums,int ele){
    for(int i=0;i<nums.size();i++){
        if(nums[i]==ele){
    return i;
           
        }
    }
    return -1;
}
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int i=0;i<mapping.size();i++){
            mp[i]=mapping[i];
        }
        //after this we need to travers in nums array 
        multiset<pair<int,int>>digitmap;
       
        for(int i=0;i<nums.size();i++){
            string number=to_string(nums[i]);
            string temp="";
            for (char ch:number){
               int mapedDigit=mp[ch-'0'];
               temp.push_back(mapedDigit+'0');
            }
            int convertedTemp=stoi(temp);
            digitmap.insert({convertedTemp,i});
            
        }
        vector<int>ans;
        for(auto ele:digitmap){
            ans.push_back(nums[ele.second]);
        }
return ans;
    }
};