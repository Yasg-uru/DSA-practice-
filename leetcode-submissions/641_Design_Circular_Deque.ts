class MyCircularDeque {
    private size:number;
    private deque:number[];
    constructor(k: number) {
        this.size=k;
        this.deque=[];
    }

    insertFront(value: number): boolean {
        if(this.deque.length===this.size){
            return false;
        }else{
            this.deque.unshift(value);
            return true;
        }
    }

    insertLast(value: number): boolean {
           if(this.deque.length===this.size){
            return false;
        }else{
            this.deque.push(value);
            return true;
        }
    }

    deleteFront(): boolean {
        if(this.deque.length>0){
            this.deque.shift();
            return true;
        }else{
            return false;
        }
    }

    deleteLast(): boolean {
        if(this.deque.length>0){
            this.deque.pop();
            return true;
        }else{
            return false;
        }
    }

    getFront(): number {
        if(this.deque.length===0){
            return -1;
        }
        return this.deque[0];
    }

    getRear(): number {
          if(this.deque.length===0){
            return -1;
        }
        return this.deque[this.deque.length-1];
    }

    isEmpty(): boolean {
        return this.deque.length===0;
    }

    isFull(): boolean {
        return this.deque.length===this.size;
    }
}

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * var obj = new MyCircularDeque(k)
 * var param_1 = obj.insertFront(value)
 * var param_2 = obj.insertLast(value)
 * var param_3 = obj.deleteFront()
 * var param_4 = obj.deleteLast()
 * var param_5 = obj.getFront()
 * var param_6 = obj.getRear()
 * var param_7 = obj.isEmpty()
 * var param_8 = obj.isFull()
 */