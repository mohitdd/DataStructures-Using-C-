class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        //vector<int> :: iterator itr = nums.begin();
        vector<int> newNums = {};
        for(int itr=0; itr<nums.size(); itr++) {
            cout<<nums[itr];
            if(nums[abs(nums[itr])-1] > 0) {
                nums[abs(nums[itr])-1] = - nums[abs(nums[itr])-1];
            }
            else {
                newNums.push_back(abs(nums[itr]));
            }
        }
     
        return newNums;
    }
};