class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string target="123450";
        string start="";
        for(int i=0;i<2;i++){
            for(int j=0;j<3;j++){
                start+=to_string(board[i][j]);
            }

        }
        queue<string>q;
        q.push(start);
        unordered_set<string>visited;
        visited.insert(start);

        unordered_map<int,vector<int>>mp;
        mp[0]={1,3};
        mp[1]={0,2,4};
        mp[2]={1,5};
        mp[3]={0,4};
        mp[4]={1,3,5};
        mp[5]={4,2};
        int level=0;
        while(not q.empty()){
            int currentSize=q.size();
            while(currentSize--){
                string curr=q.front();
                q.pop();
                if(curr==target){
                    return level;
                }
                int indexOfZero=curr.find('0');
                for(int idx:mp[indexOfZero]){
                    // we need to swap zeros with possible moves and then mark it as visited 
                    string newState=curr;
                        swap(newState[idx],newState[indexOfZero]);
                        if(visited.find(newState)==visited.end()){
                            // we need to mark it as visited and  push it to the queue
                            q.push(newState);
                            visited.insert(newState);

                        }
                }
            }
            level++;
        }
        return -1;
    }
};