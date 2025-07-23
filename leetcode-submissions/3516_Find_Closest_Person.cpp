class Solution {
public:
    int findClosest(int x, int y, int z) {
        int distanceFromPerson1= abs(z-x);
        int distanceFromPerson2= abs(z-y);
        if(distanceFromPerson1==distanceFromPerson2){
            return 0 ;
        }
        return distanceFromPerson1>distanceFromPerson2?2:1;
    }
};