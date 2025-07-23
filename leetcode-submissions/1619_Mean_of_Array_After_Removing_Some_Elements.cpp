class Solution {
public:
    double trimMean(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        //now after sorting we need to remove the minimum and maximum 5% element from the array 
        int index=(int)(0.05*arr.size());
        for(int ele:arr){
            cout<<ele<<" ";
        }
        cout<<endl;
        int lastindex=arr.size()-index;
        arr.erase(arr.begin(),arr.begin()+index+1);
        arr.erase(arr.begin()+lastindex,arr.end());
        int sum=0;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
            cout<<arr[i]<<" ";
        }
        double ans=(double)(sum/arr.size());
        return ans;
    }
};