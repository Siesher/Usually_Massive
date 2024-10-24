#include <iostream>

template<typename T, std::size_t N>

class Set{
    private:
    T data[N];
    std::size_t size;

    bool contains(T value) const{
        for(std::size_t i = 0; i < size; ++i){
            if(data[i] == value) return true;
        }
        return false;
    }

    public:
    Set() : size(0) {}

    bool is_empty() const {
        return size == 0;
    }

    bool is_full() const {
        return size == N;
    }

    void add(T value){
        if (is_full()) {
            std::cerr << "Set is full!" << std::endl;
            return;
        }
        if (!contains(value)) {
            data[size++] = value;
        }
    }

    void remove(T value){
        for(std::size_t i = 0; i < size; ++i){
            if(data[i] == value){
                for(std::size_t j = i; j < size - 1; ++j){
                    data[j] = data[j + 1];
                }
                --size;
                return;
            }
        }
    }

    bool contains_el(T value) const{
        return contains(value);
    }

    void display() const {
        for(std::size_t i = 0; i < size; ++i){
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }

};

int main(){

    int a, b;

    std::cout << "Enter limit of Set:" << std::endl << "a: " << std::endl;
    std::cin >> a;
    std::cout << "b: " << std::endl;
    std::cin >> b;

    Set<int, 100> mySet;
    

    for(std::size_t i = a; i <= b; ++i){
        mySet.add(i);
    }

    std::cout << "Set: ";
    mySet.display();

    mySet.add(20); // Попытка добавить дубликат
    std::cout << "After adding duplicate 20: ";
    mySet.display();

    mySet.remove(20);
    std::cout << "After removing 20: ";
    mySet.display();

    std::cout << "Contains 10: " << (mySet.contains_el(10) ? "Yes" : "No") << std::endl;
    std::cout << "Contains 20: " << (mySet.contains_el(20) ? "Yes" : "No") << std::endl;

    return 0;
}