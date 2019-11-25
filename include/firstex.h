//
// Created by nothingholy on 25.11.2019.
//

#ifndef TEMPLATE_FIRSTEX_H
#define TEMPLATE_FIRSTEX_H

#include "header.hpp"

template<typename T>
class FirstStack : public MajorStack<T> {
public:
    void push(const T& value) {
        auto node = new typename MajorStack<T>::Node{value,MajorStack<T>::head};
        MajorStack<T>::head = node;
    }

    void pop() {
        if(MajorStack<T>::head)
            MajorStack<T>::head=MajorStack<T>::head->next;
        else
            throw exception();
    }
};

#endif //TEMPLATE_FIRSTEX_H
