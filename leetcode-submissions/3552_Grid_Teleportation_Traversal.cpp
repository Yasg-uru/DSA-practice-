class Solution {
public:
    typedef tuple<int , int , int > t;
    int minMoves(vector<string>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        
        priority_queue<t, vector<t>, greater<t>>pq;
        unordered_map<char , vector<pair<int , int >>>portalMap;
        unordered_set<char>used;
        vector<vector<int>>directions = { {0 , 1}, {1, 0 }, {0 , -1}, {-1, 0 }};
        vector<vector<int>>result(m , vector<int>(n , INT_MAX));
        result[0][0] = 0;
        
        pq.push({0, 0, 0 });
        for(int i =0;i<m;i++ ){
            for(int j =0 ;j<n;j++){
                if(isupper(matrix[i][j])){
                    portalMap[matrix[i][j]].push_back({i , j});
                }
            }
        }
        while(not pq.empty()){
            auto [currWeight , i , j]= pq.top();
            if(i==m-1 and j==n-1) return result[i][j];
            pq.pop();
            if(currWeight>result[i][j]) continue;
            for(auto& dir : directions){
                int i_ = dir[0]+i;
                int j_ = dir[1]+j;
                if(i_>=0 and j_>=0 and i_<m and j_<n and matrix[i_][j_]!='#'){
                    int totalWt= currWeight +1;
                    if(totalWt<result[i_][j_]){
                        pq.push({totalWt , i_ , j_});
                        result[i_][j_] = totalWt;
                    }
                }
            }
            char ch = matrix[i][j];
            if(isupper(ch) and not used.count(ch)){
                used.insert(ch);
                for(auto& portal :portalMap[ch]){
                    int x = portal.first;
                    int y = portal.second ;
                    if(x!=i and y!=j and result[x][y]>currWeight){
                        result[x][y] = currWeight;
                        pq.push({currWeight , x, y});
                    }
                }
            }
        }
        return -1;
        
    }
};