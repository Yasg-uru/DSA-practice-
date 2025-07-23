class Solution {
public:
    bool checkIfLeftRemoval(string &s , char ch , int index ){
        bool isLeftRemovalDone = false;
        while(true){
            if(index==0){
                isLeftRemovalDone= true ;
            }
            if(s[index]==ch){
                s.erase(s.begin()+index);
                //shifting of the index is done 

                break;
            }
            index = (index+1)%s.length();
        }
        return isLeftRemovalDone ;

    }   
    string predictPartyVictory(string senate) {
        int n = senate.size();
        int R_count = count(senate.begin(), senate.end(), 'R');
        int D_count = senate.size()- R_count ;
        int i =0 ;

        while(R_count>0 and D_count>0){
        if(senate[i]=='R'){
            bool isLeftRemovalDone  = checkIfLeftRemoval(senate, 'D', (i+1)%senate.length());
            if(isLeftRemovalDone){
                i--;
            }
            D_count--;

        }   else{
             bool isLeftRemovalDone  = checkIfLeftRemoval(senate, 'R', (i+1)%senate.length());
            if(isLeftRemovalDone){
                i--;
            }
            R_count--;
        } 
        i= (i+1)%senate.length();
        }
        return R_count==0?"Dire":"Radiant";
    }
};