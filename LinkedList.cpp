//
// Created by Rena on 5/27/21.
//
#ifndef FIRSTDRAFT_LINKEDLIST_CPP
#define FIRSTDRAFT_LINKEDLIST_CPP
#include "LinkedList.h"

template <class T>
LinkedList<T>::LinkedList()
{
    // Set Head and Tail to Nullptr at first
    _size = 0;
    head = nullptr;
    tail = nullptr;
}

template<class T>
int LinkedList<T>::size()
{
    return _size;
}

template <class T>
LinkedList<T>::LinkedList(const LinkedList<T>& list) : LinkedList()
{
    *this = list;
}

// Create a node with certain value
template <class T>
Node<T>* LinkedList<T>::createNode(T item)
{
    _size++;
    Node<T>* n = new Node<T>;
    n ->data = item;
    n ->next = nullptr;
    n ->prev = nullptr;
    return n;
}

// Find the node at the given  item
template <class T>
Node<T>* LinkedList<T>::findIndex(T item)
{
    for(Node<T>* walk = head; walk != nullptr; walk = walk->next)
    {
        if(walk->data == item)
        {
            return walk;
        }
    }
    std::cout << "The given value is not in the linkedlist" << std::endl;
}

// Insert certain item at the end of the list
template <class T>
void LinkedList<T>::insert(T item)
{
    //_size++;
    Node<T>* temp = createNode(item);
    if(head == nullptr)
    {
        head = temp;
        tail = temp;
    }
    else
    {
//        tail->prev = temp;
//        std::cout << "prev  " << tail->prev->data<<std::endl;
        temp->prev = tail;
        tail->next = temp;
        tail = temp;

    }
}

// Insert certain value at the head of the list
template <class T>
void LinkedList<T>::insertHead(T item)
{
    _size++;
    Node<T>* temp = createNode(item);
    if(head == nullptr)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        temp->next =head;
        head->prev = temp;
        head = temp ;
        //temp->prev = head;

    }
}

// Insert certain value at the end of the list
template <class T>
void LinkedList<T>::insertAfter(T insertThis, T AfterThat)
{
    insertAfter(insertThis, findIndex(AfterThat));
}

// Insert certain value after a certain node
template <class T>
void LinkedList<T>::insertAfter(T insertThis, Node<T>* AfterThat)
{
    _size++;
    Node<T>* temp = createNode(insertThis);
    if(head == nullptr)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        temp->next = AfterThat->next;
        AfterThat->prev = temp;
        AfterThat->next = temp;
    }
}

// Insert certain value before certain value
template <class T>
void LinkedList<T>::insertBeofore(T insertThis, T beforeThat)
{
    insertBeofore(insertThis, findIndex(beforeThat));
}

template <class T>
void LinkedList<T>::insertBeofore(T insertThis, Node<T>* beforeThat)
{
    //size++;
    Node<T>* temp = createNode(insertThis);
    if(beforeThat == head)
    {
        insertHead(insertThis);
    }
    else
    {
        temp->next = beforeThat;
        beforeThat->prev ->next= temp;
    }
    _size++;
}

// Overwrite the = operator, copy the list
template <class T>
LinkedList<T>& LinkedList<T>::operator =(const LinkedList<T>& list)
{
    clear();
    Node<T>*walker = list.head;
    while(walker != nullptr)
    {
        //size++;
        insert(walker->data);
        walker = walker->next;
    }
    return *this;
}
template <class T>
void LinkedList<T>::removeTail()
{
    if ( tail )
    {
        Node<T> *nodeToDelete = tail;
        tail = tail->prev;

        if ( tail )
        {
            tail->next = nullptr;
        }
        else
        {
            head = nullptr;
        }

        delete nodeToDelete;
        _size--;
    }
}

// Clear the value in the list, empty the list
template <class T>
void LinkedList<T>::clear()
{
    _size = 0;
    Node<T>* walker = head;
    Node<T>* previous;
    while(walker!=nullptr)
    {
        previous = walker;
        walker = walker->next;
        delete previous;
    }
    head= nullptr;
    tail = nullptr;
}

// check if the list is empty
template <class T>
void LinkedList<T>::checkEmpty()
{
    if(head == nullptr)
        std::cout << "This list is empty" << std::endl;
    else
        std::cout << "This list is not empty" << std::endl;
}

// Return the size of the list
template <class T>
int LinkedList<T>::getSize()
{
    return _size;
}

// Return the tail of the list
template<class T>
T LinkedList<T>::getTailDate()
{
    return tail->data;
}

// Return the value of head in the list
template<class T>
T LinkedList<T>::getHeadDate()
{
    return head ->data;
}

// Remove a certain value at given position
template<class T>
void LinkedList<T>::removeAt(int position, int size)
{
    // When we need to remove the head
    if(position == 0)
    {
        Node<T> *temp=new Node<T>;
        temp=head;
        head=head->next;
        delete temp;
    }
        // When we need to remove the tail
    else if(position == size-1)
    {
        Node<T> *current = new Node<T>;
        Node<T> *previous = new Node<T>;
        current=head;
        while(current->next != NULL)
        {
            previous = current;
            current = current->next;
        }
        tail = previous;
        previous->next = NULL;
        delete current;
    }
        // When not head and not tail
    else
    {
        // create two new node
        Node<T> *current=new Node<T>;
        Node<T> *previous=new Node<T>;
        current=head;
        // Find the position of the given node
        for(int i=1; i < position+1; i++) //or i = 0; i < pos-1
        {
            previous=current;
            current=current->next;
        }
        previous->next=current->next;
        delete current;
    }
    _size--;
}
// Return the value of the given position in the list
template<class T>
T& LinkedList<T>::seek(int n) const
{
    Node<T>* walker= head;
    int i = 0;
    while(walker != nullptr && i <n)
    {
        walker = walker -> next;
        i++;
    }
    if(walker != nullptr)
        return walker->data;
    else if(tail != nullptr)
        return tail->data;
    else
        return walker->data;// return null

}
template <class T>
T LinkedList<T>::at(int n )
{
    Node<T>* walker= head;
    int i = 0;
    while(walker != nullptr && i <n)
    {
        walker = walker -> next;
        i++;
    }
    if(walker != nullptr)
        return walker->data;
    else if(tail != nullptr)
        return tail->data;
    else
        return walker->data;
}
template <class T>
void LinkedList<T>::deleteAllNode()
{
    Node<T>* temp = new Node<T>();
    while(head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
        _size--;
    }
    std::cout<<"\nAll nodes are deleted successfully.";
}

template<class T>
T& LinkedList<T>::rseek(int n)
{
    Node<T>* walker= tail;
    int i = 0;
    while(walker != nullptr && i <n)
    {
        walker = walker -> prev;
        i++;
    }
    if(walker != nullptr)
        return walker->data;
    else return head->data;

}

// Overwrite the += operator, add value to the list
template <class T>
void LinkedList<T>::operator +=(T item)
{
    insert(item);
}

// print out the list by overwrite the <<
template <class T>
std::ostream& operator << (std::ostream& out, const LinkedList<T>& list)
{
    for(Node<T>* walk = list.head; walk != nullptr; walk = walk-> next)
    {
        out.width(12);
        out << walk->data;
    }
    return out;
}
#endif