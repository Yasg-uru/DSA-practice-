function checkValidString(s: string): boolean {
    //now i am solving this question by using the array as stack 
    const open:number[]=[];
    const star:number[]=[];
    for(let i=0;i<s.length;i++){
        if(s.charAt(i)==="("){
            open.push(i);
        }
        else if(s.charAt(i)==="*"){
            star.push(i);
        }else{
if(open.length>0){
    open.pop();

}else if(star.length>0){
    star.pop();
}else{
    return false;
}
        }
    }
    while(open.length>0){
        if(star.length===0){
            return false;
        }else if(open[open.length-1]<star[star.length-1]){
            open.pop();
            star.pop();
        }else{
            return false;
        }
    }
return true ;
};