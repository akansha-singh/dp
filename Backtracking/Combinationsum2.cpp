class Solution{    
public:
    void helper(vector<int>& nums, int index, vector<int>& local, vector<vector<int>>& res, int target){
        if(target == 0) {
            res.push_back(local);
            return;
        }        
        for(int i = index; i < nums.size(); ++i) {
            if(nums[i] > target) return; // no need consider other inputs from this point onwards
            if(i && nums[i] == nums[i-1] && i > index) continue; // Very key step to handle duplicates (i > order)
            local.push_back(nums[i]);
            helper(nums, i+1, local, res, target - nums[i]);
            local.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> local;
        sort(candidates.begin(), candidates.end());
        helper(candidates, 0, local, res, target);
        return res;        
    }
};


