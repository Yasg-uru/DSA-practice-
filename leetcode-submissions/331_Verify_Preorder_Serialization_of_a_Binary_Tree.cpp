class Solution {
public:
    bool isValidSerialization(string preorder) {
        int vacancy=1;
        for(char node :preorder){
            if(node==',') continue;
            vacancy--;
            if(vacancy<0) return false;
            if(node!='#'){
                vacancy+=2;
            }
        }
        return vacancy==0;
    }
};