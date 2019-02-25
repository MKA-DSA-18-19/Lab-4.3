#ifndef BST_H
#define BST_H

/* Binary Search Tree - recursive
 * Fall 2018
 * DSA
 * For the sake of demonstration and clarity we are going to use 
 * only a numerical value in the nodes of the tree. An element 
 * that is comparable could be used instead, but the syntax is 
 * more complicated than we need to deal with to understand 
 * Binary Search trees. Since this class is not templated the 
 * .h file is only a header file.
 */

#include <queue>

class BST{
 private:
  BST* left;
  BST* right;

  /* some private helper functions */
  void visit() const;
  void breadthFirstHelper(std::queue<BST *>* q);

 public:
  int key;
  explicit BST(int k);
  explicit BST(int k, BST* l, BST* r);
  ~BST();
  BST(const BST& other);

  /* Accessors */
  bool isLeaf() const;    
  BST* getLeft() const;
  BST* getRight() const;
  bool find(int num) const;
  void inOrder() const;
  void preOrder() const;
  void postOrder() const;
  void breadthFirst();
  BST* getLargest() const;
  BST* getSmallest() const;

  /* Mutators */
  bool add(int num);
  bool remove(int num);

  

};

#endif
