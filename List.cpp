#include <iostream>
#include <assert.h>
#include <locale>

struct Node {
	int val_;
	Node* next_;
};

struct List {
	size_t size_;
	Node* head_;
};

void NewList(List* name)
{
	name->head_ = nullptr;
	name->size_ = 0;
}

Node* Insert(List* list, Node* pos, int val) {
	Node* node = (Node*)malloc(sizeof(Node));
	if (node == nullptr)
	{
		std::cout << "Memory error";
		return nullptr;
	}
	node->val_ = val;
	if (pos == nullptr)
	{
		list->head_ = node;
		node->next_ = nullptr;
	}
	else
	{
		node->next_ = pos->next_;
		pos->next_ = node;
	}
	list->size_++;
	return node;
}

void Remove(List* list, Node* pos)
{
	if (list->size_ == 0)
	{
		return;
	}
	if (pos->next_ == nullptr)
	{
		return;
	}
	if (pos == nullptr)
	{
		Node* buffer = list->head_->next_;
		free (list->head_);
		list->head_ = buffer;
		list->size_--;
	}
	else
	{
		Node* removed_node = pos->next_;
		pos->next_ = pos->next_->next_;
		free(removed_node);
		list->size_--;
	}
}

void Dump(List* list)
{
	std::cout << "размер структуры " << list->size_ << '\n';
	Node* node = list->head_;
	int count = 1;
	while (node != nullptr)
	{
		std::cout << count++ << "элемент" << '\n';
		std::cout << "ссылка на элемент структуры " << node << '\n';
		std::cout << "ссылка на следующий элемент структуры " << node->next_ << '\n';
		std::cout << "хранимое значение в данном элементе структуры " << node->val_ << '\n' << '\n';
		node = node->next_;
	}
	std::cout << '\n';
}

int main() {
	setlocale(LC_ALL, "Russian");
	List One;
	NewList(&One);
	Node* firstElem = Insert(&One, nullptr, 1);
	Node* secondElem = Insert(&One, firstElem, 2);
	Node* thirdElem = Insert(&One, secondElem, 3);
	Dump(&One);
	Remove(&One, secondElem);
	Dump(&One);
}

