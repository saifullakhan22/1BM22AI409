 #include <iostream>
#include <vector>

using namespace std;

void displaySubset(const vector<int>& subset) {
    cout << "{ ";
    for (int i : subset) {
        cout << i << " ";
    }
    cout << "}" << endl;
}

void sumOfSubsetsUtil(const vector<int>& set, vector<int>& subset, int n, int sum, int currentSum, int startIndex) {
    if (currentSum == sum) {
        displaySubset(subset);
        return;
    }

    for (int i = startIndex; i < n; i++) {
        if (currentSum + set[i] <= sum) {
            subset.push_back(set[i]);
            sumOfSubsetsUtil(set, subset, n, sum, currentSum + set[i], i + 1);
            subset.pop_back();
        }
    }
}

void sumOfSubsets(const vector<int>& set, int n, int sum) {
    vector<int> subset;
    sumOfSubsetsUtil(set, subset, n, sum, 0, 0);
}

int main() {
    vector<int> set = {1, 2, 5, 6, 8};
    int n = set.size();
    int sum = 9;

    cout << "Subsets with sum " << sum << " are:" << endl;
    sumOfSubsets(set, n, sum);

    return 0;
}
