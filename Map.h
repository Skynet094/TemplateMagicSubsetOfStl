#ifndef MAP_HEADER_INCLUDED
#define MAP_HEADER_INCLUDED

#include<typeinfo>
#include<iostream>
#include<cstdlib>
#include<cstring>


//THIS VERSION OF MAP USES AVL TREE AS INTERNAL DATA STRUCTURE SO, FOR INSERTION AND SEARCH WORST CASE COMPLEXITY IS nlogn

/**
THIS IMPLEMENT OF MAP REQUIRES THAT EVERY OBJECT WHICH WILL BE USED AS  INDEX OR KEY_VALUE *MUST* HAVE THREE OPERATORS OVERLOADED
   THOSE ARE:-
   i)== operator
   ii)< operator
   iii)> operator
**/


/**
    In templated map data structure, one object can be mapped to another object provided that they have their necessary operators overloaded
    If T1 and T2 are two templated types and, ob1 and ob2 are their objects respectively, map allows us perform

    map<T1,T2> mapping;  mapping[ ob1 ] = ob2;

    for any valid index 'index', we can perform, mapping[ new_index ] = mapping[ index]

**/

namespace project{

    template<typename T1, typename T2> class map_{

    public:
        map_() {
            root = NULL;
        }


        T2& operator[](const T1 key1){
            keeper=NULL;

            find_node(root,key1);
            if(keeper==NULL){
                insert_empty_node(key1);
                return hold_node->key2;
            }
            //else node found
            else
                return keeper->key2;
        }

        T2& operator=(const T2 key2){
            this->key2= key2;
            return *this;
        }
    private:
        struct avl_node{
            avl_node* left_child;
            avl_node* right_child;
            T1 key1;
            T2 key2;
            int height;
        };

        void preorder_print(avl_node* root){  // I WILL USE THIS TO CREATE THE ITERATOR FOR MAP CLASS
            if(root==NULL)
                return;

            preorder_print(root->left_child);
            cout<<root->key1<<" "<<root->key2<<endl;
            preorder_print(root->right_child);
            return;

        }

    private:

        avl_node* root;
        avl_node* hold_node;
        avl_node* keeper;



        avl_node* new_node(T1 key1){
            avl_node* temp=new avl_node();
            temp->left_child=NULL;
            temp->right_child=NULL;
            temp->key1=key1;

            temp->height=1;
            return temp;
        }

        int height(avl_node* node){
            if(node==NULL)
                return 0;
            return node->height;
        }

        int get_balance(avl_node* node){
            if(node==NULL) return 0;
            return height(node->left_child) - height(node->right_child);
        }


        avl_node* right_rotate(avl_node* cur_parent){
                //in right_child rotate, cur_parent becomes the left_child child of it's right_child child, and the left_child of the right_child
                //becomes the right_child  of the previously parent

                //THIS FUNCTION DEALS WITH THE LEFT SUBTREE, ALL THE KEYS IN THE LEFT SUBTREE ARE LESS THAN THE ROOT OF THE LEFT SUBTREE
                avl_node* new_parent=cur_parent->left_child;
                avl_node* new_child=new_parent->right_child;

                new_parent->right_child=cur_parent; //right rotation //key at new_parent < key at cur_parent, cause it's left subtree
                cur_parent->left_child=new_child;            //as we inserted the cur_parent as the right child of new_parent, we have to place the right
                                            //child to somewhere, right? this goes as the left child of the cur_parent, BST property is retained after this rotation
                //UPDATING THE HEIGHT OF THE NODE

                cur_parent->height= max_(height(cur_parent->left_child), height(cur_parent->right_child)) + 1;
                new_parent->height= max_(height(new_parent->left_child), height(new_parent->right_child))+ 1;

                return new_parent; //returing the new root of the left subtree
        }

        //similar like right_rotate(node)

        avl_node* left_rotate(avl_node* cur_parent){
            avl_node* new_parent=cur_parent->right_child;
            avl_node* new_child=new_parent->left_child;

            new_parent->left_child=cur_parent;
            cur_parent->right_child=new_child;

            //UPDATING THE HEIGHTS
        //this update order is important , because the cur_parent is a child of new_parent now
            cur_parent->height= max_(height(cur_parent->left_child), height(cur_parent->right_child)) + 1;
            new_parent->height= max_(height(new_parent->left_child), height(new_parent->right_child)) + 1;

            return new_parent;
        }

        void insert_pair(T1 ob1, T2 ob2){
            root= insert(root, ob1);
            hold_node->key2=ob2;

        }

        int max_(int a, int b)
        {
            return a>b ? a : b;
        }

        avl_node* insert(avl_node* node, T1 key1){
            //APPLYING NORMAL BST INSERTION
            if(node==NULL){
                   hold_node=new_node(key1);
                   return hold_node;
               }
            if(key1 < node->key1)
                node->left_child=insert(node->left_child,key1);
            else if(key1 > node->key1)
                node->right_child=insert(node->right_child,key1);

            //lets update the heights of the nodes

            node->height= max_(height(node->left_child), height(node->right_child)) + 1;
            int balance= get_balance(node);


            if(balance > 1 && key1 < (node->left_child)->key1)
                return right_rotate(node);// left left case

            else if(balance > 1 && key1 > (node->left_child)->key1){ //left right case
                node->left_child = left_rotate(node->left_child);
                return right_rotate(node);
            }

            else if(balance < -1 && key1 > (node->right_child)->key1) //right right case
                return left_rotate(node);

            else if(balance <-1 && key1 < (node->right_child)->key1){ //right left case,
                node->right_child= right_rotate(node->right_child);
                return left_rotate(node);
            }

            return node;
        }

        void find_node(avl_node* root, int key1){
            if(root==NULL)
                return;
            if(root-> key1 ==key1){
                keeper=root;
                return;
            }

            else if(key1 >root->key1 )
                find_node(root->right_child, key1);
            else if(key1 < root->key1)
                find_node(root->left_child, key1);
            return;
        }

        void insert_empty_node(int key1){
            root= insert(root, key1);
        }


    public:

        class iterator{

        public:
            typedef iterator self_type;
            typedef avl_node& reference;
            typedef avl_node* pointer;
            typedef std::forward_iterator_tag iterator_category;
            int count;
            typedef int difference_type;


            iterator() { _ptr=NULL; index=0; count=0; addressTable=NULL; i=NULL;}

            iterator(avl_node* node ,int flag)
            {
                count=0;
                index=0;
                _ptr=NULL;

                i = new self_type;
                node_count(node);
                addressTable= new pointer[count+1];

                preorder_addr_save(node);


                if(flag==0)
                    {
                    addressTable[index]=NULL;
                    index=0;
                    _ptr=addressTable[index];
                    }
                else
                {
                    _ptr=NULL;
                    addressTable[index]=NULL;
                }
            }


            iterator(const iterator& iter){
                 *this=iter;
            }
            ~iterator(){
                delete addressTable;
            }
            //preincrement
            self_type& operator++(){
                _ptr=addressTable[++index];
                return *this;
            }
            //postincrement
            self_type& operator++(int notused){
                *i=*this;
                _ptr=addressTable[++index];
                return *i;
            }
            self_type& operator+=(int offset){
                _ptr = addressTable[index+offset];
                index+=offset;
                return *this;
            }
            //predecrement
            self_type& operator--(){
                _ptr=addressTable[--index];
                return *this;
            }
            //postdecrement
            self_type& operator--(int notused){
                if(_ptr)*i=*this;
                _ptr=addressTable[--index];
                return *i;
            }
            self_type& operator-=(int offset){
                _ptr = addressTable[index-offset];
                index-=offset;
                return *this;
            }
            reference operator*(){
                return *_ptr;
            }
            operator pointer(){
                return _ptr;
            }
            pointer operator->(){
                return _ptr;
            }
            difference_type  operator-(const self_type right_side){
                return index - right_side.index;
            }
            difference_type operator+(const self_type right_side){
                return index+ right_side.index;
            }
            bool operator==(const self_type &right_side) const{
                return _ptr==right_side._ptr;
            }
            bool operator!=(const self_type &right_side) const{
                return _ptr!=right_side._ptr;
            }
            self_type& operator=(const self_type& iter){

                _ptr=iter._ptr;

                addressTable=new pointer[iter.count +1 ];

                for(int i=0;i<iter.count + 1;i++)
                    addressTable[i]=iter.addressTable[i];

                index=iter.index;
                count = iter.count;
                i = iter.i;
                return *this;
            }

            difference_type _index(){
                return index;
            }
            void node_count(avl_node* node){
                if(node==NULL)
                    return;
                node_count(node->left_child);
                count++;
                node_count(node->right_child);
            }

            void preorder_addr_save(avl_node* node){
                if(node==NULL)
                    return;
                preorder_addr_save(node->left_child);
                addressTable[index++]=node;
                preorder_addr_save(node->right_child);
            }
        private:
            pointer _ptr;
            self_type* i;
            int index;
            pointer* addressTable;
        };


    iterator begin()
    {
        return iterator(root, 0);
    }
    iterator end()
    {
        return iterator(root, 1);
    }
};
}
#endif
