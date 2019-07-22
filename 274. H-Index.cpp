class Solution {
public:
    bool check_index(vector<int>& citations, int index)
    {
        int h = 0x00;
        for (auto c : citations) {
            if (c >= index)
                h++;
        }
        return index <= h;
    }
    
    int hIndex(vector<int>& citations) {
        int size = citations.size();
        int max_index = 0x00;
        int low = 0, high = size-1, mid = (low+high)/2;
        while (high-low>=0) {
            if (false == this->check_index(citations, mid+1)) {
                high = mid-1;
            } else {
                if (mid+1 > max_index)
                    max_index = mid+1;
                low = mid+1;
            }
            mid = (low+high)/2;
        }
        return max_index;
    }
};
