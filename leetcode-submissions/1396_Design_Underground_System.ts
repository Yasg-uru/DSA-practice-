class UndergroundSystem {
    checkIns:Map<number , [string , number]>= new Map(); // id ->{stationName , checkInTime}
    travelTime : Map<string , [number , number]> = new Map(); // {startStattion-endStation} -> [tripCount , totalTime]
constructor() {
        
    }

    checkIn(id: number, stationName: string, t: number): void {
        this.checkIns.set(id, [stationName , t]);

    }

    checkOut(id: number, stationName: string, t: number): void {
        if(!this.checkIns.has(id)) return ;
        
        const [startStation, startTime]= this.checkIns.get(id)!;
        const key:string  = `${startStation}-${stationName}`;
        if(!this.travelTime.has(key)){
            this.travelTime.set(key , [0 , 0 ]);
            
        }
const totalTime : number = t - startTime;
        const [prevTripCount , prevTotalTime ]= this.travelTime.get(key);
        this.travelTime.set(key , [prevTripCount+1, prevTotalTime+totalTime]);
    }

    getAverageTime(startStation: string, endStation: string): number {
         const key:string  = `${startStation}-${endStation}`;
         if(!this.travelTime.has(key)){
         return 0 ;
         }
        const [tripCount , totalTime]= this.travelTime.get(key);
        return totalTime/tripCount;
    }
}

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * var obj = new UndergroundSystem()
 * obj.checkIn(id,stationName,t)
 * obj.checkOut(id,stationName,t)
 * var param_3 = obj.getAverageTime(startStation,endStation)
 */