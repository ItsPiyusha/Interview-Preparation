#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
    bool containsNearByDuplicate(vector<int>& nums, int k){
        for(int i = 0; i < (int)nums.size(); ++i){
            for(int j = i+1; j < (int)nums.size(); ++j){
                if(j-i > k) break;
                if(nums[i] == nums[j]) return true;
            }
        }
        return false;
    }
    bool containsNearByDuplicate1(vector<int>& nums, int k){
        unordered_map<int,int> last;
        for(int i = 0; i < (int)nums.size(); ++i){
            int x = nums[i];
            if(last.count(x) && i-last[x] <= k) return true;
            last[x] = i;
        }
        return false;
    }
};
int main() {
	// your code goes here
	int n;
	cin>>n;
	vector<int> nums(n);
	for(int i = 0; i < (int)nums.size(); ++i) cin>>nums[i];
	int k;
	cin >> k;
	Solution sol;
	cout<<(sol.containsNearByDuplicate(nums,k) ? "true" : "false") << "\n";
	cout<<(sol.containsNearByDuplicate1(nums,k) ? "true" : "false") << "\n";
	return 0;

}
