class Solution {
public:
    int n;
    int t[100001][3];
    int binarySearch(vector<vector<int>>&events ,int endTime){
        int result=n;
        int left=0;
        int right=n-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(events[mid][0]>endTime){
                result=mid;
                right=mid-1;
            }else{
                left=mid+1;

            }
        }
    return result;
    }
    int solve(vector<vector<int>>&events,int index,int count ){
        if(count ==2 or index>=n){
            return 0;

        }
        if(t[index][count]!=-1){

        return t[index][count];
        } 
        // we have two choices 
        // take the current or skip the current 
        int nextValidIndex=binarySearch(events,events[index][1]);
        int take=events[index][2]+solve(events,nextValidIndex,count+1);
        int not_take=solve(events,index+1,count);
        return t[index][count]=max(take,not_take);


    }
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end());
        int count=0;
        n=events.size();
    memset(t,-1,sizeof(t));
        return solve(events,0,count);
    }
};