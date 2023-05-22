#include<iostream>
using namespace std;



struct Node {
	Node* next;
	int value;
};


class linklist {
private:
	Node * head, *tail;
	Node** ref_to_head;


public:
	void add(int val);
	void print();
	void del();

	linklist();
	~linklist();
};


linklist::linklist() {
	head = 0;
	tail = 0;

}

linklist::~linklist() {
	del();
}

void linklist::add(int val){
	Node* temp = new Node();
	temp->value = val;

	if (head == 0) {
		head = temp;
		tail = temp;
	}
	else {
		tail->next = temp;
		tail = tail->next;
	}



}

void linklist::del() {
	Node* temp = new Node();
	Node* next;
	ref_to_head = &head;
	
	while (temp != 0) {
		next = temp->next;
		delete temp;
		temp = next;
	}

	*ref_to_head = 0;




}



void linklist::print() {
	Node* temp = new Node();
	temp = head;
	while (temp != 0) {
		cout << temp->value<<endl;
		temp = temp->next;
	}

}


int main(int argc, char* argv[]) {
	linklist la;
	la.add(10);
	la.add(20);
	la.add(30);
	la.add(40);
	la.add(50);
	la.print();
	cin.get();
	la.del();

	return 0;
}
