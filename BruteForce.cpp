/*
暴风(Brute Force) 算法是普通的模式匹配算法，BF算法的思想就是将目标串 S 的
第一个字符与模式串 T 的第一个字符进行匹配，若相等，则继续比较 S 的第二个字
符和 T 的第二个字符；若不相等，则比较 S 的第二个字符和T的第一个字符，依次
比较下去，直到得出最后的匹配结果。BF算法是一种蛮力算法。
 */

#include <iostream>
#include <string>

using namespace std;

int brute_force(string& S, string& T)
{
    int s_size = S.size();
    int t_size = T.size();
    int i = 0, j = 0, index = -1;
    while (i < s_size && j < t_size) {
        if (S[i] == T[j]) {
            i++;
            j++;
        } else {
            i = i - j + 1;
            j = 0;
        }
    }
    if (j == t_size){
        index = i - j + 1;
    }
    return index;
}

int main(void)
{
    string s = "12343214325789";
    string t = "3257";
    int ret = brute_force(s, t);
    std::cout<<"result : "<<ret<<std::endl;
}
