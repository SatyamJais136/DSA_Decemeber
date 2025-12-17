class Solution {
public:
    bool isPossible(int mid,vector<int>& weights, int days){
        int m = mid;
        int count = 1;
        for(int i = 0; i<weights.size(); i++){
            if(m >= weights[i]){
                m-= weights[i];
            }
            else{
                m = mid;
                m -= weights[i];
                count++;
            }
        }
        if(count >days) return false;
        return true;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int maxi = 0;
        int sum = 0;
        for(int i = 0; i < n; i++){
            maxi = max(maxi,weights[i]);
            sum += weights[i];
        }
        int l = maxi;
        int h = sum;
        int ans = 0;
        while(l<=h){
            int mid = l + (h-l)/2;
            if(isPossible(mid, weights, days)){
                ans = mid;
                h = mid -1;
            }
            else l = mid + 1;
        }
        return l;
    }
};