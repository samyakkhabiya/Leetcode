class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        int xored1 = arr1[0];
    int xored2 = arr2[0];
    
     for(int j=1 ; j<arr1.size() ;  j++) xored1 = xored1^arr1[j];
    
     for(int i=1 ; i<arr2.size() ; i++)  xored2 = xored2^arr2[i];
    
   
    
    return xored1&xored2;
    }
};