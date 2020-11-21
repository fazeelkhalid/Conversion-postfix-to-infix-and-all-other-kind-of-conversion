#include<iostream>
#include<string>
using namespace std;
template<typename T>
class stack {
private:
	template<typename T>
	class Node {
	public:
		T data;
		Node<T>* next;
		
		Node() {
			next = NULL;
		}
	};
	Node<T> * head;
public:
	stack() {
		head = NULL;
	}
	void push(T const element);
	//void stack<char*>::push(char* const element);
	int size() {
		int numbersInStack = 0;
		Node<T> *temp = head;
		while (temp != NULL) {
			numbersInStack++;
			temp = temp->next;
		}
		return numbersInStack;
	}
	bool isEmpty() {
		if (head == NULL) {
			return true;
		}
		else
			return false;
	}
	void pop() {
		if (!isEmpty()) {
			Node<T> * temp = NULL;
			temp = head->next;
			delete head;
			head = temp;
		}
	}
	T &top() {
		if (!isEmpty()) {
			return head->data;
		}
		else {
			cout << "\nStack is empty : ";
		}
	}
	
	void print() const {
		Node<T>* temp = head;
		while (temp) { //temp !=NULL;
			cout << temp->data << "\t";
			temp = temp->next;
		}
	}
};
template<typename T>
void stack<T>::push(T const element) {
	Node<T> * new_node = new Node<T>();
	new_node->data = element;
	new_node->next = head;
	head = new_node;
}
template<>
void stack<char*>::push(char* const element) {
	Node<char*> * new_node = new Node<char*>();
	int size;
	for (size = 0; element[size] != '\0'; size++); // calculate element size
	new_node->data = new char[size+1];
	new_node->data[size] = '\0';
	for (int i = 0; i < size; i++) {
		new_node->data[i] = element[i];
	}
	new_node->next = head;
	head = new_node;
}
