class Solution {
public:
    int pivotInteger(int n) 
    {
        
        vector<int> left(n+1);
        vector<int> right(n+1);
        
        int total = 0;
        
        for(int i=1;i<=n;i++)
        {
            total += i;
        }
        
        left[0] = 0;
        right[0] = 0;
        for(int i=1;i<=n;i++)
        {
            left[i] = i + left[i-1];
            right[i] = total - left[i-1];
            
            if(left[i]==right[i]) return i;
        }
        return -1;
    }
};