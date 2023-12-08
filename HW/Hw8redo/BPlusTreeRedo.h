// // this is file being changed
// /* ASSUMPTIONS:
// 1. When a node must be split and has an odd number of keys, the extra key will
// go to the new right-hand node.
// 2. There will never be a duplicate key passed to insert.
// */

// #include <fstream>
// #include <iostream>
// #include <vector>
// #ifndef DS_BPLUSTREE
// #define DS_BPLUSTREE
// using namespace std;
// ///////////////////////////////////////////////////////////////////////////////
// // DO NOT CHANGE THIS CODE
// ///////////////////////////////////////////////////////////////////////////////

// // Do not implement the class here, this is a forward declaration. Implement at
// // the bottom of the .h file
// template <class T> class BPlusTree;

// template <class T> class BPlusTreeNode {
// public:
//   BPlusTreeNode() : parent(NULL){};
//   bool is_leaf();
//   bool contains(const T &key);

//   // For grading only. This is bad practice to have, because
//   // it exposes a private member variable.
//   BPlusTreeNode *get_parent() { return parent; }

//   // We need this to let BPlusTree access private members
//   friend class BPlusTree<T>;

// private:
//   bool contains(const T &key, std::size_t low, std::size_t high);
//   std::vector<T> keys;
//   std::vector<BPlusTreeNode *> children;
//   BPlusTreeNode *parent;
// };

// template <class T> bool BPlusTreeNode<T>::is_leaf() {
//   for (unsigned int i = 0; i < children.size(); i++) {
//     if (children[i]) {
//       return false;
//     }
//   }
//   return true;
// }

// template <class T> bool BPlusTreeNode<T>::contains(const T &key) {
//   return contains(key, 0, keys.size() - 1);
// }

// // Private method takes advantage of the fact keys are sorted
// template <class T>
// bool BPlusTreeNode<T>::contains(const T &key, std::size_t low,
//                                 std::size_t high) {
//   if (low > high) {
//     return false;
//   }
//   if (low == high) {
//     return key == keys[low];
//   }
//   std::size_t mid = (low + high) / 2;
//   if (key <= keys[mid]) {
//     return contains(key, 0, mid);
//   } else {
//     return contains(key, mid + 1, high);
//   }
// }

// ///////////////////////////////////////////////////////////////////////////////////////
// // Your BPlusTree implementation goes below this point.
// ///////////////////////////////////////////////////////////////////////////////////////
// template <class T> class BPlusTree {

// public:
//   // this is the starter code from the ds_set class
//   BPlusTree(int nodeAmt) : root_(NULL), size_(nodeAmt){};
//   BPlusTree(const BPlusTree<T> &old) : size_(old.size_) {
//     root_ = this->copy_tree(old.root_, NULL);
//   };
//   BPlusTree<T> &operator=(const BPlusTree<T> &old) {
//     if (&old != this) {
//       this->destroy_tree(root_);
//       root_ = this->copy_tree(old.root, NULL);
//       size_ = old.size_;
//     }
//     return *this;
//   };
//   ~BPlusTree() { // the destructor class
//     this->destroy_tree(root_);
//     root_ = NULL;
//   };
//   BPlusTreeNode<T> *find(const T &key) { return find(key, root_); };
//   void insert(const T& key) { this->insert( root_, NULL,key); }
// //void insert(const T& key) { insert(key, root_, NULL); }
//   void print_BFS(ostream &theOutputFile);
//   void print_sideways(ostream &theOutputFile) {
//     print_sideways(theOutputFile, root_, 0);
//   };
// void print_BFS_pretty(std::ostream& theOutputFile) const;
// private:
//   int size_;               // define the size var
//   BPlusTreeNode<T> *root_; // connect the root to templated BPTNode
//   void destroy_tree(BPlusTreeNode<T> *pointEachNode);
//   BPlusTreeNode<T> *find(const T &key, BPlusTreeNode<T> *pointEachNode);
//   BPlusTreeNode<T> *copy_tree(BPlusTreeNode<T> *the_parentNode,
//                               BPlusTreeNode<T> *the_oldRoot);
//   void print_sideways(std::ostream &theOutputFile, int treeLevel,
//                       BPlusTreeNode<T> *pointEachNode) const;
//   void makeTheNewParent(BPlusTreeNode<T> *&pointerEachNode);
//   void insert(BPlusTreeNode<T> *the_parentNode, BPlusTreeNode<T> *pointEachNode,
//               const T &key);
//   void manageData(BPlusTreeNode<T> *the_parentNode,
//                   BPlusTreeNode<T> *pointEachNode, const T &key, int i);
// };

// template <class T>
// void BPlusTree<T>::destroy_tree(BPlusTreeNode<T> *pointEachNode) {
//   if (pointEachNode == NULL) {
//     return;
//   }
//   for (int i = 0; i < pointEachNode->children.size(); ++i) {
//     destroy_tree(pointEachNode->children[i]);
//   }
//   delete pointEachNode;
// }

// template <class T>
// BPlusTreeNode<T> *BPlusTree<T>::copy_tree(BPlusTreeNode<T> *the_parentNode,
//                                           BPlusTreeNode<T> *the_oldRoot) {
//   if (the_oldRoot == NULL) {
//     return NULL;
//   }
//   BPlusTreeNode<T> *temp = new BPlusTreeNode<T>();
//   for (int i = 0; i < the_oldRoot->children.size(); ++i) {
//     temp->children.push_back(copy_tree(temp, the_oldRoot->children[i]));
//   }
//   temp->keys = the_oldRoot->keys;
//   temp->parent = the_parentNode;
//   return temp;
// }

// template <class T>
// void BPlusTree<T>::makeTheNewParent(BPlusTreeNode<T> *&pointEachNode) {
//   int newAnswer;
//   BPlusTreeNode<T> *makeNewChildNode = new BPlusTreeNode<T>();
//   if (pointEachNode->is_leaf() == true) {
//     newAnswer = pointEachNode->keys.size() - (pointEachNode->keys.size()) / 2;
//   } else {
//     newAnswer = pointEachNode->keys.size() - (pointEachNode->keys.size() - 1);
//   }
//   while (makeNewChildNode->keys.size() != newAnswer) {
//     makeNewChildNode->keys.insert(makeNewChildNode->keys.begin(),
//                                   pointEachNode->keys.back());
//     pointEachNode->keys.pop_back();
//   }
//   if (!pointEachNode->is_leaf() == true) {
//     while (makeNewChildNode->children.size() !=
//            makeNewChildNode->keys.size() + 1) {
//       makeNewChildNode->children.insert(makeNewChildNode->children.begin(),
//                                         pointEachNode->children.back());
//       makeNewChildNode->children.front()->parent = makeNewChildNode;
//       pointEachNode->children.pop_back();
//     }
//   }
//   BPlusTreeNode<T> *makeNewParentNode = new BPlusTreeNode<T>();
//   pointEachNode->parent = makeNewParentNode;
//   makeNewChildNode->parent = makeNewParentNode;
//   if (pointEachNode->is_leaf() == true) {
//     makeNewParentNode->keys.push_back(makeNewChildNode->keys.front());
//   } else {
//     makeNewParentNode->keys.push_back(pointEachNode->keys.back());
//     pointEachNode->keys.pop_back();
//   }
//   makeNewParentNode->children.push_back(pointEachNode);
//   makeNewParentNode->children.push_back(makeNewParentNode);
//   this->root_ = makeNewParentNode;
// }

// template <class T>
// void BPlusTree<T>::insert(BPlusTreeNode<T> *the_parentNode,
//                           BPlusTreeNode<T> *pointEachNode, const T &key) {
//   int eachVal = 0;
//   if (this->root_ == NULL) {
//     this->root_ = new BPlusTreeNode<T>();
//     this->root_->keys.push_back(key);
//     return; // go again
//   }
  
//   for (; eachVal < pointEachNode->keys.size(); ++eachVal) {
//     if (key < pointEachNode->keys[eachVal]) {
//       manageData(the_parentNode, pointEachNode, key, eachVal);
//       return;
//       // BPlusTreeNode<T> *the_parentNode, BPlusTreeNode<T> *pointEachNode,
//       // const T &key
//     }
//   }
//   manageData(the_parentNode, pointEachNode, key, eachVal);
// }

// template <class T>
// // BPlusTreeNode<T> *the_parentNode, BPlusTreeNode<T> *pointEachNode, const T
// // &key, int i
// void BPlusTree<T>::manageData(BPlusTreeNode<T> *the_parentNode,
//                               BPlusTreeNode<T> *pointEachNode, const T &key,
//                               int i) {
//   if (!pointEachNode->is_leaf() == true) {
//     insert(pointEachNode->children[i], pointEachNode, key);
//     if (this->size_ <= pointEachNode->children[i]->keys.size()) {
//       int newAnswer;
//       if (pointEachNode->children[i]->is_leaf() == true) {
//         newAnswer = pointEachNode->children[i]->keys.size() -
//                     pointEachNode->children[i]->keys.size() / 2;
//       }

//       else
//         newAnswer = pointEachNode->children[i]->keys.size() -
//                     pointEachNode->children[i]->keys.size() / 2 - 1;

//       // Split keys
//       BPlusTreeNode<T> *new_child = new BPlusTreeNode<T>();
//       new_child->parent = pointEachNode;
//       while (new_child->keys.size() != newAnswer) {
//         new_child->keys.insert(new_child->keys.begin(),
//                                pointEachNode->children[i]->keys.back());
//         pointEachNode->children[i]->keys.pop_back();
//       }

//       // split children nodes for non-leaf node
//       if (pointEachNode->children[i]->is_leaf() == false) {
//         while (new_child->children.size() != 1 + new_child->keys.size()) {
//           new_child->children.insert(
//               new_child->children.begin(),
//               pointEachNode->children[i]->children.back());
//           new_child->children.front()->parent = new_child;
//           pointEachNode->children[i]->children.pop_back();
//         }
//       }

//       // Extract key from children to put into pointEachNode's key vector
//       T parent_key(pointEachNode->children[i]->keys.back());
//       if (pointEachNode->children[i]->is_leaf()) {
//         parent_key = new_child->keys.front();
//       } else {
//         pointEachNode->children[i]->keys.pop_back();
//       }
//       /* Insert children's key and new child node to pointEachNode's key and
//        children vector */
//       typename std::vector<T>::iterator iter = pointEachNode->keys.begin();
//       typename std::vector<BPlusTreeNode<T> *>::iterator child_iter;
//       child_iter = pointEachNode->children.begin();
//       pointEachNode->keys.insert(iter + i, parent_key);
//       pointEachNode->children.insert(child_iter + i + 1, new_child);
//     }

//     // If pointEachNode does not have parent and pointEachNode exceeds degree
//     // limit
//     if (the_parentNode == NULL && this->size_ <= pointEachNode->keys.size())
//       makeTheNewParent(pointEachNode);
//     else {
//       typename std::vector<T>::iterator iter = pointEachNode->keys.begin();
//       pointEachNode->keys.insert(iter + i, key);
//       if (this->size_ <= pointEachNode->keys.size() && the_parentNode == NULL) {
//         makeTheNewParent(pointEachNode);
//       }
//     }
//   }
// }

// template <class T>
// void BPlusTree<T>::print_sideways(std::ostream &theOutputFile, int treeLevel,
//                                   BPlusTreeNode<T> *pointEachNode) const {
//   int leftTravNum = pointEachNode->children.size() / 2;
//   int rightTravNum = pointEachNode->children.size() - leftTravNum;
//   if (this->root_ == NULL) {
//     theOutputFile << "Tree is empty." << endl;
//     return;
//   }
//   for (int i = 0; i < pointEachNode->children.size() / 2; ++i) {
//     print_sideways(theOutputFile, treeLevel + 1, pointEachNode->children[i]);
//   }
//   for (int i = 0; i < treeLevel; ++i) {
//     theOutputFile << "\t";
//   }
//   theOutputFile << pointEachNode->keys[0];
//   for (int i = 1; i < pointEachNode->keys.size(); + i) {
//     theOutputFile << ',' << pointEachNode->keys[i];
//   }
//   theOutputFile << endl;
//   for (int i = leftTravNum; i < rightTravNum + leftTravNum; ++i) {
//     print_sideways(theOutputFile, treeLevel + 1, pointEachNode->children[i]);
//   }
// }

// template <class T>
// void BPlusTree<T>::print_BFS(std::ostream &theOutputFile){
//   // Initialize a FIFO queue
//   vector<BPlusTreeNode<T> *> trackTheNumbersBeingAdded;
//   // Check: If tree is empty
//   if (this->root_ != NULL) {
//     trackTheNumbersBeingAdded.push_back(this->root_);
//     vector<int> tree_levels;
//     tree_levels.push_back(0);
//     int last_level = 0;
//     while (trackTheNumbersBeingAdded.size() != 0) {
//       // get and remove the first element from queue
//       BPlusTreeNode<T> *current(trackTheNumbersBeingAdded.front());
//       trackTheNumbersBeingAdded.erase(trackTheNumbersBeingAdded.begin());
//       int level(tree_levels.front());
//       tree_levels.erase(tree_levels.begin());

//       // spacing
//       if (level == last_level && level > 0) {
//         theOutputFile << '\t';
//       } else if(level != last_level){
//          theOutputFile << endl;
//       }
//       // print key vector
//       theOutputFile << '\t'
//       << current->keys[0];
//       for (int i = 1; current->keys.size() > i; ++i) {
//         theOutputFile << '\t'
//         << ',' << current->keys[i];
//       }

//       // append current node's children to queue
//       for (int i = 0; i < current->children.size(); ++i) {
//         trackTheNumbersBeingAdded.push_back(current->children[i]);
//         tree_levels.push_back(level + 1);
//       }

//       last_level = level;
//     }
//     theOutputFile << endl;
//   } else {
//     theOutputFile << "Tree is empty." << endl;
//     return;
//   }
// }

// template <class T>
// void BPlusTree<T>::print_BFS_pretty(std::ostream &theOutputFile) const {}

// #endif