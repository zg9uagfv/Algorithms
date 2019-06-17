class Solution:
    def search(self, nums, left, right, target):
        if target <= nums[left]:
            return left
        if target > nums[right-1]:
            return right
        mid = (int)((left+right)/2)
        if target > nums[mid]:
            return self.search(nums, mid, right, target)
        return self.search(nums, left, mid, target)
        
    def searchInsert(self, nums: List[int], target: int) -> int:
        length = len(nums)
        if target <= nums[0]:
            return 0x00
        if target > nums[length-1]:
            return length
        return self.search(nums, 0, length, target)
