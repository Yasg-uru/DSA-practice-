class Solution {
public:
    int compareVersion(string version1, string version2) {
        //now solving this question in very optimized way 
        int l1=version1.size();
        int l2=version2.size();
        int p1=0,p2=0;
        while(p1<l1 or p2<l2){
            int num1=0;
            while(p1<l1 and version1[p1]!='.'){
                num1=num1*10+(version1[p1]-'0');
                p1++;
            }
            int num2=0;
            while(p2<l2 and version2[p2]!='.'){
                num2=num2*10+(version2[p2]-'0');
                p2++;
            }
            if(num1!=num2){
                return num1<num2?-1:1;
            }
            p1++;
            p2++;
        } 
        return 0;
    }
};