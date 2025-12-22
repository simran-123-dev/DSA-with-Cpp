class Solution {
public:
    // Main function called by LeetCode
    double myPow(double x, int n) {
        // Base case
        if (n == 0) return 1;

        // Convert to long long to safely handle INT_MIN
        long long N = n;

        // Handle negative power
        if (N < 0) {
            x = 1 / x;   // x^(-n) = (1/x)^n
            N = -N;
        }

        // Call recursive helper
        return power(x, N);
    }

private:
    // Recursive helper function
    double power(double x, long long n) {
        // Base case
        if (n == 0) return 1;

        // Recursive call (divide the problem)
        double half = power(x, n / 2);

        // If n is even
        if (n % 2 == 0) {
            return half * half;
        }
        // If n is odd
        else {
            return x * half * half;
        }
    }
};


// tc O(lob n)
