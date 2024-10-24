#include <iostream>

template <typename T>
class BinaryTree {
private:
    struct Node {
        T data;
        Node* left;
        Node* right;
        Node(T val) : data(val), left(nullptr), right(nullptr) {}
    };

    Node* root;

    void insert(Node*& node, T value) {
        if (node == nullptr) {
            node = new Node(value);
        } else if (value < node->data) {
            insert(node->left, value);
        } else {
            insert(node->right, value);
        }
    }

    Node* find_min(Node* node) const {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    Node* remove(Node* node, T value) {
        if (node == nullptr) {
            return node;
        }
        if (value < node->data) {
            node->left = remove(node->left, value);
        } else if (value > node->data) {
            node->right = remove(node->right, value);
        } else {
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            Node* temp = find_min(node->right);
            node->data = temp->data;
            node->right = remove(node->right, temp->data);
        }
        return node;
    }

    bool search(Node* node, T value) const {
        if (node == nullptr) {
            return false;
        }
        if (value < node->data) {
            return search(node->left, value);
        } else if (value > node->data) {
            return search(node->right, value);
        } else {
            return true;
        }
    }

    void in_order_traversal(Node* node) const {
        if (node != nullptr) {
            in_order_traversal(node->left);
            std::cout << node->data << " ";
            in_order_traversal(node->right);
        }
    }

    void pre_order_traversal(Node* node) const {
        if (node != nullptr) {
            std::cout << node->data << " ";
            pre_order_traversal(node->left);
            pre_order_traversal(node->right);
        }
    }

    void post_order_traversal(Node* node) const {
        if (node != nullptr) {
            post_order_traversal(node->left);
            post_order_traversal(node->right);
            std::cout << node->data << " ";
        }
    }

    void destroy_tree(Node* node) {
        if (node != nullptr) {
            destroy_tree(node->left);
            destroy_tree(node->right);
            delete node;
        }
    }

public:
    BinaryTree() : root(nullptr) {}

    ~BinaryTree() {
        destroy_tree(root);
    }

    void insert(T value) {
        insert(root, value);
    }

    void remove(T value) {
        root = remove(root, value);
    }

    bool search(T value) const {
        return search(root, value);
    }

    void in_order_traversal() const {
        in_order_traversal(root);
        std::cout << std::endl;
    }

    void pre_order_traversal() const {
        pre_order_traversal(root);
        std::cout << std::endl;
    }

    void post_order_traversal() const {
        post_order_traversal(root);
        std::cout << std::endl;
    }
};

int main() {
    BinaryTree<int> tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(7);
    tree.insert(12);
    tree.insert(18);

    std::cout << "In-order traversal: ";
    tree.in_order_traversal();

    std::cout << "Pre-order traversal: ";
    tree.pre_order_traversal();

    std::cout << "Post-order traversal: ";
    tree.post_order_traversal();

    std::cout << "Search for 7: " << (tree.search(7) ? "Found" : "Not Found") << std::endl;
    std::cout << "Search for 20: " << (tree.search(20) ? "Found" : "Not Found") << std::endl;

    tree.remove(15);
    std::cout << "After removing 15, in-order traversal: ";
    tree.in_order_traversal();

    return 0;
}
