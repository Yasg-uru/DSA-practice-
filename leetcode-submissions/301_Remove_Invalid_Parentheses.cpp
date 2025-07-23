class Solution {
public:
    bool isValid(string s){
        int count =0 ;
        for(int i =0 ;i<s.length();i++){
            if(s[i]=='('){
                count++;
            }else {
                if(count==0){
                    return false;
                }
                count--;
            }
        }
        return count==0;
    }
    vector<string> removeInvalidParentheses(string s) {
        
        queue<string>q;
        unordered_set<string>visited;
        vector<string>result;
        bool isFound = false;
        q.push(s);
        visited.insert(s);
        while(not q.empty()){
            string curr = q.front();
            q.pop();
            if(isValid(curr)){
                isFound  = true ;
                result.push_back(curr);
            }
            if(isFound == true ){
                continue ;
            }
            for(int i =0 ;i<curr.size();i++){
                if(curr[i]!=')' and  curr[i]!='('){
                    continue;
                }
                // we want to skip the or remove the ith character or bracket 
                string part = curr.substr(0 , i)+ curr.substr(i+1);
                if(not visited.count(part)){
                    visited.insert(part);
                    q.push(part);
                }
            }
        }
    return result ;
        
    }
};