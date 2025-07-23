function getLucky(s: string, k: number): number {
    let number:string="";
    for(const ele of s){
        let ch=ele.charCodeAt(0)-97;
        number+=`${ch+1}`;

    }
    while(k--){
        let num=0;
        for(const ele of number){
            num+=parseInt(ele);
        }
        number=num.toString();
    }
    return parseInt(number);
};