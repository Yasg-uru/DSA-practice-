class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        //now we are writing the solution of this code by using the frequency approach
        int circlsandwich=0;
        int squaresandwich=0;
        for(int choice:students){
            if(choice==0){
                circlsandwich++;

            }else{
                squaresandwich++;
            }
        }
        for(int sandwich:sandwiches){
            if(sandwich==0 and circlsandwich==0){
                return squaresandwich;
            }else if(sandwich==1 and squaresandwich==0){
                return circlsandwich;
            }else{
                if(sandwich==0){
                    circlsandwich--;
                }else {
                    squaresandwich--;
                }
            }
        }
return 0;
    }
};