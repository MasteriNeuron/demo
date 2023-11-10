#include "linked_list.h"
#include <stack>
#include <string>

template<class T>
void LinkedList<T>::push_front(const T &value) {
    ListNode<T> *new_node = new ListNode<T>(value);
    new_node->next = head->next;
    head->next = new_node;
    num_of_element++;
}

template<class T>
void LinkedList<T>::push_back(const T &value) {
    ListNode<T> *p = head;
    while (p->next != nullptr) {
        p = p->next;
    }
    p->next = new ListNode<T>(value);
    num_of_element++;
}

template<class T>
void LinkedList<T>::pop_back() {
    ListNode<T> *p0 = head, *p1 = head->next;
    if (num_of_element == 0) {
        return;
    }

    // move to the end of the list
    while (p1->next != nullptr) {
        p0 = p1;
        p1 = p1->next;
    }

    delete p1;
    p0->next = nullptr;
    num_of_element--;
}

template<class T>
void LinkedList<T>::pop_front() {
    if (num_of_element == 0) {
        return;
    }
    ListNode<T> *p = head->next;
    head->next = p->next;
    delete p;
    num_of_element--;
}

template<class T>
void LinkedList<T>::remove(T &val) {
    if (num_of_element == 0) {
        return;
    }

    ListNode<T> *p0 = head, *p1 = head->next;
    do {
        if (p1->val == val) {
            p0->next = p1->next;
            delete p1;
            p1 = p0->next;
            num_of_element--;
        } else {
            p0 = p1;
            p1 = p1->next;
        }
    } while (p1 != nullptr);
}

/*
 * merge in ascending order
 */
template<class T>
void LinkedList<T>::merge(const List<T> &ot) {
    auto &other_list = (LinkedList<T> &) ot;
    ListNode<T> *p0 = head, *p1 = other_list.head;
    while (p1->next != nullptr) {
        if (p0->next == nullptr) {
            // list 1 already done, take whatever is left on list 2
            p0->next = new ListNode<T>(p1->next->val);
            p1 = p1->next;
            p0 = p0->next;
            num_of_element++;
            continue;
        }

        if (p0->next->val >= p1->next->val) {
            // both list not empty
            auto newNode = new ListNode<T>(p1->next->val);
            newNode->next = p0->next;
            p0->next = newNode;
            p1 = p1->next;
            num_of_element++;
        }
        p0 = p0->next;
    }
}

template<class T>
void LinkedList<T>::reverse_iterative() {
    if (head->next == nullptr || head->next->next == nullptr) {
        return;
    }

    ListNode<T> *p1 = head->next;
    ListNode<T> *p2 = p1->next;

    while (p2 != nullptr) {
        p1->next = p2->next;
        p2->next = head->next;
        head->next = p2;
        p2 = p1->next;
    }
}

template<class T>
void LinkedList<T>::reverse_print(Printer &printer) const {
    std::stack<T> elements;

    // Push elements onto the stack
    ListNode<T> *current = head->next;
    while (current != nullptr) {
        elements.push(current->val);
        current = current->next;
    }

    // Pop elements from the stack and print
    while (!elements.empty()) {
        T value = elements.top();
        elements.pop();
        printer.print(value);
    }
}
