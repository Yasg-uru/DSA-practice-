class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        int count =0 ;
        set<pair<int , int >>st;
        for(auto& building : buildings){
            st.insert({building[0], building[1]});
            
        }
        for(auto& building :buildings){
            int x = building[0], y = building[1];
            bool isLeftBoundaryPresent = false , isRightBoundaryPresent = false, isUpBoundaryPresent = false, isDownBoundaryPresent = false;
            for(int up = x-1 ;up>=1;up--){
                if(st.count({up, y})){
                    isUpBoundaryPresent = true ;
                    break ;
                }
                
            }
            for(int down = x+1;down<=n;down++){
                if(st.count({down , y})){
                    isDownBoundaryPresent = true ;
                    break ;
                    
                }
            }
            for(int left = y-1;left>=1;left--){
                if(st.count({x, left})){
                    isLeftBoundaryPresent = true ;
                    break ;
                }
                
            }
            for(int right = y+1;right<=n;right++){
                if(st.count({x, right})){
                    isRightBoundaryPresent = true ;
                    break;
                }
            }
            if(isLeftBoundaryPresent && isRightBoundaryPresent && isUpBoundaryPresent && isDownBoundaryPresent){
                count++;
            }
        }
        return count ;
    }
};