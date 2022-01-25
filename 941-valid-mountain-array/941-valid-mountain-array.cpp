class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n=arr.size();
        if(n<3)
            return false;
        bool downfall=false;
        bool up=false;
        for(int i=0;i<n-1;i++){
            if(arr[i]<arr[i+1]){
                if(downfall)
                    return false;
                // downfall=false;
                up=true;
            }
            else if(arr[i]==arr[i+1])
                return false;
            else{
                // if(up)
                downfall=true;
            }
        }
        return downfall && up;
    }
};