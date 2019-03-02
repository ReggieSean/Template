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
  DoubleLinkedNode<T> DoublyLinkedNode(DoubleLinkedNode* pre_p,T value,DoubleLinkedNode* next_ptr);

  DoubleLinkedNode<T> DoublyLinkedNode(T value,DoubleLinkedNode* next_ptr);
  //for the nod at the beginning list.size()>1





    //for the node in list.size()=1
   /* */
   DoubleLinkedNode<T> DoublyLinkedNodeDoublyLinkedNode();

  //SetNode(T value);
  <T>Value(DoubleLinkedNode* Node_arg);
  DoubleLinkedNode<T>* Ptr(const DoubleLinkedNode* Node_arg)const;
  //return the node value of type t
  //return &(this->Node);

  DoubleLinkedNode<T>* GetPrePtr(const DoubleLinkedNode* Node_arg)const;
  DoubleLinkedNode<T>* GetNextPtr(const DoubleLinkedNode* Node_arg)const;


  //return this->Pre_ptr;
  void ModifyNodeNextPtr(DoubleLinkedNode* Node_arg,DoubleLinkedNode* Next);

    //return this->Next_ptr;

  void ModifyNodePrePtr(DoubleLinkedNode* Pre,DoubleLinkedNode *Node_arg );
  virtual ~DoubleLinkedNode();
    //destructor

};
#endif //LINKEDLIST_DOUBLELINKEDNODE_H
template <typename T>
DoubleLinkedNode<T> DoublyLinkedNode(DoubleLinkedNode* pre_ptr,T value,DoubleLinkedNode* next_ptr){
  *Node(value);
  Pre_ptr(pre_ptr);
  Next_ptr(next_ptr);
  //return &this
}
template <typename T>
DoubleLinkedNode<T> DoublyLinkedNode(T value,DoubleLinkedNode* next_ptr) {
  *Node(value);
  Pre_ptr(&Node);
  Next_ptr(next_ptr);
}

template <typename T>
DoubleLinkedNode<T> DoublyLinkedNode(DoubleLinkedNode* pre_ptr,T value){
  *Node(value);
  Pre_ptr(pre_p);
  Next_ptr(&Node);
}
template <typename T>
DoubleLinkedNode<T> DoublyLinkedNode(T value) {

  *Node(value);
  Pre_ptr(&Node);
  Next_ptr(&Node);
}

DoubleLinkedNode<T> DoublyLinkedNode() {
  *Node(nullptr);
  Pre_ptr(nullptr);
  Next_ptr(nullptr);

}
template <typename T>
T DoubleLinkedNode::Value(DoubleLinkedNode *Node_arg) {
  return (*Node_arg).Node
}
DoubleLinkedNode* DoubleLinkedNode::Ptr(DoubleLinkedNode Node_arg){
  return &Node_arg;
}
const DoubleLinkedNode* DoubleLinkedNode::Ptr(const DoubleLinkedNode Node_arg) {

  return const_cast<*Node_arg>;
}
DoubleLinkedNode* DoubleLinkedNode::GetPrePtr( DoubleLinkedNode Node_arg){
  return Node_arg.Pre_ptr;
}
const DoubleLinkedNode* DoubleLinkedNode::GetPrePtr(const DoubleLinkedNode Node_arg){
  copy(Node_arg);
  return copy.Pre_ptr;
}

DoubleLinkedNode* DoubleLinkedNode::GetNextPtr( DoubleLinkedNode Node_arg){
  return Node_arg.Next_ptr;
}
const DoubleLinkedNode* DoubleLinkedNode::GetNextPtr(const DoubleLinkedNode Node_arg){
  copy(Node_arg);
  return copy.Next_ptr;
}

void ModifyNodeNextPtr(DoubleLinkedNode *Node_arg,DoubleLinkedNode*Next){

  (*Node_arg).Next_ptr= Next;
}
void ModifyNodePrePtr(DoubleLinkedNode* Pre,DoubleLinkedNode *Node_arg){
  (*Node_arg).Pre_ptr= Pre;
}


void DoubleLinkedNode::~DoubleLinkedNode(DoubleLinkedNode* Node_arg) {
  if ((*Node_arg).Node){
    delete [](*Node_arg).Node;
    (*Node_arg).Node= nullptr;
    (*Node_arg).Pre_ptr= nullptr;
    (*Node_arg).Next_ptr= nullptr;
  }
}