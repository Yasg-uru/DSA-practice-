function dividePlayers(skill: number[]): number {
    let n_2=skill.length/2;
    let sum=skill.reduce((acc,s)=>acc+s,0);
    let target_sum=sum/n_2;
    let chem=0;
    skill.sort((a,b)=>b-a);
    for(let i=0;i<n_2;i++){
        let l=skill[i],r=skill[skill.length-1-i];
        if(l+r!=target_sum){
            return -1;
        }
        chem+=l*r;
    }
    return chem;
};