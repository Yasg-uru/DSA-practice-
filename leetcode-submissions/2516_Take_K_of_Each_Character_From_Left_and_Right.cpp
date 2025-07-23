class Solution {
public:
    int takeCharacters(string s, int k) {
        int i=0,j=0;
        int notDeletedMaxWindow=0;
     
        int count_a=0,count_b=0,count_c=0;
        for(char &c:s){
            switch(c){
                case 'a':
                    count_a++;
                    break;
                case 'b':
                    count_b++;
                    break;
                case 'c':
                    count_c++;
                    break;
            }
        }
        if(count_a<k || count_b<k || count_c<k){
            return -1;

        }
        while(j<s.size()){
            // we need to maximize the window size of the characters that will not be deleted 
            switch(s[j]){
                case 'a':
                    count_a--;
                    break;
                case 'b':
                    count_b--;
                    break;
                case 'c':
                    count_c--;
                    break;
            }
            while(i<=j and (count_a<k or count_b<k or count_c<k )){
                // we need to move ith pointer to increase the count of the characters
            switch(s[i]){
                case 'a':
                    count_a++;
                    break;
                case 'b':
                    count_b++;
                    break;
                case 'c':
                    count_c++;
                    break;
            }
            i++;
            }
            notDeletedMaxWindow=max(notDeletedMaxWindow,j-i+1);
            j++;
        }
        return s.size()-notDeletedMaxWindow;

    }
};