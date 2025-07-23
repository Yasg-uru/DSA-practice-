function validateCoupons(code: string[], businessLine: string[], isActive: boolean[]): string[] {
    const validCoupons :{categoryIndex:number ; code :string ;}[] = [];
    const n : number = code.length;
    const categoryOrder:Record<string , number>= {
        electoronic :0 , grocery:1, pharmacy:2, restaurant:3
    };
    const buissnessSt:Set<string> = new Set(["electronics", "grocery", "pharmacy", "restaurant"]) ;
    for(let i:number =0 ;i<n;i++){
        if(code && isValid(code[i],businessLine[i], isActive[i],buissnessSt )===true){
            validCoupons.push({categoryIndex:categoryOrder[businessLine[i]], code : code[i]});
        }
    }
    validCoupons.sort((a, b)=>{
        if(a.categoryIndex!==b.categoryIndex){
            return a.categoryIndex-b.categoryIndex;
        }
        return a.code.localeCompare(b.code);
    });
    return validCoupons.map((coupon)=>coupon.code);
    
    
};
function isValid(code :string ,buissness:string  ,active:boolean, buissnessSt:Set<string>  ):boolean{
    const reg = /^[a-zA-Z0-9_]+$/;
    if(reg.test(code)===false){
        return false;
    }
    if(!buissnessSt.has(buissness)){
        return false;
    }
    if(!active){
        return false;
    }
    return true ;
}