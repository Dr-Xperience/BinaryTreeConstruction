#ifndef BINARYTREE_CPP
#define BINARYTREE_CPP

#ifdef DEBUG
#include<iostream>
#endif // DEBUG

#include <queue>
#include "BinaryTree.h"

template <typename T>
struct RemovePointer
{
    typedef T type;
};

template <typename T>
struct RemovePointer<T*>
{
    typedef T type;
};

template<class T>
BinaryTree<T>::BinaryTree():root(nullptr)
{
    //ctor
}
template<class T>
BinaryTree<T>::BinaryTree(T root1)
{
    #ifdef DEBUG
    long counter=0;
    #endif // DEBUG

    std::queue<T> q,q1;

    typedef typename RemovePointer<T>::type Type;

    this->root = new Type;
    *(this->root)=*root1;
    T root = this->root;
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

template <class T>
BinaryTree<T>::~BinaryTree()
{
    //dtor
}

template <class T>
void BinaryTree<T>::insertBack(T root1)
{
    #ifdef DEBUG
    long counter=0;
    #endif // DEBUG

    typedef typename RemovePointer<T>::type Type;
    std::queue<T> q,q1;

    if(this->root == nullptr)
     {
         this->root = new Type;
         *(this->root)=*root1;
     }
    T root = this->root;

    q.push(root);
    q1.push(root1);

    while(!q1.empty())
    {
        #ifdef DEBUG
        counter++;
        #endif // DEBUG

        root = q.front(); q.pop();

        if(root->left != nullptr)
        {
            q.push(root->left);
        }
        else
        {
            root1 = q1.front(); q1.pop();
            T temp = new Type;
            *temp = *root1;
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
            root1 = q1.front(); q1.pop();
            T temp = new Type;
            *temp = *root1;
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
#endif // BINARYTREE_CPP
