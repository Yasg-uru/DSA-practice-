function lengthOfLongestSubstring(s: string): number {
    let i =0 , j =0 , n  = s.length, maxLength = 0 ;
    const map:Map<string  , number > = new Map();
    while(j<n){
        map.set(s[j], map.has(s[j])?(map.get(s[j])+1):1);
        while(map.get(s[j])>1){
            map.set(s[i], map.get(s[i])!-1);
            i++;
        }
        maxLength = Math.max(maxLength , j-i+1);
        j++;
    }
    return maxLength ;
};