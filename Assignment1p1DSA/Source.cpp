#include <sstream>
#include <string>
#include <iostream>
#include <type_traits>
using namespace std;
int n = 5;
#ifndef ILIST_H
#define ILIST_H

template <class T>
class IList
{
public:
	virtual void add(const T& element) = 0;
	virtual void add(int index, const T& element) = 0;
	virtual T removeAt(int index) = 0;
	virtual bool removeItem(const T& item) = 0;
	virtual bool empty() = 0;
	virtual int size() = 0;
	virtual void clear() = 0;
	virtual T get(int index) = 0;
	virtual void set(int index, const T& element) = 0;
	virtual int indexOf(const T& item) = 0;
	virtual bool contains(const T& item) = 0;
	virtual string toString() = 0;
};

#endif

// STUDENT ANSWER
#ifndef FRAGMENT_LINKED_LIST
#define FRAGMENT_LINKED_LIST
template <class T>
class FragmentLinkedList : IList<T>
{
public:
	class Node;
	class Iterator;

protected:
	Node** fragmentPointers;
	int fragmentMaxSize;
	int count;

public:
	FragmentLinkedList(int fragmentMaxSize = 5)
	{
		this->count = 0;
		this->fragmentMaxSize = fragmentMaxSize;
		this->fragmentPointers = new Node * [2];
		this->fragmentPointers[0] = NULL;
		this->fragmentPointers[1] = NULL;
	}
	virtual ~FragmentLinkedList();
	virtual void add(const T& element);
	virtual void add(int index, const T& element);
	virtual T removeAt(int index);
	virtual bool removeItem(const T& item);
	virtual bool empty();
	virtual int size();
	virtual void clear();
	virtual T get(int index);
	virtual void set(int index, const T& element);
	virtual int indexOf(const T& item);
	virtual bool contains(const T& item);
	virtual string toString();
	virtual void toStringFragmentPointers() {
		cout << endl;
		cout << "FragmentMaxSize: " << this->fragmentMaxSize << endl;
		for (int i = 0; i < n; i++) {
			cout << "FragmentPointer[" << i << "]: " << this->fragmentPointers[i]->data << endl;
		}
		/*cout << "FragmentPointer[0]: " << checkNode->data << endl;
		checkNode = this->fragmentPointers[1];
		cout << "FragmentPointer[1]: " << checkNode->data << endl;
		checkNode = this->fragmentPointers[2];
		cout << "FragmentPointer[2]: " << checkNode->data << endl;*/
		/*checkNode = this->fragmentPointers[3];
		cout << "FragmentPointer[3]: " << checkNode->data << endl;*/
	}
	Iterator begin(int index = 0);
	Iterator end(int index = -1);

public:
	class Node
	{
	private:
		T data;
		Node* next;
		Node* prev;
		friend class FragmentLinkedList<T>;

	public:
		Node()
		{
			next = 0;
			prev = 0;
		}
		Node(Node* next, Node* prev)
		{
			this->next = next;
			this->prev = prev;
		}
		Node(T data, Node* next, Node* prev)
		{
			this->data = data;
			this->next = next;
			this->prev = prev;
		}
	};

	class Iterator
	{
	private:
		FragmentLinkedList<T>* pList;
		Node* pNode;
		int index;

	public:
		Iterator(FragmentLinkedList<T>* pList = 0, bool begin = true) {
			this->pList = pList;
			if (pList == NULL) {
				index = -1;
				pNode = NULL;
			}
			else {
				if (begin) {
					pNode = pList->fragmentPointers[0];
					index = 0;
				}
				else {
					index = pList->size();
					pNode = NULL;
				}
			}
		}
		Iterator(int fragmentIndex, FragmentLinkedList<T>* pList = 0, bool begin = true) {
			this->pList = pList;
			if (pList == NULL) {
				pNode = NULL;
				index = -1;
			}
			//pNode = pList->fragmentPointers[0];
			else {
				if (fragmentIndex == -1) {
					pNode = NULL;
					index = pList->size();
				}
				else {
					for (int i = 0; i < fragmentIndex * pList->fragmentMaxSize; i++) {
						pNode = pNode->next;
						index = i;
					}
					if (!begin) {
						for (int i = 0; i < pList->fragmentMaxSize; i++) {
							pNode = pNode->next;
							index++;
						}
					}
				}
			}
		}
		Iterator& operator=(const Iterator& iterator) {
			this->pList = iterator.pList;
			this->pNode = iterator.pNode;
			this->index = iterator.index;
			return *this;
		}
		T& operator*() {
			//try {
				if (this->pNode == NULL)
					throw std::out_of_range("Segmentation fault!");
				return this->pNode->data;
			//}
			/*catch (std::out_of_range str) {
				cout << str.what();
			}*/
		}
		bool operator!=(const Iterator& iterator) {
			return (this->pNode != iterator.pNode || this->index != iterator.index) ? 1 : 0;
		}
		void remove() {
			this->pNode = this->pNode->prev;
			this->pList->removeAt(index);
			this->index--;
		}
		void set(const T& element) {
			this->pNode->data = element;
		}
		Iterator& operator++() {
			/*if (index >= pList->size())return *this;
			else {
				index++;
				if (index == 0)pNode = pList->fragmentPointers[0];
				else
					pNode = pNode->next;
				return *this;
			}*/
			if (this->index >= this->pList->size()) {
				this->index = this->pList->size();
				this->pNode = NULL;
			}
			if (this->index < 0) {
				index = 0;
				this->pNode = this->pList->fragmentPointers[0];
			}
			else {
				this->pNode = this->pNode->next;
				this->index++;
			}
			return *this;
		}
		Iterator operator++(int) {
			/*if (index >= pList->size())return *this;
			else {
				auto tmp = *this;

				index++;
				if (index == 0)pNode = pList->fragmentPointers[0];
				else
					this->pNode = this->pNode->next;
				return tmp;
			}*/
			if (this->index >= this->pList->size()) {
				this->index = this->pList->size();
				this->pNode = NULL;
			}
			Iterator current = *this;
			if (this->index < 0) {
				this->index = 0;
				this->pNode = this->pList->fragmentPointers[0];
			}
			else {
				this->index++;
				this->pNode = this->pNode->next;
			}
			return current;
		}
	};
};

template <class T>
string FragmentLinkedList<T>::toString()
{
	stringstream ss;
	ss << "[";
	Node* ptr = this->fragmentPointers[0];

	if (this->count == 0)
		ss << "]";

	// TODO
	else {
		while (ptr != NULL) {
			ss << ptr->data;
			if (ptr->next != NULL)
				ss << ", ";
			else
				ss << "]";
			ptr = ptr->next;
		}
		//ss << ptr->data << "]";
	}
	// END: TODO

	return ss.str();
}



#endif
// END: STUDENT ANSWER

int main()
{
	//FragmentLinkedList<int> test;

	//int j = 0;
	//for (int i = 0; i < 6; i++) 
	//	test.add(i);
	//
	////cout << test.toString() << endl;

	//int option;
	//int index, element;
	//int check = 1;
	//cout << "Is Empty?   " << test.empty() << endl;
	//cout << "Size: " << test.size() << endl;

	//while (check) {
	//	cout << "1. to add tail        2. to add          3. to remove index        4. to remove item        5. clear data\n";
	//	cout << "6. to get index       7. to set index    8. to check index of element        9. to check contains\n";
	//	cin >> option;
	//	switch (option) {
	//	case 1:
	//		cout << "Input the element: ";
	//		cin >> element;
	//		test.add(element);
	//		break;
	//	case 2:
	//		cout << "Input the index and element: ";
	//		cin >> index >> element;
	//		test.add(index, element);
	//		break;
	//	case 3:
	//		cout << "Input the index: ";
	//		cin >> index;
	//		cout << test.removeAt(index) << endl;
	//		break;
	//	case 4:
	//		cout << "Input the element: ";
	//		cin >> element;
	//		cout << "Remove complete: " << test.removeItem(element) << endl;
	//		break;
	//	case 5:
	//		test.clear();
	//		break;
	//	case 6:
	//		cout << "Input the index: ";
	//		cin >> index;
	//		cout << "The element at index: " << test.get(index) << endl;
	//		break;
	//	case 7:
	//		cout << "Input the index and element: ";
	//		cin >> index >> element;
	//		test.set(index, element);
	//		break;
	//	case 8:
	//		cout << "Input the element: ";
	//		cin >> element;
	//		cout << "The index of element: " << test.indexOf(element) << endl;
	//		break;
	//	case 9:
	//		cout << "Input the element: ";
	//		cin >> element;
	//		cout << "The list has the element: " << test.contains(element) << endl;
	//		break;
	//	default:
	//		break;
	//	}
	//	cout << test.toString() << endl;
	//	cout << "Continues ?";
	//	cin >> check;
	//	cout << "Is Empty?   " << test.empty() << endl;
	//	cout << "Size: " << test.size() << endl;
	//}

	/*FragmentLinkedList<int> list;
	cout << list.size();*/

	/*FragmentLinkedList<int> fList;

	for (int i = 0; i < 20; i++)
		    fList.add(i, i * i);

	for(FragmentLinkedList<int>::Iterator it = fList.begin(); it != fList.end(); it++)
		    cout << *it << " ";
	cout << endl;*/
	//test.toStringFragmentPointers();
	FragmentLinkedList<int> fList;
	for (int i = 0; i < 20; i++)
		fList.add(i, i);
	fList.set(0, 5);
	/*fList.add(1,2);
	fList.add(5 ,3);
	cout << fList.toString() << endl;
	fList.removeItem(6);
    int i= fList.removeAt(15); 
	cout << i << endl;	*/
	std::cout << fList.toString() << endl;
	for (FragmentLinkedList<int>::Iterator it = fList.begin(); it != fList.end(1); ++it)
		cout << *it << " ";
	cout << endl;
	FragmentLinkedList<int>::Iterator it = fList.end(2);
	it.remove();
	it++;
	it.remove();
	it++;
	it.remove();
	std::cout << fList.toString() << endl;
	fList.toStringFragmentPointers();
	cout << '\n' << fList.get(15);
	//cout << fList.indexOf(5) << '\n' << fList.size() << '\n';
	//FragmentLinkedList<int>::Iterator it = fList.end(2);
	//it.set(8);
	//auto tmp = ++it;
	//it++;
	//it.remove();
	//cout << fList.toString() << '\t' << fList.size() << '\t' << *it << '\t' << *tmp << endl;
	//fList.toStringFragmentPointers();
	//FragmentLinkedList<int>::Iterator it1;
	//it1 = ++it;
	//it1++;
	////it1++;
	//cout << *it1 << '\t' << *it << endl;
	/*it1.set(5);
	cout << *it1 << '\t' << *it << endl;
	cout << fList.toString();
	cout << *it1 << endl;
	cout << *it1 << '\t' << *it << endl;*/
	/*FragmentLinkedList<int> l(4);
	for (int i = 0; i < 20; i++)
	{
		l.add(-1);
	}
	for (FragmentLinkedList<int>::Iterator v = l.begin(1); v != l.end(1); v++) v.remove();
	cout << endl;
	cout << l.size();
	cout << l.toString();*/
	return 0;
}


template <class T>
 FragmentLinkedList<T>::~FragmentLinkedList() {
	/*delete fragmentPointers[0];
	delete fragmentPointers[1];*/
	this->clear();
	delete[] fragmentPointers;
	this->fragmentMaxSize = 0;
};
 template <class T>
 void FragmentLinkedList<T>::add(const T& element) {
	Node* newPtr = new Node;
	newPtr->data = element;
	newPtr->next = NULL;
	if (count == 0) {
		this->fragmentPointers[0] = newPtr;
		this->fragmentPointers[1] = newPtr;
		newPtr->prev = NULL;
	}
	else {
		/*this->fragmentPointers[1]->next = newPtr;
		newPtr->prev = this->fragmentPointers[1];*/
		Node* pNode = this->fragmentPointers[0];
		while (pNode->next != NULL) {
			pNode = pNode->next;
		}
		pNode->next = newPtr;
		newPtr->prev = pNode;
	}
	this->count++;

	//if (this->count > this->fragmentMaxSize) {
		int k = this->count / this->fragmentMaxSize;
		//float checkK = this->count / this->fragmentMaxSize;
		//bool t = (checkK == k) ? 1 : 0;
		//cout << t;
		//k = (t) ? k - 1 : k;
		//cout << k;
		//if (k <= 0) k = 0;
		if (this->count % this->fragmentMaxSize == 0)
			k--;
		Node** tempPointers = new Node * [2 + k];
		tempPointers[0] = this->fragmentPointers[0];
		//tempPointers[1 + k] = this->fragmentPointers[1];
		int head = 1, step = 1;
		Node* hNode = this->fragmentPointers[0];

		for (int i = 0; i < this->count; i++) {
			if (i == this->fragmentMaxSize * step) {
				tempPointers[head] = hNode;
				step++;
				head++;
			}
			if (i == this->count - 1) {
				tempPointers[1 + k] = hNode;
			}
			hNode = hNode->next;
		}
		delete[] fragmentPointers;
		fragmentPointers = tempPointers;
		//Node* hNode = this->fragmentPointers[0];
	//}
}
 template <class T>
 void FragmentLinkedList<T>::add(int index, const T& element) {
	//try {
		if (index > this->count)
			throw std::out_of_range("The index is out of range!");
		else {
			Node* newPtr = new Node;
			newPtr->data = element;

			if (index == 0) {
				if (this->count == 0) {
					this->fragmentPointers[0] = newPtr;
					this->fragmentPointers[1] = newPtr;
					newPtr->prev = NULL;
					newPtr->next = NULL;
				}
				else {
					this->fragmentPointers[0]->prev = newPtr;
					newPtr->prev = NULL;
					newPtr->next = this->fragmentPointers[0];
					this->fragmentPointers[0] = newPtr;
				}
			}
			else if (index == this->count) {
				Node* pNode = this->fragmentPointers[0];
				while (pNode->next != NULL) {
					pNode = pNode->next;
				}
				pNode->next = newPtr;
				newPtr->prev = pNode;
			}
			else {
				Node* PrevNode = this->fragmentPointers[0];
				Node* NextNode = this->fragmentPointers[0];
				for (int i = 1; i <= index; i++) {
					if (i <= index - 1)
						PrevNode = PrevNode->next;
					NextNode = NextNode->next;
				}
				PrevNode->next = newPtr;
				NextNode->prev = newPtr;
				newPtr->prev = PrevNode;
				newPtr->next = NextNode;
			}
			this->count++;
			int k = this->count / this->fragmentMaxSize;
			if (this->count % this->fragmentMaxSize == 0)
				k--;
			Node** tempPointers = new Node * [2 + k];
			tempPointers[0] = this->fragmentPointers[0];
			int head = 1, step = 1;
			Node* hNode = this->fragmentPointers[0];

			for (int i = 0; i < this->count; i++) {
				if (i == this->fragmentMaxSize * step) {
					tempPointers[head] = hNode;
					step++;
					head++;
				}
				if (i == this->count - 1) {
					tempPointers[1 + k] = hNode;
				}
				hNode = hNode->next;
			}
			delete[] fragmentPointers;
			fragmentPointers = tempPointers;
		}
	//}
	/*catch (std::out_of_range str) {
		cout << str.what();
	}*/
}
 template <class T>
 T FragmentLinkedList<T>::removeAt(int index) {
	 //try {
		 if (index > this->count - 1) {
			 throw std::out_of_range("The index is out of range!");
		 }
		 else {
			 T a;
			 Node* pNode = this->fragmentPointers[0];
			 if (this->count == 1 && index == 0) {
				 a = pNode->data;
				 fragmentPointers[0] = NULL;
				 fragmentPointers[1] = NULL;
			 }
			 else if (index == 0 && this->count > 1) {
				 this->fragmentPointers[0] = this->fragmentPointers[0]->next;
				 this->fragmentPointers[0]->prev = NULL;
				 a = pNode->data;
			 }
			 else if (index == this->count - 1) {
				 Node* nNode = this->fragmentPointers[0];
				 while (pNode->next != NULL) {
					 pNode = pNode->next;
				 }
				 a = pNode->data;
				 nNode = pNode->prev;
				 nNode->next = NULL;
			 }
			 else {
				 Node* PrevNode = this->fragmentPointers[0];
				 Node* NextNode = this->fragmentPointers[0]->next;
				 for (int i = 1; i <= index; i++) {
					 pNode = pNode->next;
					 NextNode = NextNode->next;
					 if (i <= index - 1)
						 PrevNode = PrevNode->next;
				 }
				 PrevNode->next = NextNode;
				 NextNode->prev = PrevNode;
				 a = pNode->data;
			 }
			 delete pNode;
			 this->count--;
			 int k = this->count / this->fragmentMaxSize;
			 if (this->count % this->fragmentMaxSize == 0)
				 k--;
			 Node** tempPointers = new Node * [2 + k];
			 tempPointers[0] = this->fragmentPointers[0];
			 int head = 1, step = 1;
			 Node* hNode = this->fragmentPointers[0];

			 for (int i = 0; i < this->count; i++) {
				 if (i == this->fragmentMaxSize * step) {
					 tempPointers[head] = hNode;
					 step++;
					 head++;
				 }
				 if (i == this->count - 1) {
					 tempPointers[1 + k] = hNode;
				 }
				 hNode = hNode->next;
			 }
			 delete[] fragmentPointers;
			 fragmentPointers = tempPointers;
			 return a;
		 }
	 //}
	/*catch (std::out_of_range str) {
		cout << str.what();
	}*/
}
 template <class T>
 bool FragmentLinkedList<T>::removeItem(const T& item) {
	Node* rNode = this->fragmentPointers[0];
	for (int i = 0; i < this->count; i++) {
		if (rNode->data != item)
			rNode = rNode->next;
		else {
			removeAt(i);
			return 1;
		}
	}
	return 0;
}
 template <class T>
 bool FragmentLinkedList<T>::empty() {
	return (this->count == 0);
}
 template <class T>
 int FragmentLinkedList<T>::size() {
	return this->count;
}
 template <class T>
 void FragmentLinkedList<T>::clear() {
	while (this->fragmentPointers[0] != NULL) {
		Node* cNode = this->fragmentPointers[0];
		this->fragmentPointers[0] = this->fragmentPointers[0]->next;
		delete cNode;
		this->count--;
	}
	delete[] fragmentPointers;
	fragmentPointers = new Node * [2];
	fragmentPointers[0] = fragmentPointers[1] = NULL;
}
 template <class T>
 T FragmentLinkedList<T>::get(int index) {
	Node* gNode = this->fragmentPointers[0];
	//int n = gNode->data;
	//try {
	T a;
		if (index > this->count - 1) {
			throw std::out_of_range("The index is out of range!");
		}
		else {
			for (int i = 0; i <= index; i++) {
				a = gNode->data;
				if (i == index)
					break;
				gNode = gNode->next;
			}
		}
		return a;
	//}
	/*catch (std::out_of_range str) {
		cout << str.what();
	}*/
}
 template <class T>
 void FragmentLinkedList<T>::set(int index, const T& element) {
	// try {
		 if (index > this->count - 1) {
			 throw std::out_of_range("The index is out of range!");
		 }
		 else {
			 Node* sNode = this->fragmentPointers[0];
			 for (int i = 0; i <= index; i++) {
				 if (i == index)
					 sNode->data = element;
				 sNode = sNode->next;
			 }
		 }
	// }
	/* catch (std::out_of_range str) {
		 cout << str.what();
	 }*/
}
 template <class T>
int FragmentLinkedList<T>::indexOf(const T& item) {
	Node* indexNode = this->fragmentPointers[0];
	for (int i = 0; i < this->count; i++) {
		if (indexNode->data == item)
			return i;
		indexNode = indexNode->next;
	}
	return -1;
}
template <class T>
bool FragmentLinkedList<T>::contains(const T& item) {
	Node* containNode = this->fragmentPointers[0];
	for (int i = 0; i < this->count; i++) {
		if (containNode->data == item)
			return 1;
		containNode = containNode->next;
	}
	return 0;
}
//template <class T>
// FragmentLinkedList<T>::Iterator FragmentLinkedList<T>::begin(int index = 0) {
//	/*Iterator itBegin;
//	itBegin.pNode = this->fragmentPointers[0];
//	if (index != 0) {
//		for (int i = 0; i < this->count; i++) {
//			if (i == index * this->fragmentMaxSize)
//				break;
//			itBegin.pNode = itBegin.pNode->next;
//		}
//	}
//	return itBegin;*/
//	 if (((index >= count / fragmentMaxSize) && (count % fragmentMaxSize == 0)) || index < 0)throw out_of_range("Out of range");
//	 auto tmp = new Iterator(this, true);
//	 for (int i = 0; i < index * fragmentMaxSize; i++)(*tmp)++;
//	 //auto p=new FragmentLinkedList(fragmentMaxSize);
//	 //p->fragmentPointers[0]=this->fragmentPointers[index];
//	 //return FragmentLinkedList<T>::Iterator(p,true);
//	 return *tmp;
//}
//template <class T>
//FragmentLinkedList<T>::Iterator FragmentLinkedList<T>::end(int index = -1) {
//	/*Iterator itEnd;
//	if (index == -1) {
//		itEnd.pNode = NULL;
//	}
//	else if (index == this->count / this->fragmentMaxSize) {
//		itEnd.pNode = NULL;
//	}
//	else
//		itEnd = begin(index + 1);
//	return itEnd;*/
//	Iterator itEnd(index, this, false);
//	return itEnd;
//}
template <class T>
typename FragmentLinkedList<T>::Iterator FragmentLinkedList<T>::begin(int index)
{
	//if (((index >= count / fragmentMaxSize) && (count % fragmentMaxSize == 0)) || index < 0)throw out_of_range("Out of range");
	//auto tmp = new Iterator(this, true);
	//for (int i = 0; i < index * fragmentMaxSize; i++)(*tmp)++;
	////auto p=new FragmentLinkedList(fragmentMaxSize);
	////p->fragmentPointers[0]=this->fragmentPointers[index];
	////return FragmentLinkedList<T>::Iterator(p,true);
	//return *tmp;
	if (index < 0 || ((index >= this->count / this->fragmentMaxSize) && (this->count % this->fragmentMaxSize == 0)))
		throw std::out_of_range("The index is out of range!");
	Iterator* itBegin = new Iterator(this, true);
	//itBegin.pNode = this->fragmentPointers[0];
	//if (index != 0) {
	for (int i = 0; i < index * this->fragmentMaxSize; i++) {
		(*itBegin)++;
	}
	//}
	return *itBegin;
}
template<class T>
typename FragmentLinkedList<T>::Iterator FragmentLinkedList<T>::end(int index)
{
	if ((index >= this->count / this->fragmentMaxSize) && (this->count % this->fragmentMaxSize == 0))
		throw std::out_of_range("The index is out of range!");
	else if (index == -1) {
		Iterator* itEnd = new Iterator(index, this, true);
		return *itEnd;
	}
	/*auto p=new FragmentLinkedList(fragmentMaxSize);
	if(index==-1)
	{
	  p->fragmentPointers[0]=this->fragmentPointers[count/fragmentMaxSize+1];
	  return FragmentLinkedList<T>::Iterator(p,false);
	}
	//else if(index==count/fragmentMaxSize-1)return this->end();
	else
	{
	  p->fragmentPointers[0]=this->fragmentPointers[index];
	  for(int i=fragmentMaxSize;i>1;i--)
	  if(p->fragmentPointers[0]!=NULL)p->fragmentPointers[0]=p->fragmentPointers[0]->next;
	  return FragmentLinkedList<T>::Iterator(p,false);
	}*/
	else {
		Iterator* itEnd = new Iterator(this, true);
		if (index < this->count / this->fragmentMaxSize)
			for (int i = 0; i < index * this->fragmentMaxSize + this->fragmentMaxSize; i++)
				(*itEnd)++;
		else
			return Iterator(this, false);
		return *itEnd;
	}
	/*Iterator itEnd(index, this, false);
	return itEnd;*/
}