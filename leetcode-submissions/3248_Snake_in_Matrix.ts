function finalPositionOfSnake(n: number, commands: string[]): number {
    let i:number =0 , j:number =0 ;
    for(const command of commands){
        if(command === "DOWN" ) i++;
        else if (command === "RIGHT") j++;
        else if (command === "LEFT") j--;
        else i--;
    }
    return (i*n)+j;
};