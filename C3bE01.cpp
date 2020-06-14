#include <iostream>

using namespace std;

class intStack {
public:
    intStack(int);
    void push(int);
    void pop();
    int getTop();
    void display();
    bool isEmpty();

private:
	int *s;
	int top;
	int maxN;
};

intStack::intStack(int num) {
    top = 0, maxN = num, s = new int[maxN];
};

void intStack::push(int t) {
	if (top == maxN) {
		cout << "Stack Full!\n";
		return;
	}
	s[top] = t;
	top++;
};

void intStack::pop() {
	if (top==0) {
		cout << "Stack Empty!\n";
		return;
	}

	top--;
};

int intStack::getTop() {
	if (top==0) {
		cout << "Stack Empty!\n";
		return -1;
	}

    return s[top-1];
}

void intStack::display() {
	if (top == 0) {
        cout << "(Stack Empty)\n";
        return;
    }

    for (int i = 0; i < top; i++)
        cout << s[i] << " ";
	cout << "\n";
};

bool intStack::isEmpty() {
    return top==0;
};

int main()
{
	intStack *s = new intStack(3);

	s->display();
	s->push(1);
	s->display();
	s->push(2);
	s->display();
	s->push(3);
	s->display();
	cout << "Top is " << s->getTop() << endl;
	s->push(4);
	s->display();
	cout << "Top is " << s->getTop() << endl;
	s->pop();
	s->display();
	s->pop();
	s->display();
	s->push(10);
	s->display();
	s->pop();
	s->display();
	s->pop();
	s->display();

	return 0;
}

