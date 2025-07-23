class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // we need to find the left smaller and right smaller for the particular index and then calculate the area and update the maxarea so this question will become easy to solve 
        // we need to take two array 
        int n =heights.size();
        vector<int>leftSmaller(n, -1);
        vector<int>rightSmaller(n);
        //after this we need to calculate and fill this by using the stack 
        stack<int>st;
        for(int i=0;i<heights.size();i++){
            int currHeight =heights[i];

            if(not st.empty() and currHeight<=heights[st.top()]){
                st.pop();// because we need to reduce the level because the current height is smaller than the previous 

            }
            
            
                leftSmaller[i]=st.empty()?-1:st.top();//assigning previous height 
            
            st.push(i);

        }
        //for right 
        while(not st.empty()) st.pop();
        for(int i=n-1;i>=0;i--){
            int currentHeight = heights[i];
            while(not st.empty() and currentHeight<= heights[st.top()]){
                st.pop();

            }
            rightSmaller[i]=st.empty()?n:st.top();
            st.push(i);
        }
        int maxArea  = 0;
        for(int i=0;i<n;i++)
        {
            int width = rightSmaller[i]-leftSmaller[i]-1;
            maxArea= max(maxArea, heights[i]*width);
        }
        return maxArea;

    }
};