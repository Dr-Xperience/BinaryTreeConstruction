/****************************************************************************
    Cached_Heap (Linked List implementation of heap with array cache)
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
