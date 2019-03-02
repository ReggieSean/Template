//
// Created by mfbut on 2/11/2019.
//

#ifndef LINKEDLIST_GENERICDOUBLYLINKEDLISTITERATOR_H
#define LINKEDLIST_GENERICDOUBLYLINKEDLISTITERATOR_H
#include "DoublyLinkedList.h"

template<typename T>
class DoublyLinkedListIterator {

  //you must implement at least the methods below
  //you are free to add (and will likely need to add)
  //more members and methods
 public:
  int Position;
  T CurrentValue;
  DoubleLinkedNodePtr* CurrentNode;
  DoublyLinkedListPtr* CurrentList;

  DoublyLinkedListIterator(const DoublyLinkedListIterator& orig);

  explicit DoublyLinkedListIterator(DoublyLinkedlist* List);
  //are the two iterators equal?
  //they are if they are over the same doubly linked list
  //and (they are referring to the same element in the list
  //or they are out of bounds)
  bool operator==(const DoublyLinkedListIterator<T>& rhs) const;

  //are the two iterators different?
  bool operator!=(const DoublyLinkedListIterator<T>& rhs) const;

  //is the iterator safe to dereference?
  operator bool() const;

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

DoublyLinkedListIterator::DoublyLinkedListIterator(DoublyLinkedlist* orig_list){
  Position(0);
  CurrentListPtr(orig_list);
  CurrentNodePtr(CurrentListPtr.head);
  CurrentValue=DoubleLinkedNode::Value(CurrentNodePtr);
}
DoublyLinkedListIterator::DoublyLinkedListIterator(const DoublyLinkedListIterator& orig){
  Position(orig.Position);
  CurrentListPtr(orig.CurrentList);
  CurrentNodePtr(orig.CurrentList);
  CurrentValue=DoubleLinkedNode::Value(CurrentNodePtr);
}

template <typename T>
bool DoublyLinkedListIterator<T>::operator==(const DoublyLinkedListIterator<T> &rhs) const {
  if(CurrentList != rhs.CurrentList){
    return false;
  }else {
    return Position == rhs.Position;
  }
}

bool DoublyLinkedListIterator::operator!=(const DoublyLinkedListIterator<T> &rhs) const {
  if(CurrentList == rhs.CurrentList){
    return false;
  }else {
    return Position != rhs.Position;
  }
}
//automatically a bool type?
bool DoublyLinkedListIterator::operator bool() const {
  if (!this){//will refer to stdlib?
    return true;
  }else{
    return false;
  }
}
T& DoublyLinkedListIterator::operator*() {
  return &CurrentValue;
}
const T& DoublyLinkedListIterator::operator*() const {
  return const_cast<&CurrentList>;
}
DoublyLinkedListIterator<T> & DoublyLinkedListIterator::operator--() {
  if (this->CurrentNode->Pre_ptr){
    this->CurrentNode=this->CurrentNode.Pre_ptr;
    return DoubleLinkedNode::Value(this.CurrentNode);
  }
  else return this->CurrentNode;
}
const DoublyLinkedListIterator<T> DoublyLinkedListIterator::operator--(int ) {
  if (this->CurrentNode->Pre_ptr){
    this->CurrentNode=this->CurrentNode->Pre_ptr;
    return const_cast<DoubleLinkedNode::Ptr(this->CurrentNode)>;
  }
  else return nullptr;
}
DoublyLinkedListIterator<T>& operator++(); //pre
const DoublyLinkedListIterator<T> operator++(int);//post
#endif //LINKEDLIST_GENERICDOUBLYLINKEDLISTITERATOR_H
