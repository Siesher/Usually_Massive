#include <iostream>

// Структура узла списка
template<typename T>
class Dynamic_List {
private:
    struct Node {
        T data;
        Node* next;
        Node(T val) : data(val), next(nullptr) {}
    };

    Node* head;

public:
    Dynamic_List() : head(nullptr) {}

    ~Dynamic_List() {
        while (head) {
            pop_front();
        }
    }

    bool is_empty() const {
        return head == nullptr;
    }

    void add(const T& value, int index) {
        if (index == 0) {
            push_front(value);
            return;
        }
        Node* current = head;
        for (int i = 0; i < index - 1 && current != nullptr; ++i) {
            current = current->next;
        }
        if (current != nullptr) {
            Node* newNode = new Node(value);
            newNode->next = current->next;
            current->next = newNode;
        }
    }

    void remove_at(int index) {
        if (index == 0) {
            pop_front();
            return;
        }
        Node* current = head;
        for (int i = 0; i < index - 1 && current != nullptr; ++i) {
            current = current->next;
        }
        if (current != nullptr && current->next != nullptr) {
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
        }
    }

    int find(const T& value) const {
        Node* current = head;
        int index = 0;
        while (current) {
            if (current->data == value) {
                return index;
            }
            current = current->next;
            ++index;
        }
        return -1;
    }

    void print() const {
        Node* current = head;
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

// Структура для процессов
struct Process {
    int id;
    bool status;
    std::string name;
};

// Оператор вывода для структуры Process
std::ostream& operator<<(std::ostream& os, const Process& p) {
    os << "ID: " << p.id << ", Status: " << (p.status ? "Running" : "Stopped") << ", Name: " << p.name << std::endl;
    return os;
}

// Главная функция
int main() {
    Dynamic_List<Process> processList;

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