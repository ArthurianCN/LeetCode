/*
题目描述：
    给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。
    你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。
    你可以按任意顺序返回答案。
解法思路：
    将vector的索引作为key，对应的值作为value，存储到unordered_map里面，然后遍历一次即可
*/


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> um;
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i) {
            um[nums[i]] = i;
        }
        for (int i = 0; i < nums.size(); ++i) {
            int t = target - nums[i];
            if (um.count(t) && um[t] != i) {
                res.push_back(i);
                res.push_back(um[t]);
                break;
            }
        }
        return res;
    }
};