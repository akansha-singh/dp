class Solution{
    int Backtracking(vector<vector<int>>& ans,vector<int>& temp,int index,vector<int>& nums, int target){
        if(target == 0){
            ans.push_back(temp);
            return 0; 
        }
        else if(target < 0){
            //temp.clear();
            return 0;
        }
        else{
            for(int i = index;i<nums.size();i++){
                temp.push_back(nums[i]);
                Backtracking(ans,temp,i,nums,target-nums[i]);
                temp.pop_back();
            }
        }
        return 1;
    }
public:
    vector<vector<int>>combinationSum(vector<int>&candidates,int target){
        vector<vector<int>>ans;
        vector<int>temp;
        Backtracking(ans,temp,0,candidates,target);
        return ans;
    }
};

