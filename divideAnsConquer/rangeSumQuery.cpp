class NumArray {
public:
    vector<int> bit;   // Fenwick Tree
    vector<int> nums;  // original array
    int n;

    // Constructor
    NumArray(vector<int>& nums) {
        this->nums = nums;
        n = nums.size();
        bit.resize(n + 1, 0);

        // Fenwick Tree build
        for (int i = 0; i < n; i++) {
            add(i + 1, nums[i]);
        }
    }

    // Add value to Fenwick Tree
    void add(int index, int val) {
        while (index <= n) {
            bit[index] += val;
            index += (index & -index);
        }
    }

    // Update operation
    void update(int index, int val) {
        int diff = val - nums[index];
        nums[index] = val;
        add(index + 1, diff);
    }

    // Prefix sum [1..index]
    int prefixSum(int index) {
        int sum = 0;
        while (index > 0) {
            sum += bit[index];
            index -= (index & -index);
        }
        return sum;
    }

    // Range sum [left..right]
    int sumRange(int left, int right) {
        return prefixSum(right + 1) - prefixSum(left);
    }
};
