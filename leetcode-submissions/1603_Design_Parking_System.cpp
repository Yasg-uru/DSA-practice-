class ParkingSystem {
public:
    int bigSize , mediumSize , smallSize ;
    int currCarsInBig , currCarsInmedium  , currCarsInsmall;
    ParkingSystem(int big, int medium, int small) {
        bigSize = big ;
        mediumSize = medium ;
        smallSize = small;
        currCarsInBig = currCarsInmedium  = currCarsInsmall  =0 ;
    }
    
    bool addCar(int carType) {
        if(carType==3 and currCarsInsmall<smallSize){
            currCarsInsmall++;
            return true ;
        }else if(carType==2 and currCarsInmedium<mediumSize){
            currCarsInmedium++;
            return true ;
        }else if(carType==1 and currCarsInBig<bigSize){
            currCarsInBig++;
            return true ;
        }else{
            return false;
        }
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */