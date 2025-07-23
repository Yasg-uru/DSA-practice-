class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char, int >mp;
        int deletions_count =0 ;
        for(char ch : s){
            mp[ch]++;
        }
        unordered_set<int >used_frequencies ;
        for(auto& ele : mp){
            int freq = ele.second ;
            while(freq>0 and used_frequencies.find(freq)!=used_frequencies.end()){
                freq--;
                deletions_count++;
            }
            used_frequencies.insert(freq);

        }
        return deletions_count ;
    }
};