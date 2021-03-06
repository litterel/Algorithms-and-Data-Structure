#ifndef BST_H
#define BST_H
#include <iostream>
#include <queue>
using std::cout;
using std::endl;
using std::queue;

template <typename K, typename V> struct t_node {
    K key;
    V value;
    t_node *left;
    t_node *right;

    t_node(K key, V value) {
        this->key = key;
        this->value = value;
        left = nullptr;
        right = nullptr;
    }
    t_node(t_node *node) {
        this->key = node->key;
        this->value = node->value;
        this->left = this->right = nullptr;
    }
};

template <typename K, typename V> class BST {
    typedef t_node<K, V> t_node;
    typedef t_node<K,V>*
 
  private:
    t_node *root;
    int count;

    bool _contain(K key, t_node *root) {
        t_node *p = root;
        while (p != nullptr) {
            if (key == p->key)
                return true;
            else if (key < p->key)
                p = p->left;
            else
                p = p->right;
        }
        return false;
    }
    bool _contain_r(K key, t_node *root) {
        if (root == nullptr) {
            return false;
        }
        if (key == root->key)
            return true;
        else if (key < root->key)
            return _contain_r(key, root->left);
        else
            return _contain_r(key, root->right);
    }

    void _insert_ref(K key, V value, t_node *&node) {
        //把_insert_r参数中的指针改为指针的引用，函数就可以不用返回值，似乎更直观一些
        if (node == nullptr) {
            count++;
            node = new t_node(key, value);
        }
        if (key == node->key) {
            node->value = value;
        } else if (key < node->key) {
            _insert_ref(key, value, node->left);
        } else
            _insert_ref(key, value, node->right);
    }

    t_node *_insert_r(K key, V value, t_node *node) {
        // 向以node为根的二叉搜索树中,插入节点(key, value)
        // 返回插入新节点后的二叉搜索树的根
        if (node == nullptr) {
            count++;
            return new t_node(key, value);
        }

        if (key == node->key)
            node->value = value;
        else if (key < node->key)
            node->left = _insert_r(node->left, key, value);
        else // key > node->key
            node->right = _insert_r(node->right, key, value);
        return node;
    }

    // void _delete_min() {
    //     if (root == nullptr)
    //         return;

    //     t_node* node = root;
    //     t_node* parent = root;
    //         while(node->left!=nullptr){
    //             parent=node;
    //             node=node->left;
    //         }
    // }
    void wrong_insert(K key, V value, t_node *root) {
        //这是一个给二叉树插入键值的错误方法
        t_node *p = root;
        while (p != nullptr) {
            if (key < p->key)
                p = p->left;
            else if (key > p->key)
                p = p->right;
            else {
                p->value = value;
                return;
            }
        }

        p = new t_node(key, value);
        count += 1;
    }

    void wrong_insert_2(K key, V value, t_node *root) {
        //这也是一个给二叉树插入元素的错误方法，问题出在当初始化二叉树，即root=nullptr时，插入元素之后二叉树的root仍然指向nullptr
        //解决办法就是不要让函数的返回值为void，而是返回新插入节点的地址，并且使用递归，这样才可以对root赋值，使root真正指向新的结点
        //或者使用指针的引用(推荐)，这里可以体现引用的作用，相当于传入实参的一个别名，并不会在函数中为实参创建新的形参
        if (root == nullptr) {
            root = new t_node(key, value);
            count++;
            return;
        }

        t_node *node = root;
        t_node *parent = nullptr;

        bool is_left = true;

        while (node != nullptr) {
            if (key == node->key) {
                node->value = value;
                return;
            } else if (key < node->key) {
                parent = node;
                node = node->left;
                is_left = true;
            } else {
                parent = node;
                node = node->right;
                is_left = false;
            }
        }
        if (is_left) {
            parent->left = new t_node(key, value);
            count++;
            return;
        } else {
            parent->right = new t_node(key, value);
            count++;
            return;
        }
    }

    void _insert(K key, V value, t_node *&root) {
        //使用指针的引用解决了当root=nullptr时无法初始化的问题
        //当然也可以直接用this->root解决问题
        if (root == nullptr) {
            root = new t_node(key, value);
            count++;
            return;
        }

        t_node *node = root;
        t_node *parent = nullptr;
        // bool is_left = true;

        while (node != nullptr) {
            parent = node;
            if (key == node->key) {
                node->value = value;
                return;
            } else if (key < node->key) {
                node = node->left;
                // is_left = true;
            } else {
                node = node->right;
                // is_left = false;
            }
        }
        if (key < parent->key) {
            parent->left = new t_node(key, value);
            count++;
            return;
        } else {
            parent->right = new t_node(key, value);
            count++;
            return;
        }
    }
    V *_search(K key, t_node *root) {
        t_node *p = root;
        while (p != nullptr) {
            if (p->key == key)
                return &(p->value);
            else if (key < p->key)
                p = p->left;
            else
                p = p->right;
        }
        return nullptr;
    }

    V *_search_r(K key, t_node *root) {
        if (root == nullptr)
            return nullptr;

        if (key == root->key)
            return &(root->value);
        else if (key < root->key)
            return _search_r(key, root->left);
        else
            return _search_r(key, root->right);
    }

    t_node *_locate(K key, t_node *node) {
        if (node == nullptr)
            return nullptr;
        if (key == node->key)
            return node;
        else if (key < node->key) {
            return _locate(key, node->left);
        } else
            return _locate(key, node->right);
    }

    void _pre_order(t_node *root) {
        if (root == nullptr)
            return;
        cout << root->key << " ";
        _pre_order(root->left);
        _pre_order(root->right);
    }

    void _mid_order(t_node *root) {
        if (root == nullptr)
            return;
        _mid_order(root->left);
        cout << root->key << " ";
        _mid_order(root->right);
    }

    void _post_order(t_node *root) {
        if (root == nullptr)
            return;
        _post_order(root->left);
        _post_order(root->right);
        cout << root->key << " ";
    }
    void _layer_order(t_node *root) {
        if (root == nullptr)
            return;
        t_node *node = nullptr;
        queue<t_node *> q;
        q.push(root);

        while (!q.empty()) {
            node = q.front();
            cout << node->key << " ";
            if (node->left != nullptr)
                q.push(node->left);
            if (node->right != nullptr)
                q.push(node->right);
            q.pop();
        }
    }

    t_node *_min(t_node *node) {
        if (node->left == nullptr) {
            return node;
        }
        return _min(node->left);
    }

    t_node *_max(t_node *node) {
        if (node->right == nullptr) {
            return node;
        }
        return _max(node->right);
    }
    
    
    t_node *_delete_min_r(t_node *node) {
        if (node->left == nullptr) {
            t_node *p = node->right;
            delete node;
            count--;
            return p;
        } else {
            node->left = _delete_min_r(node->left);
            return node;
        }
    }

    void _delete_min_ref(t_node *&node) {
        if (node->left == nullptr) {
            t_node *p = node;
            node = node->right;
            delete p;
            count--;
        } else
            _delete_min_ref(node->left);
    }

    t_node *_delete_max_r(t_node *node) {
        if (node->right == nullptr) {
            t_node *p = node->left;
            delete node;
            count--;
            return p;
        } else {
            node->right = _delete_max_r(node->right);
            return node;
        }
    }

    void _delete_max_ref(t_node *&node) {
        if (node->right == nullptr) {
            t_node *p = node;
            node = node->left;
            delete p;
            count--;
        } else
            _delete_max_ref(node->right);
    }

    t_node *_remove(K key, t_node *node) {
        if (node == nullptr)
            return nullptr;

        if (key < node->key) {
            node->left = _remove(key, node->left);
            return node;
        } else if (key > node->key) {
            node->right = _remove(key, node->right);
            return node;
        }

        else {
            if (node->left == nullptr) {
                t_node *p_right = node->right;
                delete node;
                count--;
                return p_right;
            }
            if (node->right == nullptr) {
                t_node *p_left = node->left;
                delete node;
                count--;
                return p_left;
            }

            t_node *new_node = new t_node(_min(node->right));
            new_node->right = _delete_min_r(node->right);
            new_node->left = node->left;

            delete node;
            return new_node;
        }
    }
    void destroy(t_node *&root) {
        //指针的引用十分好用，如果传入指针的话，函数的返回值就得是t_node*，不然无法将node指向nullptr
        if (root == nullptr)
            return;
        destroy(root->left);
        destroy(root->right);
        delete root;
        count -= 1;
        root = nullptr;
    }

  public:
    BST() {
        root = nullptr;
        count = 0;
    }
    ~BST() { destroy(root); }
    bool is_null() { return root == nullptr; }
    int get_size() { return count; }
    bool is_empty() { return (count == 0); }
    // void insert1(K key, V value) { _insert(key, value, root); }

    void insert(K key, V value) { _insert(key, value, root); }
    void insert_r(K key, V value) { root = _insert_r(key, value, root); }
    void insert_ref(K key, V value) { _insert_ref(key, value, root); }
    bool contain(K key) { return _contain(key, root); }
    bool contain_r(K key) { return _contain_r(key, root); }

    V *search(K key) { return _search(key, root); };
    V *search_r(K key) { return _search_r(key, root); }

    void delete_max_r() {
        if (root)
            root = _delete_max_r(root);
    }
    void delete_min_r() {
        if (root)
            root = _delete_min_r(root);
    }
    void delete_min_ref() {
        if (root)
            _delete_min_ref(root);
    }
    void delete_max_ref() {
        if (root)
            _delete_max_ref(root);
    }
    K min() { return _min(root)->key; }
    K max() { return _max(root)->key; }

    void remove(K key) { root = _remove(key, root); }
    void pre_order() { _pre_order(root); }
    void mid_order() { _mid_order(root); }
    void post_order() { _post_order(root); }
    void layer_order() { _layer_order(root); }
};

#endif