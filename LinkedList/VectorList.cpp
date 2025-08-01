#include <iostream>
#include <vector>
using namespace std;

template<typename T>
struct Node {
    T data;
    int next; // Index of the next node in the vector
};

template<typename T>
class VectorList {
private:
    vector<Node<T>> nodes;
    int head;
    int freeIndex;

    int allocateNode(T data) {
        if (freeIndex == -1) {
            nodes.push_back({data, -1});
            return nodes.size() - 1;
        } else {
            int index = freeIndex;
            freeIndex = nodes[index].next;
            nodes[index] = {data, -1};
            return index;
        }
    }

    void freeNode(int index) {
        nodes[index].next = freeIndex;
        freeIndex = index;
    }

public:
    VectorList(int capacity) : nodes(capacity), head(-1), freeIndex(0) {
        for (int i = 0; i < capacity - 1; ++i) {
            nodes[i].next = i + 1;
        }
        nodes[capacity - 1].next = -1;
    }

    void insert_to_head(T x) {
        int newIndex = allocateNode(x);
        nodes[newIndex].next = head;
        head = newIndex;
    }

    void insert_to_tail(T x) {
        int newIndex = allocateNode(x);
        if (head == -1) {
            head = newIndex;
        } else {
            int current = head;
            while (nodes[current].next != -1) {
                current = nodes[current].next;
            }
            nodes[current].next = newIndex;
        }
    }

    void remove(T x) {
        if (head == -1) return;
        if (nodes[head].data == x) {
            int temp = head;
            head = nodes[head].next;
            freeNode(temp);
            return;
        }
        int current = head;
        while (nodes[current].next != -1 && nodes[nodes[current].next].data != x) {
            current = nodes[current].next;
        }
        if (nodes[current].next != -1) {
            int temp = nodes[current].next;
            nodes[current].next = nodes[temp].next;
            freeNode(temp);
        }
    }

    void print_vector() const {
        cout << "Elements in the linked list: ";
        for (int i = head; i != -1; i = nodes[i].next) {
            cout << nodes[i].data << " ";
        }
        cout << endl;
    }
};

int main() {
    int capacity;
    cout << "Enter the capacity of the vector list: ";
    cin >> capacity;
    VectorList<int> vList(capacity);
    int choice, value;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Insert to head\n";
        cout << "2. Insert to tail\n";
        cout << "3. Remove element\n";
        cout << "4. Print vector\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter element to insert at head: ";
                cin >> value;
                vList.insert_to_head(value);
                break;
            case 2:
                cout << "Enter element to insert at tail: ";
                cin >> value;
                vList.insert_to_tail(value);
                break;
            case 3:
                cout << "Enter element to remove: ";
                cin >> value;
                vList.remove(value);
                break;
            case 4:
                vList.print_vector();
                break;
            case 5:
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}