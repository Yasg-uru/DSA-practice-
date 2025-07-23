class Solution {
public:
    int trap(vector<int>& height) {
        // i have an appraoch that can able to solve that question now solving this question by uisng the two arrays right maximum and left maximum
        vector<int>leftmax(height.size());
        vector<int>rightmax(height.size());
        int leftmaxele=INT_MIN;
        for(int i=0;i<height.size();i++){
            leftmaxele=max(leftmaxele,height[i]);
            leftmax[i]=max(leftmaxele,height[i]);

        } 
        int rightmaxele=INT_MIN;
        for(int i=height.size()-1;i>=0;i--){
            rightmaxele=max(rightmaxele,height[i]);
            rightmax[i]=max(rightmaxele,height[i]);

        }
        int ans=0;
        for(int i=0;i<height.size();i++){
            ans+=(min(rightmax[i],leftmax[i])-height[i]);
        }
        return ans;
    }
};