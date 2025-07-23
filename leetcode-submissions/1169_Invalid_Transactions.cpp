class Solution {
public:
    vector<string> invalidTransactions(vector<string>& transactions) {
        vector<string>ans ;
        int n = transactions.size();
        for(int i =0;i<n;i++){
              string name_i, timeStr_i, amountStr_i, city_i;

                stringstream ss(transactions[i]);  // create stringstream
                getline(ss, name_i, ',');       // first token
                getline(ss, timeStr_i, ',');    // second token
                getline(ss, amountStr_i, ',');  // third token
                getline(ss, city_i, ',');       // last token

                int time_i = stoi(timeStr_i);     // convert string to int
                int amount_i = stoi(amountStr_i);
            for(int j = i+1;j<n;j++){
             string name_j, timeStr_j, amountStr_j, city_j;

                stringstream ss(transactions[j]);  // create stringstream
                getline(ss, name_j, ',');       // first token
                getline(ss, timeStr_j, ',');    // second token
                getline(ss, amountStr_j, ',');  // third token
                getline(ss, city_j, ',');       // last token

                int time_j = stoi(timeStr_j);     // convert string to int
                int amount_j = stoi(amountStr_j);
                int timeDiff = (time_j-time_i);
                if(timeDiff<=60 and city_j!=city_i){
                    ans.push_back(transactions[i]);
                    ans.push_back(transactions[j]);
                }else if(amount_j>1000){
                    ans.push_back(transactions[j]);
                }else if(amount_i>1000){
                    ans.push_back(transactions[i]);
                }
        }
        }
        return ans ;
    }
};