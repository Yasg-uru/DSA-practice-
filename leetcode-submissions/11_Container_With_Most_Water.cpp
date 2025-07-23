class Solution {
public:
    int maxArea(vector<int>& height) {
        //now using two pointer approach
        int s=0;
        int e=height.size()-1;
        int ans=0;
        while(s<e){
         int area=min(height[s],height[e])*(e-s);
         ans=max(area,ans);
         if(height[s]>height[e]){
             e--;
         }
         if(height[s]<=height[e]){
             s++;
         }   

        }
        return ans;
    }
};