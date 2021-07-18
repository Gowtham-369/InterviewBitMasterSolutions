class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int cnt1 = 1;
        int n = nums.size();
        if(n == 1){
            return nums[0];
        }
        int ele1 = nums[0];
        for(int i=1; i<n; i++){
            if(nums[i] == ele1){
                cnt1 += 1;
            }
            else{
                cnt1 -= 1;
                if(cnt1 == 0){
                    cnt1 += 1;
                    ele1 = nums[i];
                }
            }
        }
        cnt1 = 0;
        for(int i=0; i<n; i++){
            if(ele1 == nums[i]){
                cnt1 += 1;
            }
        }
        if(cnt1 > n/2){
            return ele1;
        }
        else{
            return -1;
        }
    }
};