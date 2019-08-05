class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() <= 1)
            return s.length();
        
        int hashmap[256] = {0};
        
        int begin = 0;
        int end = 0;
        int maxLenSeen = 0;
        int currentLen = 0;
        
        for(int i=0; i<s.size(); ++i)
        {
            hashmap[s[i]]++;
            // If we've already seen this value
            if (hashmap[s[i]] > 1)
            {
                end = i-1;
                //对hashmap的值重置
                while(hashmap[s[i]] > 1 && begin <= end)
                {
                    hashmap[s[begin]]--;
                    begin++; //作为下一个字符串的首字母位置
                }
            }
            else
            {
                end = i;
            }
            currentLen = end-begin+1;//计算没有重复字母的字符串长度
            if (currentLen > maxLenSeen) maxLenSeen = currentLen;
        }
        
        return maxLenSeen;
    }
};
