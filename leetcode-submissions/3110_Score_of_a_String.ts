function scoreOfString(s: string): number {
  let ans:number =0;
  for(let i:number =0;i<s.length-1;i++){
    let a : number =s.charCodeAt(i);
    let b:number =s.charCodeAt(i+1);
    ans+=Math.abs(a-b);

  } 
  return ans ; 
};