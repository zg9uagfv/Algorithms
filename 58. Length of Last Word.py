class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        if s is None:
            return 0
        length = len(s)
        if length == 0x00:
            return 0x00
        start = 0x00
        end = 0x00
        last_word = ""
        for i in range(0, length):
            if s [i] == " ":
                if i > start:
                    last_word = s[start:end]
                start = i+1
                continue
            else:
                end = i+1
        if end > start:
            last_word = s[start:end]
        return len(last_word)
