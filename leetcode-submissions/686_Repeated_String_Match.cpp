class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int maxRepeatCounts=b.size()/a.size()+1;
        string s ="";
        int maxCount=0;

        for(int i=0;i<maxRepeatCounts;i++){
            s+=a;
            maxCount++;

            if(s.find(b)!=std::string::npos){
                return maxCount ;
            }
        }
        return  -1;
    }
};