#include <iostream>

template<typename T, std::size_t N>

class stack{
    private:
    T data[N];
    std::size_t top;

    public:
    stack() : top(0) {}

    bool is_empty() const{
        return top == 0;
    }

    bool is_full() const{
        return top == N;
    }

    void push(T value){
        if(is_full()){
            std::cerr << "Stack is full!" << std::endl;
            return;
        }
        data[top++] = value;
    }

    void pop(){
        if(is_empty()){
            std::cerr << "Stack is empty!" << std::endl;
            return;
        }
        --top;
    }

    T top_element() const{
        if(is_empty()){
            std::cerr << "Stack is empty!" << std::endl;
            throw std::out_of_range("Stack is empty");
        }
        return data[top - 1];
    }

    void display() const{
        if(is_empty()){
            std::cerr << "Stack is empty!" << std::endl;
            return;
        }
        for(std::size_t i = top; i > 0; --i){
            std::cout << data[i - 1] << " ";
        }
        std::cout << std::endl;
    }
};

int main(){
    stack<int, 5> myStack;
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);
    myStack.push(4);
    myStack.push(5);

    std::cout << "Top element: " << myStack.top_element() << std::endl;

    myStack.pop();
    myStack.pop();

    std::cout << "Top element after popping: " << myStack.top_element() << std::endl;

    myStack.push(6);
    myStack.push(7);

    std::cout << "Top element after pushing 6 and 7: " << myStack.top_element() << std::endl;

    std::cout << "Stack after pushing 6 and 7: ";

    myStack.display();

    myStack.pop();

    std::cout << "Stack after popping: ";
    myStack.display();

    return 0;
}