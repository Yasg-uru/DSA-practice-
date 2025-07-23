class MyCalendar {
    bookings:{s:number,e:number}[]=[];
    constructor() {
        
    }

    book(start: number, end: number): boolean {
        for(const booking of this.bookings){
            if(Math.max(start,booking.s)<Math.min(booking.e,end)){
                return false;
            }
        }
        this.bookings.push({s:start,e:end});
        return true;
    }
}

/**
 * Your MyCalendar object will be instantiated and called as such:
 * var obj = new MyCalendar()
 * var param_1 = obj.book(start,end)
 */