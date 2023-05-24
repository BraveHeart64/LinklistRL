#include<iostream>
using namespace std;

class Node{
	public:
		int value;
		Node* next;

};

class LinkedList{

	Node* root = 0;
	Node*  tail = 0;
    Node **r = &root;

	public:
	void Push(int v){
		Node* temp = new Node();
		temp->value = v;
		if(root == 0){
			root = temp;
			tail = root;
		}
		else{
			tail->next = temp;
			tail = tail->next;
		}

    }

	void PrintList(){
		Node* r;
		r = root;

		while(r != 0){
			cout<<r->value<<endl;
			r=r->next;

		}

	}

	void Delete(){



        if(root == 0){
        // if the arraylist is empty do nothing else delete all values

        }
        else{
            while(root->next != 0){
                r = &root;
                r=0;
                root=root->next;


            }
            r = &root;
            r  = 0;
            root = 0;
            tail = 0;
        }
	}

	int FindAValue(int val){

        Node* r;
		r = root;

		while(r != 0 || r->value != val){
            if(r->value == val){
                return r->value;
            }
            else if(r->next == 0){
                break;
            }
            else{
                r=r->next;
            }
		}

    return 0;
	}

	void DelAValue(int v){
        Node* prevnode=0, *tmp;
        tmp = root;


        while(tmp->value != v){
            prevnode = tmp;
            tmp=tmp->next;
            if(tmp->next == 0){
                break;
            }



        }

        if(prevnode != 0){
            prevnode->next = prevnode->next->next;

        tmp = 0;
        }
        else{
            prevnode = root;
            root = 0;
            root = prevnode->next;


        }


	}

};


int main(){
    int look = 0;
	LinkedList ls;
	ls.Push(40);
	ls.Push(30);
	ls.Push(20);
	ls.Push(10);
	ls.Push(5);
	ls.Push(35);
	ls.PrintList();
	cout<<endl;

    ls.DelAValue(20);

	cout<<endl;
	ls.PrintList();
	 look = ls.FindAValue(20);
	cout<<"look is: "<< look;
	ls.Delete();
	return 0;
}
