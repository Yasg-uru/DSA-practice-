function findKthBit(n: number, k: number): string {
    let s:string[]=[];
    s[0]="0";
    for(let i=1;i<n;i++){
s[i]=s[i-1]+"1"+reverseString(invertString(s[i-1]));
    }
return s.join('').charAt(k-1);
};
function reverseString (str:string):string {
let reversed="";
for(let i=str.length-1;i>=0;i--){
    reversed+=str.charAt(i);
}
return reversed;
}
function invertString(str:string):string {
let inverted:string ="";
for(const c of str){
    inverted+=(c==="0"?"1":"0");
}
return inverted;
}