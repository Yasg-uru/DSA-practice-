/** 
 * Forward declaration of guess API.
 * @param {number} num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * var guess = function(num) {}
 */


function guessNumber(n: number): number {
let l :number =1, r :number =n;
    while(l<=r){
    const  mid = Math.floor((r+l)/2);
    const result = guess(mid);
        if(result===0){
            return mid;
    }else if(result===-1){
    r = mid-1;
    }else {
    l = mid+1;
    }
    }
    return -1;
};