#include <iostream>
#include <bits/c++config.h>
#include <time.h>
template<typename T>

class Dynamic_queue{
    private:
    struct Node{
        T data;
        Node* next;
        Node(T val): data(val), next(nullptr) {};
    };

    Node* front;
    Node* rear;
    std::size_t size;

    public:
    Dynamic_queue(): front(nullptr), rear(nullptr), size(0) {}

    ~Dynamic_queue(){
        while(!is_empty()){
            dequeue();
        }
    }

    bool is_empty() const{
        return size == 0;
    }


    void enqueue(T val){
        Node* new_node = new Node(val);
        if(is_empty()){
            front = rear = new_node;
        } else{
            rear->next = new_node;
            rear = new_node;
        }
        ++size;
    }


    void dequeue(){
        if(is_empty()){
            std::cerr << "Queue is empty" << std::endl;
            return;
        }
        Node* temp = front;
        front = front->next;
        delete temp;
        --size;
        if(is_empty()){
            rear = nullptr;
        }
    }


    T front_el() const {
        if(is_empty()){
            std::cerr << "Queue is empty" << std::endl;
            throw std::out_of_range("Queue is empty");
        }
        return front->data;
    }

    void disp() const {
        if(is_empty()){
            std::cout << "Queue is empty" << std::endl;
            return;
        }

        Node* current = front;
        while(current){
            std::cout << current->data << " ";
            current = current->next;
        }

        std::cout << std::endl;

    }

};

int main(){
    Dynamic_queue<int> q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);

    std::cout << "Queue elements: ";
    q.disp();

    std::cout << "Front element: " << q.front_el() << std::endl;

    q.dequeue();
    q.dequeue();

    std::cout << "Queue after dequeue: ";
    q.disp();

    q.enqueue(75);
    std::cout << "Queue after enqueue: ";
    q.disp();

    return 0;
}