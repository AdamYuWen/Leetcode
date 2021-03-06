# Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.
# Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.
# The order of output does not matter.
# Example 1:
# Input:
# s: "cbaebabacd" p: "abc"
# Output:
# [0, 6]
# Explanation:
# The substring with start index = 0 is "cba", which is an anagram of "abc".
# The substring with start index = 6 is "bac", which is an anagram of "abc".
# Example 2:
# Input:
# s: "abab" p: "ab"
# Output:
# [0, 1, 2]
# Explanation:
# The substring with start index = 0 is "ab", which is an anagram of "ab".
# The substring with start index = 1 is "ba", which is an anagram of "ab".
# The substring with start index = 2 is "ab", which is an anagram of "ab".
# https://leetcode.com/problems/find-all-anagrams-in-a-string/description/
# 
# Author: Adam Yu Wen
# Date: May 23, 2018

class Solution(object):
    def findAnagrams(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: List[int]
        """
        res = []
        sMap = collections.Counter(s[:len(p) - len(s)])
        pMap = collections.Counter(p)
        
        if sMap == pMap:
            res.append(0)
        for i in range(len(s) - len(p)):
            if sMap[s[i]] == 1:
                del sMap[s[i]]
            else:
                sMap[s[i]] -= 1
            sMap[s[i + len(p)]] += 1
            if sMap == pMap:
                res.append(i + 1)
        return res
