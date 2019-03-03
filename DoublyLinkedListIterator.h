//
// Created by mfbut on 2/11/2019.
//

#ifndef LINKEDLIST_GENERICDOUBLYLINKEDLISTITERATOR_H
#define LINKEDLIST_GENERICDOUBLYLINKEDLISTITERATOR_H
#include "DoublyLinkedList.h"
template <typename T>
class DoublyLinkedList{};
template<typename T>
class DoublyLinkedListIterator {

  //you must implement at least the methods below
  //you are free to add (and will likely need to add)
  //more members and methods
 private:
  int Position;
  T* CurrentValuePtr;
  DoubleLinkedNode<T>* CurrentNodePtr;
  DoublyLinkedList<T>* CurrentListPtr;
 public:
  DoublyLinkedListIterator(const DoublyLinkedListIterator& orig);

  explicit DoublyLinkedListIterator(DoublyLinkedList<T>* List);
  //are the two iterators equal?
  //they are if they are over the same doubly linked list
  //and (they are referring to the same element in the list
  //or they are out of bounds)
  bool operator==(const DoublyLinkedListIterator<T>& rhs) const;

  //are the two iterators different?
  bool operator!=(const DoublyLinkedListIterator<T>& rhs) const;

  //is the iterator safe to dereference?
  explicit operator bool() const;

  //go to the next element
  DoublyLinkedListIterator<T>& operator++(); //pre
  const DoublyLinkedListIterator<T> operator++(int);//post

  //go to the previous element
  DoublyLinkedListIterator<T>& operator--(); //pre
  const DoublyLinkedListIterator<T> operator--(int); //post

  //get a const reference to the value
  const T& operator*() const;

  //get a non const iterator
  T& operator*();

};
template<typename T>
DoublyLinkedListIterator<T>::DoublyLinkedListIterator(DoublyLinkedList<T>* orig_list):Position(0){


  CurrentListPtr(orig_list);
  CurrentNodePtr(CurrentListPtr->head);
  CurrentValuePtr=DoubleLinkedNode<T>::ValuePtr(CurrentNodePtr);
}
template <typename T>
DoublyLinkedListIterator<T>::DoublyLinkedListIterator(const DoublyLinkedListIterator& orig):Position(orig.Position){


  CurrentListPtr(orig.CurrentList);
  CurrentNodePtr(orig.CurrentList);
  CurrentValuePtr=DoubleLinkedNode<T>::ValuePtr(CurrentNodePtr);
}

template <typename T>
bool DoublyLinkedListIterator<T>::operator==(const DoublyLinkedListIterator<T> &rhs) const {
  if(CurrentListPtr != rhs.CurrentListPtr){
    return false;
  }else {
    return Position == rhs.Position;
  }
}
template <typename T>
bool DoublyLinkedListIterator<T>::operator!=(const DoublyLinkedListIterator<T> &rhs) const {
  if(CurrentListPtr == rhs.CurrentListPtr){
    return false;
  }else {
    return Position != rhs.Position;
  }
}
//automatically a bool type?
template <typename T>
DoublyLinkedListIterator<T>::operator bool() const {
  if (this== nullptr){
    return false;
  }
  else return this->CurrentListPtr== nullptr;
}
template <typename T>
T& DoublyLinkedListIterator<T>::operator*() {
  return CurrentValuePtr;
}
template <typename T>
const T& DoublyLinkedListIterator<T>::operator*() const {
  return const_cast<const T&>(CurrentValuePtr);
}
template <typename T>
DoublyLinkedListIterator<T> & DoublyLinkedListIterator<T>::operator--() {
  if (DoubleLinkedNode<T>::GetPrePtr(this->CurrentNodePtr)){
    this->CurrentNodePtr=DoubleLinkedNode<T>::GetPrePtr(this->CurrentNodePtr);
    CurrentValuePtr=DoubleLinkedNode<T>::ValuePtr(CurrentNodePtr);
    Position--;
    return &this;

  }
  else return &this;
}
template <typename T>
const DoublyLinkedListIterator<T> DoublyLinkedListIterator<T>::operator--(int ) {
  if (DoubleLinkedNode<T>::GetPrePtr(this->CurrentNodePtr)){
    this->CurrentNodePtr=DoubleLinkedNode<T>::GetPrePtr(this->CurrentNodePtr);
    CurrentValuePtr=DoubleLinkedNode<T>::ValuePtr(CurrentNodePtr);
    Position--;
    DoublyLinkedListIterator<T>temp=(DoublyLinkedListIterator(this));
    DoublyLinkedListIterator<T>*temp_ref=&temp;
    const_cast<const DoublyLinkedListIterator<T>*>(temp_ref);//is it the correct way of const casting?
    return temp_ref;
  }
  else {
    DoublyLinkedListIterator<T>*this_ref=&this;
    const_cast<const DoublyLinkedListIterator<T>*>(this_ref);
    return this_ref;
  }


}
template <typename T>
DoublyLinkedListIterator<T>& DoublyLinkedListIterator<T>:: operator++(){
  if (DoubleLinkedNode<T>::GetNextPtr(this->CurrentNodePtr)){
    this->CurrentNodePtr=DoubleLinkedNode<T>::GetNextPtr(this->CurrentNodePtr);
    CurrentValuePtr=DoubleLinkedNode<T>::ValuePtr(CurrentNodePtr);
    Position++;
    return &this;
  }
  else return &this;
}


template <typename T>
const DoublyLinkedListIterator<T> DoublyLinkedListIterator<T>::operator++(int){
  if (DoubleLinkedNode<T>::GetNextPtr(this->CurrentNodePtr)){
    this->CurrentNodePtr=DoubleLinkedNode<T>::GetNextPtr(this->CurrentNodePtr);
    CurrentValuePtr=DoubleLinkedNode<T>::ValuePtr(CurrentNodePtr);
    Position++;
    DoublyLinkedListIterator<T>temp=(DoublyLinkedListIterator(this));
    DoublyLinkedListIterator<T>*temp_ref=&temp;

    const_cast<const DoublyLinkedListIterator<T>*>(temp_ref);
    return temp_ref;
  }
  else{
    DoublyLinkedListIterator<T>*this_ref=&this;
    const_cast<const DoublyLinkedListIterator<T>*>(this_ref);
    return this_ref;
  }
}//post
#endif //LINKEDLIST_GENERICDOUBLYLINKEDLISTITERATOR_H
