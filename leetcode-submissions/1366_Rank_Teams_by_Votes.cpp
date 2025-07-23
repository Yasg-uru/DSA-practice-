class Solution {
public:
    string rankTeams(vector<string>& votes) {
        int wordsLength = votes[0].size();
        int n = votes.size();
       vector<vector<int>>freq(26 , vector<int>(wordsLength));
       for(int i =0;i<n;i++){
            for(int j = 0 ;j<votes[i].size();j++){
                freq[votes[i][j]-'A'][j]+=1;
            }
       }
        string teams = votes[0];

        sort(begin(teams), end(teams), [&](char&a, char&b){
            for(int i =0 ;i<wordsLength;i++){
                if(freq[a-'A'][i]!=freq[b-'A'][i]){
                    return freq[a-'A'][i]>freq[b-'A'][i];
                }
            }
            return a<b;
        });
        return teams ;

    }
};