function singleNumber(nums: number[]): number {
    let result :number = 0 ;
    for(let bit:number =0 ;bit<=31;bit++){
        const temp:number = (1<<bit);
        let count_ones :number =0 , count_zeroes:number =0 ;
        for(const num of nums){
            if((num&temp)===0){
                count_zeroes++;
            }else{
                count_ones++;
            }
        }
        if(count_ones%3==1){
            result= (result | (1<<bit));
        }
       
    }
    return result ;
};