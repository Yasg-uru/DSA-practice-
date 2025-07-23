function lengthOfLastWord(s: string): number {
    let j:number =s.length-1;
    
    //this loop removes the spaces and move the pointer to the last index of the last word 
    while(j>=0){
        if(s[j]==" "){
            j--;
        }else{
            break;
        }
    }
    let i:number =j;
    while (i>=0)
    {
        if(s[i]==" "){
            break;
        }
        i--;

    }
    return j-i;
};