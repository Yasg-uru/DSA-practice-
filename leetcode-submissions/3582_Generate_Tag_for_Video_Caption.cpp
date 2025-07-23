class Solution {
public:
    string generateTag(string caption) {
       string word = "";
        int i =0, n = caption.size() ;
        bool isFirst= true ;
        while(i<n){
            while(i<n and caption[i]==' '){
                i++;
                
            }
            int j = i ;
            
            while(j<n and caption[j]!=' '){
                j++;
            }
            string substr = caption.substr(i , j-i);
            if(isFirst){
                isFirst = false;
                for(char &ch :substr){
                    tolower(ch);
                }
                substr = "#"+substr;
                substr[1]= tolower(substr[1]);
                word+=substr;
            }else{
                string modified = "";
                for(char& ch :substr){
                    if(!isalpha(ch)){

                        continue;
                    }
                    modified+=tolower(ch);
                }
                modified[0]= toupper(modified[0]);
                word+=modified;
            }
            i= j ;
            
        }
        return word ;
    }
};