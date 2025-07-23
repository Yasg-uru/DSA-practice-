class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        // brute force 
        int ans =0;
        int n = s.length();
        for(int i=0;i<n;i++){
            int count0 =0 ;
            int count1= 0 ;

            for(int j=i;j<n;j++){
                if(s[j] == '0') {
                    count0++;
                } else {
                    count1++;
                }
               if (count1 <= k || count0 <= k) {
                    ans++;
                } else {
                    break; // No need to check further, this substring and beyond are invalid
                }

            }
        }
        return ans;
    }
};