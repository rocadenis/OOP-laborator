#include <iostream>

template<typename K, typename V>
class Map {
private:
    struct Node {
        K key;
        V value;
        Node* next;
        Node(const K& key, const V& value) : key(key), value(value), next(nullptr) {}
    };
    Node* head;
    int size;

public:
    Map() : head(nullptr), size(0) {}

    ~Map() {
        clear();
    }

    // Copy constructor
    Map(const Map& other) : head(nullptr), size(0) {
        Node* curr = other.head;
        while (curr != nullptr) {
            set(curr->key, curr->value);
            curr = curr->next;
        }
    }

    // Copy assignment operator
    Map& operator=(const Map& other) {
        if (this != &other) {
            clear();
            Node* curr = other.head;
            while (curr != nullptr) {
                set(curr->key, curr->value);
                curr = curr->next;
            }
        }
        return *this;
    }

    void set(const K& key, const V& value) {
        Node* curr = head;
        while (curr != nullptr) {
            if (curr->key == key) {
                curr->value = value;
                return;
            }
            curr = curr->next;
        }
        // key not found, create new node
        Node* new_node = new Node(key, value);
        new_node->next = head;
        head = new_node;
        size++;
    }

    bool get(const K& key, V& value) const {
        Node* curr = head;
        while (curr != nullptr) {
            if (curr->key == key) {
                value = curr->value;
                return true;
            }
            curr = curr->next;
        }
        return false;
    }

    int count() const {
        return size;
    }

    bool delete_key(const K& key) {
        Node* curr = head;
        Node* prev = nullptr;
        while (curr != nullptr) {
            if (curr->key == key) {
                if (prev != nullptr) {
                    prev->next = curr->next;
                } else {
                    head = curr->next;
                }
                delete curr;
                size--;
                return true;
            }
            prev = curr;
            curr = curr->next;
        }
        return false;
    }

    void clear() {
        Node* curr = head;
        while (curr != nullptr) {
            Node* temp = curr->next;
            delete curr;
            curr = temp;
        }
        head = nullptr;
        size = 0;
    }

    bool includes(const Map<K,V>& other) const {
        Node* curr = other.head;
        while (curr != nullptr) {
            V value;
            if (!get(curr->key, value) || value != curr->value) {
                return false;
            }
            curr = curr->next;
        }
        return true;
    }

    // Iterator class
    class Iterator {
    private:
        Node* curr;
        int index;

    public:
        Iterator(Node* node, int index) : curr(node), index(index) {}

        bool operator!=(const Iterator& other) const {
            return curr != other.curr;
        }

        void operator++() {
            curr = curr->next;
            index++;
        }

        std::tuple<K, V, int> operator*() const {
            return std::make_tuple(curr->key, curr->value, index);
        }
    };

    Iterator begin() const {
        return Iterator(head, 0);
    }
     Iterator end() const {
        return Iterator(nullptr, size);
     }
};
