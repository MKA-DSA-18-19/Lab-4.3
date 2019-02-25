/* Binary Search Tree - recursive
 * Fall 2018
 * DSA
 * For the sake of demonstration and clarity we are going to use 
 * only a numerical value in the nodes of the tree. An element 
 * that is comparable could be used instead, but the syntax is 
 * more complicated than we need to deal with to understand 
 * Binary Search trees. This is the actual class definition.
 * 
 * BST ADT
 * add element
 * remove element if in tree
 * remove minimum
 * remove maximum
 * search for element - boolean result
 * traversals
 */
#include <iostream>
#include "BST.h"
#include <queue>

using namespace std;

// Constructor, destructor, copy 
BST::BST(int k){
  key = k;
  left = right = nullptr;
}
BST::BST(int k, BST* l, BST* r){
  key = k;
  left = l;
  right = r;
}
BST::~BST(){
  delete left;
  delete right;
}

BST::BST(const BST& other){
  key = other.key;
  left = other.getLeft();
  right = other.getRight();
}

void BST::breadthFirstHelper(std::queue<BST *>* q){
  if (left != nullptr) q->push(left);
  if (right != nullptr) q->push(right);
  if (left != nullptr) left ->breadthFirstHelper(q);
  if (right != nullptr) right->breadthFirstHelper(q);
}


// private methods
void BST::visit() const{
  cout << key << endl;
}
bool BST::isLeaf() const{
  return left == nullptr && right == nullptr;
}

BST* BST::getLargest() const{
    if (right != nullptr)
    return right->getLargest();
  return new BST(key, left, right);
}
BST* BST::getSmallest() const{
  if (left != nullptr)
    return left->getSmallest();
  return new BST(key, left, right);
}


/* Accessors */
BST* BST::getLeft(){
  return left;
}
BST* BST::getRight(){
  return right;
}

bool BST::find(int num) const{
  if (num == key) return true;
  if (num < key && left != nullptr) return left->find(num);
  if (num > key && right != nullptr) return right->find(num);
  return false;
}

void BST::inOrder() const{
  if (left != nullptr) left->inOrder();
  visit();
  if (right != nullptr) right->inOrder();
}
void BST::preOrder() const{
  visit();
  if (left != nullptr) left->preOrder();
  if (right != nullptr) right->preOrder();
}
void BST::postOrder() const{
  if (left != nullptr) left->postOrder();
  if (right != nullptr) right->postOrder();
  visit();
}
void BST::breadthFirst() {
  std::queue<BST* >* traversal = new queue<BST* >();
  traversal->push(new BST(key, left, right));
  breadthFirstHelper(traversal);
  while (!traversal->empty()){
    traversal->front()->visit();
    traversal->pop();
  }
  
}

/* Mutators */
bool BST::add(int num){
  if(key == num) return false;
  if(key > num){
    if(left != nullptr) left->add(num);
    else left = new BST(num);
  }
  if(key < num){
    if(right != nullptr) right->add(num);
    else right = new BST(num);
  }
  return true;
}
bool BST::remove(int num){
  if (num == key){
    BST* temp;
    if (left != nullptr) {
      temp = left->getLargest();
      key = temp->key;
      left = temp->getLeft();
    }
    else if (right != nullptr){
      temp = right->getSmallest();
      key = temp->key;
      right = temp->getRight();
    }
    return true;
  }
  if (num < key && left != nullptr){
    return left->remove(num);
  }
  else if (num > key && right != nullptr){
    return right->remove(num);
  }
  return false;
}



int main(){
  BST* bst = new BST(5);
  bst->add(1);
  bst->add(2);
  bst->add(10);
  bst->add(6);
  bst->add(99999);
  /*
             5
       1          10
          2     6    9999
  cout << "inOrder" << endl;
  bst->inOrder();
  cout << "preOrder" << endl;
  bst->preOrder();

  cout << "" << endl;

  bst->remove(10);
  cout << "inOrder" <<endl;
  bst->inOrder();
  cout << "preOrder" << endl;
  bst->preOrder(); */

  bst->breadthFirst();
  
}
