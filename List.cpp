#include <iostream>
#include <assert.h>
 
struct Node {
    int val_;
    Node* next_;
};
 
struct List {
    size_t size_;
    Node* head_;
};
 
void Insert(List* list, Node* pos, int val) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->val_ = val;
    pos->next_ = node;
    list->size_++;
}

void Remove()
 
int main(const int argc, const char* argv[]) {
    List l;
    return 0;
}
 
