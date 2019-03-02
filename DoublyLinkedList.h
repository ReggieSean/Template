//
// Created by mfbut on 2/11/2019.
//

#ifndef LINKEDLIST_DOUBLYLINKEDLIST_H
#define LINKEDLIST_DOUBLYLINKEDLIST_H

#include <vector>
#include <memory>
#include "DoubleLinkedNode.h"
#include "DoublyLinkedListIterator.h"
#include "ReverseDoublyLinkedListIterator.h"

template<typename T>
class DoublyLinkedListIterator {};

template<typename T>
class DoublyLinkedList {
  friend class DoublyLinkedListIterator;
 public:
  using Node_Ptr = DoubleLinkedNode<T>*;

  using iterator =  DoubleLinkedNode<T>*/*put the type of your iterator here*/;
  using const_iterator = const DoubleLinkedNode<T>* /*put the type of your const iterator here*/;
  using reverse_iterator = DoubleLinkedNode<T>*/*put the type of your reverse iterator here*/;
  using const_reverse_iterator =const DoubleLinkedNode<T>* /*put the type of your const reverse iterator here*/;

  //create a Doubly Linked List that has the same values
  //as in the vector and in the same order
  explicit DoublyLinkedList(const std::vector<T>& values);
    /*

    */

  //create an empty DoublyLinkedList
  DoublyLinkedList();


  virtual ~DoublyLinkedList();

  //remove all of the elements from your list
  void clear();

  //get a reference to the front element in the list
  const T& front() const;

  T& front();

  //get a reference to the last element in the list
  const T& back() const;
  T& back();

  //add a value to the front of the list
  void push_front(const T& value);

  //add a value to the back of the list
  void push_back(const T& value);

  //is the list empty?
  bool empty() const;

  //return the number of elements in the list
  int size() const;

  //return a constant bidirectional iterator to the front of the list
  const_iterator begin() const;
  const_iterator end() const;

  //return a nonconstant bidirectional iterator to the front of the list
  iterator begin();
  iterator end();

  const_reverse_iterator crbegin() const;
  const_reverse_iterator crend() const;

  reverse_iterator rbegin();
  reverse_iterator rend();

  //insert the value at the position in the list
  //I promise not to use the iterator again after the insertion is done
  //An example if we had the list 1 <-> 9 <-> 17
  //And the iterator was pointing to the 9 and we wanted to
  //insert -22 the result would be
  //1 <-> 22 <-> 9 <-> 17
  void insert(iterator& position, const T& value);

  //remove the element at the position pointed to
  //by the iterator.
  //I promise not to use the iterator again after the erase is done
  //An example if we had the list 1 <-> 9 <-> 17
  //And when the wanted to erase the iterator was at the 9
  //1 <-> 17
  void erase(iterator& position);

 private:
  Node_Ptr head;
  Node_Ptr tail;
  int len;
};
template<typename T>
DoublyLinkedList::DoublyLinkedList(const std::vector<T> &values):len((*values).size()) {
  int i = 0;
  Node_Ptr temp_1= nullptr;
  Node_Ptr temp_node= nullptr;
  Node_Ptr temp_2= nullptr;


  if (*values)[0]!=EOF{
    while ((*values)[i]!=EOF){
        DoubleLinkedNode current_node_1=DoubleLinkedNode(temp_1,(*valuse)[i], nullptr);
        //make the current node
        Node_Ptr temp_node = DoubleLinkedNode::Ptr(current_node_1);
        //get the current node pointer
        ModifyNodeNextPtr(temp_1,temp_node);
        //modify the pointer
        temp_1=temp_node;
        //make temp node  as next pre pointer

        if (i==0){
          head =temp_node;}

        if ((*values)[i + 1] != '\0') {
          //if next one is good, create next node and set current node's next ptr as next node's
          DoubleLinkedNode current_node_2 = DoublyLinkedNode(temp_1,(*values)[i + 1], nullptr);
          Node_Ptr temp_node = DoubleLinkedNode::Ptr(current_node_2);
          ModifyNodeNextPtr(*temp_1,temp_node);
          i+=2;
          list_len+=2;
          temp_1=temp_node;
          //move the temp_1 ptr to the nextnode
          tail=temp_node;
        }
        if ((*values)[i + 1] == '\0'){
          //if next one is the end of line set tail and current node's next prt
          ModifyNodeNextPtr(*temp_1, nullptr);
          i+=1;
          list_len+=1;
          tail=temp_node;

        }

    }

  }
  else DoublyLinkedList();
}
//write to the stream each element in the list in order
//with a space in between them

DoublyLinkedList::DoublyLinkedList() {
  len(0);
  head(nullptr);
  tail(nullptr);

}


DoublyLinkedList:: clear();

//get a reference to the front element in the list
template <typename T>
const T& DoublyLinkedList:: front() const{
  return this->head;
}
template <typename T>
T& DoublyLinkedList::front(){
  return this->head;
}

//get a reference to the last element in the list
template <typename T>
const T& DoublyLinkedList::back() const{
  return this->tail;
}
template <typename T>
T& DoublyLinkedList::back(){
  return this->tail;
}

//add a value to the front of the list
template <typename T>
void DoublyLinkedList::push_front(const T& value){
  if (value){
    DoubleLinkedNode NewNode=DoubleLinkedNode::DoublyLinkedNode(nullptr,value,(this->head));
    DoublyLinkedList::len+=1;
    DoublyLinkedList::head=DoubleLinkedNode::Ptr(NewNode);
  }
}

//add a value to the back of the list
template <typename T>
void DoublyLinkedList::push_back(const T& value){
  if (value){
    DoubleLinkedNode NewNode=DoubleLinkedNode::DoublyLinkedNode((this->tail),value, nullptr);
    DoublyLinkedList::len+=1;
    DoublyLinkedList::tail=DoubleLinkedNode::Ptr(NewNode);
  }
}

//is the list empty?

bool DoublyLinkedList::empty() const{
  if (this){//if the variable using now is not a nullptr
    return this->len==0;
  }
}

//return the number of elements in the list
int DoublyLinkedList::size() const{
  if(this){
    return this->len;
  }
}

//return a constant bidirectional iterator to the front of the list
const_iterator DoublyLinkedList::begin() const;
const_iterator DoublyLinkedList::end() const;

//return a nonconstant bidirectional iterator to the front of the list
iterator begin();
iterator end();

const_reverse_iterator crbegin() const;
const_reverse_iterator crend() const;

reverse_iterator rbegin();
reverse_iterator rend();

//insert the value at the position in the list
//I promise not to use the iterator again after the insertion is done
//An example if we had the list 1 <-> 9 <-> 17
//And the iterator was pointing to the 9 and we wanted to
//insert -22 the result would be
//1 <-> 22 <-> 9 <-> 17
void insert(iterator& position, const T& value);

//remove the element at the position pointed to
//by the iterator.
//I promise not to use the iterator again after the erase is done
//An example if we had the list 1 <-> 9 <-> 17
//And when the wanted to erase the iterator was at the 9
//1 <-> 17
void erase(iterator& position);


template<typename T>
std::ostream& operator<<(std::ostream& out, const DoublyLinkedList<T>& doublyLinkedList){

};

//read elements from the stream as long as it is good
// or until a newline (\n) is encountered
//if a newline is encontered it should be consumed
template<typename T>
std::istream& operator>>(std::istream& in, DoublyLinkedList<T>& doublyLinkedList){

};


#endif //LINKEDLIST_DOUBLYLINKEDLIST_H
