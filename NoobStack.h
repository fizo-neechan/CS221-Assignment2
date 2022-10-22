#include "headers.h"

template <class T>
class NoobStack {
    private:
        int size;
        T *bottom;
        T *top;

    public:
        NoobStack();
        ~NoobStack();

        void push(T val);
        T pop();
        bool isEmpty();
};

template <class T> 
NoobStack<T>::NoobStack(){
    this->size = 0;
    this->bottom = NULL;
    this.head = NULL;
}

template <class T> 
NoobStack<T>::~NoobStack(){
    delete [] this->top;
    delete [] this->bottom;
}

template <class T> 
void NoobStack<T>::push(T val){
    size++;
    if(this->top == NULL)
        this->top = new T[size];
    else{
        T *temp = new T[size];
        temp[0] = val;
        for(int i = 1; i < size; i++)
            temp = this->top[i];
        
        delete [] this.top;
        this->top = temp;
        this->bottom = this->top[size-1];
    }
}

template <class T> 
T NoobStack<T>::pop(){
    if(this->top == NULL)
        return NULL;
    else {
        T returner;
        T *temp = new T[size-1];
        int i = 0;
        for(i = 0; i < size; i++){
            if(this->top[i] == val){
                returner = this->top[i];
                break;
            }
            else
                temp[i] = this->top[i];
        }

        for(++i; i < size; i++)
            temp[i-1] = this->top[i];

        size --;
    }
}

template<class T>
bool NoobStack<T>::isEmpty(){
    return size == 0;
}