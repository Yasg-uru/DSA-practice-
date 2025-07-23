class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
      //steps to solve this question by easily using priority queue 
      // 1 . we need to calculate the delta values after adding the extrastudents to it 
      // 2 . adding maxdelta values student to the class 
      // 3 . update the delta values after assiging

      priority_queue<pair<double ,int>>pq;
      for(int i=0;i<classes.size();i++){
        double current_PR=(double)classes[i][0]/classes[i][1];
        double new_PR=(double)(classes[i][0]+1)/(classes[i][1]+1);
        double delta_value=new_PR-current_PR;

    pq.push({delta_value,i});
      }
      while(extraStudents--){
        auto curr=pq.top();
        pq.pop();
        //fetching the max delta values for assigining the new student 
        int index=curr.second ;
        // int delta_value=curr.first;
        classes[index][0]++;
        classes[index][1]++;
         double current_PR=(double)classes[index][0]/classes[index][1];
        double new_PR=(double)(classes[index][0]+1)/(classes[index][1]+1);
        double delta_value=new_PR-current_PR;
        pq.push({delta_value,index});
      }
      double result=0.0;

      for(int i=0;i<classes.size();i++){
        result +=(double )classes[i][0]/classes[i][1];
      }
      return result /classes.size();
    }
};