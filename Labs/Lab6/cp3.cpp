#include <iostream>

class Node {
public:
    Node(int value, Node* next) : value(value), next(next) {}

    int value;
    Node* next;
};

int main() {
    // Dynamically allocate the nodes on the heap
    Node* node1 = new Node(1, nullptr);
    Node* node2 = new Node(2, nullptr);
    Node* node3 = new Node(3, nullptr);
    Node* node4 = new Node(4, nullptr);

    // Link the nodes together
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;

    // Create a variable on the stack pointing to the first node
    Node* my_list = node1;

    // Use the variable to access the nodes in the list
    std::cout << "The first node in the list has value " << my_list->value << "\n";
    std::cout << "The second node in the list has value " << my_list->next->value << "\n";
    std::cout << "The third node in the list has value " << my_list->next->next->value << "\n";
    std::cout << "The fourth node in the list has value " << my_list->next->next->next->value << "\n";

    // Free the memory allocated on
