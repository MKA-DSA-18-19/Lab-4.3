/* Binary Search Tree - recursive
 * Fall 2018
 * DSA
 * AMMENDED FOR USE IN OPTIMIZING BST
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

// private methods
void BST::visit() const{
  cout << key << ": " << cost << endl;
}
bool BST::isLeaf() const{
  return left == nullptr && right == nullptr;
}
/* TO DO */
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

/* Mutators */
bool BST::addLeft(BST* l){
  assert(l->getKey() < key);
  left = l;
  calculateCost(l);
}

bool BST::addRight(BST* r){
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

int main(){ //for testing of calculate cost
  BST* one = new BST(4,2.5);
  BST* two = new BST(5, 1.2);
  BST* three = new BST(1, .8);
  BST* four = new BST(8, .9);
  two->addRight(four);
  one->addLeft(three);
  one->addRight(two);
  one->inOrder();
}
