#include <iostream>

template<typename T>

class Dynamic_Stack{
    private:
    struct Node{
        T data;
        Node* next;
        Node(T val): data(val), next(nullptr) {}
    };

    Node* top;

    public:
    Dynamic_Stack() : top(nullptr) {}

    ~Dynamic_Stack(){
        while(!is_empty()){
            pop();
        }
    }

    bool is_empty() const{
        return top == nullptr;
    }

    void push(T value){
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
    }

    void pop(){
        if(is_empty()){
            std::cerr << "Stack is empty" << std::endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    T top_element() const {
        if(is_empty()){
            std::cerr << "Stack is empty" << std::endl;
            throw std::out_of_range("Stack is empty");
        }
        return top->data;
    }

    void display() const{
        if(is_empty()){
            std::cerr << "Stack is empty" << std::endl;
            return;
        }
        Node* current = top;
        while(current){
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

int main(){
    Dynamic_Stack<int> myStack;

    myStack.push(1);
    myStack.push(2);
    myStack.push(3);

    std::cout << "Top element: " << myStack.top_element() << std::endl;

    myStack.display();

    myStack.pop();

    myStack.display();

    myStack.push(4);
    myStack.push(10);
    myStack.push(58638);
    myStack.push(9);

    std::cout << "Top element: " << myStack.top_element() << std::endl;

    myStack.display();

    return 0;
}