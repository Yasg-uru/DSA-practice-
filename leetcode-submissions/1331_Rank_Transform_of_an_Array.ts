function arrayRankTransform(arr: number[]): number[] {
  const rank:{ele:number;index:number}[]=[];
  for(let i=0;i<arr.length;i++){
    rank.push({
        ele:arr[i],
        index:i
    });

  } 
  rank.sort((a,b)=>a.ele-b.ele);
  //after sorting we need to iterate over the rank 
  const ans=Array.from({length:arr.length},()=>0);
  let r:number=1;
  for(let i=0;i<rank.length;i++){
    if(i>0 && rank[i].ele===rank[i-1].ele){
        ans[rank[i].index]=ans[rank[i-1].index];
    }else{
        ans[rank[i].index]=r++;
    }
  }
  return ans;
   
};