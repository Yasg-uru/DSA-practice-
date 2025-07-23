class Solution {
public:
    long long calculateScore(vector<string>& instructions, vector<int>& values) {
        int score =0 ;
        int n = instructions.size();
        int i =0 ;
        vector<bool>visited(n , false);
        while(i<n and i>=0 and not visited[i]){
            visited[i] = true ;
            if(instructions[i]=="jump"){
                int prev = i;
                i = i+values[i];
                if(prev==i){
                    break;
                }                
            }else{
                
                score+=values[i];
                i++;
            }
            
            
        }
        return score ;
    }
};