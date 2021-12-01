//#include <iostream>
//#include <fstream>
//using namespace std;
//
//ifstream ifs;
//
//struct node
//{
//	int data;
//	node* next;
//};
//
//node* createLinkList(int n) {
//	node* q = NULL, * h = NULL;
//	for (int i = 0; i < n; i++) {
//		node* p = new node;
//		ifs >> p->data;
//		p->next = NULL;
//		if (!q) {
//			h = p;
//			q = p;
//		}
//		else {
//			h->next = p;
//			h = p;
//		}
//	}
//	return q;
//}
//
//node* insertNode(node* head, node* newNode, int position)
//{
//	node* p = head;
//	int count = 0;
//	while (p) {
//		count++;
//		p = p->next;
//	}
//
//	if (position <= 0) return head;
//	else if (position == 1) {
//		newNode->next = head;
//		return newNode;
//	}
//	p = head;
//	if (position > count) {
//		for (int i = 0; i < count - 1; i++) head = head->next;
//		head->next = newNode;
//	}
//	else {
//		for (int i = 0; i < position - 2; i++) {
//			head = head->next;
//		}
//		newNode->next = head->next;
//		head->next = newNode;
//	}
//	return p;
//}
//
//void print(node * head)
//{
//	while (head != nullptr)
//	{
//		cout << head->data << endl;
//		head = head->next;
//	}
//}
//
//int main(int narg, char** argv)
//{
//	ifs.open(argv[1]);
//
//	int n = 0;
//	ifs >> n;
//	if (n > 0)
//	{
//		node* head = createLinkList(n);
//
//		node* newNode = new node();
//		ifs >> newNode->data;
//		int position = 0;
//		ifs >> position;
//		head = insertNode(head, newNode, position);
//
//		print(head);
//	}
//	else
//	{
//		cout << "Invalid n" << endl;
//	}
//
//	ifs.close();
//	return 0;
//}
//


#include <iostream>
#include <fstream>
using namespace std;

ifstream ifs;

struct node
{
	int data;
	node* next;
};

node* createLinkList(int n)
{
	node* q = NULL, * h = NULL;
	for (int i = 0; i < n; i++) {
		node* p = new node;
		ifs >> p->data;
		p->next = NULL;
		if (!q) {
			q = p;
			h = p;
		}
		else {
			h->next = p;
			h = p;
		}
	}
	return q;
}

bool isEqual(node* head1, node* head2)
{
	node* temp1 = head1;
	node* temp2 = head2;
	int count1 = 0, count2 = 0;
	while (temp1) {
		count1++;
		temp1 = temp1->next;
	}
	while (temp2) {
		count2++;
		temp2 = temp2->next;
	}
	if (count1 != count2) return 0;
	else {
		for (int i = 0; i < count1; i++) {
			if (head1->data == head2->data) {
				head1 = head1->next;
				head2 = head2->next;
			}
			else return 0;
		}
	}
	return 1;
}

int main(int narg, char** argv)
{
	ifs.open(argv[1]);

	int n = 0;
	ifs >> n;
	if (n <= 0)
	{
		cout << "Invalid n" << endl;
		return 0;
	}
	node* head1 = createLinkList(n);

	int m = 0;
	ifs >> m;
	if (m <= 0)
	{
		cout << "Invalid m" << endl;
		return 0;
	}
	node* head2 = createLinkList(m);

	cout << isEqual(head1, head2) << endl;

	ifs.close();
	return 0;
}
