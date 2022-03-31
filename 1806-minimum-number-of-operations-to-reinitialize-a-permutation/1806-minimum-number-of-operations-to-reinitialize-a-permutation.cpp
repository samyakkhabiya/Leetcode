class Solution {
public:
    int reinitializePermutation(int n)
{
	int ans = 1;
	int curr = n/2; // we start at node 1 itself { (n-1+1)/2 }
	while(curr != 1)
	{
		curr = (curr&1) ? (n-1+curr)/2 : curr/2;
		ans++;
	}

	return ans;
}
};