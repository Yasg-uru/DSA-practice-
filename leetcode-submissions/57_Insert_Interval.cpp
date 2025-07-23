class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
      //now we need to check the cases for inserting the newinterval
      int i=0;
      vector<vector<int>>ans;
      int n=intervals.size();
      while(i<n and intervals[i][1]<newInterval[0]){
          ans.push_back(intervals[i]);
          i++;

      }  
      //now we need to merge the intervals
      vector<int>merge=newInterval;
      while(i<n and intervals[i][0]<=newInterval[1]){
          merge[0]=min(merge[0],intervals[i][0]);
          merge[1]=max(merge[1],intervals[i][1]);
          i++;


      }
      ans.push_back(merge);
      while(i<n ){
          ans.push_back(intervals[i]);
          i++;
      }
      return ans;
    }
};