/****************************************************************************
    BinaryTreeConstruction Library (With just method to create a binary tree in BFS fashion (Level by level)).
    Copyright (C) 2016  Anubhav Arun <dr.xperience@gmail.com>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

*****************************************************************************/
#ifndef BINARYTREE_CPP
#define BINARYTREE_CPP

#ifdef DEBUG
#include <iostream>
#endif  // DEBUG

#include <deque>
#include <queue>
#include "BinaryTree.h"

/** Total Code re-base Now node will be integral part of BinaryTree
  * And T will signify the datatype of Node's data
  * Tree may take nullptr as data, if and only if T is of T* i.e. pointer type
  * Each node will be given id of long type (I am not sure about this)
  * Warning The createN function is just for benchmarking purpose
**/

/** To check whether the given Type T is a pointer **/

// template<class T>
// struct isPointer
//{
//    static const bool value=false;
//};
//
// template<class T>
// struct isPointer<T*>
//{
//    static const bool value=true;
//};

template <class T>
BinaryTree<T>::BinaryTree()
    : root(nullptr), id(0), totalNodes(0)
{
  // ctor
}

// Parameterized Constructor for taking in just root
// Overloaded to differentiate between pointer type and normal
/**
    //Alternate Approach (to SFINAE)of checking whether given type is a pointer
    //by making a default second parameter

template <class T> template<typename TT>
BinaryTree<T>::BinaryTree(TT data,typename std::enable_if<!isPointer<TT>::value>::type* a)
{

}
**/
template <class T>
template <typename TT, typename std::enable_if<!isPointer<TT>::value>::type* a>
BinaryTree<T>::BinaryTree(T data)
{
  this->root = new Node;
  this->root->id = 1;
  this->root->data = data;
  this->root->left = this->root->right = nullptr;
  this->id = this->totalNodes = 1;
}

template <class T>
template <typename TT, typename std::enable_if<isPointer<TT>::value>::type* a>
BinaryTree<T>::BinaryTree(T data)
{
  if (data != nullptr)
    {
      this->root = new Node;
      this->root->id = 1;
      this->root->data = data;
      this->root->left = this->root->right = nullptr;
      this->id = this->totalNodes = 1;
    }
}

// Copy Constructor
// Parametrized Constructor for taking in a BinaryTree (data or T being a pointer)
template <class T>
template <typename TT, typename std::enable_if<isPointer<TT>::value>::type* a>
BinaryTree<T>::BinaryTree(BinaryTree<T>& b)
{
#ifdef DEBUG
  long counter = 0;
#endif  // DEBUG

  if (b.root == nullptr || b.root->data == nullptr)
    return;  // throw some sort of exception

  std::queue<Node *> q, q1;
  Node *node, root1, temp;

  bool isRoot = false;

  this.id = b.id;
  this.totalNodes = b.totalNodes;
  do
    {
      if (this->root == nullptr)
        {
          this->root = new Node;
          *(this->root) = *(b.root);
          node = this->root;

          q.push(node);
          q1.push(b.root);

          while (!q1.empty())
            {
              node = q.front();
              q.pop();
              root1 = q1.front();
              q1.pop();

              if (root1->left != nullptr)
                {
                  temp = new Node;
                  *(temp) = *(root1->left);
                  temp->left = temp->right = nullptr;
                  node->left = temp;

                  q.push(node->left);
                  q1.push(root1->left);
                }

              if (root1->right != nullptr)
                {
                  temp = new Node;
                  *(temp) = *(root1->right);
                  temp->left = temp->right = nullptr;
                  node->right = temp;

                  q.push(node->right);
                  q1.push(root1->right);
                }
            }

          isRoot = false;
        }
      else
        {
          // delete old tree before copying
          node = this->root;
          q.push(node);

          while (!q.empty())
            {
              node = q.front();
              q.pop();

              if (node->left != nullptr)
                {
                  q.push(node->left);
                }

              if (node->right != nullptr)
                {
                  q.push(node->right);
                }
			  delete node->data;
              delete node;
            }

          this->id = 0;
          this->totalNodes = 0;
          this->root = nullptr;
          isRoot = true;
        }
    }
  while (isRoot == true);

#ifdef DEBUG
  std::cout << std::endl << "Insertion Loop Counter :: " << counter << std::endl;
#endif  // DEBUG
}

// Copy Constructor
// Parametrized Constructor for taking in a BinaryTree (data or T being a non pointer)
template <class T>
template <typename TT, typename std::enable_if<!isPointer<TT>::value>::type* a>
BinaryTree<T>::BinaryTree(BinaryTree<T>& b)
{
#ifdef DEBUG
  long counter = 0;
#endif  // DEBUG

  if (b.root == nullptr)
    return;  // throw some sort of exception

  std::queue<Node *> q, q1;
  Node *node, root1, temp;

  bool isRoot = false;

  this.id = b.id;
  this.totalNodes = b.totalNodes;
  do
    {
      if (this->root == nullptr)
        {
          this->root = new Node;
          *(this->root) = *(b.root);
          node = this->root;

          q.push(node);
          q1.push(b.root);

          while (!q1.empty())
            {
              node = q.front();
              q.pop();
              root1 = q1.front();
              q1.pop();

              if (root1->left != nullptr)
                {
                  temp = new Node;
                  *(temp) = *(root1->left);
                  temp->left = temp->right = nullptr;
                  node->left = temp;

                  q.push(node->left);
                  q1.push(root1->left);
                }

              if (root1->right != nullptr)
                {
                  temp = new Node;
                  *(temp) = *(root1->right);
                  temp->left = temp->right = nullptr;
                  node->right = temp;

                  q.push(node->right);
                  q1.push(root1->right);
                }
            }

          isRoot = false;
        }
      else
        {
          // delete old tree before copying
          node = this->root;
          q.push(node);

          while (!q.empty())
            {
              node = q.front();
              q.pop();

              if (node->left != nullptr)
                {
                  q.push(node->left);
                }

              if (node->right != nullptr)
                {
                  q.push(node->right);
                }

              delete node;
            }

          //            delete this->root;
          this->id = 0;
          this->totalNodes = 0;
          this->root = nullptr;
          isRoot = true;
        }
    }
  while (isRoot == true);

#ifdef DEBUG
  std::cout << std::endl << "Insertion Loop Counter :: " << counter << std::endl;
#endif  // DEBUG
}

// Move constructorHere
/**
{
    #ifdef DEBUG
    long counter=0;
    #endif // DEBUG

    std::queue<Node *> q,q1;


    this->root = new Node;
    this->root->data=data;
    Node* node = this->root;
    q.push(node);
    q1.push(root1);

    while(!q1.empty())
    {
        #ifdef DEBUG
        counter++;
        #endif // DEBUG

        root1 = q1.front(); q1.pop();
        node = new Type;
        node = q.front(); q.pop();

        if(root1->left != nullptr)
         {
             node->left=root1->left;
             q1.push(root1->left);q.push(node->left);
         }

         if(root1->right != nullptr)
         {
             node->right=root1->right;
             q1.push(root1->right);q.push(node->right);
         }
    }


    #ifdef DEBUG
    std::cout<<std::endl<<"Insertion Loop Counter :: "<<counter<<std::endl;
    #endif // DEBUG

}
*/

template <class T>
BinaryTree<T>::~BinaryTree()
{
  // dtor
  this->clear();
}

/******************************************************************
 *
 *                Member Functions for pointer
 *
 *******************************************************************/

/**
 insert at first blank location found in tree
**/

template <class T>
template <typename TT, typename std::enable_if<isPointer<TT>::value>::type* a>
int BinaryTree<T>::insert(T data)
{
  if (this->root == nullptr)
    {
      if (data == nullptr)
        {
          return -1;
        }

      this->root = new Node;
      this->root->id = 1;
      this->root->data = data;
      this->root->left = this->root->right = nullptr;
      this->id = this->totalNodes = 1;
      return;
    }
  //    if(data ==nullptr)
  //    {
  //         id++;
  //         return;
  //    }
  //
  Node *node = this->root, *temp;

  std::queue<Node*> q;

  q.push(node);

  while (!q.empty())
    {
      node = q.front();
      q.pop();

      if (node->left != nullptr)
        {
          q.push(node->left);
        }
      else
        {
          if (data == nullptr)
            return -1;
          temp = new Node;
          temp->id = node.id * 2;
          temp->data = data;
          temp->left = temp->right = nullptr;

          node->left = temp;
          this->totalNodes++;
          break;
        }

      if (node->right != nullptr)
        {
          q.push(node->right);
        }
      else
        {
          if (data == nullptr)
            return -1;
          temp = new Node;
          temp->id = (node.id * 2) + 1;
          temp->data = data;
          temp->left = temp->right = nullptr;

          node->right = temp;
          this->totalNodes++;
          break;
        }
    }

  return 0;
}

/** Overloaded and Improved insert method which takes a buffer on input values (a std::queue)
  * And fills it in the empty spaces while traversing BFD
  * Complexity ?? (Probably should be better, like something around N+m,
  *                where N is total no. of nodes in tree and m total no of notes in queue)
  * Will test it by replacing it against the creatN method in memory benchmark
  */

template <class T>
template <typename TT, typename std::enable_if<isPointer<TT>::value>::type* a>
int BinaryTree<T>::insert(std::deque<T> stream)
{
#ifdef DEBUG
  long counter = 0;
#endif  // DEBUG

  if (this->root == nullptr)
    {
      if (stream.empty() || stream.front() == nullptr)
        {
          return -1;
        }

      this->root = new Node;
      this->root->id = 1;
      this->root->data = stream.front();
      stream.pop_front();
      this->root->left = this->root->right = nullptr;
      this->id = this->totalNodes = 1;
    }
  //    if(data ==nullptr)
  //    {
  //         id++;
  //         return;
  //    }
  //
  Node *node = this->root, *temp;

  std::queue<Node*> q;

  q.push(node);

  while (!stream.empty())
    {
#ifdef DEBUG
      counter++;
#endif  // DEBUG

      node = q.front();
      q.pop();

      if (node->left != nullptr)
        {
          q.push(node->left);
        }
      else
        {
          if (stream.front == nullptr)
            return -1;
          temp = new Node;
          temp->id = node.id * 2;
          temp->data = stream.front();
          stream.pop_front();
          temp->left = temp->right = nullptr;
          node->left = temp;

          q.push(node->left);
          this->totalNodes++;
        }

      if (node->right != nullptr)
        {
          q.push(node->right);
        }
      else
        {
          if (!stream.empty())
            {
              if (stream.front == nullptr)
                return -1;
              temp = new Node;
              temp->id = (node.id * 2) + 1;
              temp->data = stream.front();
              stream.pop_front();
              temp->left = temp->right = nullptr;
              node->right = temp;

              q.push(node->right);
              this->totalNodes++;
            }
        }
    }

#ifdef DEBUG
  std::cout << std::endl << "Insertion Loop Counter :: " << counter << std::endl;
#endif  // DEBUG

  return 0;
}
template <class T>
template <typename TT, typename std::enable_if<isPointer<TT>::value>::type* a>
void BinaryTree<T>::insertInteractive(T (*process)(long id, bool& skip, bool& cont))
{
  Node *node, *temp;
  T data;
  //  long id = 1;
  bool cont = true, skip = false;

  if (this->root == nullptr)
    {
      data = process(1, skip, cont);

      if (data == nullptr || skip == true)
        {
          return;
        }

      this->root = new Node;
      this->root->id = 1;
      this->root->data = data;
      this->root->left = this->root->right = nullptr;
      this->id = this->totalNodes = 1;
    }

  node = this->root;
  std::queue<Node*> q;

  q.push(node);

  while (cont == true && !q.empty())
    {
      node = q.front();
      q.pop();

      if (node->left != nullptr)
        {
          q.push(node->left);
        }
      else
        {
          data = process(node->id * 2, skip, cont);

          if (skip != true || data != nullptr)
            {
              temp = new Node;
              temp->id = (node->id) * 2;
              temp->data = data;
              temp->left = temp->right = nullptr;
              node->left = temp;
              q.push(node->left);
            }
        }

      if (node->right != nullptr)
        {
          q.push(node->right);
        }
      else
        {
          data = process((node->id * 2) + 1, skip, cont);

          if (skip == true || data == nullptr)
            {
              temp = new Node;
              temp->id = ((node->id) * 2) + 1;
              temp->data = data;
              temp->left = temp->right = nullptr;
              node->right = temp;
              q.push(node->right);
            }
        }
    }
}

/**
 appendBack create a full binary tree. It takes root of any binary tree and forms a full/complete binary tree from it
**/

template <class T>
template <typename TT, typename std::enable_if<isPointer<TT>::value>::type* a>
void BinaryTree<T>::appendBack(BinaryTree<T>& b)
{
#ifdef DEBUG
  long counter = 0;
#endif  // DEBUG

  std::queue<Node *> q, q1;
  Node *node, root1, temp;

  if (this->root == nullptr)
    {
      this->root = new Node;
      *(this->root) = *(b.root);
      this->root->id = 1;
      this->root->left = nullptr;
      this->root->right = nullptr;

      node = this->root;
      q.push(node);

      if (node->left != nullptr)
        {
          q1.push(b.root->left);
        }
      else if (node->right != nullptr)
        {
          q1.push(b.root->right);
        }
    }
  else
    {
      node = this->root;
      q.push(node);
      q1.push(b.root);
    }

  while (!q1.empty())
    {
#ifdef DEBUG
      counter++;
#endif  // DEBUG

      node = q.front();
      q.pop();

      if (node->left != nullptr)
        {
          q.push(node->left);
        }
      else
        {
          root1 = q1.front();
          q1.pop();
          root1.id = node.id * 2;
          temp = new Node;
          *temp = *root1;
          temp->left = nullptr;
          temp->right = nullptr;

          node->left = temp;
          q.push(node->left);

          if (root1->left != nullptr)
            {
              q1.push(root1->left);
            }
          if (root1->right != nullptr)
            {
              q1.push(root1->right);
            }
        }

      if (node->right != nullptr)
        {
          q.push(node->right);
        }
      else
        {
          if (q1.empty())
            break;
          root1 = q1.front();
          q1.pop();
          root1.id = (node.id * 2) + 1;
          temp = new Node;
          *temp = *root1;
          temp->left = nullptr;
          temp->right = nullptr;

          node->right = temp;
          q.push(node->right);

          if (root1->left != nullptr)
            {
              q1.push(root1->left);
            }
          if (root1->right != nullptr)
            {
              q1.push(root1->right);
            }
        }
    }

#ifdef DEBUG
  std::cout << std::endl << "Insertion Loop Counter :: " << counter << std::endl;
#endif  // DEBUG
}

/******************************************************************
 *
 *                Member Functions for non pointer
 *
 *******************************************************************/

/**
 insert at first blank location found in tree
**/

template <class T>
template <typename TT, typename std::enable_if<!isPointer<TT>::value>::type* a>
void BinaryTree<T>::insert(T data)
{
  if (this->root == nullptr)
    {
      this->root = new Node;
      this->root->id = 1;
      this->root->data = data;
      this->root->left = this->root->right = nullptr;
      this->id = this->totalNodes = 1;
      return;
    }
  //    if(data ==nullptr)
  //    {
  //         id++;
  //         return;
  //    }
  //
  Node *node = this->root, *temp;

  std::queue<Node*> q;

  q.push(node);

  while (!q.empty())
    {
      node = q.front();
      q.pop();

      if (node->left != nullptr)
        {
          q.push(node->left);
        }
      else
        {
          temp = new Node;
          temp->id = node->id * 2;
          temp->data = data;
          temp->left = temp->right = nullptr;

          node->left = temp;
          this->totalNodes++;
          break;
        }

      if (node->right != nullptr)
        {
          q.push(node->right);
        }
      else
        {
          temp = new Node;
          temp->id = (node->id * 2) + 1;
          temp->data = data;
          temp->left = temp->right = nullptr;

          node->right = temp;
          this->totalNodes++;
          break;
        }
    }
}

template <class T>
template <typename TT, typename std::enable_if<!isPointer<TT>::value>::type* a>
void BinaryTree<T>::insert(std::deque<T> stream)
{
#ifdef DEBUG
  long counter = 0;
#endif  // DEBUG

  if (this->root == nullptr)
    {
      this->root = new Node;
      this->root->id = 1;
      this->root->data = stream.front();
      stream.pop_front();
      this->root->left = this->root->right = nullptr;
      this->id = this->totalNodes = 1;
    }
  //    if(data ==nullptr)
  //    {
  //         id++;
  //         return;
  //    }
  //
  Node *node = this->root, *temp;

  std::queue<Node*> q;

  q.push(node);

  while (!stream.empty())
    {
#ifdef DEBUG
      counter++;
#endif  // DEBUG

      node = q.front();
      q.pop();

      if (node->left != nullptr)
        {
          q.push(node->left);
        }
      else
        {
          temp = new Node;
          temp->id = node->id * 2;
          temp->data = stream.front();
          stream.pop_front();
          temp->left = temp->right = nullptr;
          node->left = temp;

          q.push(node->left);
          this->totalNodes++;
        }

      if (node->right != nullptr)
        {
          q.push(node->right);
        }
      else
        {
          if (!stream.empty())
            {
              temp = new Node;
              temp->id = (node->id * 2) + 1;
              temp->data = stream.front();
              stream.pop_front();
              temp->left = temp->right = nullptr;
              node->right = temp;

              q.push(node->right);
              this->totalNodes++;
            }
        }
    }

#ifdef DEBUG
  std::cout << std::endl << "Insertion Loop Counter :: " << counter << std::endl;
#endif  // DEBUG
}

template <class T>
template <typename TT, typename std::enable_if<!isPointer<TT>::value>::type* a>
void BinaryTree<T>::insertInteractive(T (*process)(long id, bool& skip, bool& cont))
{
  Node *node, *temp;
  T data;
  //    long id=1;
  bool cont = true, skip = false;

  if (this->root == nullptr)
    {
      data = process(1, skip, cont);

      if (skip == true)
        {
          return;
        }

      this->root = new Node;
      this->root->id = 1;
      this->root->data = data;
      this->root->left = this->root->right = nullptr;
      this->id = this->totalNodes = 1;
    }

  node = this->root;
  std::queue<Node*> q;

  q.push(node);

  while (cont == true && !q.empty())
    {
      node = q.front();
      q.pop();

      if (node->left != nullptr)
        {
          q.push(node->left);
        }
      else
        {
          data = process(node->id * 2, skip, cont);

          if (skip == false)
            {
              temp = new Node;
              temp->id = (node->id) * 2;
              temp->data = data;
              temp->left = temp->right = nullptr;
              node->left = temp;
              q.push(node->left);
            }
        }

      if (node->right != nullptr)
        {
          q.push(node->right);
        }
      else
        {
          data = process((node->id * 2) + 1, skip, cont);

          if (skip == false)
            {
              temp = new Node;
              temp->id = ((node->id) * 2) + 1;
              temp->data = data;
              temp->left = temp->right = nullptr;
              node->right = temp;
              q.push(node->right);
            }
        }
    }
}

/**
 appendBack create a full binary tree. It takes root of any binary tree and forms a full/complete binary tree from it
**/

template <class T>
template <typename TT, typename std::enable_if<!isPointer<TT>::value>::type* a>
void BinaryTree<T>::appendBack(BinaryTree<T>& b)
{
#ifdef DEBUG
  long counter = 0;
#endif  // DEBUG

  std::queue<Node *> q, q1;
  Node *node, root1, temp;

  if (this->root == nullptr)
    {
      this->root = new Node;
      *(this->root) = *(b.root);
      this->root->id = 1;
      this->root->left = nullptr;
      this->root->right = nullptr;

      node = this->root;
      q.push(node);

      if (node->left != nullptr)
        {
          q1.push(b.root->left);
        }
      else if (node->right != nullptr)
        {
          q1.push(b.root->right);
        }
    }
  else
    {
      node = this->root;
      q.push(node);
      q1.push(b.root);
    }

  while (!q1.empty())
    {
#ifdef DEBUG
      counter++;
#endif  // DEBUG

      node = q.front();
      q.pop();

      if (node->left != nullptr)
        {
          q.push(node->left);
        }
      else
        {
          root1 = q1.front();
          q1.pop();
          root1.id = node.id * 2;
          temp = new Node;
          *temp = *root1;
          temp->left = nullptr;
          temp->right = nullptr;

          node->left = temp;
          q.push(node->left);

          if (root1->left != nullptr)
            {
              q1.push(root1->left);
            }
          if (root1->right != nullptr)
            {
              q1.push(root1->right);
            }
        }

      if (node->right != nullptr)
        {
          q.push(node->right);
        }
      else
        {
          if (q1.empty())
            break;
          root1 = q1.front();
          q1.pop();
          root1.id = (node.id * 2) + 1;
          temp = new Node;
          *temp = *root1;
          temp->left = nullptr;
          temp->right = nullptr;

          node->right = temp;
          q.push(node->right);

          if (root1->left != nullptr)
            {
              q1.push(root1->left);
            }
          if (root1->right != nullptr)
            {
              q1.push(root1->right);
            }
        }
    }

#ifdef DEBUG
  std::cout << std::endl << "Insertion Loop Counter :: " << counter << std::endl;
#endif  // DEBUG
}

template <class T>
void BinaryTree<T>::createN(unsigned long N)
{
  this->root = new Node;
  this->root->id = 1;
  this->root->data = 1;
  this->root->left = this->root->right = nullptr;
  this->id = this->totalNodes = 1;

  Node *node = this->root, *temp;

  std::queue<Node*> q;

  q.push(node);

  while (!q.empty())
    {
      node = q.front();
      q.pop();

      if (node->id >= N)
        break;

      if (node->left != nullptr)
        {
          q.push(node->left);
        }
      else
        {
          temp = new Node;
          temp->id = temp->data = node->id * 2;
          temp->left = temp->right = nullptr;
          node->left = temp;
          q.push(node->left);
          this->totalNodes++;
        }

      if (node->right != nullptr)
        {
          q.push(node->right);
        }
      else
        {
          temp = new Node;
          temp->id = temp->data = (node->id * 2) + 1;
          temp->left = temp->right = nullptr;
          node->right = temp;
          q.push(node->right);
          this->totalNodes++;
        }
    }
}

template <class T>
template <typename TT, typename std::enable_if<!isPointer<TT>::value>::type* a>
void BinaryTree<T>::clear()
{
  if (this->root == nullptr)
    return;

  Node* node = this->root;
  std::queue<Node*> q;
  q.push(node);

#ifdef DEBUG
  std::cout << std::endl << "this->root :: " << this->root << std::endl;
  std::cout << std::endl << "node :: " << node << std::endl;
  std::cout << std::endl << "qroot :: " << q.front() << std::endl;
#endif
  while (!q.empty())
    {
      node = q.front();
      q.pop();

      if (node->left != nullptr)
        {
          q.push(node->left);
        }

      if (node->right != nullptr)
        {
          q.push(node->right);
        }

      delete node;
    }

  //    delete this->root;
  this->id = 0;
  this->totalNodes = 0;
  this->root = nullptr;
}

template <class T>
template <typename TT, typename std::enable_if<!isPointer<TT>::value>::type* a, typename Compare>
void BinaryTree<T>::deleteNodeGivenDataApproach1(T data, Compare comp)
{
  /***************************************************************
   * My Approach 1 (This approach will be pretty usefull during node balancing)
   *
   * What I am trying to do is, when a node is identified as the one to be delete,
   *
   * i> I save the address of the pointer pointing to the identifed node(i.e. either root or node->left or node->right in **parent pointer.
   *    Then, I shift all the node on its left or right subtree (whichever available)
   *    up by one level
   * 	Example :
   * 			In this we need to remove this->root node
   * 			parent = &(this->root) // else we would have done something like parent=&(node->left)
   * 					    *parent											 *parent
   * 					       |												|
   * 					       1	<= node to be deleted						2
   * 				    /            \									 /            \
   * 			       2              3					==>				4              3
   * 			     /   \         /    \						      /   \         /    \
   * 			    4     5       6      7					         8     5       6      7
   * 			   / \   / \    /  \   /  \					          \   / \    /  \   /  \
   * 			  8   9 10 11  12  13 14  15				           9 10 11  12  13 14  15
   *
   * ii> This is achieved by carrying out following steps
   *
   * 		Assuming we have a left subtree available
   *
   * 		a.> We save the right node of the left node of the identified
   * 			node in temp variable
   *
   * 			temp = (*parent)->left-right
   *
   * 				*parent
   * 					|
   * 					1
   * 				   /
   * 				  2							temp =>  5
   * 				   \			==> 			   /  \
   * 				    5							  10  11
   * 				   / \
   * 				  10 11
   *
   * 		b.> Assign the right subtree of the identified node to the right of the left node of the identified node.
   *
   * 			(*parent)->left->right = (*parent)->right
   *
   * 				*parent								*parent
   * 					|									|
   * 					1									1
   * 				   /								   /
   * 				  2			   ==> 					  2
   * 				   \								   \
   * 				    x								    3
   * 				   									   / \
   * 													  6   7
   *
   * 		c.> Now both (*parent)->left->right and (*parent)->right are pointing to
   * 			same subtree
   *
   * 						  *parent
   * 							 |
   * 					    2----1
   * 					  /  \  /
   * 					 4    3
   * 					/ \  / \
   * 				   8  9 6   7
   *
   * 		d.> Now delete the identified node & update the pointer(*parent)
   * 			pointing to the current(identified) node with the replaced node
   *
   * 			node = (*parent)->left; //where node is the pointer pointing to identified node as well
   * 			node->id = (*parent)->id;
   * 			delete *parent;
   * 			(*parent)=node;
   *
   * 					*parent									temp
   * 						|									  |
   * 					    2									  5
   * 					  /  \  				&				 / \
   * 					 4    3									10 11
   * 					/ \  / \
   * 				   8  9 6   7
   *
   * 		e.> We have a tree with identified node deleted. Now all we have to do is,
   * 			iterate on the left path and adjust the right subtree
   *
   * 			while(temp != nullptr && node->left != nullptr)
   * 			{
   * 				temp1 = node->left->right;
   * 				node->left->right = temp;
   * 				temp = temp1;
   * 				node->left->id = 2 * (node->id);
   * 				node = node->left;
   * 			}
   *
   *							 *parent
   *								|
   *								2
   *						 /            \
   *						4              3
   *				      /   \         /    \
   *			         8     5       6      7
   * 			          \   / \    /  \   /  \
   *			           9 10 11  12  13 14  15
   *
   * 		f.> Covering a corner case when temp != nullptr but node->left == nullptr
   * 					    *parent											 *parent
   * 					       |												|
   * 					       1	<= node to be deleted						2
   * 				    /            \									 /            \
   * 			       2              3					==>				4              3
   * 			     /   \         /    \						      /   \         /    \
   * 			    4     5       6      7					         9     5       6      7
   * 			     \   / \    /  \   /  \					              / \    /  \   /  \
   * 			     9 10 11  12  13 14  15					        	 10 11  12  13 14  15
   *
   * 			if(temp != nullptr && node->left == nullptr)
   * 			{
   * 				node->left = temp;
   * 				node->left->id = 2 * (node->id);
   * 			}
   * ****************************************************************************/

  if (this->root == nullptr)
    return;  // throw exception

#ifdef DEBUG
  unsigned long counter = 0;
#endif

  typedef typename BinaryTree<T>::Node Node;
  Node *node = this->root, *temp = nullptr, *temp1 = nullptr;
  Node** parent = nullptr;

  if (comp(data, node->data) == 0)
    {
      parent = &(this->root);
    }

  if (parent == nullptr)
    {
      std::queue<Node*> q;
      q.push(node);

      while (!q.empty())
        {
#ifdef DEBUG
          counter++;
#endif

          node = q.front();
          q.pop();

          if (node->left != nullptr)
            {
              if (comp(data, node->left->data) == 0)
                {
                  parent = &(node->left);
                  break;
                }
              q.push(node->left);
            }

          if (node->right != nullptr)
            {
              if (comp(data, node->right->data) == 0)
                {
                  parent = &(node->right);
                  break;
                }
              q.push(node->right);
            }

        }  // end of while
    }

  if (parent == nullptr)
    return;  // throw exception node with data not found

  if ((*parent)->left != nullptr)
    {
      temp = (*parent)->left->right;
      (*parent)->left->right = (*parent)->right;
      node = (*parent)->left;
      node->id = (*parent)->id;
      delete (*parent);
      (*parent) = node;

      while (temp != nullptr && node->left != nullptr)
        {
#ifdef DEBUG
          counter++;
#endif
          temp1 = node->left->right;
          node->left->right = temp;
          temp = temp1;
          node->left->id = 2 * (node->id);
          node = node->left;
        }

      if (temp != nullptr && node->left == nullptr)
        {
          node->left = temp;
          node->left->id = 2 * (node->id);
        }
      // Since the while loop terminates when temp == nullptr
      // Thus, if there is a single path with no right node in it
      // then node->id will not update (again because loop will terminate)

      // This is good because it will decreases the no of iterations if subtree is heavily deep and one sided
      // and it will decrease time complexity as well

      // This is bad because one sided subtree will not have updated id  (which we can live with I guess)
    }
  else if ((*parent)->right != nullptr)
    {
      temp = (*parent)->right->left;
      (*parent)->right->left = (*parent)->left;
      node = (*parent)->right;
      node->id = (*parent)->id;
      delete (*parent);
      (*parent) = node;

      while (temp != nullptr && node->right != nullptr)
        {
#ifdef DEBUG
          counter++;
#endif
          temp1 = node->right->left;
          node->right->left = temp;
          temp = temp1;
          node->right->id = 2 * (node->id) + 1;
          node = node->right;
        }

      if (temp != nullptr && node->right == nullptr)
        {
          node->right = temp;
          node->right->id = 2 * (node->id) + 1;
        }

      // Since the while loop terminates when temp == nullptr
      // Thus, if there is a single path with no left node in it
      // then node->id will not update (again because loop will terminate)

      // This is good because it will decreases the no of iterations if subtree is heavily deep and one sided
      // and it will decrease time complexity as well

      // This is bad because one sided subtree will not have updated id  (which we can live with I guess)
    }
  else
    {
      delete *parent;
      *parent = nullptr;
    }

  this->totalNodes--;

#ifdef DEBUG
  std::cout << std::endl << "Number of Loops to delete node with given data :: " << counter << std::endl;
#endif
}

template <class T>
template <typename TT, typename std::enable_if<!isPointer<TT>::value>::type* a, typename Compare>
void BinaryTree<T>::deleteNodeGivenDataApproach2(T data, Compare comp)
{
  /*************************************************************************
   * When a node is identified save its parensts. Find the deepest node in the subtree of the identified node.
   * Delete the identified node & insert the deepest node of the subtree instead
   * *****************************************************************************/

  if (this->root == nullptr)
    return;  // throw exception

#ifdef DEBUG
  unsigned long counter = 0;
#endif

  typedef typename BinaryTree<T>::Node Node;

  Node* node = this->root;
  Node** parent = nullptr;
  Node** deepParent = nullptr;

  if (comp(data, node->data) == 0)
    {
      parent = &(this->root);
    }

  if (parent == nullptr)
    {
      std::queue<Node*> q;
      q.push(node);

      while (!q.empty())
        {
#ifdef DEBUG
          counter++;
#endif
          node = q.front();
          q.pop();

          if (node->left != nullptr)
            {
              if (comp(data, node->left->data) == 0)
                {
                  parent = &(node->left);
                  break;
                }
              q.push(node->left);
            }

          if (node->right != nullptr)
            {
              if (comp(data, node->right->data) == 0)
                {
                  parent = &(node->right);
                  break;
                }
              q.push(node->right);
            }
        }  // end of while
    }

  if (parent == nullptr)
    return;  // throw exception (node not found)

  node = *parent;

  while (node->left != nullptr || node->right != nullptr)
    {
#ifdef DEBUG
      counter++;
#endif
      if (node->left != nullptr)
        {
          deepParent = &(node->left);
          node = node->left;
        }
      else if (node->right != nullptr)
        {
          deepParent = &(node->right);
          node = node->right;
        }
    }

  if (deepParent == nullptr)
    {
      delete *parent;
      *parent = nullptr;
    }
  else if ((*parent)->left != *deepParent && (*parent)->right != *deepParent)
    {
      (*deepParent)->id = (*parent)->id;
      (*deepParent)->left = (*parent)->left;
      (*deepParent)->right = (*parent)->right;

      delete *parent;
      *parent = *deepParent;
      *deepParent = nullptr;
    }
  else
    {
      (*deepParent)->id = (*parent)->id;
      if ((*parent)->left != *deepParent)
        {
          (*deepParent)->left = (*parent)->left;
        }
      if ((*parent)->right != *deepParent)
        {
          (*deepParent)->right = (*parent)->right;
        }

      // Saving deepParent value in node because deepParent is either left pointer or right pointer inside parent
      node = *deepParent;
      delete *parent;
      (*parent) = node;
    }

  this->totalNodes--;

#ifdef DEBUG
  std::cout << std::endl << "Number of Loops to delete node with given data :: " << counter << std::endl;
#endif
}

#endif  // BINARYTREE_CPP
