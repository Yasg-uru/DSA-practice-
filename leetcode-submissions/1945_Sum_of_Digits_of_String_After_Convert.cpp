class Solution {
public:
    int getLucky(string s, int k) {
        string number="";

        for(int i=0;i<s.size();i++){
            int ch=s[i]-97;
            number+=to_string(ch+1);
            
        }
       int ans=0;
        while(k--){
            int num=0;
        for(int i=0;i<number.size();i++){
            num=num+(number[i]-'0');
        }
        number=to_string(num);

        }
        return stoi(number);
    }
};