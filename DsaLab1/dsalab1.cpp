#include <iostream>
#include <string>
#include <sstream>

using namespace std;

template <class T>
class SLinkedList {
public:
	class Node; // Forward declaration
protected:
	Node* head;
	Node* tail;
	int count;
public:
	SLinkedList() : head(NULL), tail(NULL), count(0) {};
	~SLinkedList() { this->clear(); };
	void    add(const T& e);
	void    add(int index, const T& e);
	int     size();
	bool    empty();
	void    clear();
	T       get(int index);
	void    set(int index, const T& e);
	int     indexOf(const T& item);
	bool    contains(const T& item);
	T       removeAt(int index);
	bool    removeItem(const T& removeItem);
	string  toString() {
		stringstream ss;
		ss << "[";
		Node* ptr = head;
		while (ptr != tail) {
			ss << ptr->data << ",";
			ptr = ptr->next;
		}

		if (count > 0)
			ss << ptr->data << "]";
		else
			ss << "]";
		return ss.str();
	}

public:
	class Node {
	private:
		T data;
		Node* next;
		friend class SLinkedList<T>;
	public:
		Node() {
			next = 0;
		}
		Node(Node* next) {
			this->next = next;
		}
		Node(T data, Node* next = NULL) {
			this->data = data;
			this->next = next;
		}
	};
};

template <class T>
void SLinkedList<T>::add(const T& e) {
	/* Insert an element into the end of the list. */
	Node* nNode = new Node;
	nNode->data = e;
	nNode->next = NULL;
	if (this->count == 0)
		this->head = nNode;
	else
		this->tail->next = nNode;
	this->tail = nNode;
	this->count++;
}

template<class T>
void SLinkedList<T>::add(int index, const T& e) {
	/* Insert an element into the list at given index. */
	Node* iNode = new Node;
	iNode->data = e;
	if (index == 0) {
		if (this->count == 0) {
			add(e);
			this->count--;
		}
		else {
			iNode->next = this->head;
			this->head = iNode;
		}
	}
	else {
		Node* PrevNode = this->head;
		for (int i = 0; i < index - 1; i++) {
			PrevNode = PrevNode->next;
			if (PrevNode->next == NULL)
				break;
		}
		iNode->next = PrevNode->next;
		PrevNode->next = iNode;
		if (iNode->next == NULL)
			this->tail = iNode;
	}
	this->count++;
}

template<class T>
int SLinkedList<T>::size() {
	/* Return the length (size) of list */
	return this->count;
}

template<class T>
T SLinkedList<T>::get(int index) {
	/* Give the data of the element at given index in the list. */
	if (index == 0)
		return this->head->data;
	else {
		Node* gNode = this->head->next;
		for (int i = 1; i < index; i++) {
			gNode = gNode->next;
		}
		return gNode->data;
	}
}

template <class T>
void SLinkedList<T>::set(int index, const T& e) {
	/* Assign new value for element at given index in the list */
	if (index == 0)
		this->head->data = e;
	else {
		Node* sNode = this->head->next;
		for (int i = 1; i < index; i++) {
			sNode = sNode->next;
		}
		sNode->data = e;
	}
}

template<class T>
bool SLinkedList<T>::empty() {
	/* Check if the list is empty or not. */
	return (this->count == 0);
}

template<class T>
int SLinkedList<T>::indexOf(const T& item) {
	/* Return the first index wheter item appears in list, otherwise return -1 */
	Node* indexofNode = this->head;
	for (int i = 0; i < this->count; i++) {
		if (indexofNode->data == item)
			return i;
		indexofNode = indexofNode->next;
	}
	return -1;
}

template<class T>
bool SLinkedList<T>::contains(const T& item) {
	/* Check if item appears in the list */
	Node* containNode = this->head;
	for (int i = 0; i < this->count; i++) {
		if (containNode->data == item)
			return 1;
		containNode = containNode->next;
	}
	return 0;
}
template <class T>
T SLinkedList<T>::removeAt(int index)
{
	/* Remove element at index and return removed value */
	int a;
	Node* rNode = new Node;
	if (index == 0) {
		a = this->head->data;
		rNode = this->head;
		this->head = this->head->next;
	}
	else {
		rNode = this->head->next;
		Node* PrevNode = this->head;
		for (int i = 1; i < index; i++) {
			rNode = rNode->next;
			PrevNode = PrevNode->next;
		}
		PrevNode->next = rNode->next;
		a = rNode->data;
		if (PrevNode->next == NULL)
			this->tail = PrevNode;
	}
	delete rNode;
	this->count--;
	return a;
}

template <class T>
bool SLinkedList<T>::removeItem(const T& item)
{
	/* Remove the first apperance of item in list and return true, otherwise return false */
	Node* riNode = this->head;
	for (int i = 0; i < this->count; i++) {
		if (riNode->data == item) {
			removeAt(i);
			return 1;
		}
		riNode = riNode->next;
	}
	return 0;
}

template<class T>
void SLinkedList<T>::clear() {
	/* Remove all elements in list */
	while(this->head != NULL) {
		Node* cNode = this->head;
		this->head = this->head->next;
		delete cNode;
		this->count--;
	}
	this->tail = NULL;
}

int main() {
	/*SLinkedList<int> list;
	int size = 10;

	for (int index = 0; index < size; index++) {
		list.add(index);
	}
	list.add(0, 11);
	list.add(2, 21);
	list.add(12, 121);
	cout << list.toString() << "\nSize: " << list.size();*/

	/*SLinkedList<int> list;
	int values[] = { 10, 15, 2,  6,  4,  7,  40,  8 };
	int index[] = { 0,  0,  1,  3,  2,  3,  5,   0 };
	int expvalues[] = { 8,  15, 2,  4,  7, 10,  40,  6 };

	for (int idx = 0; idx < 8; idx++) {
		list.add(index[idx], values[idx]);
	}*/

	//assert(list.size() == 8);

	//for (int idx = 0; idx < 8; idx++) {
	//	assert(list.get(idx) == expvalues[idx]);
	//}

	//cout << list.toString();
	SLinkedList<int> list;
	int size = 10;

	for (int index = 0; index < size; index++) {
		list.add(index);
	}
	cout << list.get(9) << endl;
	cout << list.toString() << "\nSize: " << list.size();
	return 0;
}