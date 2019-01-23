class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      int i = 0;
      vector<int> res(2, 0);
      for (;i < nums.size();i ++){
          for(int j = i + 1;j < nums.size();j ++){
              if(nums[i] + nums[j] == target){
                  res[0] = i;
                  res[1] = j;
                  return res;
              }else{
                  continue;
              }
          }
      }
      return res;
    }
};
