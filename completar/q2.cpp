#include <queue>
#include <iostream>
using namespace std;

template <class T>
class Queue: public queue<T> {
	protected:
		queue<T> fila;
	public:
	T popQueue(){
		T tmp=fila.front();
		fila.pop();
		return tmp;
	}


	void popTodos(){
         while(!fila.empty()){
            cout<<popQueue();
         }
    }

    void simulaPilha(T novo){
        queue<T> f1;
        queue<T> f2;
        if(!fila.empty()){
            f1.push(novo);
        }
        else{
            while(!f1.empty()){
                f2.push(popQueue());
            }
            f1.push(novo);
            while(!f2.empty()){
                f1.push(popQueue());
            }
        }
    	}
};

main(){
	Queue <int> fila;
	fila.push(4);
	fila.push(5);
	cout<<fila.front()<<endl;
	fila.simulaPilha(5);
	fila.simulaPilha(4);
	cout<<fila.popQueue();


}
