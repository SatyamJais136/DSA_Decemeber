class Solution {
public:
    bool check(long long mid, vector<int>& time, int totalTrips){
        int n = time.size();
        long long trips = 0;
        for(int i = 0; i < n; i++){
            trips += mid/(long long)time[i];
        }
        if(trips < totalTrips) return false;
        else return true;
    }

    long long minimumTime(vector<int>& time, int totalTrips) {
        int n = time.size();
        int mx = -1;
        for(int i = 0; i< n; i++){
            mx = max(mx, time[i]);
        }
        long long l = 1;
        long long h = (long long)mx * (long long)totalTrips;
        long long ans = 0;
        while(l <= h){
            long long mid = l + (h-l)/2;
            if(check(mid, time, totalTrips)){
                ans = mid;
                h = mid - 1;
            }
            else l = mid + 1;
        }       
        return ans;
    }
};