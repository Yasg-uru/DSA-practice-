class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        unordered_map<string , int >mp;
        queue<int >q;
        q.push(id);
        int l =0 ;
        unordered_set<int>visited;
        visited.insert(id);

        while(not q.empty()){
            int size = q.size();
            while(size--){
                int currNode = q.front() ;
                q.pop();
                if(l==level){
                    vector<string>temp = watchedVideos[currNode];
                    for(string& str : temp){
                        mp[str]++;
                    }
                }
                for(int& nbr :friends[currNode]){
                    if(not visited.count(nbr)){
                        visited.insert(nbr);
                        q.push(nbr);

                    }
                }
                

            }
            l++;
        }
        priority_queue<pair<int , string >, vector<pair<int , string>>, greater<pair<int, string>>>pq;
        for(auto& ele : mp)
        {
            pq.push({ele.second, ele.first});

        }
        vector<string>ans ;
        while(not pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();

        }
        return ans ;
    }
};