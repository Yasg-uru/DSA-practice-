class Solution {
public:
    int minOperations(vector<string>& logs) {
        int depth=0;
        for(string str:logs){
            if(str=="./"){
                continue;
            }else if(str=="../"){
                depth--;
                if(depth<0)depth=0;
            }else{
                depth++;
            }
        }
        return depth;
    }
};