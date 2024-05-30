#include<iostream>
using namespace std;

class node
{
public:

	int data;
	node* next;
	node* prev;

	node(int d)
	{
		data = d;
		next = NULL;
		prev = NULL;
	}

	void insertathead(node*& head, int d)
	{
		node* temp = new node(d);
		temp->next = head;
		head->prev = temp;
		head = temp;
	}

	void deleteAtHead(node*& head)
	{
		node* temp = head;
		head = head->next;
		head->prev = NULL;
		delete temp;
	}

	void deleteattail(node*& tail)
	{
		node* temp = tail;
		tail = tail->prev;
		tail->next = NULL;
		delete temp;
	}

	void deleteatpos(node*& head, node*& tail, int p)
	{
		int count = 1;
		if (p == 1)
		{
			deleteAtHead(head);
			return;
		}
		else
		{
			node* curr = head;
			node* prev = NULL;

			while (count < p)
			{
				prev = curr;
				curr = curr->next;
				curr->prev = NULL;
				count++;
			}

			prev->next = curr->next;
			curr->next = NULL;
			delete curr;

		}
	}


	void display(node*& head)
	{
		node* temp = head;
		while (temp != NULL)
		{
			cout << temp->data << "->";
			temp = temp->next;
		}
		cout << "NULL";
	}
};

int main() {
	node* node1 = new node(1);
	node* node2 = new node(2);
	node* node3 = new node(3);
	node* node4 = new node(4);
	node* node5 = new node(5);

	node1->next = node2;
	node2->prev = node1;
	node2->next = node3;
	node3->prev = node2;
	node3->next = node4;
	node4->prev = node3;
	node4->next = node5;
	node5->prev = node4;


	node* head = node1;
	node* tail = node5;

	head->insertathead(head, 0);
	head->display(head);
	cout << endl;

	tail->deleteattail(tail);
	head->display(head);
	cout << endl;

	head->deleteatpos(head, tail, 2);
	head->display(head);
	cout << endl;

	return 0;
}