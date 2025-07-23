function findOcurrences(text: string, first: string, second: string): string[] {
    const array:string[] = text.split(" ");
    const ans :string[]= [];
    const n = array.length;
    for(let i:number =0 ;i<n-2;i++){
        if(array[i]===first && array[i+1]===second){
           
                ans.push(array[i+2]);
            
        }
        
    }
    return ans ;
};