class Solution {
public:
    bool solve(int i, int n , vector<int>&result, vector<bool>&isUsed){
        if(i>=result.size()) return true ;
        // we need to run a loop and then check trying to place the numbers at higher as possible 
        if(result[i]!=-1) {
            return solve(i+1, n , result, isUsed);
        }
        for(int num= n ;num>=1;num--){
            //trying 
            if(isUsed[num]) continue; // dont do anything
            result[i]=num ;
            isUsed[num]=true ;
              //exploring 
            if(num==1){
                if(solve(i+1,n, result, isUsed)){
                    return true ;
                }
            } else {
                int j = result[i]+i;
                if(j<result.size() and result[j]==-1){
                    result[j]= num;
                    if(solve(i+1, n , result, isUsed)){
                        return true;
                    }
                result[j]=-1;
                }
            }
          
            // reverting 
            result[i]=-1;
            isUsed[num]=false; 
        }
        return false;
    }
    vector<int> constructDistancedSequence(int n) {

        // as we know the largest lexicographically sequence is built by placing the largest number in the start of the sequence
        // and also the size of the result will become n*2-1 because we need to include 1 at once 
        // and another step is that if we are not found the correct answer then return false because if reduces the calls 
        // and also we need to check if the index exceeds the result length then return result because we made the sequence in the ccorrect order 
        vector<int>result(n*2-1, -1);
        vector<bool>isUsed(n+1, false);
        solve(0 ,n, result , isUsed);
        return result ;
    }
};