class Solution {
public:
    int maximumSwap(int num) {
       string str=to_string(num);
       //after this we need to create two variables to be swaped 
       int first=-1;
       int second=-1;
       int maxIndex=str.size()-1;
       for(int i=str.size()-1;i>=0;i--){
    if(str[i]>str[maxIndex]){
        maxIndex=i;
    }
    //after that we need to check wether the most smallest number is exist or not 
    if(str[i]<str[maxIndex]){
        first=i;
        second=maxIndex;

    }

       }
       if(first==-1){
        return num;
       }
       swap(str[second],str[first]);
       return stoi(str);
    }
};