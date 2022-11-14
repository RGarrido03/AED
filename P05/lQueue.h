//
// Tomás Oliveira e Silva, AED, November 2021
//
// Generic queue (First In First Out) implementation based on an linked list
//

#ifndef _AED_lQueue_
#define _AED_lQueue_

#include <cassert>

template <typename T>
class lQueue
{
  private:
    class sNode
    {
      public:
        T value;     // the data stored in the node
        sNode *next; // pointer to the next node
    };
    int n_nodes;     // number of nodes
    int max_size;
    sNode *head;     // head of the queue
    sNode *tail;     // tail of the queue
  
  public:
    lQueue(int n = 100)
    {
      n_nodes = 0;
      max_size = n;
      head = nullptr;
      tail = nullptr;
      pos = -1; // default position is before the head of the list
    }

    ~lQueue(void)
    {
      sNode *sn1,*sn2;

      for(sn1 = head;sn1 != nullptr;sn1 = sn2)
      {
        sn2 = sn1->next;
        delete sn1;
      }
      n_nodes = 0;
      head = nullptr;
      tail = nullptr;
    }

    void clear(void)
    {
      for(sn1 = head;sn1 != nullptr;sn1 = sn2)
      {
        sn2 = sn1->next;
        delete sn1;
      }
      n_nodes = 0;
    }

    int size(void) const
    {
      return n_nodes;
    }

    int is_full(void) const
    {
      return (n_nodes >= max_size) ? 1 : 0;
    }

    int is_empty(void) const
    {
      return (n_nodes == 0) ? 1 : 0;
    }

    void enqueue(T &v)
    {
    }

    T dequeue(void)
    {
    }

    T peek(void)
    {
      sNode *sn1;
      sn1 = head;
      return sn1->value;
    }
};

#endif
