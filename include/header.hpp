// Copyright 2018 Your Name <your_email>

#ifndef INCLUDE_HEADER_HPP_
#define INCLUDE_HEADER_HPP_

#include <iostream>
#include <type_traits>
#include <exception>
using namespace std;

template<typename T>
class MajorStack {
protected:
    struct Node {
        T data;
        Node *next;
    };

    Node *head;

public:
    MajorStack()= default;
    MajorStack(const MajorStack &stack)= delete;
    MajorStack(MajorStack&& stack)= default;

    auto operator=(const MajorStack &stack)->MajorStack& = delete;
    auto operator=(MajorStack&& stack) noexcept ->MajorStack& = default;

    void push(T&& value)
    {
        auto node = new Node{forward<T>(value),head};
        head = node;
    }

    const T& Head() {
        if(!head)
            throw exception();
        return head->data;
    }

    ~MajorStack() {
        while(head) {
            auto *act=head;
            head = act->next;
            delete act;
        }
    }
};




#endif // INCLUDE_HEADER_HPP_
