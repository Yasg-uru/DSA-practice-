class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_set<string>suppliesLookup(begin(supplies), end(supplies));
        vector<string>ans;
        int n = recipes.size();
        int count =  n ;
    vector<int>isCooked(n, false);
       while(count--){
         for(int i=0;i<n;i++){
            if(isCooked[i]==true){
                continue;
            }
            //finding all the ingredients of the recipe
            bool isPossibleToCook= true;
            for(int j =0;j<ingredients[i].size();j++){
                if(suppliesLookup.find(ingredients[i][j])==suppliesLookup.end()){
                    isPossibleToCook=false;
                    break;
                }
            }
            if(isPossibleToCook==true){
                ans.push_back(recipes[i]);
                isCooked[i]= true ;
                suppliesLookup.insert(recipes[i]);
            }
        }
       }
        return ans ;
    }
};