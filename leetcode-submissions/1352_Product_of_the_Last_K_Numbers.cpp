class ProductOfNumbers {
public:
    vector<int>arr;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        arr.push_back(num);
    }
    
    int getProduct(int k) {
        int i= (arr.size()-k);
        int product = 1;
        for(;i<arr.size();i++){
            product*= arr[i];
        }
        return product;
        
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */