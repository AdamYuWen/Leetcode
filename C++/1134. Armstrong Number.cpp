/* The k-digit number N is an Armstrong number if and only if the k-th power of each digit sums to N.
 * Given a positive integer N, return true if and only if it is an Armstrong number.
 * Example 1:
 *	Input: 153
 *	Output: true
 *	Explanation: 
 *	153 is a 3-digit number, and 153 = 1^3 + 5^3 + 3^3.
 * Example 2:
 *	Input: 123
 *	Output: false
 *	Explanation: 
 *	123 is a 3-digit number, and 123 != 1^3 + 2^3 + 3^3 = 36.
 * Note:
 *	1 <= N <= 10^8
 * https://leetcode.com/problems/armstrong-number/
 *
 * Author: Adam Yu Wen
 * Date: November 22, 2019
 */

class Solution {
public:
    bool isArmstrong(int N) {
        int armstrong = 0;
        int k_digit = to_string(N).size();
        int modified_N = N;
        while (modified_N > 0) {
            armstrong += pow(modified_N % 10, k_digit);
            if (armstrong > N) {
                return false;
            }
            modified_N /= 10;
        }
        return N == armstrong;
    }
};