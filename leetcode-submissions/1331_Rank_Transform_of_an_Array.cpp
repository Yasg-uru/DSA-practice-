class Solution {
public:

    vector<int> arrayRankTransform(vector<int>& arr) {
     set<int>s(arr.begin(),arr.end());
     //after this we need to store it in array 
     vector<int>temp(s.begin(),s.end());
     vector<int>ans(arr.size());
     for(int i=0;i<arr.size();i++){
        for(int j=0;j<temp.size();j++){
            if(arr[i]==temp[j]){
                ans[i]=j+1;
            }
        }
     }
     return ans;

    }
};