/*
题目描述：
    给你一个字符串 s，由若干单词组成，单词前后用一些空格字符隔开。返回字符串中 最后一个 单词的长度。
    单词 是指仅由字母组成、不包含任何空格字符的最大子字符串。
    1 <= s.length <= 104
    s 仅由英文字母和空格 ' ' 组成
    s 中至少存在一个单词
解法思路：
    朴实无华，直接无脑遍历，分别找到起始和结束位置
*/


class Solution {
public:
    int lengthOfLastWord(string s) {
        int nBegin = -1, nEnd = -1, nLength = 0;
        for(int i = 0; s[i]; ++i)
        {
            // 当前位置是字母，下一个位置是空格或者结束符，那就是结尾
            if((' ' != s[i]) && ((!s[i + 1]) || (' ' == s[i+1])))
            {
                nEnd = i;
                continue;
            }
            
            // 当前位置是空格，下一个位置是字母，那就是起始
            if((' ' == s[i]) && s[i+1] && (' ' != s[i+1]))
            {
                nBegin = i;
                continue;
            }
        }

        return nEnd - nBegin;
    }
};