class Solution {
public:
    bool isSet(int &x,int bit){
        return x&(1<<bit);
    }
    void setBit(int &x,int bit){
        x|=(1<<bit);
    }
    void unSetBit(int &x,int bit){
        x&=~(1<<bit);
    }
    int minimizeXor(int num1, int num2) {
        int required_set_bits=__builtin_popcount(num2);
        int x=num1;// because if we do the xor with num1 then it always gives zero 
        int current_set_bits=__builtin_popcount(num1);
        int bit=0;
        if(current_set_bits<required_set_bits){
            while(current_set_bits<required_set_bits){
                // we need to set the bits on the unset position in the least bit side
                if(not isSet(x,bit)){
                    setBit(x,bit);
                current_set_bits++;
                }
                bit++;
            }
        }else{
            while(current_set_bits>required_set_bits){
                if(isSet(x,bit)){
                    unSetBit(x,bit);
                current_set_bits--;
                }
                bit++;
            }
        }
        return x;
    }
};