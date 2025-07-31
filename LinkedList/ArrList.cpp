#include <iostream>
#define MAX_N 100000
using namespace std;

// values[]: stores values, next_idx[]: stores next indices
int values[MAX_N];
int next_idx[MAX_N];
int head = -1; // index of the head node
int unused = 0; // next available index

// Insert x at the head
void insert_to_head(int x) {
    values[unused] = x;
    next_idx[unused] = head;
    head = unused++;
}

// Insert x after the k-th node (k is index in array, not position)
void insert_after(int k, int x) {
    values[unused] = x;
    next_idx[unused] = next_idx[k];
    next_idx[k] = unused++;
}

// Delete the node after the k-th node (k is index in array)
void delete_after(int k) {
    if (next_idx[k] != -1) {
        next_idx[k] = next_idx[next_idx[k]];
    }
}

// Delete the k-th node in the list (0-based position)
void delete_at(int pos) {
    if (head == -1) return; // List is empty
    if (pos == 0) {
        head = next_idx[head];
    } else {
        delete_after(pos - 1);
    }
}

// Print all elements in the list
void print_list() {
    for (int i = head; i != -1; i = next_idx[i]) {
        cout << values[i] << " ";
    }
    cout << endl;
}

// Insert x after the pos-th position (0-based, after head is pos=0)
void insert_after_pos(int pos, int x) {
    if (pos == -1) {
        // Insert before head (become new head)
        insert_to_head(x);
    } else {
        int cur = head;
        for (int i = 0; i < pos && cur != -1; i++) {
            cur = next_idx[cur];
        }
        if (cur != -1) {
            insert_after(cur, x);
        }
    }
}

int main() {
    int n, value;
    cout << "Enter number of elements to insert: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> value;
        insert_to_head(value);
    }

    cout << "Elements in the linked list: ";
    print_list();

    // Example: delete the 2nd element (0-based)
    // delete_at(1);
    // print_list();

    return 0;
}
