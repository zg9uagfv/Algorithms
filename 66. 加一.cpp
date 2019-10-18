class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int length = digits.size();
        int i = length-1, flag = 0x01;
        for (; i >= 0x00; --i) {
            if (0x01 == flag) {
                if (9 == digits[i]) {
                    digits[i] = 0x00;
                } else {
                    digits[i] += 1;
                    flag = 0x00;
                }
            }
        }
        std::vector<int> new_digits;
        if (0x01 == flag) {
            new_digits.push_back(1);
        }
        for (auto node : digits) {
            new_digits.push_back(node);
        }
        return new_digits;
    }
};
