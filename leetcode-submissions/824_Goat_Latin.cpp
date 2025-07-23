class Solution {
public:
    bool isVowel(char ch ){
return ch=='a' or ch=='e' or ch=='i' or ch=='o' or ch=='u';}
    string toGoatLatin(string sentence) {
        string adder = "", ans = "";
        int i =0, n = sentence.size();
        while(i<n){
            adder+="a";
            int j =i;
            while(j<n and sentence[j]!=' '){
j++;}
            string word= sentence.substr(i , j-i);
            if(isVowel(word[0])){
                word+="ma";
                word+=adder;
            }else{
                char firstCh = word[0];
                word.erase(0 ,1);
                word.push_back(firstCh);
                word+="ma";
                word+=adder;
            }
            ans+=word;
            ans+=" ";
            
            i = j+1;
        }
        return ans ;
    }
};