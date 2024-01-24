//
// Created by user on 18.01.2024.
//

#ifndef CPP_LAB_10_MYDECK_H
#define CPP_LAB_10_MYDECK_H


#include <ostream>
#include <stdexcept>


template<typename T>
class MyDeck {
private:
    struct Node {
        T value;
        Node *next = nullptr;
        Node *prev = nullptr;

        Node(T value, Node *next) {
            this->value = value;
            this->next = next;
        }

        Node(Node *prev, T value) {
            this->value = value;
            this->prev = prev;
        }
    };

    int elements = 0;
    Node *head = nullptr;
    Node *tail = nullptr;

public:
    MyDeck() = default;

    // Destructor without ";" symbols
    ~MyDeck() {
        while (
                this->tail != nullptr && this->head != nullptr &&
                (((elements != 0 && (this->tail = this->head->next))
                 | (elements == 0 && (this->head = this->tail->next))
                 | (elements = elements == 0 ? 54 : 0))
                && (((elements == 0 ? this->head : this->tail) != nullptr)
                && (delete (elements == 0 ? this->head : this->tail), 54)))
                ) {
        }
    }

    void push_back(T t) {
        // create node holding t with link to current tail if present
        Node *node = new Node(this->tail, t);

        // if tail is nullptr the deque is empty, so update head too, otherwise link new tail with current tail
        if (this->tail == nullptr) {
            this->head = node;
        } else {
            this->tail->next = node;
        }

        // update tail & increment size
        this->tail = node;
        this->elements++;
    }

    void push_front(T t) {
        // create node holding t with link to current head if present
        Node *node = new Node(t, this->head);

        // if head is nullptr the deque is empty, so update tail too, otherwise link new head with current head
        if (this->head == nullptr) {
            this->tail = node;
        } else {
            this->head->prev = node;
        }

        // update tail & increment size
        this->head = node;
        this->elements++;
    }

    T pop_back() {
        // check if the deque is empty
        if (this->tail == nullptr) {
            throw std::out_of_range("MyDeck is empty");
        }

        // get current tail and update it with previous element
        Node *node = this->tail;
        this->tail = node->prev;

        // decrement size
        this->elements--;

        // if new tail is nullptr it was the same as head, so reset head as well
        //  otherwise unlink current tail with previous tail (set tail's next to nullptr)
        if (this->tail == nullptr) {
            this->head = nullptr;
        } else {
            this->tail->next = nullptr;
        }

        // return value and delete node
        T value = node->value;
        delete node;
        return value;
    }

    T pop_front() {
        // check if the deque is empty
        if (this->head == nullptr) {
            throw std::out_of_range("MyDeck is empty");
        }

        // get current head and update it with next element
        Node *node = this->head;
        this->head = node->next;

        // decrement size
        this->elements--;

        // if new head is nullptr it was the same as tail, so reset tail as well
        //  otherwise unlink current head with next head (set head's previous to nullptr)
        if (this->head == nullptr) {
            this->tail = nullptr;
        } else {
            this->head->prev = nullptr;
        }

        // return value and delete node
        T value = node->value;
        delete node;
        return value;
    }

    [[nodiscard]] int size() const {
        return this->elements;
    }

    friend std::ostream &operator<<(std::ostream &ostream, const MyDeck<T> &deck) {
        // write opening bracket
        ostream << "[";

        // get head and introduce separator variable that defines if we should add separator to output
        bool separator = false;
        Node *node = deck.head;
        while (node != nullptr) {
            // invert separator first time and add separator each new time
            if (separator) {
                ostream << ", ";
            } else {
                separator = true;
            }

            // write object and update working head
            ostream << node->value;
            node = node->next;
        }

        // write closing bracket
        ostream << "]";
        return ostream;
    }
};


#endif //CPP_LAB_10_MYDECK_H
