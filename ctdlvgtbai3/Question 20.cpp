#include <sstream>
#include <string>
#include <iostream>

using namespace std;

template <class T>
class DLinkedList {
public:
	class Node; // Forward declaration
	class Iterator;
protected:
	Node* head;
	Node* tail;
	int count;
public:
	DLinkedList() : head(NULL), tail(NULL), count(0) {};
	~DLinkedList() {};
	void    add(const T& e);
	void    add(int index, const T& e);
	int     size();
	bool    empty();
	T       get(int index);
	void    set(int index, const T& e);
	int     indexOf(const T& item);
	bool    contains(const T& item);
	T       removeAt(int index);
	bool    removeItem(const T& item);
	void    clear();
	Iterator begin()
	{
		return Iterator(this, true);
	}
	Iterator end()
	{
		return Iterator(this, false);
	}
public:
	class Node
	{
	private:
		T data;
		Node* next;
		Node* previous;
		friend class DLinkedList<T>;
		Iterator begin()
		{
			return Iterator(this, true);
		}
		Iterator end()
		{
			return Iterator(this, false);
		}

	public:
		Node()
		{
			this->previous = NULL;
			this->next = NULL;
		}

		Node(const T& data)
		{
			this->data = data;
			this->previous = NULL;
			this->next = NULL;
		}
	};
	class Iterator
	{
	private:
		DLinkedList<T>* pList;
		Node* current;
		int index; // is the index of current in pList
	public:
		Iterator(DLinkedList<T>* pList, bool begin);
		Iterator& operator=(const Iterator& iterator);
		void set(const T& e);
		T& operator*();
		bool operator!=(const Iterator& iterator);
		void remove();

		// Prefix ++ overload
		Iterator& operator++();

		// Postfix ++ overload
		Iterator operator++(int);
	};
	string toString()
	{
		stringstream ss;
		ss << "[";
		Node* ptr = head;
		while (ptr != tail)
		{
			ss << ptr->data << ",";
			ptr = ptr->next;
		}
		if (count > 0)
			ss << ptr->data << "]";
		else
			ss << "]";
		return ss.str();
	}
};

template <class T>
void DLinkedList<T>::add(const T& e) {
	/* Insert an element into the end of the list. */
	Node* nNode = new Node;
	nNode->data = e;
	nNode->next = NULL;
	if (this->count == 0) {
		this->head = nNode;
		this->tail = nNode;
		nNode->previous = NULL;
	}
	else {
		Node* pNode = this->head;
		while (pNode->next != NULL) {
			pNode = pNode->next;
		}
		pNode->next = nNode;
		nNode->previous = pNode;
	}
	this->tail = nNode;
	this->count++;
}

template<class T>
void DLinkedList<T>::add(int index, const T& e) {
	/* Insert an element into the list at given index. */
	if (index > this->count)
		throw std::out_of_range("The index is out of range!");
	else {
		Node* iNode = new Node;
		iNode->data = e;
		iNode->next = NULL;
		if (index == 0) {
			if (this->count == 0) {
				this->head = iNode;
				this->tail = iNode;
				iNode->previous = NULL;
				iNode->next = NULL;
			}
			else {
				this->head->previous = iNode;
				iNode->next = this->head;
				iNode->previous = NULL;
				this->head = iNode;
			}
		}
		else if (index == this->count) {
			Node* pNode = this->head;
			while (pNode->next != NULL) {
				pNode = pNode->next;
			}
			pNode->next = iNode;
			iNode->previous = pNode;
		}
		else {
			Node* PrevNode = this->head;
			Node* NextNode = this->head;
			for (int i = 0; i < index; i++) {
				if (i < index - 1) {
					PrevNode = PrevNode->next;
				}
				NextNode = NextNode->next;
			}
			PrevNode->next = iNode;
			iNode->previous = PrevNode;
			iNode->next = NextNode;
			NextNode->previous = iNode;
		}
		this->tail = iNode;
		this->count++;
	}
}

template<class T>
int DLinkedList<T>::size() {
	/* Return the length (size) of list */
	return this->count;
}

template <class T>
T DLinkedList<T>::removeAt(int index)
{
	/* Remove element at index and return removed value */
	if (index > this->count)
		throw std::out_of_range("The index is out of range!");
	else {
		Node* rNode = this->head;
		T a;
		if (index == 0) {
			if (this->count == 1) {
				a = rNode->data;
				this->head = NULL;
				this->tail = NULL;
			}
			else {
				a = rNode->data;
				this->head = this->head->next;
				this->head->previous = NULL;
			}
		}
		else if (index == this->count - 1) {
			Node* nNode = this->head;
			while (rNode->next != NULL) {
				rNode = rNode->next;
			}
			a = rNode->data;
			nNode = rNode->previous;
			nNode->next = NULL;
		}
		else {
			Node* PrevNode = this->head;
			Node* NextNode = this->head->next;
			for (int i = 0; i < index; i++) {
				if (i < index - 1)
					PrevNode = PrevNode->next;
				NextNode = NextNode->next;
				rNode = rNode->next;
			}
			a = rNode->data;
			PrevNode->next = NextNode;
			NextNode->previous = PrevNode;
		}
		this->count--;
		delete rNode;
		return a;
	}
}

template <class T>
bool DLinkedList<T>::removeItem(const T& item)
{
	/* Remove the first apperance of item in list and return true, otherwise return false */
	Node* pNode = this->head;
	for (int i = 0; i < this->count; i++) {
		if (pNode->data == item) {
			removeAt(i);
			return 1;
		}
		else
			pNode = pNode->next;
	}
	return 0;

}

template<class T>
void DLinkedList<T>::clear() {
	/* Remove all elements in list */
	while (this->head != NULL) {
		Node* cNode = this->head;
		this->head = this->head->next;
		delete cNode;
		this->count--;
	}
	this->tail = NULL;
}
template<class T>
T DLinkedList<T>::get(int index) {
	/* Give the data of the element at given index in the list. */
	T a;
	Node* gNode = this->head;
	for (int i = 0; i <= index; i++) {
		a = gNode->data;
		if (i == index)
			break;
		gNode = gNode->next;
	}
	return a;
}

template <class T>
void DLinkedList<T>::set(int index, const T& e) {
	/* Assign new value for element at given index in the list */
	Node* sNode = this->head;
	for (int i = 0; i <= index; i++) {
		if (i == index)
			sNode->data = e;
		sNode = sNode->next;
	}
}

template<class T>
bool DLinkedList<T>::empty() {
	/* Check if the list is empty or not. */
	return (this->count == 0);
}

template<class T>
int DLinkedList<T>::indexOf(const T& item) {
	/* Return the first index wheter item appears in list, otherwise return -1 */
	Node* indexNode = this->head;
	for (int i = 0; i < this->count; i++) {
		if (indexNode->data == item)
			return i;
		indexNode = indexNode->next;
	}
	return -1;
}

template<class T>
bool DLinkedList<T>::contains(const T& item) {
	/* Check if item appears in the list */
	Node* containNode = this->head;
	for (int i = 0; i < this->count; i++) {
		if (containNode->data == item)
			return 1;
		containNode = containNode->next;
	}
	return 0;
}

/*
 * TODO: Implement class Iterator's method
 * Note: method remove is different from SLinkedList, which is the advantage of DLinkedList
 */
template <class T>
DLinkedList<T>::Iterator::Iterator(DLinkedList<T>* pList, bool begin)
{
	this->pList = pList;
	if (!pList) {
		index = -1;
		current = NULL;
	}
	else {
		if (begin) {
			current = this->pList->head;
			index = 0;
		}
		else {
			index = this->pList->size();
			current = NULL;
		}
	}
}

template <class T>
typename DLinkedList<T>::Iterator& DLinkedList<T>::Iterator::operator=(const DLinkedList<T>::Iterator& iterator)
{
	this->pList = iterator.pList;
	this->current = iterator.current;
	this->index = iterator.index;
	return *this;
}

template <class T>
void DLinkedList<T>::Iterator::set(const T& e)
{
	this->current->data = e;
}

template<class T>
T& DLinkedList<T>::Iterator::operator*()
{
	if (this->current == NULL)
		throw std::out_of_range("Segmentation fault!");
	return this->current->data;
}

template<class T>
void DLinkedList<T>::Iterator::remove()
{
	/*
	* TODO: delete Node in pList which Node* current point to.
	*       After that, Node* current point to the node before the node just deleted.
	*       If we remove first node of pList, Node* current point to nullptr.
	*       Then we use operator ++, Node* current will point to the head of pList.
	*/
	this->current = this->current->previous;
	this->pList->removeAt(index);
	this->index--;
}

template<class T>
bool DLinkedList<T>::Iterator::operator!=(const DLinkedList::Iterator& iterator)
{
	return (this->index != iterator.index || this->current != iterator.current) ? 1 : 0;
}

template<class T>
typename DLinkedList<T>::Iterator& DLinkedList<T>::Iterator::operator++()
{
	if (this->index >= this->pList->size()) {
		this->index = this->pList->size();
		this->current = NULL;
	}
	else if (index < 0) {
		this->index = 0;
		this->current = this->pList->head;
	}
	else {
		this->index++;
		this->current = this->current->next;
	}
	return *this;
}

template<class T>
typename DLinkedList<T>::Iterator DLinkedList<T>::Iterator::operator++(int)
{
	
	if (this->index >= this->pList->size()) {
		this->index = this->pList->size();
		this->current = NULL;
	}
	Iterator temp = *this;
	if (index < 0) {
		this->index = 0;
		this->current = this->pList->head;
	}
	else {
		this->index++;
		this->current = this->current->next;
	}
	return temp;
}



int main() {
	/*DLinkedList<int> list;
	int size = 10;
	for (int idx = 0; idx < size; idx++) {
		list.add(idx);
	}
	DLinkedList<int>::Iterator it = list.begin();
	for (; it != list.end(); it++)
	{
		cout << *it << " |";
	}*/

	/*DLinkedList<int> list;
	int size = 10;
	for (int idx = 0; idx < size; idx++)
	{
		list.add(idx);
	}

	DLinkedList<int>::Iterator it = list.begin();
	for (; it != list.end(); it++)
	{
		it.remove();
	}
	cout << list.toString();*/

	DLinkedList<int> list;
	int values[] = { 10, 15, 2,  6,  4,  7,  40,  8 };
	//                0   1   2   3   4   5   6    7
	int index[] = { 0,  0,  1,  3,  2,  3,  5,   0 };
	for (int idx = 0; idx < 8; idx++) {
		list.add(index[idx], values[idx]);
	}
	cout << list.toString();
	return 0;
}