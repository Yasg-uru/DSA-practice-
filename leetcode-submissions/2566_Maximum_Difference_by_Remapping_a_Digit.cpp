class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);
        string maxS =s;
        for(char &ch : s)
        {
            if(ch!='9'){
                for(char& c :maxS){
                    if(c==ch){
                        c= '9';

                    }
                }
                break;
            }

        }
        string minS = s;
        for(char & ch : s){
            if(ch!='0'){
                for(char& c :minS){
                    if(c==ch){
                        c= '0';

                    }
                }
                break;
            }
        }
        return stoi(maxS)-stoi(minS);

    }
};