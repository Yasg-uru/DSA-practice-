class Solution {
public:
    vector<int>parent;
    vector<int>rank ;
    int find(int x){
        return parent[x]=(parent[x]==x)?x:find(parent[x]);
    }
    void Union(int x, int y ){
        int x_parent = find(x);
        int y_parent = find(y);
        if(x_parent==y_parent){
            return ;
        }
        if(rank[x_parent]>rank[y_parent]){
            parent[y_parent]=x_parent;
            
        }else if(rank[x_parent]<rank[y_parent]){
            parent[x_parent]=y_parent;
           
        }else{
             parent[y_parent]=x_parent;
            rank[x_parent]++; 
        }
    }
    bool equationsPossible(vector<string>& equations) {
        parent.resize(26);
        rank.resize(26, 1);
        for(int i=0;i<26;i++){
            parent[i]= i ;

        }
        for(string& s : equations){
            if(s[1]=='='){
                Union(s[0]-'a', s[3]-'a');

            }else{
                int parent_x = find(s[0]-'a');
                int parent_y = find(s[3]-'a');
                if(parent_x==parent_y){
                    return false;
                } 
            }
        }
    return true ;
    }
};