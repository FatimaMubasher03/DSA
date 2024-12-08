#include <iostream>
#include <unordered_set>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
public:
    Node* head;
    LinkedList() : head(nullptr) {}

    void append(int value) {
        if (!head) {
            head = new Node(value);
            return;
        }
        Node* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = new Node(value);
    }

    void printUnique() {
        unordered_set<int> uniqueSet;
        Node* current = head;
        while (current) {
            if (uniqueSet.find(current->data) == uniqueSet.end()) {
                cout << current->data << " ";
                uniqueSet.insert(current->data);
            }
            current = current->next;
        }
        cout << endl;
    }
    
    
    void printList() {
        Node* current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main(){
	LinkedList list;
	list.append(15);
	list.append(5);
	list.append(13);
	list.append(7);
	list.append(6);
	list.append(13);
	list.append(7);
	list.append(5);
	list.append(4);
	list.append(3);
	list.append(4);
	
	cout << "Elements: ";
	list.printList();
	 	
	
	cout << "Output: ";
    list.printUnique();
    
    return 0;
}
