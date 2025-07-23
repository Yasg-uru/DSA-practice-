class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string strs = to_string(num);
        int ans = 0;
        int start = 0;
       
        for (int end = 0; end < strs.size(); end++) {
            if ((end - start + 1) > k) {
               
                start++;
            }
            if ((end - start + 1) == k) {
                string tempstr = strs.substr(start, end );
                cout << tempstr << " ";
                int n = stoi(tempstr);
                if(n!=0 and num%n==0){
                    ans++;
                }
                start++;
                
            }
        }
        return ans;
    }
};
