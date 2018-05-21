#include <iostream>
#include <stack>
#include <assert.h>
using namespace std;

 class StackWithTop
{
private:
	stack<int> m_data;
	stack<int> m_min;

	bool empty();

public:
	StackWithTop(){}
	~StackWithTop(){}

	int top();
	void pop();
	void push(int value);
	int min();
};

bool StackWithTop::empty(){
	return m_data.empty();
}

int StackWithTop::top(){
	if (!empty() == true){
		return m_data.top();
	}
	else{
		cout << "The stack is empty, can't get the top element." << endl;
	}
}

void StackWithTop::pop(){
	if (!empty() == true){
		m_data.pop();
		m_min.pop();
	}
	else{
		cout << "The stack is empty, can't pop the element." << endl;
	}
}

void StackWithTop::push(int value){
	if (!empty() == true){
		m_data.push(value);
		if (value < m_min.top()){
			m_min.push(value);
		}
		else{
			m_min.push(m_min.top());
		}
	}
	else{
	m_data.push(value);
	m_min.push(value);
	}
}

int StackWithTop::min(){
	return m_min.top();
}