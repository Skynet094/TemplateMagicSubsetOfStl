#include "Stack.h"
#include <iostream>
#ifndef PRIORITY_QUEUE_INCLUDED
#define PRIORTIY_QUEUE_INCLUDED

/** This header includes the priorty queue template, which has heap as it's internal data structure.

The available built in function are (taking 'T' as the template data type)-
    i)void push(T data)
    ii)T top() //this function returns the highest priority element
    iii)void pop() //this function removes the highest priority element
    iv)bool empty() //this function returns a bool value which denotes whether the container is empty
    v)int size() //this function returns the size

**/

/**
    CONSTRAINS TO BE NOTED:

    i) The template types *must* have a blank parametrized constructor //for array creation
    ii) The template types should have ">" operator function overloaded //this is used for comparison purposes

**/


namespace project{
template<typename T>
struct binaryTree
{
       struct binaryTree* parent;
       T element;
       struct binaryTree* leftchild;
       struct binaryTree* rightchild;
       int height;
};

template<typename T>
class priorityQueue
{
       struct binaryTree<T>* root;
       Stack<struct binaryTree<T>*>* list;
       struct binaryTree<T>* tempTree;
       T temp;
       T tmp;
public:
    priorityQueue()
    {
        root = NULL;
        list = new Stack<struct binaryTree<T>*>;
    }
    void insert(T element, struct binaryTree<T>* tree = NULL)
    {
        if (tree == NULL)
        {
                    tree = root;
                    if (tree == NULL)
                    {
                        root = new struct binaryTree<T>;
                        list->push(root);
                        root->parent = NULL;
                        root->leftchild = NULL;
                        root->rightchild = NULL;
                        root->element = element;
                        root->height = 0;
                        return;
                     }
            }
            if (tree->leftchild != NULL && tree->rightchild != NULL)
            {
               if (tree->leftchild->height > tree->rightchild->height)
               {
                   insert(element, tree->rightchild);
               }
               else
               {
                   insert(element, tree->leftchild);
               }
            }
            else if (tree->leftchild == NULL)
            {
               tree->leftchild = new struct binaryTree<T>;
               list->push(tree->leftchild);
               tree->leftchild->parent = tree;
               tree->leftchild->leftchild = NULL;
               tree->leftchild->rightchild = NULL;
               tree->leftchild->element = element;
               tree->leftchild->height = 0;
               maxheapify(tree->leftchild);
               return;
            }
            else if (tree->rightchild == NULL)
            {
               tree->rightchild = new struct binaryTree<T>;
               list->push(tree->rightchild);
               tree->rightchild->parent = tree;
               tree->rightchild->leftchild = NULL;
               tree->rightchild->rightchild = NULL;
               tree->rightchild->element = element;
               tree->rightchild->height = 0;
               maxheapify(tree->rightchild);
               while(tree->parent!=NULL)
               {
                  if (tree->leftchild->height != tree->rightchild->height)
                  {
                      break;
                  }
                  tree->height++;
                  tree = tree->parent;
               }
               return;
            }
    }
    struct binaryTree<T>* getRoot()
    {
              return root;
    }
    Stack<struct binaryTree<T>*>* getStack()
    {
           return list;
    }
    void maxheapify(struct binaryTree<T>* tree)
    {
            if (tree->parent != NULL)
            {
               if (tree->element > tree->parent->element)
               {
                  temp = tree->parent->element;
                  tree->parent->element = tree->element;
                  tree->element = temp;
               }
               maxheapify(tree->parent);
            }
            return;
    }
    void downmaxheapify(struct binaryTree<T>* root)
    {
        if ((root->leftchild != NULL)&&(root->rightchild != NULL))
        {
            if (root->leftchild->element > root->rightchild->element)
            {
                if (root->leftchild->element > root->element)
                {
                    tmp = root->element;
                    root->element = root->leftchild->element;
                    root->leftchild->element = tmp;
                    downmaxheapify(root->leftchild);
                    return;
                }
                return;
            }
            if (root->rightchild->element >= root->leftchild->element)
            {
                if (root->rightchild->element > root->element)
                {
                    tmp = root->element;
                    root->element = root->rightchild->element;
                    root->rightchild->element = tmp;
                    downmaxheapify(root->rightchild);
                    return;
                }
                return;
            }
            return;
        }
        return;
    }
    void remove()
    {
        if (root == NULL){}
        else if(root->leftchild == NULL)
        {
            delete root;
            root = NULL;
        }
        else
        {
            tempTree = list->top();
            list->pop();
            root->element = tempTree->element;
            if (tempTree->parent->rightchild == NULL)
            {
                tempTree->parent->leftchild = NULL;
            }
            else
            {
                tempTree->parent->rightchild = NULL;
            }
            delete tempTree;
            downmaxheapify(root);
        }
    }
    T top()
    {
         try{
               return root->element;
         }
         catch(std::exception& ex){
               if (root == NULL)
               {
                  std::cout << "Queue is empty" ;
                  exit(1);
               }
         }
    }
};
}
#endif







