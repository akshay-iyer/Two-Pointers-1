// Brute force - consider all psbl pairs - TLE
// Time Complexity : O(n^2) 
// Space Complexity : O(1) 
// Did this code successfully run on Leetcode : Yes
// Any problem you faced while coding this : No

// [***] KEY INSIGHT: CONSIDER ALL PSBL PAIRS

// Your code here along with comments explaining your approach
// 1. Consider all psbl pairs and find maxArea

class Solution {
public:
    int maxArea(vector<int>& height) {
        if(height.size()==0)
            return 0;
        int maxArea = 0;
        int n = height.size();
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                maxArea = max(maxArea, (j-i)*min(height[i],height[j]));
            }
        }
        return maxArea;
    }
};

// Optimized soln - 2 pointers
// Time Complexity : O(n) 
// Space Complexity : O(1) 
// Did this code successfully run on Leetcode : Yes
// Any problem you faced while coding this : No

// [***] KEY INSIGHT: AREA LIMITED BY LOWER HEIGHT POINTER; IF LEFT IS LOWER, MOVE LEFT; ELSE MOVE RIGHT

// Your code here along with comments explaining your approach
// 1. 2 pointers - one at start and one at end
// 2. Calculate area and compare with maxArea always
// 3. If height at left pointer is lower, the psbility of a better area is only towards right; similar logic if right area is small then move left

// The intuition behind this approach is that the area formed between the lines will always be limited by the height of the shorter line. 
// Further, the farther the lines, the more will be the area obtained.
// We take two pointers, one at the beginning and one at the end of the array constituting the length of the lines. 
// Further, we maintain a variable maxarea\text{maxarea}maxarea to store the maximum area obtained till now. At every step, we find out the area formed between them, update maxarea\text{maxarea}maxarea and move the pointer pointing to the shorter line towards the other end by one step.

class Solution {
public:
    int maxArea(vector<int>& height) {
        if(height.size()==0)
            return 0;
        int maxArea = 0;
        int n = height.size();
        int l=0, r=n-1;
        while(l<r){
            maxArea = max(maxArea,(r-l)*min(height[l],height[r]));
            if(height[l]<height[r])
                l++;
            else
                r--;
        }
        return maxArea;
    }
};