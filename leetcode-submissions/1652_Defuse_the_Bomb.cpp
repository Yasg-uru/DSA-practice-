class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int>ans(code.size(),0);
        if(k==0){
            return ans ;
        }
        if(k>0){
            for(int i=0;i<code.size();i++){
                int count =0;
                int j=(i+1)%code.size();
                int temp=0;
                while(count<k){
                    count++;
                 
                   
                    temp+=code[j];
                    j=(j+1)%code.size();
                    
                }
                ans[i]=temp;
            }
        }else if(k<0){
            for(int i=0;i<code.size();i++){
                int count =0;
                int j=(i-1+code.size())%code.size();
                int temp=0;
                while(count<abs(k)){
                    count++;
                    
                    temp+=code[j];
                    j=(j-1+code.size())%code.size();
                }
                ans[i]=temp;
            }
        }
        return ans;
    }
};