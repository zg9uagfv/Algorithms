‘’‘
给定一个整数 n，计算所有小于等于 n 的非负整数中数字 1 出现的个数。

示例:

输入: 13
输出: 6 
解释: 数字 1 出现在以下数字中: 1, 10, 11, 12, 13 。
’‘’
class Solution(object):
    def countDigitOne(self, n):
        if n <= 0:
            return 0x00
        str_num = str(n)
        length = len(str_num)
        divisor = pow(10, length-1)
        head = int(str_num[0])
        remainder = n - head*pow(10, length-1)
        if head != 0x01:
            count = self.countDigitOne(remainder) + divisor + head*self.countDigitOne(divisor-1)
            return count
        else:
            count = self.countDigitOne(divisor-1) + self.countDigitOne(remainder) + 1 + remainder
        return count
