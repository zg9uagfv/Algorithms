class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        #把num作为key放入map中
        std::map<int, int> mapOfElements;
        std::vector<int>::iterator iter = nums.begin();
        for (; iter != nums.end(); iter++) {
            std::map<int, int>::iterator it = mapOfElements.find(*iter);
            if (it != mapOfElements.end()) {
                it->second += 1;
            } else {
                mapOfElements.insert(std::pair<int, int>(*iter, 0x01));
            }
        }
        
        #桶排序
        std::vector<std::vector<int> > vecElements(nums.size()+1);
        std::map<int, int>::iterator it = mapOfElements.begin();
        for(; it != mapOfElements.end();it++) {
            vecElements[it->second].push_back(it->first);
        }   
        
        #逆序遍历K个数
        vector<int> output;
        int i = 0x00;
        std::vector<std::vector<int> >::reverse_iterator itr = vecElements.rbegin();
        for(; itr != vecElements.rend() && i < k; itr++) {
            std::vector<int>::iterator iter = itr->begin();
            for (; iter != itr->end(); iter++) {
                output.push_back(*iter);
                i++;
            }
        }
        return output;
    }
};
