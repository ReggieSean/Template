//
// Created by mfbut on 2/11/2019.
//

#ifndef LINKEDLIST_DOUBLELINKEDNODE_H
#define LINKEDLIST_DOUBLELINKEDNODE_H
#include <iostream>

//the class that represents a node in the list

template<typename T>
class DoubleLinkedNode {

 private:
  T& Node;
  DoubleLinkedNode* Pre_ptr;
  DoubleLinkedNode* Next_ptr;
  DoubleLinkedNode copy;
 public:

  DoubleLinkedNode(DoubleLinkedNode* pre_p,T value,DoubleLinkedNode* next_ptr);


  //default constructor
  DoubleLinkedNode();

  //ReturnNode(T value);
  T& ValuePtr(DoubleLinkedNode* Node_arg);

  DoubleLinkedNode* GetPrePtr(const DoubleLinkedNode* Node_arg);
  DoubleLinkedNode* GetNextPtr(const DoubleLinkedNode* Node_arg);
  DoubleLinkedNode* GetPtr(const DoubleLinkedNode* Node_arg);

  //return this->Pre_ptr;
  void ModifyNodeNextPtr(DoubleLinkedNode* Node_arg,DoubleLinkedNode* Next);

  void ModifyNodePrePtr(DoubleLinkedNode* Pre,DoubleLinkedNode *Node_arg );
  virtual ~DoubleLinkedNode();
    //destructor

};

template <typename T>
DoubleLinkedNode<T>::DoubleLinkedNode(DoubleLinkedNode<T>* pre_ptr,T value,DoubleLinkedNode<T>* next_ptr){
  *Node(value);
  Pre_ptr(pre_ptr);
  Next_ptr(next_ptr);

}

template<typename T>
DoubleLinkedNode<T>::DoubleLinkedNode() {
  Node(nullptr);
  Pre_ptr(nullptr);
  Next_ptr(nullptr);

}
template <typename T>
T& DoubleLinkedNode<T>::ValuePtr(DoubleLinkedNode *Node_arg) {
  return Node_arg->Node;
}
template<typename T>
DoubleLinkedNode<T> *DoubleLinkedNode<T>::GetPtr(const DoubleLinkedNode *Node_arg)  {
  return Node_arg;
}

template<typename T>
DoubleLinkedNode<T>*DoubleLinkedNode<T>::GetPrePtr(const DoubleLinkedNode<T> *Node_arg) {
  return Node_arg->Pre_ptr;
}
template<typename T>
DoubleLinkedNode<T> *DoubleLinkedNode<T>::GetNextPtr(const DoubleLinkedNode *Node_arg) {
  return Node_arg->Next_ptr;
}
template<typename T>
void DoubleLinkedNode<T>::ModifyNodeNextPtr(DoubleLinkedNode *Node_arg, DoubleLinkedNode *Next) {
  (*Node_arg).Next_ptr= Next;
}
template<typename T>
void DoubleLinkedNode<T>::ModifyNodePrePtr(DoubleLinkedNode *Pre, DoubleLinkedNode *Node_arg) {
  (*Node_arg).Pre_ptr= Pre;
}

template <typename T>
DoubleLinkedNode<T>::~DoubleLinkedNode() {
  if (this->Node){
    delete [](this->Node);
    this->Node= nullptr;
    this->Pre_ptr= nullptr;
    this->Next_ptr= nullptr;
  }
}

#endif //LINKEDLIST_DOUBLELINKEDNODE_H