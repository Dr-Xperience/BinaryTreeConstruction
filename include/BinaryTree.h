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

/** Total Code re-base Now node will be integral part of BinaryTree
  * And T will signify the datatype of Node's data
  * Tree may take nullptr as data, if and only if T is of T* i.e. pointer type
  * Each node will be given id of long type (I am not sure about this)
  * Warning The createN function is just for benchmarking purpose
**/

/** To check whether the given Type T is a pointer **/

template<class T>
struct isPointer
{
    static const bool value=false;
};

template<class T>
struct isPointer<T*>
{
    static const bool value=true;
};

template <class T>
class BinaryTree
{
private:


public:

    //Constructor
    BinaryTree();

    //Overloaded parameterised constructor for non pointer
    template<typename TT = T>
    BinaryTree(TT, typename std::enable_if<!isPointer<TT>::value>::type * = nullptr);

    //Overloaded parameterised constructor for pointer
    template<typename TT = T>
    BinaryTree(TT data, typename std::enable_if<isPointer<TT>::value>::type * = nullptr);

    //Overloaded copy constructor for non pointer
    //BinaryTree(BinaryTree&);
    template<typename TT = T>
    BinaryTree(BinaryTree&, typename std::enable_if<!isPointer<TT>::value>::type * = nullptr);

    //Overloaded copy constructor for pointer
    //BinaryTree(BinaryTree&);
    template<typename TT = T>
    BinaryTree(BinaryTree&, typename std::enable_if<isPointer<TT>::value>::type * = nullptr);

    virtual ~BinaryTree();

    //Member Function for T being a pointer type
    /** insert method complexity is N*N that N^2.
      * This is so because
      * Worst case scenario, to place Nth node it has to traverse N-(No of leave nodes) nodes
      */
    template<typename TT = T>
    void insert(TT data,typename std::enable_if<isPointer<TT>::value>::type * = nullptr);

    template<typename TT = T>
    void insertInteractive(T (*process)(long id,bool& skip,bool& cont),typename std::enable_if<isPointer<TT>::value>::type * = nullptr);

    template<typename TT = T>
    void appendBack(BinaryTree&,typename std::enable_if<isPointer<TT>::value>::type * = nullptr);

    //Member Function for T being a non pointer type
    template<typename TT = T>
    void insert(TT data,typename std::enable_if<!isPointer<TT>::value>::type * = nullptr);

    template<typename TT = T>
    void insertInteractive(T (*process)(long id,bool& skip,bool& cont),typename std::enable_if<!isPointer<TT>::value>::type * = nullptr);

    template<typename TT = T>
    void appendBack(BinaryTree&,typename std::enable_if<!isPointer<TT>::value>::type * = nullptr);

    /** Warning only for benchmarking */
    void createN(long n);

protected:

    struct Node
    {
        long id;
        T data;
        Node * left = nullptr;
        Node * right = nullptr;
    };

    Node* root;

    long id,totalNodes;

};

#endif // BINARYTREE_H
