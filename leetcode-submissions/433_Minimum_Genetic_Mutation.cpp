class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string>bankSet(bank.begin(), bank.end());
        queue<string>q;
        unordered_set<string>visited;
        visited.insert(startGene);
        q.push(startGene);
        int level = 0;

        while(not q.empty()){
            int n = q.size();
            while(n--){
                string currString = q.front();
                q.pop();
                if(currString==endGene){
                    return level;
                }
                // we need to explore all the neghbours of the string 
                for(char ch : "ACGT"){
                    for(int i=0;i<currString.size();i++){
                        string neighbour= currString;
                        neighbour[i]= ch; // assigning A at a particular index of the currString and then C and then G and then T
                        if(visited.find(neighbour)==visited.end() and bankSet.find(neighbour)!=bankSet.end()){
                            visited.insert(neighbour);
                            q.push(neighbour);

                        }
                    }
                }
            }
            level++;

        }
        return -1;
    }
};