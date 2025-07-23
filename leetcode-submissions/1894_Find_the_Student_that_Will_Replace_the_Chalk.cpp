class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
       int totalchalk=0;
       for(int ch:chalk){
        totalchalk+=ch;
       }
       k=k%totalchalk;
       int i=0;
       while(true){
        if(k<=chalk[i]){
            return i;
        }
        k-=chalk[i];
        i=(i+1)%chalk.size();
       }
       return 0;
    }
};