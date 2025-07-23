class Solution {
public:
    string getEncryptedString(string s, int k) {
        
        //if we want circular indexing then we need to use modulo operator for this 
        int n=s.size();
        string encrpted(n,' ');

        for(int i=0;i<s.size();i++){
       int calculated_index=(i+k)>=s.size()?(i+k)-s.size():(i+k);
    encrpted[i]=s[calculated_index];

        }
        return encrpted;
    }
};