class Solution {
public:
    double average(vector<int>& salary) {
        
       int averagesalary=0;
       sort(salary.begin(),salary.end());
       int count=0;
       for(int i=1;i<=(salary.size()-2);i++){
count++;
averagesalary+=salary[i];
cout<<salary[i]<<" ";
       } 
       if(count==0){
           return averagesalary;
       }
       return static_cast<double>(averagesalary/count);
    }
};