// Also called Dutch Flag Problem - use 3 pointers; since 3 colors
// Time Complexity : O(n) 
// Space Complexity : O(1) 
// Did this code successfully run on Leetcode : Yes
// Any problem you faced while coding this : No

// [***] KEY INSIGHT: 3 POINTERS; LOW FOR 0, MID FOR 1, HIGH FOR 2. ALWAYS SEE WHAT IS PRESENT AT MID AND SWAP ACCORDINGLY AND MOVE RESP POINTERS

// Your code here along with comments explaining your approach
// 1. Init low and mid at 0 and high at last element
// 2. If el at mid is 1, then great, move mid ahead
// 3. If el at mid is 2, then swap with high and decrease high
// 4. If el at mid is 0, then swap with low and increase both low and mid
// 5. Stop when mid and high cross each other 

class Solution {
public:
    void swap(int& a, int& b){
        int temp = a;
        a = b;
        b = temp;
    }
    
    void sortColors(vector<int>& nums) {
        if(nums.size()==0)
            return;
        int n = nums.size();
        int low=0,mid=0,high=n-1;
        // low corr to 0, mid corr to 1 and high corr to 2
        // always check what is at mid
        while(mid<=high){
            if(nums[mid] == 1)
                mid++;
            else if(nums[mid]==2){
                swap(nums[mid], nums[high]);
                high--;
            }
            else{
                swap(nums[low],nums[mid]);
                low++;mid++;
            }
        }
    }
};
