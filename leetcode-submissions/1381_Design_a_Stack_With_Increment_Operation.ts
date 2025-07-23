class CustomStack {
    private stack:number[];
    private size:number ;

    constructor(maxSize: number) {
        this.size=maxSize;
        this.stack=[];
    }

    push(x: number): void {
        if(this.stack.length<this.size){
            this.stack.push(x);
        }
    }

    pop(): number {
        if(this.stack.length>0){
            const topEle=this.stack[this.stack.length-1];
            this.stack.pop();
            return topEle;
        }
        return -1;
    }

    increment(k: number, val: number): void {
  let limit=Math.min(k,this.stack.length);
  for(let i=0;i<limit;i++){
    this.stack[i]+=val;
  }

    }
}

/**
 * Your CustomStack object will be instantiated and called as such:
 * var obj = new CustomStack(maxSize)
 * obj.push(x)
 * var param_2 = obj.pop()
 * obj.increment(k,val)
 */