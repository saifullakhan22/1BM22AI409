#include <iostream>
#include <ctime>

using namespace std;

void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int N;
    cout << "Enter the number of elements (N): ";
    cin >> N;

    int arr[N];
    cout << "Enter " << N << " integers:" << endl;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    clock_t start_time = clock(); // Record the start time

    insertionSort(arr, N);

    clock_t end_time = clock(); // Record the end time
    double time_taken = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;

    cout << "Sorted array: ";
    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Time taken to sort " << N << " elements: " << time_taken << " seconds" << endl;

    return 0;
}
