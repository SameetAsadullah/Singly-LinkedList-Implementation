#pragma once
#include<iostream>
using namespace std;

template<class DT>
class Node {
public:
	DT data;
	Node* next;

	Node() :next(NULL) {
	}
};

template<class DT>
class List {
private:
	Node<DT>* head;
	Node<DT>* cursor;

public:
	List(int ignored = 0) {
		head = NULL;
		cursor = NULL;
	}

	void insert(const DT& newDataItem) {
		if (head == NULL) {
			head = new Node<DT>;
			head->data = newDataItem;
			cursor = head;
		}

		else {
			cursor = head;
			while (cursor->next != NULL) {
				cursor = cursor->next;
			}

			cursor->next = new Node<DT>;
			cursor->next->data = newDataItem;
			cursor = cursor->next;
		}
	}

	void insertAt(const DT& newDataItem, int index) {
		int size = 1;
		cursor = head;

		if (index == 0) {
			Node<DT>* temp = head;
			head = new Node<DT>;
			head->data = newDataItem;
			head->next = temp;
			cursor = head;
		}

		else {
			while (cursor->next != NULL && index > size) {
				cursor = cursor->next;
				size++;
			}

			if (index > size && cursor->next == NULL) {
				cout << "Index out of range" << endl;
			}

			else {
				Node<DT>* temp = cursor->next;
				cursor->next = new Node<DT>;
				cursor->next->data = newDataItem;
				cursor->next->next = temp;
				cursor = cursor->next;
			}
		}
	}

	void Remove() {
		if (head != NULL) {
			Node<DT>* temp = head;

			if (cursor == head) {
				head = head->next;
				delete cursor;
				cursor = head;
			}

			else {

				while (temp->next != cursor) {
					temp = temp->next;
				}

				temp->next = temp->next->next;
				delete cursor;

				if (temp->next != NULL) {
					cursor = temp->next;
				}

				else {
					cursor = head;
				}
			}
		}
	}

	void removeAt(int index) {
		int size = 1;
		cursor = head;

		if (index == 1) {
			head = head->next;
			delete cursor;
			cursor = head;
		}

		else {
			while (cursor->next != NULL && index - 1 > size) {
				cursor = cursor->next;
				size++;
			}

			if (index > size && cursor->next == NULL) {
				cout << "Index out of range" << endl;
			}

			else {
				Node<DT>* temp = cursor->next;
				cursor->next = cursor->next->next;
				delete temp;

				if (cursor->next != NULL) {
					cursor = cursor->next;
				}

				else {
					cursor = head;
				}
			}
		}
	}

	void replace(const DT& newDataItem) {
		if (head != NULL) {
			cursor->data = newDataItem;
		}
	}

	void replaceAt(const DT& newDataItem, int index) {
		int size = 1;
		cursor = head;

		if (index == 0) {
			head->data = newDataItem;
		}

		else {
			while (cursor->next != NULL && index >= size) {
				cursor = cursor->next;
				size++;
			}

			if (index >= size && cursor->next == NULL) {
				cout << "Index out of range" << endl;
			}

			else {
				cursor->data = newDataItem;
			}
		}
	}

	void clear() {
		cursor = head;
		while (cursor != NULL) {
			Node<DT>* temp = cursor;
			cursor = cursor->next;
			delete temp;
		}
		head = cursor;
	}

	Node<DT>* getHead() {
		return head;
	}

	bool isEmpty() {
		if (head == NULL) {
			return true;
		}
		return false;
	}

	bool gotoNext() {
		if (cursor->next != NULL) {
			cursor = cursor->next;
			return true;
		}
		return false;
	}

	bool gotoPrior() {
		if (cursor != head) {
			Node<DT>* temp = head;
			while (temp->next != cursor) {
				temp = temp->next;
			}
			cursor = temp;
			return true;
		}
		return false;
	}

	DT getCursor() {
		if (head != NULL) {
			return cursor->data;
		}
	}

	bool moveCursor(int index) {
		if (head != NULL) {
			Node<DT>* temp = cursor;
			int size = 1;
			cursor = head;

			while (cursor->next != NULL && index >= size) {
				cursor = cursor->next;
				size++;
			}

			if (cursor->next == NULL && index >= size) {
				cout << "Index out of range" << endl;
				cursor = temp;
				return false;
			}
			return true;
		}
	}

	bool moveCursortoEnd() {
		if (head != NULL) {
			cursor = head;

			while (cursor->next != NULL) {
				cursor = cursor->next;
			}
			return true;
		}
		return false;
	}

	void Display() {
		Node<DT>* temp = head;

		while (temp != NULL) {
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}

	void sort() {
		if (head != NULL) {
			int size = 0;
			Node<DT>* temp = head;
			Node<DT>* prev;

			while (temp != NULL) {
				temp = temp->next;
				size++;
			}

			for (int i = 0; i < size; i++) {
				temp = head;

				while (temp->next != NULL) {
					prev = temp;
					temp = temp->next;

					if (prev->data > temp->data) {
						int num = prev->data;
						prev->data = temp->data;
						temp->data = num;
					}
				}
			}
		}
	}

	bool duplicate() {
		if (head != NULL) {
			Node<DT>* temp = head;

			while (temp != NULL) {
				Node<DT>* temp1 = head;
				while (temp1 != NULL) {
					if ((temp != temp1) && (temp->data == temp1->data)) {
						return true;
					}
					temp1 = temp1->next;
				}
				temp = temp->next;
			}
		}
		return false;
	}

	List splitList(int index) {
		if (head != NULL && head->next != NULL) {
			List<DT> splittedList;
			Node<DT>* temp = head;
			int size = 1;

			while (temp != NULL) {
				if (size > index + 1) {
					splittedList.insert(temp->data);
					Node<DT>* temp1 = temp;
					temp = temp->next;
					delete temp1;
				}

				else {
					if (size == index + 1) {
						Node<DT>* temp1 = temp;
						temp = temp->next;
						temp1->next = NULL;
					}

					else {
						temp = temp->next;
					}
				}
				size++;
			}

			if (index >= size) {
				cout << "Index out of range" << endl;
			}
			return splittedList;
		}
		return NULL;
	}

	~List() {
	}
};
