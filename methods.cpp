#include "methods.hpp"
#include <iostream>
using namespace std;

template<typename T>
Sequence<T>::Sequence() {
    begin = (Node<T>*) malloc (sizeof(Node<T>));
    end = begin;
    begin->next = nullptr;
};

template<typename T>
void Sequence<T>::Insert(T value) {
    end->next = (Node<T>*) malloc (sizeof(Node<T>));
    end = end->next;
    end->value = value;
    end->next = nullptr;
}

template<typename T>
void Sequence<T>::Print() {
    Node<T>* current = begin->next;
    while (current != nullptr) {
        cout << current->value << " ";
        current = current->next;
    }
    cout << "\n";
}

template<typename T>
T Sequence<T>::queueLeave() {
    if (begin->next == end) {
        cout << "No elements on queue!";
        return T();
    }

    T leaving = begin->next->value;
    begin->next = begin->next->next;
    if(begin->next == nullptr)
        end = begin;

    cout << leaving << " left the queue!\n";
    return leaving;
}

template<typename T>
T Sequence<T>::stackPop() {
    if (begin->next == end) {
        cout << "No elements on stack!";
        return 0;
    }

    T leaving = end->value;
    Node<T>* prev = begin;
    while(prev->next != end)
        prev = prev->next;
    delete end;
    end = prev;
    end->next = nullptr;
    
    cout << leaving << " has been popped from stack!\n";
    return leaving;
}

template<typename T>
T Sequence<T>::listRemove(T value) {
    if (begin->next == end) {
        cout << "No elements on stack!";
        return 0;
    }

    Node<T>* temp = begin->next, *swap;
    while (temp->next != nullptr) {
        if (temp->value == value) {
            T leaving = temp->value;
            swap = temp;
            *temp = *swap->next;
            temp = nullptr;
            cout << leaving << " has been removed from list!\n";
            return leaving;
        }
        temp = temp->next;
    }
    cout << "Given value wasn't in list!\n";
    return 0;
}