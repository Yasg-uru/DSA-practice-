class Solution {
public:
    string countOfAtoms(string formula) {
        //i am solving this question by using the stack approach and keeping track of the open bracket and close bracket and performing some operations of the string manupulation then we can solve this question easily 
        //first we need to create an stack of unordered_map or string and their count 
        stack<unordered_map<string,int>>st;
        //creating temporary map for holding the string that need to manupulate further if needed 
        unordered_map<string,int>currMap;
        int index=0;
        int n=formula.size();
        while(index<n){
            if(isupper(formula[index])){
                //first chacacter is uppercase then 
                string atom;
                 atom+=formula[index];
                index++;
                while(index<n and islower(formula[index])){
                    atom.push_back(formula[index]);
                    index++;

                }
                //now we get full atom that is a combination of the uppercase and lowercase characters

                int count =0;
                while(index<n and isdigit(formula[index])){
                    count=count*10+(formula[index]-'0');
                    index++;

                }
                count=max(count,1);
                //now storing the current atom with their frequency 
                currMap[atom]=count;


            }else if(formula[index]=='('){
//now open bracket is found then we need to skip this bracket 
index++;
//we need to push the current string to the main stack because all the operations are need to do on the string that is inside the ()
                st.push(currMap);
                currMap.clear();
//after that we need to do same operation on it
                string atom;
                 atom+=formula[index];
                index++;
                while(index<n and islower(formula[index])){
                    atom.push_back(formula[index]);
                    index++;

                }
                //now we get full atom that is a combination of the uppercase and lowercase characters

                int count =0;
                while(index<n and isdigit(formula[index])){
                    count=count*10+(formula[index]-'0');
                    index++;

                }
                count=max(count,1);
                //now storing the current atom with their frequency 
                currMap[atom]=count;

            }else if(formula[index]==')'){
//in this case we need to do same operation but we need to multiply the values of th atoms to the currentmap 

index ++; //skipping the ( character 

int count =0;
while(index<n and isdigit(formula[index])){
    count=count*10+(formula[index]-'0');
    index++;

}
count=max(count,1);
for(auto &element:currMap){
   element.second*=count;
}

if(not st.empty()){
    auto& prevmap=st.top();
    for(const auto& element:currMap){
        prevmap[element.first]+=element.second;

    } 
    currMap=prevmap;
    st.pop();
}
            }else{
                //increamenting the index to going toward the next character
                index++;

            }
        }
        string ans="";
        vector<string>arr;
        for(auto& element:currMap){
arr.push_back(element.first);
cout<<element.first<<" "<<element.second<<endl;

        }
        sort(arr.begin(),arr.end());
        for(string str:arr){
            ans+=str;
            if(currMap[str]>1){
                ans+=to_string(currMap[str]);
            }
        }
return ans;
    }
};