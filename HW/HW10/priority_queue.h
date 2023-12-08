#ifndef priority_queue_h_
#define priority_queue_h_

#include <cassert>
#include <iostream>
#include <vector>
#include "image.h"
#include <map>

// The DistancePixel_PriorityQueue is a customized, non-templated
// priority queue that stores DistancePixel pointers in a heap.  The
// elements in the heap can be looked up in a map, to quickly find out
// the current index of the element within the heap.

// ASSIGNMENT: The class implementation is incomplete.  Finish the
//   implementation of this class, and add any functions you need.

// =========================================================================

class DistancePixel_PriorityQueue
{

public:
  // --------------------------
  // CONSTRUCTORS
  // default constructor
  DistancePixel_PriorityQueue() {}
  // construct a heap from a vector of data
  DistancePixel_PriorityQueue(const std::vector<DistancePixel *> &values)
  {
    for (std::vector<DistancePixel *>::const_iterator itr = values.begin(); itr != values.end(); itr++)
    {
      std::cout << *itr;
      percolate_up(m_heap.size()); // percolate up the last element in the heap
      backpointers[*itr] = m_heap.size() - 1;
      m_heap.push_back(*itr);
    }
  }

  // ------------------------
  // ACCESSORS
  int size() { return m_heap.size(); }
  bool empty() { return m_heap.empty(); }
  int last_non_leaf() { return (size() - 1) / 2; }
  int get_parent(int i)
  {
    assert(i > 0 && i < size());
    return (i - 1) / 2;
  }
  bool has_left_child(int i) { return (2 * i) + 1 < size(); }
  bool has_right_child(int i) { return (2 * i) + 2 < size(); }
  int get_left_child(int i)
  {
    assert(i >= 0 && has_left_child(i));
    return 2 * i + 1;
  }
  int get_right_child(int i)
  {
    assert(i >= 0 && has_right_child(i));
    return 2 * i + 2;
  }

  // read the top element
  DistancePixel *top() const
  {
    assert(!m_heap.empty());
    return m_heap[0];
  }

  // is this element in the heap?
  bool in_heap(DistancePixel *element) const
  {
    std::map<DistancePixel *, int>::const_iterator itr = backpointers.find(element);
    return (itr != backpointers.end());
  }

  // add an element to the heap
  void push(DistancePixel *element)
  {
    std::map<DistancePixel *, int>::const_iterator itr = backpointers.find(element);

    m_heap.push_back(element);
    backpointers[element] = m_heap.size() - 1;
    this->percolate_up(m_heap.size() - 1); // percolate up the last element in the heap
  }

  // the value of this element has been edited, move the element up or down
  void update_position(DistancePixel *element)
  {
    std::map<DistancePixel *, int>::iterator itr = backpointers.find(element);
    assert(itr != backpointers.end());
    this->percolate_up(itr->second);   // percolate up the element at index itr->second
    this->percolate_down(itr->second); // percolate down the element at index itr->second
  }

  // remove the top (minimum) element
  void pop()
  {
    assert(!m_heap.empty());
    int success = backpointers.erase(m_heap[0]);
    assert(success == 1);
    m_heap[0] = m_heap.back();
    m_heap.pop_back();
    this->percolate_down(0);
  }

private:
  // REPRESENTATION
  // the heap is stored in a vector representation (the binary tree
  // structure "unrolled" one row at a time)
  std::vector<DistancePixel *> m_heap;
  // the map stores a correpondence between elements & indices in the heap
  std::map<DistancePixel *, int> backpointers;

  // private helper functions
  void percolate_up(int i)
  {
    //
    // ASSIGNMENT: Implement this function
    //
    DistancePixel *x = m_heap[i];
    // get the value and do a comparison
    while (i > 0 && x->getValue() < m_heap[get_parent(i)]->getValue())
    {
      m_heap[i] = m_heap[get_parent(i)]; // change each item in the stack that fits the requirements to the parent
      backpointers[m_heap[i]] = i;       // now change the backpointer item to i
      i = get_parent(i);
    }
    m_heap[i] = x;
    backpointers[x] = i;
  }

  void percolate_down(int i)
  {
    // Store the DistancePixel object at index i in x
    DistancePixel *x = m_heap[i];
    // While i has a left child:
    while (has_left_child(i))
    {
      // Get the index of the left child
      int child = get_left_child(i);
      // If i has a right child and the right child has a smaller value than the left child:
      if (has_right_child(i) && *m_heap[get_right_child(i)] < *m_heap[child])
      {
        // Set child to the index of the right child
        child = get_right_child(i);
      }
      // If the value of the child is smaller than the value of x:
      if (*m_heap[child] < *x)
      {
        // Swap the DistancePixel object at index i with the DistancePixel object at index child
        m_heap[i] = m_heap[child];
        // Update the backpointer of the swapped DistancePixel object to i
        backpointers[m_heap[i]] = i;
        // Update i to child
        i = child;
      }
      else
      {
        // If the value of the child is not smaller than the value of x, break out of the loop
        break;
      }
    }
    // Set the DistancePixel object at the final index i to x
    m_heap[i] = x;
    // Update the backpointer of x to i
    backpointers[x] = i;
  }
};

#endif