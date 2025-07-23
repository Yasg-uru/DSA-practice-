class Solution {
public:
    void updateSegmentTree(int node, int start, int end, int indexToUpdate, vector<long long>& tree) {
        if (start == end) {
            tree[node] = 1;
            return;
        }

        int mid = start + (end - start) / 2;
        if (indexToUpdate <= mid) {
            updateSegmentTree(2 * node + 1, start, mid, indexToUpdate, tree);
        } else {
            updateSegmentTree(2 * node + 2, mid + 1, end, indexToUpdate, tree);
        }

        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }

    long long querySegmentTree(int queryLeft, int queryRight, int node, int start, int end, vector<long long>& tree) {
        if (end < queryLeft || start > queryRight) {
            return 0;
        }

        if (start >= queryLeft && end <= queryRight) {
            return tree[node];
        }

        int mid = start + (end - start) / 2;
        long long leftResult = querySegmentTree(queryLeft, queryRight, 2 * node + 1, start, mid, tree);
        long long rightResult = querySegmentTree(queryLeft, queryRight, 2 * node + 2, mid + 1, end, tree);
        return leftResult + rightResult;
    }

    long long goodTriplets(vector<int>& orderA, vector<int>& orderB) {
        int size = orderA.size();
        unordered_map<int, int> indexInB;
        for (int i = 0; i < size; i++) {
            indexInB[orderB[i]] = i;
        }

        vector<long long> tree(4 * size);
        long long totalTriplets = 0;

        updateSegmentTree(0, 0, size - 1, indexInB[orderA[0]], tree);

        for (int i = 1; i < size; i++) {
            int currentIndex = indexInB[orderA[i]];
            long long commonOnLeft = querySegmentTree(0, currentIndex, 0, 0, size - 1, tree);
            long long notCommonOnLeft = i - commonOnLeft;
            long long remainingOnRight = (size - 1) - currentIndex;
            long long commonOnRight = remainingOnRight - notCommonOnLeft;
            totalTriplets += commonOnLeft * commonOnRight;

            updateSegmentTree(0, 0, size - 1, currentIndex, tree);
        }

        return totalTriplets;
    }
};
