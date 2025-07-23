class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int number_of_lines =0 , curr_line_width =0 , n =s.length()  ;
        for(int i =0 ;i<n;i++){
            int currWidth = widths[s[i]-'a'];
        if(curr_line_width+currWidth>100){
                number_of_lines++;
                curr_line_width=currWidth ;
        }
        else{
            curr_line_width+=currWidth;
        }
        
            
        }
        if(curr_line_width>0){
            return {number_of_lines+1 , curr_line_width};
        }
        return {number_of_lines, curr_line_width};
    }
};