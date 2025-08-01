#include <iostream>
using namespace std;

#define eleType int

struct ListNode {
    eleType value;
    ListNode* next;
    ListNode(eleType val) : value(val), next(nullptr) {}
};

class DynamicList {
private:
    ListNode* head; // Pointer to the head of the list 
public:
    DynamicList() : head(nullptr) {}
    ~DynamicList() {
        while (head) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
        }
    }
    void insert_to_head(eleType x) {
        ListNode* newNode = new ListNode(x);
        newNode->next = head;
        head = newNode;
    }
    void insert_to_tail(eleType x) {
        ListNode* newNode = new ListNode(x);
        if (!head) {
            head = newNode;
        } else {
            ListNode* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = newNode;
        }
    }
    void remove(eleType x) {
        if (!head) return; // List is empty
        if (head->value == x) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        ListNode* current = head;
        while (current->next && current->next->value != x) {
            current = current->next;
        }
        if (current->next) {
            ListNode* temp = current->next;
            current->next = current->next->next;
            delete temp;
        }
    }
    void print_list() const {
        cout << "Elements in the linked list: ";
        ListNode* current = head;
        while (current) {
            cout << current->value << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    DynamicList list;
    int n, value;
    cout << "Enter number of elements to insert: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> value;
        list.insert_to_head(value);
    }

    cout << "Elements in the linked list: ";
    list.print_list();

    // Example: remove an element
    // list.remove(3);
    // list.print_list();

    return 0;
}