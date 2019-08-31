class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xxor = 0x00;
        for (auto num:nums) {
            xxor ^= num;
        }
        int mask = 0x01;
        while((xxor&mask)==0x00){
            mask <<= 1;
        }
        
        int i = 0, j = 0;
        for (auto num:nums) {
            if ((num & mask) == 0x00) {
                i ^= num;
            } else {
                j ^= num;
            }
        }
        
        vector<int> new_nums;
        new_nums.push_back(i);
        new_nums.push_back(j);
        return new_nums;
    }
};
