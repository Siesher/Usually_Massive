#include <iostream>

template<typename T, std::size_t N>

class queue{
    private:

    T data[N];
    std::size_t size;
    std::size_t front;
    std::size_t rear;

    public:

    queue() : size(0), front(0), rear(0) {}

    bool is_empty() const{
        return size == 0;
    }

    bool is_full() const{
        return size == N;
    }

    void enqueue(T value){
        if(is_full()){
            std::cerr << "Queue is full" << std::endl;
            return;
        }
        data[rear] = value;
        rear = (rear + 1) % N;
        ++size;
    }

    void dequeue(){
        if(is_empty()){
            std::cerr << "Queue is empty" << std::endl;
            return;
        }
        front = (front + 1) % N;
        --size;
    }

    T front_value() const{
        if(is_empty()){
            std::cerr << "Queue is empty" << std::endl;
            throw std::out_of_range("Queue is empty");
        }

        return data[front];

    }

    void display() const{
        if(is_empty()){
            std::cerr << "Queue is empty" << std::endl;
            return;
        }
        std::size_t current = front;
        for(std::size_t i = 0; i != size; ++i){
            std::cout << data[current] << " ";
            current = (current + 1) % N;
        }
        std::cout << std::endl;
    }
};


int main(){
    queue<int, 5> q;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);

    std::cout << "Front value: " << q.front_value() << std::endl;

    std::cout << "Queue after enqueueing 5 elements: ";
    q.display();

    q.dequeue();
    q.dequeue();

    std::cout << "Queue after dequeueing 2 elements: ";
    q.display();

    std::cout << "Front value: " << q.front_value() << std::endl;

    return 0;
}