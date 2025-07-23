function longestDiverseString(a: number, b: number, c: number): string {
    const pq:[number,string][]=[];
    if(a>0){
        pq.push([a,"a"]);
    }
    if(b>0){
pq.push([b,"b"]);

    }
    if(c>0){
pq.push([c,"c"]);
    }
    let res:string="";
    while(pq.length>0){
        pq.sort((a,b)=>b[0]-a[0]);
        let [count,character]=pq.shift();
        
        //after this we need to check whether the string contains consective characters or not 
        if(res.length>=2 && res.charAt(res.length-1)===character && res.charAt(res.length-2)===character){
            if(!pq.length){
                break;
            }
            //otherwise we will need to extract the second largets character count character and add it to the string 
            let [c,ch]=pq.shift();
            res+=ch;
            c--;

            if(c>0){
                pq.push([c,ch]);
            }
        }else{
            res+=character;
            count--;
        }
        if(count>0){
            pq.push([count,character]);
        }
return  res;
    }
};