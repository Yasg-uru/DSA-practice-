class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int count =0;

        for(int i=low;i<=high;i++){
            string str = to_string(i);
            if(str.length()%2==1){
                continue;
            }
            int mid = (str.length()-1)/2;
            string s1= str.substr(0 ,mid+1);
            string s2= str.substr(mid+1);
            int firstSum =0, lastSum = 0 ;
            for(char ch:s1){
                firstSum+=(ch-'0');
            }
            for(char ch:s2){
                lastSum+=(ch-'0');
            }
            count+=(firstSum==lastSum);
        }
        return count ;
    }
};