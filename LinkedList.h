//
// Created by Rena on 5/27/21.
//

#ifndef FIRSTDRAFT_LINKEDLIST_H
#define FIRSTDRAFT_LINKEDLIST_H


#include "Node.h"
#include <iostream>

template <class T>

class LinkedList {
private:
    Node<T>* head;
    Node<T>* tail;
    Node<T>* createNode(T item);

    void insertAfter(T insertThis, Node<T>* AfterThat);
    void insertBeofore(T insertThis, Node<T>* beforeThat);
    Node<T>* findIndex(T item);

public:
    LinkedList();
    LinkedList(const LinkedList<T>& list);
    int getSize();
    void insert(T item);
    void insertHead(T item);
    int size();
    T getTailDate();
    T getHeadDate();
    void removeTail();
    T& seek(int n ) const;
    T& rseek(int n );
    T at(int n ) ;
    void removeAt(int position, int size);

    template<class S>
    friend std::ostream& operator << (std::ostream& out, const LinkedList<S>& list);

    void operator +=(T item);
    void clear();
    void checkEmpty();
    LinkedList<T>& operator=(const LinkedList<T>& list);
    void insertAfter(T insertThis, T AfterThat);
    void insertBeofore(T insertThis, T beforeThat);
    void deleteAllNode();
    int _size;
};

# include "LinkedList.cpp"

#endif //FIRSTDRAFT_LINKEDLIST_H
