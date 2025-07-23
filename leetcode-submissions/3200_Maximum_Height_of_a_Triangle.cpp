class Solution {
public:
    int maxHeightOfTriangle(int red, int blue) {
       int totalballs=red+blue;
       int currentheight=0;
       int maxhieght=0;
       while(totalballs>=currentheight+1){
        currentheight++;
        totalballs-=currentheight;
        if(totalballs>=currentheight){
            maxhieght++;
        }
       }
       return maxhieght;
    }
};