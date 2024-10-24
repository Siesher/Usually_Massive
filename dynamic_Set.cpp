#include <iostream>

template<typename T>

class Dynamic_Set{

private:

    struct Node{
        T data;
        Node* next;
        Node(T val): data(val), next(nullptr) {}
    };

    Node* head;

    bool contains(T val) const {
        Node* current = head;
        while(current){
            if(current->data == val){
                return true;
            }
            current = current->next;
        }
        return false;
    }

public:

    Dynamic_Set() : head(nullptr) {}

    ~Dynamic_Set(){
        while(head){
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    bool is_empty() const{
        return head == nullptr;
    }

    void add(T val){
        if(!contains(val)){
            Node* newNode = new Node(val);
            newNode->next = head;
            head = newNode;
        }
    }

    void remove(T val){
        if(head == nullptr) return;

        if(head->data == val){
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* current = head;
        while(current->next && current->next->data != val){
            current = current->next;
        }

        if(current->next){
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
        }
    }

    bool contains_el(T val) const{
        return contains(val);
    }

    void display() const{
        Node* current = head;
        while(current){
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

int main(){
    Dynamic_Set<int> mySet;

    mySet.add(1);
    mySet.add(2);
    mySet.add(3);

    std::cout << "Set after adding 1, 2, 3:" << std::endl;
    mySet.display();
    
    mySet.add(2);

    std::cout << "Set after adding 2 again: " << std::endl;
    mySet.display();

    mySet.add(10);

    std::cout << "Set: ";
    mySet.display();

    mySet.remove(2);

    std::cout << "Set after removing 2: ";
    mySet.display();

    std::cout << "Set contains el 10: " << (mySet.contains_el(10) ? "Yes" : "No") << std::endl;

    return 0;
}