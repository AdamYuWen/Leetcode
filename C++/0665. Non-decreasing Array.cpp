/* Given an array with n integers, your task is to check if it could become non-decreasing
 * by modifying at most 1 element.
 * We define an array is non-decreasing if array[i] <= array[i + 1] holds for every i
 * (1 <= i < n).
 * Example 1:
 * Input: [4,2,3]
 * Output: True
 * Explanation: You could modify the first 4 to 1 to get a non-decreasing array.
 * Example 2:
 * Input: [4,2,1]
 * Output: False
 * Explanation: You can't get a non-decreasing array by modify at most one element.
 * Note: The n belongs to [1, 10,000].
 * https://leetcode.com/problems/non-decreasing-array/description/
 * 
 * Author: Adam Yu Wen
 * Date: May 17, 2018
 */

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int numsSize = nums.size(), cnt = 0;
        for (int i = 0; i < numsSize - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                if (i == 0) {
                    // Example: 4, 2, 3
                    cnt++;
                }
                else if (i + 1 == numsSize - 1) {
                    // Example: 2, 3, 3, 2
                    cnt++;
                }
                else if (nums[i - 1] <= nums[i + 1]) {
                    // Example: -1, 4, 2, 3
                    cnt++;
                }
                else if (i + 2 < numsSize && nums[i] <= nums[i + 2]) {
                    // Example: 2, 3, 3, 2, 4
                    cnt++;
                }
                else {
                    return false;
                }

                if (cnt > 1) return false;
            }
        }
        return true;
    }
};
