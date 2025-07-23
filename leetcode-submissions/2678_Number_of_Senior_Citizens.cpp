class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ans=0;
        for(int i=0;i<details.size();i++){
            string s=details[i];
        int digit=stoi(s.substr(11,2));
        if(digit>60){
            ans+=1;
        }

        }
        return ans;
    }
};