function compressedString(word: string): string {
    let count :number =1;

    let ans:string ="";
    //after that we need 

    for(let i:number =0;i<word.length;i++){
        if(i<word.length-1 && word[i]===word[i+1] && count!==9){
            count++;
        }else{
            ans+=`${count}${word[i]}`;
            count =1;
        }
    }
    return ans;
};