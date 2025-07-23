function minimumSteps(s: string): number {
    let  counter=0;
        let answer=0;
        for(let  i=s.length-1 ;i>=0;i--){
            if(s.charAt(i)==="0"){
                counter++;
            }else{
                answer+=counter;
            }
        }
        return answer;
};