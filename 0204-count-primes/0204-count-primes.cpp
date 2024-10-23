class Solution {
public:
    int countPrimes(int n) {
        vector<bool> prime(n, true);
        int count = 0;
        for (int i = 2; i <= n - 1; i++) {
            if (prime[i]) {
                count++;
                int j = 2*i;
                while (j <= n - 1) {
                    prime[j] = false;
                    j += i;
                }
            }
        }
        return count;
    }
};