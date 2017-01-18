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

#ifndef BINARYTREE_H
#define BINARYTREE_H

#ifdef DEBUG
#include <iostream>
#endif  // DEBUG

#include <deque>
#include <type_traits>

/** Total Code re-base Now node will be integral part of BinaryTree
  * And T will signify the datatype of Node's data
  * Tree may take nullptr as data, if and only if T is of T* i.e. pointer type
  * Each node will be given id of long type (I am not sure about this)
  * Warning The createN function is just for benchmarking purpose
**/

/** To check whether the given Type T is a pointer **/

template <class T>
struct isPointer
{
  static const bool value = false;
};

template <class T>
struct isPointer<T*>
{
  static const bool value = true;
};

template <class T>
class BinaryTree
{
  private:
  public:
  // Constructor
  BinaryTree();

  // Overloaded parameterised constructor for non pointer
  template <typename TT = T, typename std::enable_if<!isPointer<TT>::value>::type* = nullptr>
  BinaryTree(T data);

  // Overloaded parameterised constructor for pointer
  template <typename TT = T, typename std::enable_if<isPointer<TT>::value>::type* = nullptr>
  BinaryTree(T data);

  /**

  //Alternate Approach (to SFINAE) of checking whether given type is a pointer
  //by making a default second parameter

  //Overloaded parameterised constructor for non pointer
  template<typename TT = T>
  BinaryTree(T data,typename std::enable_if<!isPointer<TT>::value>::type * = nullptr);

  //Overloaded parameterised constructor for pointer
  template<typename TT = T>
  BinaryTree(T data,typename std::enable_if<isPointer<TT>::value>::type * = nullptr);

  **/

  // Overloaded copy constructor for non pointer
  // BinaryTree(BinaryTree&);
  template <typename TT = T, typename std::enable_if<!isPointer<TT>::value>::type* = nullptr>
  BinaryTree(BinaryTree&);

  // Overloaded copy constructor for pointer
  // BinaryTree(BinaryTree&);
  template <typename TT = T, typename std::enable_if<isPointer<TT>::value>::type* = nullptr>
  BinaryTree(BinaryTree&);

  virtual ~BinaryTree();

  /** ***********************************************************
         * 		Member Functions for T being a pointer type
         * **********************************************************/

  /** insert method complexity is N*N that N^2.
    * This is so because
    * Worst case scenario, to place Nth node it has to traverse N-(No of leave nodes) nodes
    */
  template <typename TT = T, typename std::enable_if<isPointer<TT>::value>::type* = nullptr>
  int insert(T data);

  /** Overloaded and Improved insert method which takes a buffer on input values (a std::queue)
    * And fills it in the empty spaces while traversing BFD
    * Complexity ?? (Probably should be better, like something around N+m,
    *                where N is total no. of nodes in tree and m total no of notes in queue)
    * Will test it by replacing it against the creatN method in memory benchmark
    */
  template <typename TT = T, typename std::enable_if<isPointer<TT>::value>::type* = nullptr>
  int insert(std::deque<T> stream);

  template <typename TT = T, typename std::enable_if<isPointer<TT>::value>::type* = nullptr>
  void insertInteractive(T (*process)(long id, bool& skip, bool& cont));

  template <typename TT = T, typename std::enable_if<isPointer<TT>::value>::type* = nullptr>
  void appendBack(BinaryTree&);

  template <typename TT = T, typename std::enable_if<isPointer<TT>::value>::type* = nullptr, typename Compare>
  void deleteNodeGivenDataApproach1(T data, Compare comp)
  {
    if (isPointer<T>::value == true)
      {
#ifdef DEBUG
        std::cout << "\npointer T" << std::endl;
#endif
      }
    if (isPointer<TT>::value == true)
      {
#ifdef DEBUG
        std::cout << "\npointer TT" << std::endl;
#endif
      }
    if (isPointer<Compare>::value == true)
      {
#ifdef DEBUG
        std::cout << "\npointer Compare" << std::endl;
#endif
      }
    /// TODO
  }

  template <typename TT = T, typename std::enable_if<isPointer<TT>::value>::type* = nullptr, typename Compare>
  void deleteNodeGivenDataApproach2(T data, Compare comp)
  {
    /// TODO
  }
  /** **************************************************
   * 	Member Function for T being a non pointer type
   * ***************************************************/

  template <typename TT = T, typename std::enable_if<!isPointer<TT>::value>::type* = nullptr>
  void insert(T data);

  template <typename TT = T, typename std::enable_if<!isPointer<TT>::value>::type* = nullptr>
  void insert(std::deque<T> stream);

  template <typename TT = T, typename std::enable_if<!isPointer<TT>::value>::type* = nullptr>
  void insertInteractive(T (*process)(long id, bool& skip, bool& cont));

  template <typename TT = T, typename std::enable_if<!isPointer<TT>::value>::type* = nullptr>
  void appendBack(BinaryTree&);

  template <typename TT = T, typename std::enable_if<!isPointer<TT>::value>::type* = nullptr>
  void clear();

  /** Time Complexity
   * Worst Case = O(N)
   *
   * Considering Complete Binary Tree
   * Average Case = O(Max(N,M)) (More like O(Max(N-(N-x),M-y),
   * 						where x is the id of node's parent & y is the level of node.)
   *
   * Considering Complete Binary Tree
   * Best Case = O(M)
   *
   * where, N = Total Number of Nodes
   *        M = Total Number of Levels
   * */
  template <typename TT = T, typename std::enable_if<!isPointer<TT>::value>::type* = nullptr, typename Compare>
  void deleteNodeGivenDataApproach1(T data, Compare comp);

  /** Time Complexity
 * Worst Case = O(N)
 *
 * Considering Complete Binary Tree
 * Average Case = O(N+M) (More like O(N-(N-x),M-y),
 * 						where x is the id of node's parent & y is the level of node.)
 *
 * Considering Complete Binary Tree
 * Best Case = O(M)
 *
 * where, N = Total Number of Nodes
 *        M = Total Number of Levels
 * */
  template <typename TT = T, typename std::enable_if<!isPointer<TT>::value>::type* = nullptr, typename Compare>
  void deleteNodeGivenDataApproach2(T data, Compare comp);

  /** Warning only for benchmarking */
  void createN(unsigned long n);

  protected:
  struct Node
  {
    unsigned long id;
    T data;
    Node* left = nullptr;
    Node* right = nullptr;
  };

  Node* root;

  long id, totalNodes;
};

#endif  // BINARYTREE_H
