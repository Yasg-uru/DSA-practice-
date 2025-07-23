function takeCharacters(s: string, k: number): number {
  let a_count =0,b_count=0,c_count=0;
  let notDeletedMax=0;
  for(const c  of s){
    if(c==="a"){
        a_count ++;
    }else if (c==="b"){
        b_count ++;

    }else {
        c_count++;
    }
  }  
  let i=0;
  let j=0;
  let n=s.length;
  if(a_count<k || b_count<k || c_count<k){
    return -1;
  }
  while(j<n){
    const c=s[j];
     if(c==="a"){
        a_count --;
    }else if (c==="b"){
        b_count --;

    }else {
        c_count--;
    }
    while(i<=j && (a_count<k || b_count<k || c_count <k)){
         if(s[i]==="a"){
        a_count ++;
    }else if (s[i]==="b"){
        b_count ++;

    }else {
        c_count++;
    }

    i++;

    }
    notDeletedMax=Math.max(notDeletedMax,j-i+1);
    j++;
  }
  return n-notDeletedMax;
};