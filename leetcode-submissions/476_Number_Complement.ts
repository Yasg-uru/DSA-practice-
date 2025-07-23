function findComplement(num: number): number {
    // in typescript we have built in function for converting binary to decimal and decimal to binary 
    let binary:string =num.toString(2);
    //after that we need to flip it 
    let FlippedString:string="";

    for(let i=0;i<binary.length;i++){
        if(binary.charAt(i)==="1"){
           FlippedString+="0";

        }
        else{
           FlippedString+="1";
        }
    }
return parseInt(FlippedString,2);
};