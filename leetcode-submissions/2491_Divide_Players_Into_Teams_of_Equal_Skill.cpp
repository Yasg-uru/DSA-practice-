class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        // we need to find out the average of the all the skills 
        int n_2=skill.size()/2;
        long long sum=0;
        for(int ele:skill){
            sum+=ele;
        }
        //after finding the sum 
        int target_sum=sum/n_2;
        sort(skill.begin(),skill.end());
        long long chem=0;
        for(int i=0;i<n_2;i++){
            int l=skill[i],r=skill[skill.size()-1-i];
            if(l+r!=target_sum){
                return -1;
            }
            chem+=l*r;
        }
        return chem;
    }
};