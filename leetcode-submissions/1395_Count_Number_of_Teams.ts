function numTeams(rating: number[]): number {
    let ans:number=0;

    for(let i=0;i<rating.length;i++){
        let left_smaller=0,right_smaller=0,right_greater=0,left_greater=0;
        for(let j=i-1;j>=0;j-- ){
            if(rating[i]>rating[j]){
                left_smaller++;
            }else{
                left_greater++;
            }
        }
        for(let j=i+1;j<rating.length;j++){
            if(rating[j]>rating[i]){
                right_greater++;
            }else{
                right_smaller++;
            }
        }
        ans+=(left_smaller*right_greater)+(right_smaller*left_greater);
    }
    return ans;
};