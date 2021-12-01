#include <sstream>
#include <string>
#include <iostream>
#include <type_traits>
using namespace std;

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
		Iterator(FragmentLinkedList<T>* pList = 0, bool begin = true)
		{
			this->pList = pList;
			if (!pList)
			{
				index = -1;
				pNode = NULL;
			}
			else {
				if (begin)
				{
					pNode = pList->fragmentPointers[0]; index = 0;
				}
				if (pNode)
					if (!begin)
					{
						pNode = NULL; index = pList->size();
					}
			}
		};
		Iterator(int fragmentIndex, FragmentLinkedList<T>* pList = 0, bool begin = true)
		{
			this->pList = pList;
			if (!pList)
			{
				pNode = NULL;
				index = -1;
				return;
			}
			if (fragmentIndex == -1)
			{
				pNode = NULL;
				index = pList->size();
				return;
			}
			if (!begin)
			{
				fragmentIndex++;
				if (pList->size() / pList->fragmentMaxSize < fragmentIndex)index = pList->size();
				else index = fragmentIndex * (pList->fragmentMaxSize);
			}
			pNode = pList->fragmentPointers[fragmentIndex];

		};

		Iterator& operator=(const Iterator& iterator) {
			pList = iterator.pList;
			pNode = iterator.pNode;
			index = iterator.index;
			return *this;
		};
		T& operator*() { return this->pNode->data; };
		bool operator!=(const Iterator& iterator) {
			if (this->pNode != iterator.pNode)return true;
			else return false;
		};
		void remove()
		{
			pNode = pNode->prev;
			pList->removeAt(index);
			index--;
		};
		void set(const T& element)
		{
			pNode->data = element;
		};
		Iterator& operator++() {
			if (index >= pList->size())return *this;
			else {
				index++;
				if (index == 0)pNode = pList->fragmentPointers[0];
				else
					pNode = pNode->next;
				return *this;
			}
		};
		Iterator operator++(int x) {
			if (index >= pList->size())return *this;
			else {
				auto tmp = *this;

				index++;
				if (index == 0)pNode = pList->fragmentPointers[0];
				else
					this->pNode = this->pNode->next;
				//Iterator tmp(this->pList,1);
				//tmp.pNode=pNode;
				return tmp;
			}
		};
	};
};

template <class T>
string FragmentLinkedList<T>::toString()
{
	count = this->size();
	stringstream ss;
	ss << "[";
	Node* ptr = this->fragmentPointers[0];

	if (this->count == 0)
		ss << "]";
	// TODO
	else for (; ptr != NULL; ptr = ptr->next)
	{
		ss << ptr->data;
		if (ptr->next != nullptr) ss << ",";
		else ss << ']';
	}
	// END: TODO

	return ss.str();
}
template<class T>
void FragmentLinkedList<T>::add(const T& x)
{
	//const int tcount = count / fragmentMaxSize+1;
	count = this->size();
	count += 1;
	auto newN = new Node(x, NULL, NULL);
	auto p = fragmentPointers[0];
	if (!p)fragmentPointers[0] = fragmentPointers[1] = newN;
	else
	{
		while (p->next) p = p->next;
		p->next = newN;
		newN->prev = p;
	}

	Node** tmp = new Node * [count / fragmentMaxSize + 2];
	int i = 0;
	auto q = fragmentPointers[0];
	for (; q; q = q->next)
	{
		if (i % fragmentMaxSize == 0)tmp[i / fragmentMaxSize] = q;
		if (q->next == nullptr)tmp[i / fragmentMaxSize + 1] = q;
		i++;
	}
	delete[] fragmentPointers;
	fragmentPointers = tmp;
};
template<class T>
void FragmentLinkedList<T>::add(int index, const T& x)
{
	count = this->size();
	if (index > count)return;
	//const int tcount = count / fragmentMaxSize + 1;
	if (((count == 0) && (index == 0)) || (count == index))
	{
		add(x);
		return;
	}
	if (index == 0)
	{
		auto newN = new Node(x, NULL, NULL);
		auto p = fragmentPointers[0];
		newN->next = p;
		p->prev = newN;
		fragmentPointers[0] = newN;
		count++;
		Node** tmp = new Node * [count / fragmentMaxSize + 2];
		int i = 0;
		auto q = fragmentPointers[0];
		for (; q; q = q->next)
		{
			if (i % fragmentMaxSize == 0)tmp[i / fragmentMaxSize] = q;
			if (q->next == nullptr)tmp[i / fragmentMaxSize + 1] = q;
			i++;
		}
		delete[] fragmentPointers;
		fragmentPointers = tmp;
		return;
	}
	count++;
	Node* p = fragmentPointers[0];
	auto newN = new Node(x, NULL, NULL);
	int k = 0;
	for (; p; p = p->next)
	{
		if (k == index)
		{
			if (p->prev != nullptr)p->prev->next = newN;
			newN->prev = p->prev;
			p->prev = newN;
			newN->next = p;
			p = newN;
		}
		k++;
	}
	Node** tmp = new Node * [count / fragmentMaxSize + 2];
	int i = 0;
	auto q = fragmentPointers[0];
	for (; q; q = q->next)
	{
		if (i % fragmentMaxSize == 0)tmp[i / fragmentMaxSize] = q;
		if (q->next == nullptr)tmp[i / fragmentMaxSize + 1] = q;
		i++;
	}
	delete[] fragmentPointers;
	fragmentPointers = tmp;
}
template<class T>
T FragmentLinkedList<T>::removeAt(int index)
{
	count = this->size();
	if (index >= count)throw std::out_of_range("outofrange");
	T* hold = new T;
	if (index == 0)
	{
		auto p = fragmentPointers[0];
		*hold = p->data;
		fragmentPointers[0] = p->next;
		fragmentPointers[0]->prev = nullptr;
		//delete p;
		count -= 1;
		Node** tmp = new Node * [count / fragmentMaxSize + 2];
		int i = 0;
		auto q = fragmentPointers[0];
		for (; q; q = q->next)
		{
			if (i % fragmentMaxSize == 0)tmp[i / fragmentMaxSize] = q;
			if (q->next == nullptr)tmp[i / fragmentMaxSize + 1] = q;
			i++;
		}
		delete[] fragmentPointers;
		fragmentPointers = tmp;
		return *hold;
	}
	int u = index / fragmentMaxSize, l = index % fragmentMaxSize;
	for (auto p = fragmentPointers[u]; p != nullptr; p = p->next)
	{
		if (l == 0)
		{
			//cout<<l<<'\n'<<index<<'\n';
			if (p->prev != nullptr)p->prev->next = p->next;
			if (p->next != nullptr)p->next->prev = p->prev;
			*hold = p->data;
			auto temp = p;
			p = p->next;
			*hold = temp->data;
			delete temp;
			count -= 1;
			break;
		}
		l--;
	}
	Node** tmp = new Node * [count / fragmentMaxSize + 2];
	int i = 0;
	auto q = fragmentPointers[0];
	for (; q; q = q->next)
	{
		if (i % fragmentMaxSize == 0)tmp[i / fragmentMaxSize] = q;
		if (q->next == nullptr)tmp[i / fragmentMaxSize + 1] = q;
		i++;
	}
	delete[] fragmentPointers;
	fragmentPointers = tmp;
	return *hold;
}
template<class T>
bool FragmentLinkedList<T>::removeItem(const T& x)
{
	auto p = fragmentPointers[0];
	int i = 0;
	for (; p != nullptr; p = p->next)
	{
		if (p->data == x)
		{
			//cout<<i<<'\n';
			this->removeAt(i);
			return true;
		}
		i += 1;
	}
	return false;
}
template<class T>
bool FragmentLinkedList<T>::empty()
{
	if (fragmentPointers[0] == nullptr)return true;
	else return false;
}
template<class T>
int FragmentLinkedList<T>::size()
{
	return count;

}
template<class T>
void FragmentLinkedList<T>::clear()
{
	count = 0;
	auto p = fragmentPointers[0];
	auto c = p;
	while (p != nullptr)
	{
		p = p->next;
		delete c;
		c = p;
	}
	delete[] fragmentPointers;
	fragmentPointers = new Node * [2];
	fragmentPointers[0] = fragmentPointers[1] = nullptr;
	count = 0;
}
template<class T>
T FragmentLinkedList<T>::get(int index)
{
	if (index >= count)throw out_of_range("fuckyou");
	T* hold = new T;
	int i = index / fragmentMaxSize, l = index % fragmentMaxSize;
	auto p = fragmentPointers[i];
	for (; p != nullptr; p = p->next)
		if (l == 0) {
			*hold = p->data;
			return *hold;
		}
		else l--;
	return *hold;
}
template<class T>
void FragmentLinkedList<T>::set(int index, const T& x)
{
	if (index >= count)return;
	int i = 0;
	auto& p = fragmentPointers[index / fragmentMaxSize];
	for (; p != nullptr; p = p->next)
		if (i == index % fragmentMaxSize)
		{
			p->data = x;
			return;
		}
		else i++;
}
template<class T>
int FragmentLinkedList<T>::indexOf(const T& x)
{
	auto p = fragmentPointers[0];
	int i = 0;
	for (; p != nullptr; p = p->next)
		if (p->data == x)
		{
			return i;
		}
		else i++;
	i = -1;
	return i;
}
template<class T>
bool FragmentLinkedList<T>::contains(const T& x)
{
	for (auto p = fragmentPointers[0]; p != nullptr; p = p->next)
		if (p->data == x)return true;
	return false;
}
template<class T>
typename FragmentLinkedList<T>::Iterator FragmentLinkedList<T>::begin(int index)
{
	if (((index >= count / fragmentMaxSize) && (count % fragmentMaxSize == 0)) || index < 0)throw out_of_range("Out of range");
	auto tmp = new Iterator(this, true);
	for (int i = 0; i < index * fragmentMaxSize; i++)(*tmp)++;
	//auto p=new FragmentLinkedList(fragmentMaxSize);
	//p->fragmentPointers[0]=this->fragmentPointers[index];
	//return FragmentLinkedList<T>::Iterator(p,true);
	return *tmp;
};
template<class T>
typename FragmentLinkedList<T>::Iterator FragmentLinkedList<T>::end(int index)
{
	if (index >= (count / fragmentMaxSize) && (count % fragmentMaxSize == 0))throw out_of_range("Out of range");
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
	if (index == -1)return Iterator(this, false);
	auto tmp = new Iterator(this, true);
	if (index < count / fragmentMaxSize) for (int i = 0; i < index * fragmentMaxSize + fragmentMaxSize; i++)(*tmp)++;
	else return Iterator(this, false);
	return (*tmp);
}
template<class T>
FragmentLinkedList<T>::~FragmentLinkedList()
{
	this->clear();
	delete[] fragmentPointers;
	fragmentMaxSize = 0;
}
#endif
// END: STUDENT ANSWER

int main()
{
	// TESTCASE INPUT
	// === Example
	FragmentLinkedList<int> fList;
	for (int i = 0; i < 20; i++)
		fList.add(i, i);
	fList.set(0, 5);
	//fList.add(1,2);
	//fList.add(5 ,3);
	//cout<<fList.toString();
	//fList.removeItem(6);
   //int i= fList.removeAt(15);
	std::cout << fList.toString() << endl;
	for (FragmentLinkedList<int>::Iterator it = fList.begin(); it != fList.end(1); ++it)
		cout << *it << " ";
	cout << endl;
	cout << fList.indexOf(5) << '\n' << fList.size() << '\n';
	FragmentLinkedList<int>::Iterator it = fList.end(2);
	//it.set(8);
	auto tmp = ++it;
	it++;
	it.remove();
	cout << fList.toString() << '\t' << fList.size() << '\t' << *it << '\t' << *tmp;
	// === END: Example
	// END: TESTCASE INPUT

	return 0;
}
