class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        bool flag=true;
        for(int  i=0;i<candyType.size();i++){
            for(int j=i+1;j<candyType.size();j++){
                if(candyType[i]!=candyType[j]){
                    flag=false;
                    break;
                }
            }
        }
        if(flag==true){
            return 1;
        }
        return (candyType.size()/2);
    }
};