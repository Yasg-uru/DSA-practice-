function lemonadeChange(bills: number[]): boolean {
    //now we need to declare the 3 variables 
    let a=0,b=0,c=0;
    for(let bill of bills ){
        if(bill===5){
            a++;
        }
        if(bill===10){
            if(a>0){
                a--;
            }else{
                return false;
            }

            b++;
        }
        if(bill===20){
            c++;
            if(b!==0 && a!==0){
                b--;
                a--;

            }else if (b===0 && a>=3){
                a-=3;
            }else{
                return false;
            }
        }
    }
        return true ;
};