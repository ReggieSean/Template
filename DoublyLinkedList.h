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
class DoublyLinkedList {
 public:
  using Node_Ptr = DoubleLinkedNode<T>*;

  using iterator =  /*put the type of your iterator here*/;
  using const_iterator =  /*put the type of your const iterator here*/;
  using reverse_iterator = /*put the type of your reverse iterator here*/;
  using const_reverse_iterator = /*put the type of your const reverse iterator here*/;

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
DoublyLinkedList::DoublyLinkedList(const std::vector<T> &values) {
  int i = 0;
  Node_Ptr temp_1= nullptr;
  Node_Ptr temp_node= nullptr;
  Node_Ptr temp_2= nullptr;
  int list_len=0;
  DoublyLinkedList()
  if (*values)[i]!=EOF{
    while ((*values)[i]!=EOF){
        Node_Ptr temp_node = DoubleLinkedNode::GetNodePtr(DoubleLinkedNode(temp_1,(*valuse).at[i]), nullptr);
        ModifyNodeNextPtr(*temp_1,temp_node);
        temp_1=temp_node;
        if (i==0){
          head =temp_node;
          tail = temp_node;
        }
        if ((*values)[i + 1] != EOF) {
          Node_Ptr temp_node = DoubleLinkedNode::GetNodePtr(DoublyLinkedNode(temp_1,(*values).at[i + 1], nullptr));

          ModifyNodeNextPtr(*temp_1,temp_node);
          temp_1=temp_node;
          i+=2;
          list_len+=2;
        }
        if ((*values)[i + 1] == EOF){
          Node_Ptr temp_node = DoubleLinkedNode::GetNodePtr(DoublyLinkedNode(temp_1,(*values).at[i + 1], nullptr));
          ModifyNodeNextPtr(*temp_1,temp_node);
          i+=1;
          list_len+=1;
          tail=DoubleLinkedNode::GetNodePtr(temp_node);
        }
    }
  }
  len(list_len);
}
//write to the stream each element in the list in order
//with a space in between them
template<typename T>
std::ostream& operator<<(std::ostream& out, const DoublyLinkedList<T>& doublyLinkedList);

//read elements from the stream as long as it is good
// or until a newline (\n) is encountered
//if a newline is encontered it should be consumed
template<typename T>
std::istream& operator>>(std::istream& in, DoublyLinkedList<T>& doublyLinkedList);


#endif //LINKEDLIST_DOUBLYLINKEDLIST_H
