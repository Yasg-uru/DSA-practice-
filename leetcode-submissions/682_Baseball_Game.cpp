class Solution {
public:
  bool isNumber(string s) {
    int i = 0;
    if (s[i] == '-' && s.size() > 1) i++; 
    for (; i < s.size(); i++) {
        if (!isdigit(s[i])) return false;
    }
    return true;
}

    int calPoints(vector<string>& operations) {
        stack<string>st;
        for(int i=0;i<operations.size();i++){
            if(isNumber(operations[i])){
                st.push(operations[i]);
            }
            else if(operations[i]=="D"){
                string top = st.top();
                int num = stoi(top);
                st.push(to_string(num*2));

            }else if (operations[i]=="+"){
               if (st.size() < 2) continue; // Prevent popping if less than two elements

    string num1 = st.top(); st.pop();
    string num2 = st.top(); st.pop();

    st.push(num2);  // Push back second last element
    st.push(num1);  // Push back last element

    int n1 = stoi(num1);
    int n2 = stoi(num2);
    st.push(to_string(n1 + n2));  // Push sum
            }else if(operations[i]=="C" and not st.empty()) {
                st.pop();
            }
        }
        int ans =0;
        while(not st.empty()){
            ans+=stoi(st.top());
            st.pop();
        }
        return ans ;
    }
};