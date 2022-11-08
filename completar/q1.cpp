#include <stack>
#include <iostream>
using namespace std;

template <class T>
class Stack: public stack<T> {
	protected:
		stack<T> pilha;
	public:
	T popStack(){
		T tmp=pilha.top();
		pilha.pop();
		return tmp;
	}


	void popTodos(){
		while(!pilha.empty()){
            cout<<popStack();
		}
    }

	void simulaFila(T novo){
			stack <T> p1;
			if(!pilha.empty()){
                p1.push(popStack());
			}
                else{
                    pilha.push(novo);
                }

                if(!p1.empty()){
                    pilha.push(p1.top());
                    p1.pop();
                }
			free(&p1);

	}


};

main(){
    Stack <int> pilha;

	pilha.simulaFila(3);
	pilha.simulaFila(2);
    pilha.simulaFila(1);

	pilha.popTodos();
}
