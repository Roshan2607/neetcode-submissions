class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> charMap(256, -1); 
        
        int left = 0;
        int maxLength = 0;
        for (int right = 0; right < s.length(); right++) {
            if (charMap[s[right]] >= left) {
                left = charMap[s[right]] + 1;
            }
            charMap[s[right]] = right;
            maxLength = max(maxLength, right - left + 1);
        }
        return maxLength;
    }
};
