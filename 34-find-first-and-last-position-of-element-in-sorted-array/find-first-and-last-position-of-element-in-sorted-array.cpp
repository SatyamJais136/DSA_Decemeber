class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2,-1); //default [-1, -1]
        int n = nums.size();

        // First occurence
        int low = 0;
        int high = n-1;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(nums[mid] >= target) high = mid-1;
            else low = mid+1;
            if(nums[mid] == target) ans[0] = mid;
        } 

        // Last occurence
        low = 0;
        high = n-1;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(nums[mid] <= target) low = low+1;
            else high = mid-1;
            if(nums[mid] == target) ans[1] = mid;
        } 
        return ans;
    }
};