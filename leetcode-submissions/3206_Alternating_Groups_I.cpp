class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        int i = 0 ;
        int j = 1;
        int k = 2;
        int n = colors.size();
        if(colors.size()<3){
            return 0;
        }
        int count = 0 ;

        while(i<n){
            if(colors[i]!=colors[j] and colors[j]!=colors[k]){
                count++;
            }
            i++;
            k= (k==n-1)?0:k+1;
            j=(j==n-1)?0:j+1;

        }
        return count;
    }
};