class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int sum = 0, maxDist = 0, size = nums.size();
        unordered_map<int, int> indexBySum;
        indexBySum[0] = -1;
        for(int i = 0; i < size; i++){
            sum = (nums[i] == 0) ? sum - 1 : sum + 1;
            if(indexBySum.find(sum) != indexBySum.end()){
                maxDist = max(maxDist, i - indexBySum[sum]);
            }
            else {
                indexBySum[sum] = i;
            }
        }
        return maxDist;
    }
};
