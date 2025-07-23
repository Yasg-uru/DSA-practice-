/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        queue<int>q;
        q.push(id);
        unordered_map<int  , Employee*>mp;
        unordered_set<int>visited;
        visited.insert(id);
        int n = employees.size();
        for(int i =0;i<n;i++){
            mp[employees[i]->id]= employees[i];
        }
        int totalImportance =0 ;
        
        while(not q.empty()){
            int currNode_id = q.front();
            q.pop();
            totalImportance+=mp[currNode_id]->importance;
            for(int nbrId : mp[currNode_id]->subordinates){
                if(not visited.count(nbrId)){
                    visited.insert(nbrId);
                    q.push(nbrId);
                    
                }
            }
            
        }
        return totalImportance;
    }
};