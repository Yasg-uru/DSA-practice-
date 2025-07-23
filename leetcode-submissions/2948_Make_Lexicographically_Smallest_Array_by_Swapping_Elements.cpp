class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<int> vec = nums;
        sort(vec.begin(), vec.end());

        unordered_map<int, int> numToGroup;
        unordered_map<int, list<int>> groupToNum;

        int groupNumber = 0;
        numToGroup[vec[0]] = groupNumber;
        groupToNum[groupNumber].push_back(vec[0]);

        for (int i = 1; i < vec.size(); i++) {
            if (abs(vec[i] - vec[i - 1]) > limit) {
                groupNumber++;
            }
            numToGroup[vec[i]] = groupNumber;
            groupToNum[groupNumber].push_back(vec[i]);
        }

        vector<int> result(vec.size());
        for (int i = 0; i < vec.size(); i++) {
            int num = nums[i];
            int group = numToGroup[num];
            result[i] = groupToNum[group].front();
            groupToNum[group].pop_front();
        }

        return result;
    }
};
