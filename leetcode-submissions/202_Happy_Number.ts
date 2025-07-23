function isHappy(n: number): boolean {
    const set:Set<number>= new Set();
    while(true){
        let sum :number =0;
        while(n>0){
            let lastDigit:number = n%10;
            let sq:number = lastDigit*lastDigit;
            sum+=sq;
            n = Math.floor(n / 10);

        }
        if(set.has(sum)) return false;
        set.add(sum);
        if(sum===1) return true;
        n=sum;
    }
    return true;
};