class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left = 0, right = arr.size()-1;

        //Shrink the window till size becomes k
        while(right - left + 1 > k){
            if(abs(arr[left]-x) > abs(arr[right]-x)){
                left++;
            }
            else right--;
        }

        //collect the k closet elements
        vector<int> res;
        for(int i = left; i<= right; i++){
            res.push_back(arr[i]);
        }
        return res;
    }
};