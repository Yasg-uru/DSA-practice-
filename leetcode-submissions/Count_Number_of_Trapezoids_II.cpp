class Solution {
public:
    pair<int , int >getSlope(vector<int>&point1 , vector<int>&point2){
        int x = point2[1]-point1[1];
        int y = point2[0]-point1[0];
        if(x==0) return {1, 0};
        if(y == 0 ){
            return {0 , 1};
        }
        int commonDiv = gcd(y, x);
        y/=commonDiv;
        x/=commonDiv;
        if(x<0){
            x=-x;
            y=-y;
        }
        return {y, x};
    }
    int countTrapezoids(vector<vector<int>>& points) {
        int n = points.size();
        if(n<4){
            return 0 ;
        }
        map<pair<int , int >, int >SCounts ;
        for(int i =0 ;i<n;i++){
            for(int j = i+1;j<n;j++){
                SCounts[getSlope(points[i], points[j])]++;
                
            }
        }
        long long totalPpairs = 0 ;
        for(auto [s, freq]:SCounts){
            totalPpairs+=(long long )freq*(freq-1);
            
        }
        long long overlappingP= 0 ;
        for(int i =0 ;i<n;i++){
                map<pair<int , int >, int >LocalScopeC;
            for(int j =0 ;j<n;j++){
                
                    if(i==j){
                        continue ;
                    }
                    LocalScopeC[getSlope(points[i], points[j])]++;
                

            }
                            for(auto [s, freq]:LocalScopeC){
                overlappingP+=(long long )freq*(freq-1)/2;
                
            }

        }
        return totalPpairs;
    }
    
};