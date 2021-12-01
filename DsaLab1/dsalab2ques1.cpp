#include <iostream>
#include <sstream>


using namespace std;


template <class T>
class DLinkedList {
public:
	class Node; // Forward declaration
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
	T get(int index);
	void set(int index, const T& e);
	bool empty();
	int indexOf(const T& item);
	bool contains(const T& item);
	T removeAt(int index);
	bool removeItem(const T& item);
	void clear();
public:
	class Node
	{
	private:
		T data;
		Node* next;
		Node* previous;
		friend class DLinkedList<T>;

	public:
		Node()
		{
			this->data = 0;
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
		if (this->count == 0) {
			this->head = nNode;
			this->tail = nNode;
			nNode->previous = NULL;
			nNode->next = NULL;
		}
		else {
			this->tail->next = nNode;
			nNode->previous = this->tail;
			this->tail = nNode;
			nNode->next = NULL;
		}
		this->count++;
	}

	template<class T>
	void DLinkedList<T>::add(int index, const T& e) {
		/* Insert an element into the list at given index. */
		Node* iNode = new Node;
		iNode->data = e;
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
			this->tail->next = iNode;
			iNode->previous = this->tail;
			iNode->next = NULL;
			this->tail = iNode;
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
		this->count++;
	}

	template<class T>
	int DLinkedList<T>::size() {
		/* Return the length (size) of list */
		return this->count;
	}
	template<class T>
	T DLinkedList<T>::get(int index) {
		/* Give the data of the element at given index in the list. */
		Node* gNode = this->head;
		for (int i = 0; i <= index; i++) {
			if (i == index)
				return gNode->data;
			gNode = gNode->next;
		}
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
		/* Return the first index whether item appears in list, otherwise return -1 */
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
	template <class T>
	T DLinkedList<T>::removeAt(int index)
	{
		/* Remove element at index and return removed value */
		Node* rNode = this->head;
		int a;
		if (index == 0) {
			if (this->count == 1) {
				a = this->head->data;
				this->head = NULL;
				this->tail = NULL;
			}
			else {
				a = this->head->data;
				this->head = this->head->next;
				this->head->previous = NULL;
			}
		}
		else if (index == this->count - 1) {
			a = this->tail->data;
			this->tail = this->tail->previous;
			this->tail->next = NULL;
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
		/*for (int i = 0; i <= this->count; i++) {
			Node* cNode = this->head;
			this->head = this->head->next;
			delete cNode;
			this->count--;
		}*/
		while (this->head != NULL) {
			Node* cNode = this->head;
			this->head = this->head->next;
			delete cNode;
			this->count--;
		}
		this->tail = NULL;
	}
	template<class T>
	class Stack {
	protected:
		DLinkedList<T> list;
	public:
		Stack() {};
		void push(T item){
			/*Node* nNode = new Node;
			nNode->data = e;
			if (this->count == 0) {
				this->head = nNode;
				this->tail = nNode;
				nNode->previous = NULL;
				nNode->next = NULL;
			}
			else {
				this->head->previous = nNode;
				nNode->next = this->head;
				this->head = nNode;
				nNode->previous = NULL;
			}
			this->count++;*/
			list.add(0, item);
		}
		T pop() {
			return list.removeAt(0);
		}
		T top() {
			return list.get(0);
		}
		bool empty() {
			return list.empty();
		}
		int size() {
			return list.size();
		}
		void clear() {
			list.clear();
		}
	};
	template<class T>
	class Queue {
	protected:
		DLinkedList<T> list;
	public:
		Queue() {};
		void push(T item) {
			list.add(item);
		}
		T pop() {
			return list.removeAt(0);
		}
		T top() {
			return list.get(0);
		}
		bool empty() {
			return list.empty();
		}
		int size() {
			return list.size();
		}
		void clear() {
			list.clear();
		}
	};


int main() {
	/*DLinkedList<int> list;
	int size = 10;
	for (int idx = 0; idx < size; idx++) {
		list.add(idx);
	}
	cout << list.toString() << endl;
	cout << list.size() << endl;*/
	//list.add(0, 111);
	//list.add(11, 20);
	//list.add(5, 222);
	/*cout << list.get(0) << endl;
	cout << list.get(5) << endl;
	list.set(0, 11);
	list.set(5, 15);*/
	//cout << list.toString() << endl;
	//cout << list.size() << endl;
	//cout << list.indexOf(15) << endl;
	//cout << list.contains(5) << '\t' << list.contains(0) << '\t' << list.contains(9) << '\t' << list.contains(10) << endl;
	//DLinkedList<int> list;
	//int size = 10;
	//int value[] = { 2,5,6,3,67,332,43,1,0,9 };

	//for (int idx = 0; idx < size; idx++) {
	//	list.add(value[idx]);
	//}
	////list.removeAt(0);
	////cout <<	list.removeItem(0);
	//cout << list.toString() << endl;
	//cout << list.size() << endl;
	//list.clear();
	//cout << list.toString() << endl;
	//cout << list.size();
	Queue<int> stack;

	int item[] = { 3, 1, 4, 5, 2, 8, 10, 12 };
	for (int idx = 0; idx < 8; idx++) stack.push(item[idx]);

	

	stack.pop();
	stack.pop();

	cout << stack.top();
}