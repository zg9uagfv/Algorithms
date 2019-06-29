class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int sum = 0x00;
        std::vector<int>::iterator iter = machines.begin();
        for (; iter != machines.end(); iter++) {
            sum += *iter;
        }
        int size = machines.size();
        if (sum % size != 0x00) {
            //不能满足平均分配
            return -1;
        }
        //每个洗衣机应该最终分配的衣服数量
        int mean = sum / size;
        iter = machines.begin();
        for (; iter != machines.end(); iter++) {
            //归一化
            *iter -= mean;
        }
        int i = 0x01;
        int max_steps = abs(machines[0]);
        for (; i < size; i++) {
            int steps = abs(machines[i-1]+machines[i]);
            //machines[i]与machines[i-1]:
            //同号，表示移动衣服的次数增加
            //异号，表示移动衣服的次数减少
            max_steps = max(max_steps, max(machines[i], steps));
            machines[i] = machines[i-1] + machines[i];
        }
        return max_steps;
    }
};
