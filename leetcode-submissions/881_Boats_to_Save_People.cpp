class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        //now sorting this vector and we need to use the two pointer approach for solving this question 
        sort(people.begin(),people.end());
        int left=0;
        int right=people.size()-1;
        int boats=0;

        while(left<=right){
            if(people[left]+people[right]<=limit){
boats++;
        left++;
        right--;
            }
        else{
            right--;
            boats++;
        }
        }
return boats;
    }
};