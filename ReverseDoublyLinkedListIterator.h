//
// Created by mfbut on 2/13/2019.
//

#ifndef LINKEDLIST_GENERICREVERSEDOUBLYLINKEDLISTITERATOR_H
#define LINKEDLIST_GENERICREVERSEDOUBLYLINKEDLISTITERATOR_H
#include "ConstDoublyLinkedListIterator.h"
template<typename T>
class ReverseDoublyLinkedListIterator {
  private:
  //you must implement at least the methods below
  //you are free to add (and will likely need to add)
  //more members and methods
  int Position;
  T* CurrentValuePtr;
  DoubleLinkedNode<T>* CurrentNodePtr;
  DoublyLinkedList<T>* CurrentListPtr;
 public:
  //copy constructor

  ReverseDoublyLinkedListIterator(const ReverseDoublyLinkedListIterator& orig);

  //are the two iterators equal?
  //they are if they are over the same doubly linked list
  //and (they are referring to the same element in the list
  //or they are out of bounds)
  bool operator==(const ReverseDoublyLinkedListIterator<T>& rhs) const;

  //are the two iterators different?
  bool operator!=(ReverseDoublyLinkedListIterator<T>& rhs) const;

  //is the iterator safe to dereference?
  explicit operator bool() const;

  //go to the next element
  ReverseDoublyLinkedListIterator<T>& operator++(); //pre
  const ReverseDoublyLinkedListIterator<T> operator++(int);//post

  //go to the previous element
  ReverseDoublyLinkedListIterator<T>& operator--(); //pre
  const ReverseDoublyLinkedListIterator<T> operator--(int);//post

  //get a const reference to the value
  const T& operator*() const;

  //get a non-const reference to the value
  T& operator*();

};
template<typename T>
ReverseDoublyLinkedListIterator<T>::ReverseDoublyLinkedListIterator(const ReverseDoublyLinkedListIterator &orig):Position(orig.Position) {
  CurrentListPtr(orig.CurrentList);
  CurrentNodePtr(orig.CurrentList);
  CurrentValuePtr=DoubleLinkedNode<T>::ValuePtr(CurrentNodePtr);
}
template<typename T>
bool ReverseDoublyLinkedListIterator<T>::operator==(const ReverseDoublyLinkedListIterator<T> &rhs) const {
  if(CurrentListPtr != rhs.CurrentListPtr){
    return false;
  }else {
    return Position == rhs.Position;
  }
}
template<typename T>
bool ReverseDoublyLinkedListIterator<T>::operator!=(ReverseDoublyLinkedListIterator<T> &rhs) const {
  if(CurrentListPtr == rhs.CurrentListPtr){
    return false;
  }else {
    return Position != rhs.Position;
  }
}
template<typename T>
ReverseDoublyLinkedListIterator<T>::operator bool() const {
  if (this== nullptr){
    return false;
  }
  else return this->CurrentListPtr== nullptr;
}
template<typename T>
ReverseDoublyLinkedListIterator<T> &ReverseDoublyLinkedListIterator<T>::operator++() {
  if (DoubleLinkedNode<T>::GetPrePtr(this->CurrentNodePtr)){
    this->CurrentNodePtr=DoubleLinkedNode<T>::GetPrePtr(this->CurrentNodePtr);
    CurrentValuePtr=DoubleLinkedNode<T>::ValuePtr(CurrentNodePtr);
    Position--;
    return &this;

  }
  else return &this;
}
template<typename T>
const ReverseDoublyLinkedListIterator<T> ReverseDoublyLinkedListIterator<T>::operator++(int) {
  if (DoubleLinkedNode<T>::GetPrePtr(this->CurrentNodePtr)){
    this->CurrentNodePtr=DoubleLinkedNode<T>::GetPrePtr(this->CurrentNodePtr);
    CurrentValuePtr=DoubleLinkedNode<T>::ValuePtr(CurrentNodePtr);
    Position--;
    ReverseDoublyLinkedListIterator<T>temp=(ReverseDoublyLinkedListIterator(this));
    ReverseDoublyLinkedListIterator<T>*temp_ref=&temp;
    const_cast<const ReverseDoublyLinkedListIterator<T>*>(temp_ref);//is it the correct way of const casting?
    return temp_ref;
  }
  else {
    ReverseDoublyLinkedListIterator<T>*this_ref=&this;
    const_cast<const ReverseDoublyLinkedListIterator<T>*>(this_ref);
    return this_ref;
  }}
template<typename T>
ReverseDoublyLinkedListIterator<T> &ReverseDoublyLinkedListIterator<T>::operator--() {
  if (DoubleLinkedNode<T>::GetNextPtr(this->CurrentNodePtr)){
    this->CurrentNodePtr=DoubleLinkedNode<T>::GetNextPtr(this->CurrentNodePtr);
    CurrentValuePtr=DoubleLinkedNode<T>::ValuePtr(CurrentNodePtr);
    Position++;
    return &this;
  }
  else return &this;}
template<typename T>
const ReverseDoublyLinkedListIterator<T> ReverseDoublyLinkedListIterator<T>::operator--(int) {
  if (DoubleLinkedNode<T>::GetNextPtr(this->CurrentNodePtr)){
    this->CurrentNodePtr=DoubleLinkedNode<T>::GetNextPtr(this->CurrentNodePtr);
    CurrentValuePtr=DoubleLinkedNode<T>::ValuePtr(CurrentNodePtr);
    Position++;
    ReverseDoublyLinkedListIterator<T>temp=(ReverseDoublyLinkedListIterator(this));
    ReverseDoublyLinkedListIterator<T>*temp_ref=&temp;

    const_cast<const ReverseDoublyLinkedListIterator<T>*>(temp_ref);
    return temp_ref;
  }
  else{
    ReverseDoublyLinkedListIterator<T>*this_ref=&this;
    const_cast<const ReverseDoublyLinkedListIterator<T>*>(this_ref);
    return this_ref;
  }
}
template<typename T>
const T &ReverseDoublyLinkedListIterator<T>::operator*() const {
  return const_cast<const T&>(CurrentValuePtr);
}
template<typename T>
T &ReverseDoublyLinkedListIterator<T>::operator*() {
  return CurrentValuePtr;
}

#endif //LINKEDLIST_GENERICREVERSEDOUBLYLINKEDLISTITERATOR_H
