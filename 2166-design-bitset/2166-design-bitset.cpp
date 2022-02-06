class Bitset {
public:
    vector<int>arr;
    int cnt,cntflip;
    Bitset(int size) {
        arr.resize(size,0);
        cnt=0,cntflip=0;
    }
    void fix(int idx) {
	// means current bit is 0 ,so set it to 1
        if((arr[idx]+cntflip)%2==0){
            arr[idx]++;
            cnt++;
        }
    }
    void unfix(int idx) {
	// means current bit is 1,so set it to 0
      if((arr[idx]+cntflip)%2!=0){
            arr[idx]--;
            cnt--;
        }  
    }
    void flip() {
	// cnt will flip ,if we flip all the bits
         cnt=arr.size()-cnt;
        cntflip++;
    }
    bool all() {
        if(cnt==arr.size())
            return true;
        return false;
    }
    bool one() {
        if(cnt>=1)
            return true;
        return false;
    }
    int count() {
        return cnt;
    }
    string toString() {
        string ans;
        for(auto &ele :arr){
            if((cntflip+ele)%2==0)
                ans.push_back('0');
            else
                ans.push_back('1');  
        }
        return ans;
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */