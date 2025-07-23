class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        if(k==1){
            return 'a';
        }
        int operationType ;
        int n = operations.size();
        int len = 1;
        int newK ;
        for(int i =0 ;i<n;i++){
            len*=2;// because each operations is making double length 
            if(len>=k){//current length of the string is crossed the k 
            newK = k-len/2;
            operationType = operations[i];
            break;
                
            }
        }
        char res = kthCharacter(newK , operations);
        if(operationType==0){
            return res ;
        }
        if(res=='z'){
            return 'a';
        }
        return (char)res+1;

    }
};