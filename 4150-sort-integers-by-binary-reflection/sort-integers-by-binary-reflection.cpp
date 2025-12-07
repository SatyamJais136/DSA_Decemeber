class Solution {
public:
    vector<int> sortByReflection(vector<int>& nums) {
        auto reflect = [](int x){
            int r = 0;
            while(x > 0){
                r = (r << 1) | (x & 1);
                x >>= 1;
            }
            return r;
        };

        sort(nums.begin(), nums.end(), [&](int a, int b){
            int ra = reflect(a), rb = reflect(b);
            return ra == rb ? a < b : ra < rb;
        });
        return nums;
    }
};