function validPalindrome(s: string): boolean {
    let left:number =0;
    let right :number =s.length-1;
    while(left<right){
        if(s[left]!==s[right]){
return isPalindrome(s,left+1,right) || isPalindrome(s,left,right-1);
        }
        left++;
        right--;
    }
    return true;
};
function isPalindrome(s:string ,left:number ,right:number):boolean{
while(left<right){
    if(s[left]===s[right]){
        left++;
        right --;
    }else {
        return false;
    }
}
return true;
}