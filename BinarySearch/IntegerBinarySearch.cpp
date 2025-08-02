#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 找最小的 index，使 arr[index] >= target
int lower_bound_bs(const vector<int>& arr, int target) {
    int left = -1, right = arr.size();
    while (left + 1 < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] >= target) right = mid;
        else left = mid;
    }
    return right;
}

// 找最大的 index，使 arr[index] < target
int upper_bound_bs(const vector<int>& arr, int target) {
    int left = -1, right = arr.size();
    while (left + 1 < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] < target) left = mid;
        else right = mid;
    }
    return left;
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements of the array(sorted): ";
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());
    int target;
    cout << "Enter the target value: ";
    cin >> target;

    int idx = lower_bound_bs(arr, target);
    if (idx < n)
        cout << "The smallest index with value >= " << target << " is: " << idx << endl;
    else
        cout << "No value >= " << target << endl;

    idx = upper_bound_bs(arr, target);
    if (idx >= 0)
        cout << "The largest index with value < " << target << " is: " << idx << endl;
    else
        cout << "No value < " << target << endl;

    return 0;
}