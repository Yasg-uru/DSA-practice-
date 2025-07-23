class Solution {
public:
    int candy(vector<int>& ratings) {
        //for solving this question we need to calculate the left and right choice of the child for distributing the candy according to their preference 
        vector<int>left(ratings.size(),1);
        vector<int>right(ratings.size(),1);
        //now we need to calculate based on their preference 
        for(int i=1;i<ratings.size();i++){
            if(ratings[i-1]<ratings[i]){
               left[i]=left[i-1]+1;
            }
        }
        
         for(int i=ratings.size()-2;i>=0;i--){
            if(ratings[i]>ratings[i+1]){
                right[i]=right[i+1]+1;
            }
        }
        int ans=0;
for(int i=0;i<ratings.size();i++){
    ans+=max(right[i],left[i]);
}
return ans ;
    }
};