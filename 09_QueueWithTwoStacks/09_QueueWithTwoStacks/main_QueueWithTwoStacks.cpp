#include <iostream>
#include <stack>
using namespace std;

template <typename T> class CQueue{
public:
	CQueue(void);
	~CQueue(void);

	void appendTail(const T& node);
	T deleteHead();
	void deleteAll();

private:
	stack<T> stack1;
	stack<T> stack2;
};

template<typename T> CQueue<T>::CQueue(){

}

template<typename T> CQueue<T>::~CQueue(){

}

template<typename T> void CQueue<T>::appendTail(const T& node){
	if (!stack2.empty()){
		while (!stack2.empty()){
			T tmp = stack2.top();
			stack2.pop();
			stack1.push(tmp);
		}
		stack1.push(node);
	}
	else{
		stack1.push(node);
	}
}

template<typename T> T CQueue<T>::deleteHead(void){
	if (!stack2.empty()){
		T tmp = stack2.top();
		cout << "当前弹出的是" << tmp << endl;
		stack2.pop();
		return tmp;
	}
	else if (stack1.empty()){
		cout << "The queue is empty." << endl;
	}
	else{
		while (!stack1.empty()){
			char tmp = stack1.top();
			stack1.pop();
			stack2.push(tmp);
		}
		T tmp = stack2.top();
		cout << "当前弹出的是" << tmp << endl;
		stack2.pop();
		return tmp;
	}
}

template<typename T> void CQueue<T>::deleteAll(void){
	if (!stack2.empty()){
		while (!stack2.empty()){
			cout << stack2.top();
			stack2.pop();
		}
	}
	else if (stack1.empty()){
		cout << "The queue is empty." << endl;
	}
	else{
		while (!stack1.empty()){
			T tmp = stack1.top();
			stack1.pop();
			stack2.push(tmp);
		}
		while (!stack2.empty()){
			cout << stack2.top();
			stack2.pop();
		}
	}
}

int main(void){
	CQueue<char> queue;
	queue.appendTail('a');
	queue.appendTail('b');
	queue.appendTail('c');
	queue.deleteHead();
	queue.appendTail('e');
	queue.appendTail('f');
	queue.deleteAll();
	system("pause");
}