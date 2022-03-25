class Solution {
public:
    int boxDelivering(vector<vector<int>>& boxes, int portsCount, int maxBoxes, int maxWeight) {
        vector<int> trips(boxes.size()+1);
        trips[0] = 0; 
        for (int i = 1; i < boxes.size(); ++i) {
            if (boxes[i][0] == boxes[i-1][0]) {
                trips[i] = trips[i-1];
            } else {
                trips[i] = trips[i-1]+1;
            }
        }
        trips.push_back(0);
        vector<long int> weights(boxes.size()+1);
        weights[0] = 0;
        for (int i = 0; i < boxes.size(); ++i) {
            weights[i+1] = weights[i]+boxes[i][1];
        }
        // dp[i] is minimum trips assuming i is the last box to deliver and will return to port afterwards. 
        vector<int> dp(boxes.size()+1);
        dp[0] = 0;
        deque<int> asc_dq;
        asc_dq.push_back(-1);
        for (int i = 0; i < boxes.size(); ++i) {
            while (asc_dq.size()) {
                int prev_box = asc_dq.front();
                int num_boxes = i-prev_box;
                int num_weights = weights[i+1]-weights[prev_box+1];
                if (num_boxes > maxBoxes || num_weights > maxWeight) {
                    asc_dq.pop_front(); continue;
                }
                break;
            }
            int prev_box = asc_dq.front();
            dp[i+1] = 2+dp[prev_box+1]+trips[i]-trips[prev_box+1];
            while (asc_dq.size()) {
                int prev_box = asc_dq.back();
                int last = dp[prev_box+1]-trips[prev_box+1];
                if (dp[i+1]-trips[i+1] <= last) {
                    asc_dq.pop_back(); continue;
                }
                break;
            }
            asc_dq.push_back(i);
        }
        return dp.back();
    }
};