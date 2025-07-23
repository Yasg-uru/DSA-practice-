function dayOfTheWeek(day: number, month: number, year: number): string {
    const dt = new Date(`${year}-${month}-${day}`);
    const map : Map<number , string>= new Map(
   [ [0 , 'Sunday'], [1, "Monday"], [2, "Tuesday"],[3, "Wednesday"], [4, "Thursday"], [ 5,"Friday" ], [ 6, "Saturday"]]
    );
    
    const index = dt.getDay();
    return map.get(index);
};