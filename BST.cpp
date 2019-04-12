/* Binary Search Tree - recursive
 * Fall 2018
 * DSA
 * AMMENDED FOR USE IN OPTIMIZING BST
 * STARTER CODE
 */
#include <iostream>
#include "BST.h"
#include <assert.h> 

using namespace std;

// Constructor, destructor, copy 
BST::BST(int k, double p){
  key = k; 
  prob = p; cost = p; // cost and prob are same for singleton
  left = nullptr; right = nullptr;
  first = k; last = k; //start and end are root for singleton
}
BST::BST(BST &b2){
  key = b2.getKey();
  prob = b2.getProb();
  cost = b2.getCost();
  left = b2.getLeft();
  right = b2.getRight();
  first = b2.getFirst();
  last = b2.getLast();
}
  

  
// private methods
void BST::visit() const{
  cout << key << ": " << cost << endl;
}
bool BST::isLeaf() const{
  return left == nullptr && right == nullptr;
}

double BST::getSumProb(){
  if (isLeaf())
    return prob;
  double sum = prob;
  if (left != nullptr)
    sum += left -> getSumProb();
  if (right != nullptr)
    sum += right -> getSumProb();
  return sum;
}


void BST::calculateCost(BST* justAdded){
  // happens when a node is added to left or right of current
  // current prob + total cost of node added + sum of all nodes in tree added
}

/* Accessors */
int BST::getKey(){ return key; }
double BST::getCost(){ return cost; }
double BST::getProb(){ return prob; }
int BST::getFirst(){ return first; }
int BST::getLast(){ return last; }
BST* BST::getLeft() { return left; }
BST* BST::getRight() { return right;}

/* Mutators */
bool BST::addLeft(BST* l){
  //cout << "IN ADD LEFT" << endl;
  if (l == nullptr) return false;
  assert(l->getKey() < key);
  left = l;
  calculateCost(l);
}

bool BST::addRight(BST* r){
  //cout << "IN ADD RIGHT" <<endl;
  if (r == nullptr) return false;
  assert(r->getKey() > key);
  right = r;
  calculateCost(r);
}

void BST::inOrder(){
  if (left != nullptr)
    left->inOrder();
  visit();
  if (right != nullptr)
    right->inOrder();
}

/*
int main(){ // use this to make sure getCost works properly
  BST* one = new BST(4, .1);
  BST* two = new BST(10, .2);
  BST* three = new BST(2, .4);
  BST* four = new BST(8, .3);
  BST* five = new BST(3, .15);
  BST* six = new BST(1, .9);
  three -> addLeft(six);
  three -> addRight(five);
  one -> addLeft(three);
  cout << one -> getCost() << endl;
  two -> addLeft(four);
  one -> addRight(two);

  one -> inOrder();

}


*/
