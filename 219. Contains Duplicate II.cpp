class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, vector<int> > table;
        int size = nums.size(), i = 0x00;
        for (; i < size; i++) {
            if (table.find(nums[i]) == table.end()) {
                vector<int> seq;
                seq.push_back(i);
                table.insert(pair<int, vector<int> >(nums[i], seq));
            } else {
                vector<int>& seq = table[nums[i]];
                int j = 0x00, length = seq.size();
                for (; j < length; j++) {
                    if (i - seq[j] <= k) {
                        return true;
                    } else {
                        seq.push_back(i);
                    }
                }
            }
        }
        return false;
    }
};
