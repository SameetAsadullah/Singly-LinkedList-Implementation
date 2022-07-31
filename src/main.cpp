#include<iostream>
#include"List.h"
using namespace std;

int main() {
	List<int> l1;
	l1.insert(5);
	l1.insert(4);
	l1.insert(6);
	l1.insert(1);
	l1.removeAt(2);
	l1.insertAt(9, 2);
	l1.Display();
	l1.replaceAt(7, 1);
	l1.Display();
	l1.splitList(2);
	l1.Display();
	l1.getHead();
}