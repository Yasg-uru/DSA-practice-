function secondsToRemoveOccurrences(s: string): number {
    let operations :number =0 ;
    
    while(s.indexOf("01")!=-1){
        operations++;
        s = s.replaceAll("01", "10");
    }
    return operations ;
};