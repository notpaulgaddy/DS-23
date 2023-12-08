/* ASSUMPTIONS:
1. When a node must be split and has an odd number of keys, the extra key will
go to the new rightSide-hand node.
2. There will never be a duplicate key passed to insert.
*/

#include <clocale>
#include <vector>
#include <iostream>
#ifndef DS_BPLUSTREE
#define DS_BPLUSTREE
using namespace std;

///////////////////////////////////////////////////////////////////////////////
// DO NOT CHANGE THIS CODE
///////////////////////////////////////////////////////////////////////////////

// Do not implement the class here, this is a forward declaration. Implement at
// the bottom of the .h file
template <class T> class BPlusTree;

template <class T> class BPlusTreeNode {
public:
  BPlusTreeNode() : parent(NULL){};
  bool is_leaf();
  bool contains(const T &key);

  // For grading only. This is bad practice to have, because
  // it exposes a private member variable.
  BPlusTreeNode *get_parent() { return parent; }

  // We need this to let BPlusTree access private members
  friend class BPlusTree<T>;

private:
  bool contains(const T &key, std::size_t low, std::size_t high);
  std::vector<T> keys;
  std::vector<BPlusTreeNode *> children;
  BPlusTreeNode *parent;
};

template <class T> bool BPlusTreeNode<T>::is_leaf() {
  for (unsigned int i = 0; i < children.size(); i++) {
    if (children[i]) {
      return false;
    }
  }
  return true;
}

template <class T> bool BPlusTreeNode<T>::contains(const T &key) {
  return contains(key, 0, keys.size() - 1);
}

// Private method takes advantage of the fact keys are sorted
template <class T>
bool BPlusTreeNode<T>::contains(const T &key, std::size_t low,
                                std::size_t high) {
  if (low > high) {
    return false;
  }
  if (low == high) {
    return key == keys[low];
  }
  std::size_t mid = (low + high) / 2;
  if (key <= keys[mid]) {
    return contains(key, 0, mid);
  } else {
    return contains(key, mid + 1, high);
  }
}

///////////////////////////////////////////////////////////////////////////////////////
// Your BPlusTree implementation goes below this point.
///////////////////////////////////////////////////////////////////////////////////////
using namespace std;
template <class T> class BPlusTree {
public:
  // FROM THE DS_SET CLASS
  BPlusTree(int nodeSize) : root_(NULL), size_(nodeSize){};
  BPlusTree(const BPlusTree<T> &old) : size_(old.size_) {
    root_ = this->copy_tree(old.root_, NULL);
  }
  BPlusTree<T> &operator=(const BPlusTree<T> &old) {
    if (&old != this) {
      this->destroy_tree(root_);
      root_ = this->copy_tree(old.root_, NULL);
      size_ = old.size_;
    }
    return *this;
  }
  ~BPlusTree() {
    this->destroy_tree(root_);
    // this->destroy_subtree(root_);
    root_ = NULL;
  }

  // Find & Insert
  void insert(const T &key) { insert(key, root_, NULL); }
  void print_BFS_pretty(ostream &theOutputFile) const;
  // Print
  void print_sideways(ostream &theOutputFile) const {
    print_sideways(theOutputFile, root_, 0);
  }
  void print_BFS(ostream &theOutputFile) const;
  BPlusTreeNode<T> *find(const T &key) const { return find(key, root_); }

private:
  // Representation
  BPlusTreeNode<T> *root_;
  int size_;
  // Private helper functions
  BPlusTreeNode<T> *copy_tree(BPlusTreeNode<T> *oRoot,
                              BPlusTreeNode<T> *newParentNode);
  void destroy_tree(BPlusTreeNode<T> *pointEachNode);
  // void destroy_subtree(BPlusTreeNode<T>* pointEachNode);
  BPlusTreeNode<T> *find(const T &key, BPlusTreeNode<T> *pointEachNode) const;
  void makeNewParentNode(BPlusTreeNode<T> *&pointEachNode);
  void manageData(const T &key, BPlusTreeNode<T> *&pointEachNode,BPlusTreeNode<T> *newParentNode, unsigned int i);
  void insert(const T &key, BPlusTreeNode<T> *&pointEachNode,BPlusTreeNode<T> *newParentNode);
  void print_sideways(ostream &theOutputFile, BPlusTreeNode<T> *pointEachNode, int theTreeLevel) const;
};

template <class T>
BPlusTreeNode<T> *
BPlusTree<T>::copy_tree(BPlusTreeNode<T> *oRoot,BPlusTreeNode<T> *newParentNode) { // mix
  BPlusTreeNode<T> *temp = new BPlusTreeNode<T>();//create new tree node
  if (!oRoot) {//if the node is null
    return NULL;
  }
  int oldRootChildSize = oRoot->children.size();//count the size of the children vector node
  for (unsigned int i = 0; i < oldRootChildSize; ++i) {//iterate thru the amt of nodes in the size
    temp->children.push_back(copy_tree(oRoot->children[i], temp));//append the copied tree to children
  }
  temp->keys = oRoot->keys;
  temp->parent = newParentNode;
  return temp;
}

template <class T>
BPlusTreeNode<T> *
BPlusTree<T>::find(const T &key, BPlusTreeNode<T> *pointEachNode) const { // mix
    if (this->root_ == NULL) {
        return NULL;
    }

    unsigned int i = 0;
    for (; i < pointEachNode->keys.size(); ++i){
        if (key < pointEachNode->keys[i]) { //key in left child node or does not exist
            if (pointEachNode->is_leaf()==true) {//if its a leaf node
                return pointEachNode;
            }else if(pointEachNode->is_leaf()==false){//if not a leaf node
                return find(key, pointEachNode->children[i]);
            }
        }
    }
    if (pointEachNode->is_leaf()==true) {//if its a leaf node
        return pointEachNode; // key does not exist
    }else{
        return find(key, pointEachNode->children[i]); // key might in rightmost child node
    }
}

template <class T>
void BPlusTree<T>::makeNewParentNode(BPlusTreeNode<T> *&pointEachNode) { 
  unsigned int newAnswer;//store the new value
  if (pointEachNode->is_leaf() == true) {
    newAnswer = pointEachNode->keys.size() - (pointEachNode->keys.size() / 2);
  } else {
    newAnswer =
        pointEachNode->keys.size() - (pointEachNode->keys.size() / 2) - 1;
  }
  BPlusTreeNode<T> *theNewChild = new BPlusTreeNode<T>();//new node
  while (theNewChild->keys.size() != newAnswer) {
    theNewChild->keys.insert(theNewChild->keys.begin(),pointEachNode->keys.back());//add the first and last keys
    pointEachNode->keys.pop_back();//remove the last keys
  }

  if (!pointEachNode->is_leaf() == true) {// split children nodes for non-leaf node
    while (theNewChild->children.size() != theNewChild->keys.size() + 1) {
      theNewChild->children.insert(theNewChild->children.begin(),
                                   pointEachNode->children.back());
      theNewChild->children.front()->parent = theNewChild;
      pointEachNode->children.pop_back();
    }
  }

  BPlusTreeNode<T> *theNewParent = new BPlusTreeNode<T>();// create new parent node
  pointEachNode->parent = theNewParent;
  theNewChild->parent = theNewParent;
  if (pointEachNode->is_leaf() == true) {
    theNewParent->keys.push_back(theNewChild->keys.front());
  } else if (pointEachNode->is_leaf() == false) {
    theNewParent->keys.push_back(pointEachNode->keys.back());
    pointEachNode->keys.pop_back();
  }
  theNewParent->children.push_back(pointEachNode);
  theNewParent->children.push_back(theNewChild);
  this->root_ = theNewParent;
}

template <class T>
void BPlusTree<T>::manageData(const T &key, BPlusTreeNode<T> *&pointEachNode, BPlusTreeNode<T> *newParentNode,unsigned int i) { 
  if (!pointEachNode->is_leaf() == true) {
    // key is in leftSide child node. Find recursively in deeper theTreeLevel
    insert(key, pointEachNode->children[i], pointEachNode);
    // If this child node exceeds degree limit
    if (pointEachNode->children[i]->keys.size() >= this->size_) {
      unsigned int firPortion = pointEachNode->children[i]->keys.size() / 2;//size of node 1
      unsigned int secPortion =  pointEachNode->children[i]->keys.size() - firPortion; //size of node 2
      if (pointEachNode->children[i]->is_leaf() != true) {//check if the node isnt true
        secPortion -= 1;//decrement one 
      }
      BPlusTreeNode<T> *theNewChild = new BPlusTreeNode<T>();
      theNewChild->parent = pointEachNode;
      while (secPortion != theNewChild->keys.size()) {
        theNewChild->keys.insert(theNewChild->keys.begin(), pointEachNode->children[i]->keys.back());
        pointEachNode->children[i]->keys.pop_back();
      }

      // split children nodes for non-leaf node
      if (!pointEachNode->children[i]->is_leaf()) {
        while (theNewChild->children.size() != theNewChild->keys.size() + 1) {
          theNewChild->children.insert(
              theNewChild->children.begin(),
              pointEachNode->children[i]->children.back());
          theNewChild->children.front()->parent = theNewChild;
          pointEachNode->children[i]->children.pop_back();
        }
      }

      // Extract key from children to put into pointEachNode's key vector
      T parKey(pointEachNode->children[i]->keys.back());
      if (pointEachNode->children[i]->is_leaf() == true) {
        parKey = theNewChild->keys.front();
      } else {
        pointEachNode->children[i]->keys.pop_back();
      }
      /* Insert children's key and new child node to pointEachNode's key and
       children vector */
      typename vector<T>::iterator keys_itr = pointEachNode->keys.begin();
      typename vector<BPlusTreeNode<T> *>::iterator children_itr;
      children_itr = pointEachNode->children.begin();
      pointEachNode->keys.insert(keys_itr + i, parKey);
      pointEachNode->children.insert(children_itr + i + 1, theNewChild);
    }

    // If pointEachNode does not have parent and pointEachNode exceeds degree
    // limit
    if (pointEachNode->keys.size() == this->size_ ||
        pointEachNode->keys.size() > this->size_) {
      if (newParentNode == NULL) {
        makeNewParentNode(pointEachNode);
      } else {
      }
    }
  } else {
    /* Arrive at leaf of tree. Inserting key to pointEachNode's key vector in
     sorted order */
    typename vector<T>::iterator itr = pointEachNode->keys.begin();
    pointEachNode->keys.insert(itr + i, key);
    // If pointEachNode does not have parent and pointEachNode exceeds degree
    // limit
    if (pointEachNode->keys.size() == this->size_ || pointEachNode->keys.size() > this->size_) {
      if (newParentNode != NULL) {
        cout << "Empty parent node";
      } else {
        makeNewParentNode(pointEachNode);
      }
    }
  }
}

template <class T>
void BPlusTree<T>::insert(const T &key, BPlusTreeNode<T> *&pointEachNode,
                          BPlusTreeNode<T> *newParentNode) {
  // If B+ tree is empty, dynamically allocate a new node.
  if (this->root_ != NULL) {

  } else {
    this->root_ = new BPlusTreeNode<T>();//new node for the root
    this->root_->keys.push_back(key);//append it
    return;
  }

 
  unsigned int i = 0;
  for (; i < pointEachNode->keys.size(); ++i) { // See if the key is in a leaf
    if (key < pointEachNode->keys[i]) {
      manageData(key, pointEachNode, newParentNode, i);
      return;
    }
  }
  manageData(key, pointEachNode, newParentNode, i);
}

// PrintSideways() print B+ tree using in-order traversal
template <class T>
void BPlusTree<T>::print_sideways(ostream &theOutputFile,BPlusTreeNode<T> *pointEachNode,int theTreeLevel) const {
  // Check: If tree is empty
  if (this->root_ != NULL) {

  } else {
    theOutputFile << "Tree is empty." << std::endl;
    return;
  }

  unsigned int rightSide =
      pointEachNode->children.size() - pointEachNode->children.size() / 2;

  // go thru left child nodess
  for (unsigned int i = 0; i < pointEachNode->children.size() / 2; ++i){
    print_sideways(theOutputFile, pointEachNode->children[i], 1 + theTreeLevel);
  }
    

  // print key vector
  for (int i = 0; i < theTreeLevel; ++i) {
    theOutputFile << "\t";
  }
  theOutputFile << pointEachNode->keys[0];
  for (unsigned int i = 1; i < pointEachNode->keys.size(); ++i) {
    theOutputFile << "," << pointEachNode->keys[i];
  }
  theOutputFile << endl;

  // go thru right child nodes
  for (unsigned int i = pointEachNode->children.size() / 2;
       i < (pointEachNode->children.size() / 2) + rightSide; ++i) {
    print_sideways(theOutputFile, pointEachNode->children[i], 1 + theTreeLevel);
  }
}

template <class T>
void BPlusTree<T>::print_BFS(ostream& theOutputFile) const {
    // Check: If tree is empty
    if (this->root_ != NULL) {
        
    }else{
        theOutputFile << "Tree is empty." << endl;
        return;
    }

    vector<int> theLvlsOfTree;//stoer all teh numbers we'll be using
    vector<BPlusTreeNode<T>*> manageAddedNumbers;
    manageAddedNumbers.push_back(this->root_);//add the root
    theLvlsOfTree.push_back(0);
    int finalTreeLvl = 0;
    while (manageAddedNumbers.size() != 0) {
        int theTreeLevel(theLvlsOfTree.front());
        // get and remove the first element from manageAddedNumbers
        BPlusTreeNode<T>* ourNode(manageAddedNumbers.front());//set it to the first number in the vector
        manageAddedNumbers.erase(manageAddedNumbers.begin());//remove the first item 
        theLvlsOfTree.erase(theLvlsOfTree.begin());//do it again
        //spacing
        if(theTreeLevel > 0){
            if (theTreeLevel == finalTreeLvl){
            theOutputFile << "\t";//some spacing
            }
        }else if (theTreeLevel != finalTreeLvl){
            theOutputFile << endl;//add a \n
        }
        theOutputFile << ourNode->keys[0];// print key vectors
        for (unsigned int i = 1; i < ourNode->keys.size(); ++i){
            theOutputFile << "," << ourNode->keys[i];
        }
            
        // append ourNode node's children to manageAddedNumbers
        for (unsigned int i = 0; i < ourNode->children.size(); ++i) {
            theLvlsOfTree.push_back(theTreeLevel + 1);
            manageAddedNumbers.push_back(ourNode->children[i]);
        }
        finalTreeLvl = theTreeLevel;
    }
    theOutputFile << endl;
}


template <class T>
void BPlusTree<T>::print_BFS_pretty(std::ostream &theOutputFile) const {
  // need to put this since it'll run the print_BFS_pretty function
}

template <class T>
void BPlusTree<T>::destroy_tree(BPlusTreeNode<T> *pointEachNode) {
  if (!pointEachNode) {
    return;
  }
  for (unsigned int i = 0; i < pointEachNode->children.size(); ++i) {
    destroy_tree(pointEachNode->children[i]);
  }
  delete pointEachNode;
}

#endif

//clear; g++ *.cpp -o redo.exe -Wall; ./redo.exe out.txt