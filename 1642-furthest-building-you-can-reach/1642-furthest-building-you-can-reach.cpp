class Solution {
public:
    int furthestBuilding(vector<int>& h, int bricks, int ladders) {
        priority_queue<int> pq;
        int sum=0;
        for(int i=1;i<h.size();i++){
            if(h[i]-h[i-1]>0){
                pq.push(h[i]-h[i-1]);
                bricks-=(h[i]-h[i-1]);
                if(bricks<0){
                    if(ladders){
                        ladders--;
                        bricks+=pq.top();
                        pq.pop();
                    }
                    else
                        return i-1;
                }
            }
        }
        return h.size()-1;
    }
};