class SnapshotArray {
public:
   vector<vector<int>>vec;
    int snap_id =0 ;
    SnapshotArray(int length) {
    vec.resize(length+1, vector<int>(length+1, 0 ));
        snap_id = 0 ;
    }
    
    void set(int index, int val) {
        vec[index][snap_id]= val;
    }
    
    int snap() {
        snap_id++;
        return snap_id-1;
    }
    
    int get(int index, int snap_id) {
        return vec[index][snap_id];
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */