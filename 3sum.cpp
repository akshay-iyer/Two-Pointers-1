// Time Complexity : O(n^2) 
// Space Complexity : O(n) - hashset
// Did this code successfully run on Leetcode : Yes
// Any problem you faced while coding this : No

// [***] KEY INSIGHT: SORT ARRAY AND USE 3 POINTERS. IF SUM<TARGET, MOVE LEFT POINTER ELSE IF GREATER THEN MOVE RIGHT ELSE MOVE BOTH

// Your code here along with comments explaining your approach
// 1. Sort the array
// 2. 3 pointers: one indicates the start point. The other two are left and right on rest of the array
// 3. Add the 3 pointer elements. If its less than target(here 0), move left ahead else move right behind
// 4. If sum equals target, add combo to set

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        set<vector<int>> hashset; // unordered set doesn't work with vector as elements
        if(nums.size() <3)
            return result;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int target = 0; // this can be generalized to any target
        int start = 0, l=1,r=n-1;
        for(;start<n-2;start++){
            l = start+1; r=n-1;
            while(l<r){
                int sum = nums[start] + nums[l] + nums[r];
                // cout<<sum<<endl;
                if(sum == target){
                    hashset.insert({nums[start], nums[l], nums[r]});
                    l++;
                    r--;
                }
                else if(sum<target){
                    l++;
                }
                else{
                    r--;
                }
            }
        }
        for(auto el: hashset)
            result.emplace_back(el);
        return result;
    }
};



// Time Complexity : O(n^2) 
// Space Complexity : O(1) 
// Did this code successfully run on Leetcode : Yes
// Any problem you faced while coding this : No

// [***] KEY INSIGHT: SAME BUT W/O SET. ON FINDING TARGET, KEEP MOVING LEFT AND RIGHT TILL THEY LAND ON UNIQUE ELEMENTS

// Your code here along with comments explaining your approach
// 1. Sort the array
// 2. 3 pointers: one indicates the start point. The other two are left and right on rest of the array
// 3. Add the 3 pointer elements. If its less than target(here 0), move left ahead else move right behind
// 4. If sum equals target, add combo to result vector. Move left and right by 1. Now in while loops, keep moving left and right till we come across new elements

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        if(nums.size() <3)
            return result;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int target = 0; // this can be generalized to any target
        int start = 0, l=1,r=n-1;
        for(;start<n-2;start++){
            if(start>0 && nums[start]==nums[start-1])
                continue;
            l = start+1; r=n-1;
            while(l<r){
                int sum = nums[start] + nums[l] + nums[r];
                if(sum == target){
                    vector<int> temp = {nums[start], nums[l], nums[r]};
                    result.emplace_back(temp);
                    l++; r--;
                    while(l<r && nums[l]==nums[l-1])
                        l++;
                    while(l<r && nums[r]==nums[r+1])
                        r--;
                }
                else if(sum<target)
                    l++;
                else
                    r--;
            }
        }
        return result;
    }
};

