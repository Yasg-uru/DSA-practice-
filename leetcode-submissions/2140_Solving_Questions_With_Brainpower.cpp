class Solution {
public:
    int n;
    int t[100001];
    long long solve(vector<vector<int>>& questions, int i ){
        if(i>=n) return 0 ;
        if(t[i]!=-1) return t[i];
        int take = questions[i][0]+solve(questions , i+questions[i][1]+1);
        int not_take = solve(questions , i+1);
        return t[i]=max(take , not_take);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        n = questions.size();
        memset(t, -1 , sizeof(t));
        return solve(questions , 0 );
    }
};