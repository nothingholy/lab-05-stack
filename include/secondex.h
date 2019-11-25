//
// Created by nothingholy on 25.11.2019.
//

#ifndef TEMPLATE_SECONDEX_H
#define TEMPLATE_SECONDEX_H

#include "header.hpp"

template<typename T>
class SecondStack : public MajorStack<T> {
public:
    template<typename ... Args>
    void push_emplace(Args&& ... value) {
        auto node = MajorStack<T>::head;
        MajorStack<T>::head=new typename MajorStack<T>::Node{forward<Args>(value)...,node};
    }

    T pop() {
        if(MajorStack<T>::head) {
            auto node = MajorStack<T>::head->data;
            MajorStack<T>::head=MajorStack<T>::head->next;
            return node;
        }
        else
            throw exception();
    }
};

#endif //TEMPLATE_SECONDEX_H
