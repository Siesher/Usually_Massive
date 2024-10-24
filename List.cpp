#include <iostream>
#include <bits/c++config.h>

template<typename T, std::size_t size>
class List {
private:
    T data[size];
    std::size_t size_;
public:
    List() : size_(0) {}

    bool is_empty() const {
        return size_ == 0;
    }

    bool is_full() const {
        return size_ == size;
    }

    void add(const T& value, std::size_t index) {
        if (is_full()) {
            std::cerr << "List is full" << std::endl;
            return;
        }
        if (index > size_) {
            std::cerr << "Invalid index" << std::endl;
            return;
        }
        for (std::size_t i = size_; i > index; --i) {
            data[i] = data[i - 1];
        }
        data[index] = value;
        ++size_;
    }

    void remove_at(std::size_t index) {
        if (is_empty()) {
            std::cerr << "List is empty" << std::endl;
            return;
        }
        if (index >= size_) {
            std::cerr << "Invalid index" << std::endl;
            return;
        }
        for (std::size_t i = index; i < size_ - 1; ++i) {
            data[i] = data[i + 1];
        }
        --size_;
    }

    int find(const T& value) const {
        for (std::size_t i = 0; i < size_; ++i) {
            if (data[i] == value) {
                return i;
            }
        }
        return -1;
    }

    void print() const {
        if (is_empty()) {
            std::cout << "List is empty" << std::endl;
            return;
        }
        for (std::size_t i = 0; i < size_; ++i) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }
};

struct Process {
    int id;
    bool status;
    std::string name;
};

std::ostream& operator<<(std::ostream& os, const Process& p) {
    os << "ID: " << p.id << ", Status: " << (p.status ? "Running" : "Stopped") << ", Name: " << p.name << std::endl;
    return os;
}


int main() {
    List<Process, 10> processList;

    Process p1 = {1, true, "Process 1"};
    Process p2 = {2, false, "Process 2"};
    Process p3 = {3, true, "Process 3"};
    Process p4 = {4, false, "Process 4"};
    Process p5 = {5, true, "Process 5"};

    processList.add(p1, 0);
    processList.add(p2, 1);
    processList.add(p3, 2);
    processList.add(p4, 3);
    processList.add(p5, 4);

    processList.print();

    Process p6 = {6, true, "Process 6"};
    processList.add(p6, 3);
    processList.print();

    processList.remove_at(2);
    processList.print();

    std::cout << "Index of Process 3: " << processList.find(p3) << std::endl;
    std::cout << "Index of Process 4: " << processList.find(p4) << std::endl;

    return 0;
}