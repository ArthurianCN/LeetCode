/*
题目描述：
    实现 pow(x, n) ，即计算 x 的整数 n 次幂函数（即，x^n ）
    -100.0 < x < 100.0
    -231 <= n <= 231-1
    n 是一个整数
    要么 x 不为零，要么 n > 0 。
    -104 <= xn <= 104
解法思路：
    使用递归方式进行处理
*/


class Solution {
public:
    double myPow(double x, long n) {
        if(n == 0)
        {
            return 1.0;
        }

        if(n == 1)
        {
            return x;
        }

        if(0 > n)
        {
            return 1.0 / myPow(x, -n);
        }

        if(n % 2 == 1)
        {
            return x * myPow(x, n - 1);
        }
        
        auto dTmp = myPow(x, n / 2);
        return dTmp * dTmp;
    }
};