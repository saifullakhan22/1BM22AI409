#include <iostream>
using namespace std;

int binomial_coefficient(int n, int k) {
    // Create a 2D array to store binomial coefficients
    int dp[n + 1][k + 1];

    // Fill in the base cases: C(n, 0) = C(n, n) = 1
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1;
        dp[i][i] = 1;
    }

    // Calculate binomial coefficients using dynamic programming
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= min(i, k); j++) {
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        }
    }

    return dp[n][k];
}

int main() {
    int n = 5;
    int k = 4;
    int result = binomial_coefficient(n, k);
    cout << "The binomial coefficient C(" << n << ", " << k << ") is: " << result << endl;

    return 0;
}
