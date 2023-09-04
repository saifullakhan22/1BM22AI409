#include <iostream>

using namespace std;

void findSubsetsWithSum(int S[], int n, int d, int subset[], int subsetSize, int startIndex) {
    if (d == 0) {
        // If the target sum becomes 0, we found a valid subset
        for (int i = 0; i < subsetSize; ++i) {
            cout << subset[i] << " ";
        }
        cout << endl;
        return;
    }

    for (int i = startIndex; i < n; ++i) {
        if (d - S[i] >= 0) {
            // Include the current element in the subset
            subset[subsetSize] = S[i];
            findSubsetsWithSum(S, n, d - S[i], subset, subsetSize + 1, i + 1);

            // Exclude the current element from the subset
        }
    }
}

int main() {
    int S[] = {1, 2, 5, 6, 8};
    int n = sizeof(S) / sizeof(S[0]);
    int d = 9;
    int subset[n];

    findSubsetsWithSum(S, n, d, subset, 0, 0);

    return 0;
}
