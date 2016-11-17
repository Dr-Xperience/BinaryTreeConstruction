#ifndef BINARYTREE_H
#define BINARYTREE_H

template <class T>
class BinaryTree
{

    public:

        //Constructor
        BinaryTree();
        BinaryTree(T);
        virtual ~BinaryTree();

        //Member Function
        void insertBack(T);

    protected:
        T root;
    private:

};

#endif // BINARYTREE_H
