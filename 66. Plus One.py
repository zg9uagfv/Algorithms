class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        if digits[-1] != 9:
            digits[-1] += 1
            return digits
        for i in range(len(digits), 0, -1):
            if digits[i-1] == 9:
                digits[i-1] = 0x00
                if i-1 == 0x00:
                    digits = [1]+digits
            else:
                digits[i-1] += 1
                break
        return digits
