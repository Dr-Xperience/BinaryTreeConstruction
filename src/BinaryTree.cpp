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
#include<iostream>
#endif // DEBUG

#include <queue>
#include "BinaryTree.h"

/** Total Code re-base Now node will be integral part of BinaryTree
  * And T will signify the datatype of Node's data
  * Tree may take nullptr as data, if and only if T is of T* i.e. pointer type
  * Each node will be given id of long type (I am not sure about this)
  * Warning The createN function is just for benchmarking purpose
**/

/** To check whether the given Type T is a pointer **/

//template<class T>
//struct isPointer
//{
//    static const bool value=false;
//};
//
//template<class T>
//struct isPointer<T*>
//{
//    static const bool value=true;
//};

template<class T>
BinaryTree<T>::BinaryTree():root(nullptr)
{
    //ctor
}

//Parameterized Constructor for taking in just root
//Overloaded to differentiate between pointer type and normal
template <class T> template<typename TT>
BinaryTree<T>::BinaryTree(TT data, typename std::enable_if<!isPointer<TT>::value>::type* a)
{
            this->root = new Node;
            this->root->id =1;
            this->root->data=data;
            this->root->left=this->root->right=nullptr;
            this->id=this->totalNodes=1;
}

template <class T> template<typename TT>
BinaryTree<T>::BinaryTree(TT data, typename std::enable_if<isPointer<TT>::value>::type * a)
{

        if(data != nullptr)
        {
            this->root = new Node;
            this->root->id =1;
            this->root->data=data;
            this->root->left=this->root->right=nullptr;
            this->id=this->totalNodes=1;
        }

}


//Copy Constructor
//Parametrized Constructor for taking in a BinaryTree root (data or T being a pointer)
template<class T> template<typename TT>
BinaryTree<T>::BinaryTree(BinaryTree<T>& b,typename std::enable_if<isPointer<TT>::value>::type* a)
{
#ifdef DEBUG
    long counter=0;
#endif // DEBUG

    if(b.root ==nullptr || b.root->data ==nullptr)
        return; //throw some sort of exception

    std::queue<Node *> q,q1;
    Node* root,root1,temp;

    bool isRoot=false;

    this.id=b.id;
    this.totalNodes=b.totalNodes;
    do{

        if(this->root == nullptr)
        {
            this->root = new Node;
            *(this->root)=*(b.root);
            root = this->root;

            q.push(root);
            q1.push(b.root);

            while(!q1.empty())
            {
                root = q.front();
                q.pop();
                root1 = q1.front();
                q1.pop();

                if(root1->left != nullptr)
                {
                    temp=new Node;
                    *(temp) = *(root1->left);
                    temp->left=temp->right=nullptr;
                    root->left = temp;

                    q.push(root->left);
                    q1.push(root1->left);
                }

                if(root1->right != nullptr)
                {
                    temp=new Node;
                    *(temp) = *(root1->right);
                    temp->left=temp->right=nullptr;
                    root->right = temp;

                    q.push(root->right);
                    q1.push(root1->right);
                }

            }

            isRoot=false;
        }
        else
        {
            //delete old tree before copying
            root=this->root;
            q.push(root);

            while(!q.empty())
            {
                root=q.front();
                q.pop();

                if(root->left !=nullptr)
                {
                    q.push(root->left);
                }

                if(root->right != nullptr)
                {
                    q.push(root->right);
                }

                delete root;
            }
            isRoot=true;
        }
    }while(isRoot==true);

#ifdef DEBUG
    std::cout<<std::endl<<"Insertion Loop Counter :: "<<counter<<std::endl;
#endif // DEBUG

}

//Copy Constructor
//Parametrized Constructor for taking in a BinaryTree root (data or T being a non pointer)
template<class T> template<typename TT>
BinaryTree<T>::BinaryTree(BinaryTree<T>& b,typename std::enable_if<!isPointer<TT>::value>::type* a)
{
#ifdef DEBUG
    long counter=0;
#endif // DEBUG

    if(b.root ==nullptr)
        return; //throw some sort of exception

    std::queue<Node *> q,q1;
    Node* root,root1,temp;

    bool isRoot=false;

    this.id=b.id;
    this.totalNodes=b.totalNodes;
    do{

        if(this->root == nullptr)
        {
            this->root = new Node;
            *(this->root)=*(b.root);
            root = this->root;

            q.push(root);
            q1.push(b.root);

            while(!q1.empty())
            {
                root = q.front();
                q.pop();
                root1 = q1.front();
                q1.pop();

                if(root1->left != nullptr)
                {
                    temp=new Node;
                    *(temp) = *(root1->left);
                    temp->left=temp->right=nullptr;
                    root->left = temp;

                    q.push(root->left);
                    q1.push(root1->left);
                }

                if(root1->right != nullptr)
                {
                    temp=new Node;
                    *(temp) = *(root1->right);
                    temp->left=temp->right=nullptr;
                    root->right = temp;

                    q.push(root->right);
                    q1.push(root1->right);
                }

            }

            isRoot=false;
        }
        else
        {
            //delete old tree before copying
            root=this->root;
            q.push(root);

            while(!q.empty())
            {
                root=q.front();
                q.pop();

                if(root->left !=nullptr)
                {
                    q.push(root->left);
                }

                if(root->right != nullptr)
                {
                    q.push(root->right);
                }

                delete root;
            }
            isRoot=true;
        }
    }while(isRoot==true);

#ifdef DEBUG
    std::cout<<std::endl<<"Insertion Loop Counter :: "<<counter<<std::endl;
#endif // DEBUG

}

//Move constructorHere
/**
{
    #ifdef DEBUG
    long counter=0;
    #endif // DEBUG

    std::queue<Node *> q,q1;


    this->root = new Node;
    this->root->data=data;
    Node* root = this->root;
    q.push(root);
    q1.push(root1);

    while(!q1.empty())
    {
        #ifdef DEBUG
        counter++;
        #endif // DEBUG

        root1 = q1.front(); q1.pop();
        root = new Type;
        root = q.front(); q.pop();

        if(root1->left != nullptr)
         {
             root->left=root1->left;
             q1.push(root1->left);q.push(root->left);
         }

         if(root1->right != nullptr)
         {
             root->right=root1->right;
             q1.push(root1->right);q.push(root->right);
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
    //dtor
}


/******************************************************************
 *
 *                Member Functions for pointer
 *
 *******************************************************************/

/**
 insert at first blank location found in tree
**/

template <class T> template <typename TT>
int BinaryTree<T>::insert(TT data,typename std::enable_if<isPointer<TT>::value>::type *a)
{

    if(this->root == nullptr )
    {

            if(data == nullptr)
            {
                return -1;
            }

        this->root = new Node;
        this->root->id=1;
        this->root->data=data;
        this->root->left=this->root->right=nullptr;
        this->id=this->totalNodes=1;
        return;
    }
//    if(data ==nullptr)
//    {
//         id++;
//         return;
//    }
//
    Node * root=this->root,*temp;

    std::queue<Node*> q;

    q.push(root);

    while(!q.empty())
    {
        root=q.front();q.pop();

        if(root->left != nullptr)
        {
            q.push(root->left);
        }
        else
        {
            if(data == nullptr)
                return -1;
            temp = new Node;
            temp->id=root.id*2;
            temp->data=data;
            temp->left=temp->right=nullptr;

            root->left=temp;
            this->totalNodes++;
            break;
        }

        if(root->right != nullptr)
        {
            q.push(root->right);
        }
        else
        {
            if(data == nullptr)
                return -1;
            temp = new Node;
            temp->id=(root.id*2)+1;
            temp->data=data;
            temp->left=temp->right=nullptr;

            root->right=temp;
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

template<class T> template <typename TT>
int BinaryTree<T>::insert(std::queue<TT> stream, typename std::enable_if<isPointer<TT>::value>::type *a)
{
    #ifdef DEBUG
    long counter=0;
    #endif // DEBUG

    if(this->root == nullptr )
    {
        if(stream.empty() || stream.front() == nullptr)
        {
            return -1;
        }

        this->root = new Node;
        this->root->id=1;
        this->root->data=stream.front();
        stream.pop();
        this->root->left=this->root->right=nullptr;
        this->id=this->totalNodes=1;
    }
//    if(data ==nullptr)
//    {
//         id++;
//         return;
//    }
//
    Node * root=this->root,*temp;

    std::queue<Node*> q;

    q.push(root);

    while(!stream.empty())
    {
        #ifdef DEBUG
        counter++;
        #endif // DEBUG

        root=q.front();q.pop();

        if(root->left != nullptr)
        {
            q.push(root->left);
        }
        else
        {
            if(stream.front == nullptr)
                return -1;
            temp = new Node;
            temp->id=root.id*2;
            temp->data=stream.front();
            stream.pop();
            temp->left=temp->right=nullptr;
            root->left=temp;

            q.push(root->left);
            this->totalNodes++;
        }

        if(root->right != nullptr)
        {
            q.push(root->right);
        }
        else
        {
            if(stream.front == nullptr)
                return -1;
            temp = new Node;
            temp->id=(root.id*2)+1;
            temp->data=stream.front();
            stream.pop();
            temp->left=temp->right=nullptr;
            root->right=temp;

            q.push(root->right);
            this->totalNodes++;
        }
    }

    #ifdef DEBUG
    std::cout<<std::endl<<"Insertion Loop Counter :: "<<counter<<std::endl;
    #endif // DEBUG

 return 0;
}
template <class T> template <typename TT>
void BinaryTree<T>::insertInteractive(T (*process)(long id,bool& skip,bool& cont),typename std::enable_if<isPointer<TT>::value>::type *a)
{
    Node* root,*temp;
    T data;
    long id=1;
    bool cont=true,skip=false;

    if(this->root == nullptr )
    {
        data = process(1,skip,cont);

            if(data == nullptr || skip==true)
            {
                return;
            }


        this->root = new Node;
        this->root->id=1;
        this->root->data=data;
        this->root->left=this->root->right=nullptr;
        this->id=this->totalNodes=1;
    }

   root=this->root;
   std::queue<Node*> q;

    q.push(root);

    while(cont==true && !q.empty())
    {
        root=q.front(); q.pop();

        if(root->left != nullptr)
        {
            q.push(root->left);
        }
        else
        {
           data = process(root->id*2,skip,cont);

            if(skip!=true || data != nullptr)
            {
                temp = new Node;
                temp->id = (root->id)*2;
                temp->data = data;
                temp->left=temp->right=nullptr;
                root->left=temp;
                q.push(root->left);
            }
        }

        if(root->right != nullptr)
        {
            q.push(root->right);
        }
        else
        {
           data = process((root->id*2)+1,skip,cont);

            if(skip==true || data == nullptr)
            {
                temp = new Node;
                temp->id = ((root->id)*2)+1;
                temp->data = data;
                temp->left=temp->right=nullptr;
                root->right=temp;
                q.push(root->right);
            }
        }
    }
}

/**
 appendBack create a full binary tree. It takes root of any binary tree and forms a full/complete binary tree from it
**/

template <class T> template<typename TT>
void BinaryTree<T>::appendBack(BinaryTree<T>& b, typename std::enable_if<isPointer<TT>::value>::type *a)
{
#ifdef DEBUG
    long counter=0;
#endif // DEBUG


    std::queue<Node*> q,q1;
    Node * root,root1,temp;

    if(this->root == nullptr)
    {
        this->root = new Node;
        *(this->root)=*(b.root);
        this->root->id=1;
        this->root->left=nullptr;
        this->root->right=nullptr;

        root=this->root;
        q.push(root);

        if(root->left != nullptr)
        {
            q1.push(b.root->left);
        }
        else if(root->right != nullptr)
        {
            q1.push(b.root->right);
        }

    }
    else
    {
        root=this->root;
        q.push(root);
        q1.push(b.root);
    }


    while(!q1.empty())
    {
#ifdef DEBUG
        counter++;
#endif // DEBUG

        root = q.front();
        q.pop();

        if(root->left != nullptr)
        {
            q.push(root->left);
        }
        else
        {
            root1 = q1.front();
            q1.pop();
            root1.id=root.id*2;
            temp = new Node;
            *temp = *root1;
            temp->left = nullptr;
            temp->right = nullptr;

            root->left=temp;
            q.push(root->left);

            if(root1->left!=nullptr)
            {
                q1.push(root1->left);
            }
            if(root1->right!=nullptr)
            {
                q1.push(root1->right);
            }
        }

        if(root->right != nullptr)
        {
            q.push(root->right);
        }
        else
        {
            if(q1.empty())
                break;
            root1 = q1.front();
            q1.pop();
            root1.id=(root.id*2)+1;
            temp = new Node;
            *temp = *root1;
            temp->left = nullptr;
            temp->right = nullptr;

            root-> right = temp;
            q.push(root->right);

            if(root1->left!=nullptr)
            {
                q1.push(root1->left);
            }
            if(root1->right!=nullptr)
            {
                q1.push(root1->right);
            }
        }
    }

#ifdef DEBUG
    std::cout<<std::endl<<"Insertion Loop Counter :: "<<counter<<std::endl;
#endif // DEBUG
}


/******************************************************************
 *
 *                Member Functions for non pointer
 *
 *******************************************************************/

/**
 insert at first blank location found in tree
**/

template <class T> template<typename TT>
void BinaryTree<T>::insert(TT data, typename std::enable_if<!isPointer<TT>::value>::type *a)
{

    if(this->root == nullptr )
    {
        this->root = new Node;
        this->root->id=1;
        this->root->data=data;
        this->root->left=this->root->right=nullptr;
        this->id=this->totalNodes=1;
        return;
    }
//    if(data ==nullptr)
//    {
//         id++;
//         return;
//    }
//
    Node * root=this->root,*temp;

    std::queue<Node*> q;

    q.push(root);

    while(!q.empty())
    {
        root=q.front();q.pop();

        if(root->left != nullptr)
        {
            q.push(root->left);
        }
        else
        {
            temp = new Node;
            temp->id=root->id*2;
            temp->data=data;
            temp->left=temp->right=nullptr;

            root->left=temp;
            this->totalNodes++;
            break;
        }

        if(root->right != nullptr)
        {
            q.push(root->right);
        }
        else
        {
            temp = new Node;
            temp->id=(root->id*2)+1;
            temp->data=data;
            temp->left=temp->right=nullptr;

            root->right=temp;
            this->totalNodes++;
            break;
        }
    }

}

template<class T> template <typename TT>
void BinaryTree<T>::insert(std::queue<TT> stream, typename std::enable_if<!isPointer<TT>::value>::type *a)
{
    #ifdef DEBUG
    long counter=0;
    #endif // DEBUG

    if(this->root == nullptr )
    {
        this->root = new Node;
        this->root->id=1;
        this->root->data=stream.front();
        stream.pop();
        this->root->left=this->root->right=nullptr;
        this->id=this->totalNodes=1;
    }
//    if(data ==nullptr)
//    {
//         id++;
//         return;
//    }
//
    Node * root=this->root,*temp;

    std::queue<Node*> q;

    q.push(root);

    while(!stream.empty())
    {
        #ifdef DEBUG
        counter++;
        #endif // DEBUG

        root=q.front();q.pop();

        if(root->left != nullptr)
        {
            q.push(root->left);
        }
        else
        {
            temp = new Node;
            temp->id=root->id*2;
            temp->data=stream.front();
            stream.pop();
            temp->left=temp->right=nullptr;
            root->left=temp;

            q.push(root->left);
            this->totalNodes++;
        }

        if(root->right != nullptr)
        {
            q.push(root->right);
        }
        else
        {
            temp = new Node;
            temp->id=(root->id*2)+1;
            temp->data=stream.front();
            stream.pop();
            temp->left=temp->right=nullptr;
            root->right=temp;

            q.push(root->right);
            this->totalNodes++;
        }
    }

#ifdef DEBUG
std::cout<<std::endl<<"Insertion Loop Counter :: "<<counter<<std::endl;
#endif // DEBUG
}

template <class T> template <typename TT>
void BinaryTree<T>::insertInteractive(T (*process)(long id,bool& skip,bool& cont), typename std::enable_if<!isPointer<TT>::value>::type *a)
{
    Node* root,*temp;
    T data;
//    long id=1;
    bool cont=true,skip=false;

    if(this->root == nullptr )
    {
        data = process(1,skip,cont);

        if(skip==true)
        {
            return;
        }

        this->root = new Node;
        this->root->id=1;
        this->root->data=data;
        this->root->left=this->root->right=nullptr;
        this->id=this->totalNodes=1;
    }

   root = this->root;
   std::queue<Node*> q;

    q.push(root);

    while(cont==true && !q.empty())
    {
        root=q.front();q.pop();

        if(root->left != nullptr)
        {
            q.push(root->left);
        }
        else
        {
            data = process(root->id*2,skip,cont);

            if(skip==false)
            {
                temp = new Node;
                temp->id = (root->id)*2;
                temp->data = data;
                temp->left=temp->right=nullptr;
                root->left = temp;
                q.push(root->left);
            }
        }

        if(root->right != nullptr)
        {
            q.push(root->right);
        }
        else
        {
            data = process((root->id*2)+1,skip,cont);

            if(skip==false)
            {
                temp = new Node;
                temp->id = ((root->id)*2)+1;
                temp->data = data;
                temp->left=temp->right=nullptr;
                root->right = temp;
                q.push(root->right);
            }
        }
    }
}

/**
 appendBack create a full binary tree. It takes root of any binary tree and forms a full/complete binary tree from it
**/

template <class T> template<typename TT>
void BinaryTree<T>::appendBack(BinaryTree<T>& b, typename std::enable_if<!isPointer<TT>::value>::type* a)
{
#ifdef DEBUG
    long counter=0;
#endif // DEBUG


    std::queue<Node*> q,q1;
    Node * root,root1,temp;

    if(this->root == nullptr)
    {
        this->root = new Node;
        *(this->root)=*(b.root);
        this->root->id=1;
        this->root->left=nullptr;
        this->root->right=nullptr;

        root=this->root;
        q.push(root);

        if(root->left != nullptr)
        {
            q1.push(b.root->left);
        }
        else if(root->right != nullptr)
        {
            q1.push(b.root->right);
        }

    }
    else
    {
        root=this->root;
        q.push(root);
        q1.push(b.root);
    }


    while(!q1.empty())
    {
#ifdef DEBUG
        counter++;
#endif // DEBUG

        root = q.front();
        q.pop();

        if(root->left != nullptr)
        {
            q.push(root->left);
        }
        else
        {
            root1 = q1.front();
            q1.pop();
            root1.id=root.id*2;
            temp = new Node;
            *temp = *root1;
            temp->left = nullptr;
            temp->right = nullptr;

            root->left=temp;
            q.push(root->left);

            if(root1->left!=nullptr)
            {
                q1.push(root1->left);
            }
            if(root1->right!=nullptr)
            {
                q1.push(root1->right);
            }
        }

        if(root->right != nullptr)
        {
            q.push(root->right);
        }
        else
        {
            if(q1.empty())
                break;
            root1 = q1.front();
            q1.pop();
            root1.id=(root.id*2)+1;
            temp = new Node;
            *temp = *root1;
            temp->left = nullptr;
            temp->right = nullptr;

            root-> right = temp;
            q.push(root->right);

            if(root1->left!=nullptr)
            {
                q1.push(root1->left);
            }
            if(root1->right!=nullptr)
            {
                q1.push(root1->right);
            }
        }
    }

#ifdef DEBUG
    std::cout<<std::endl<<"Insertion Loop Counter :: "<<counter<<std::endl;
#endif // DEBUG
}

template <class T>
void BinaryTree<T>::createN(unsigned long N)
{

    this->root = new Node;
    this->root->id=1;
    this->root->data=1;
    this->root->left=this->root->right=nullptr;
    this->id=this->totalNodes=1;

    Node * root=this->root,*temp;

    std::queue<Node*> q;

    q.push(root);

    while(!q.empty())
    {
        root=q.front();
        q.pop();

        if(root->id>=N)
            break;

        if(root->left != nullptr)
        {
            q.push(root->left);
        }
        else
        {
            temp = new Node;
            temp->id=temp->data=root->id*2;
            temp->left=temp->right=nullptr;
            root->left=temp;
            q.push(root->left);
            this->totalNodes++;

        }

        if(root->right != nullptr)
        {
            q.push(root->right);
        }
        else
        {
            temp = new Node;
            temp->id=temp->data=(root->id*2)+1;
            temp->left=temp->right=nullptr;
            root->right=temp;
            q.push(root->right);
            this->totalNodes++;
        }
    }
}

#endif // BINARYTREE_CPP
