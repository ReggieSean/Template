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
  T Node;
  DoubleLinkedNode* Pre_ptr;
  DoubleLinkedNode* Next_ptr;
 public:
  DoublyLinkedNode(T value,int pre_p,int next_ptr);
    /*for the nod in between list.size>1
   */
  DoublyLinkedNode(T value,int next_ptr);
  //for the nod at the beginning list.size()>1

  DoublyLinkedNode(T value,int pre_ptr);
    //for the nod at the end list.size()>1

  DoublyLinkedNode(T value);
    //for the node in list.size()=1
   /* */

  DoublyLinkedNode();

  //SetNode(T value);

  GetNodePtr(const DoubleLinkedNode Node_arg)const;
  //return the node value of type t
  //return &(this->Node);

  GetPrePtr(const DoubleLinkedNode Node_arg)const;



  //return this->Pre_ptr;
  ModifyNodeNextPtr(DoubleLinkedNode *Node_arg);
  GetNextPtr(const DoubleLinkedNode Node_arg)const;
    //return this->Next_ptr;

  virtual ~DoubleLinkedNode();
    //destructor

};
#endif //LINKEDLIST_DOUBLELINKEDNODE_H
template <typename T>
DoubleLinkedNode<T>::DoublyLinkedNode(T value,DoubleLinkedNode* pre_p,DoubleLinkedNode* next_ptr){
  Node(value);
  Pre_ptr(pre_p);
  Next_ptr(next_ptr);
  //return &this
}
template <typename T>
DoubleLinkedNode<T>::DoublyLinkedNode(T value,DoubleLinkedNode* next_ptr) {
  Node(value);
  Pre_ptr(&Node);
  Next_ptr(next_ptr);
}

template <typename T>
DoubleLinkedNode<T>::DoublyLinkedNode(DoubleLinkedNode* pre_ptr,T value){
  Node(value);
  Pre_ptr(pre_p);
  Next_ptr(&Node);
}
template <typename T>
DoubleLinkedNode<T>::DoublyLinkedNode(T value) {

  Node(value);
  Pre_ptr(&Node);
  Next_ptr(&Node);
}

DoubleLinkedNode<T>::DoublyLinkedNode() {
  Node(nullptr);
  Pre_ptr(nullptr);
  Next_ptr(nullptr);

}

DoubleLinkedNode* DoubleLinkedNode::GetNodePtr(const DoubleLinkedNode Node_arg)const{
  return &Node_arg ;
}

DoubleLinkedNode* DoubleLinkedNode::GetPrePtr(const DoubleLinkedNode Node_arg)const{
  return Node_arg.Pre_ptr;

}
DoubleLinkedNode* DoubleLinkedNode::GetNextPtr(const DoubleLinkedNode Node_arg)const{
  return Node_arg.Next_ptr;
}
void ModifyNodeNextPtr(DoubleLinkedNode *Node_arg,DoubleLinkedNode*Next){
  //can you modify the private members?
  (*Node_arg).Next_ptr= Next;
}