#include <iostream>
#include <stack>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    vector<int> arr(n + 1);
    vector<int> res(n + 1);
    arr.push_back(INT_MAX);
    res.push_back(0); 
    cout << "Enter the elements of the array";
    for (int i = 1; i <= n; i ++) cin >> arr[i];

    // show the first element bigger than the current element on the left side
    stack<int> s;
    // In theory, it won't be pop out, we push it to avoid empty stack
    s.push(0);

    for (int i = 1; i <= n; i++) {
        while (!s.empty() && arr[s.top()] < arr[i]) {
            s.pop();
        }
        if (!s.empty()) {
            res[i] = arr[s.top()];
        }
        s.push(i);
    }

    for (int i = 1; i <= n; i++) {
        if (res[i] == 0) {
            cout << "No element bigger than " << arr[i] << " on the left side." << endl;
        } else {
            cout << "The first element bigger than " << arr[i] << " on the left side is: " << res[i] << endl;
        }
    }

    return 0;
}