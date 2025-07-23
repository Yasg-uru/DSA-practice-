function numberOfAlternatingGroups(colors: number[], k: number): number {
    let i :number =0, j:number =0, groups :number =0;
    const n :number = colors.length;
    const N:number = n+(k-1);
    for(let i:number =0;i<k;i++){
        colors.push(colors[i]);
    }
    while(j<N){
        if(colors[j]==colors[j-1]){
            i=j;
            j++;
            continue;
        }
        if(j-i+1==k){
            groups+=1;
            i++;

        }
        j++;

    }
    return groups;
};