function spiralOrder(matrix: number[][]): number[] {
    const m = matrix.length , n = matrix[0].length;
    let direction : number =0, left =0 , right = n-1, down = m-1 , top = 0  ;
    const ans: number[] = [];
    while(left<=right && top<=down){
        // first we need to go from left to right via top row 
       if(direction===0) {

        for(let i=left ;i<=right;i++){
            ans.push(matrix[top][i]);
        }
        top++;
       }

        // 2. we needd to go top to down via right column 
        if(direction===1){
            for(let i= top ;i<=down;i++){
                ans.push(matrix[i][right]);
            }
            right--;
        }
        // 3. we need to go right to left via down row
        if(direction===2){
            for(let i = right ;i>=left;i--){
                ans.push(matrix[down][i]);
            }
            down--;
        }

        //4. we need to go down to top via left column 
        if(direction===3){
            for(let i = down ; i>=top;i--){
                ans.push(matrix[i][left]);
            }
            left++;
        }
        direction = (direction+1)%4;
    }
    return ans ;
};