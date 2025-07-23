class Solution {
public:
    int rotatedDigits(int n) {
        unordered_map<int , int >mp;
        mp[2]= 5;
        mp[6] =9 ;
        mp[5] = 2;
        mp[9] = 6;
        int count =0 ;
        for(int i =1;i<=n;i++){
            int originalNumber = i ;
            string str = to_string(originalNumber);
            string convertedNumber ="";
            for(char ch : str){
                int num = ch-'0';
                if(mp.find(num)!=mp.end()){
                    char con = mp[num];
                    convertedNumber.push_back(con);
                    
                }else{
                convertedNumber.push_back(ch);
                }
            }
            if(str!=convertedNumber){
                count++;
            }
        }
        return count ; 
    }
};