class Solution {
public:
bool canweplace(int mid,vector<int>&position,int m){
    int lastelement=position[0];
    int count=1;
    for(int i=1;i<position.size();i++){
        if(position[i]-lastelement>=mid){
            lastelement=position[i];
            count++;

        if(count>=m){
            return true;
        }
        }
    }
    return false;

}
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int left=1;
        int n=position.size();
        int right=position[n-1]-position[0];
        int ans=0;
      
        while(left<=right){
            int mid=left+(right-left)/2;
if(canweplace(mid,position,m)){
    ans=mid;
    left=mid+1;

}else{
    right=mid-1;
}

        }
        return ans;
    }
};