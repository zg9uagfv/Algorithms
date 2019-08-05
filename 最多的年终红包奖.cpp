//From:
//https://mp.weixin.qq.com/s/la3OFcBUh57KHgVwqIFWeQ

//题目：在数字矩阵中，从左上角到右下角，每次只能向右或向下，如何规划路径，能获得最大数字总和？

#include <iostream>

unsigned int matrix1[4][5] = {
    {300, 500, 560, 400, 160},
    {1000, 100, 200, 340, 690},
    {600, 500, 500, 460, 320},
    {300, 400, 250, 210, 760}
};

unsigned int max(unsigned int left, unsigned int up)
{
    if (left > up) {
        return left;
    }
    return up;
}

unsigned int max_red_packet(unsigned int (*redpacket_matrix)[5], 
                            unsigned int row, 
                            unsigned int column)
{
    //申请一个新的二维数组，不用判断redpacket_matrix的边界情况
    unsigned int new_row = row + 2, new_column = column+2;
    unsigned int** tmp_matrix = new unsigned int*[new_row];
    int idx = 0;
    for(idx=0; idx < new_row; idx++)
        tmp_matrix[idx] = new unsigned int[new_column];

    unsigned int i = 0, j = 0;
    for (; i < new_row; i++) {
        for (; j < new_column; j++) {
            tmp_matrix[i][j] = 0x00;
        }
    }

    i = 1, j = 1;
    for (; i < row+1; i++) {
        j = 1;
        for (; j < column+1; j++) {
            tmp_matrix[i][j] = max(tmp_matrix[i-1][j], tmp_matrix[i][j-1]) + redpacket_matrix[i-1][j-1];
        }
    }
    unsigned int max_value =  tmp_matrix[i-1][j-1];

    //释放空间
    for(i =0; i <new_row; i++)
        delete []tmp_matrix[i];
    delete []tmp_matrix;

    return max_value;
}

int main(void)
{
    std::cout<<max_red_packet(matrix1, 4, 5)<<std::endl;
}
