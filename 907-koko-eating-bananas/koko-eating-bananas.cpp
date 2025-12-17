class Solution {
public:
    bool check(int mid,vector<int>& piles, int h){
        int n = piles.size();
        int count = 0;
        for(int i = 0; i <n ; i++){
            if(count > h) return false;
            if(mid >= piles[i]) count++;
            else if(piles[i] % mid == 0) count += piles[i]/mid;
            else count += piles[i]/mid + 1;
        }
        if(count > h) return false;
        return true;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int l = 1;
        int mx = -1;
        for(int pile: piles){
            mx = max(mx,pile);
        }
        int hi = mx;
        int ans = 0;
        while(l <= hi){
            int mid = l + (hi-l)/2;
            if(check(mid, piles, h)){
                ans = mid;
                hi = mid -1;
                // if(mid >= h){
                //     hi = mid -1;
                // }
            }
            else l = mid+1;
        }
        
        return ans;
    }
};