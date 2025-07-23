class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        set<pair<int,int>>obs;
        for(auto i:obstacles){
            obs.insert({i[0],i[1]});

        }
        //north east south west
        vector<vector<int>>directions={{0,1},{1,0},{0,-1},{-1,0}};
        int dir=0;
        int x_dir=0,y_dir=0;
int maxD=0;
        //initially in the north direction
        for(int ch:commands){
            if(ch==-1){
                dir=(dir+1)%4;
            }else if(ch==-2){
                 dir=(dir-1+4)%4;
            }else{

                for(int step=0;step<ch;step++){
                int x_local=x_dir+directions[dir][0];
                int y_local=y_dir+directions[dir][1];

                    if(obs.count({x_local,y_local})){
                        break;
                    }
                    x_dir=x_local;
                    y_dir=y_local;
                }
                
                maxD=max(maxD,x_dir*x_dir+y_dir*y_dir);
            }
        }
        return maxD;
    }
};