#ifndef BST_NEW_H
#define BST_NEW_H
#include <cassert>
#include <iostream>
#include <queue>
#include <vector>
using std::cout;
using std::endl;
using std::queue;
using std::vector;

template <typename K, typename V> struct t_node {
    K key;
    V value;
    t_node *left;
    t_node *right;
    int num; //用于记录以node为根的子树中一共有多少节点

    t_node(K key, V value) {
        this->key = key;
        this->value = value;
        left = right = nullptr;
    }

    t_node(t_node *node) {
        this->key = node->key;
        this->value = node->value;
        this->left = node->left;
        this->right = node->right;
        this->num = node->num;
    }
};

template <typename K, typename V>

class bst {
    typedef t_node<K, V> t_node;
    typedef t_node *p_node;

  private:
    p_node root;
    int size;
    bool exist;
    int _get_num(p_node &node) {
        if (node == nullptr)
            return 0;
        else
            return node->num;
    }
    void _insert_r(K key, V value, p_node &node) {
        if (node == nullptr) {
            node = new t_node(key, value);
            node->num = 1;
            exist = false;
            size++;
            return;
        }
        if (key == node->key) {
            node->value = value;
            exist = true;
        } else if (key < node->key) {
            // path.push_back(node);
            _insert_r(key, value, node->left);
        } else {
            // path.push_back(node);
            _insert_r(key, value, node->right);
        }
        node->num = _get_num(node->left) + _get_num(node->right) + 1;
        return;
    }

    void _add_num(vector<p_node> &path) {
        //使用递归方法的时候用不到这个函数
        if (exist == false) {
            for (auto iter = path.begin(); iter != path.end(); iter++) {
                if (*iter != nullptr)
                    (*iter)->num += 1;
            }
        }
    }

    void _insert(K key, V value, p_node &node) {
        if (node == nullptr) {
            node == new t_node(key, value);
            size++;
            return;
        }

        p_node parent = nullptr;
        p_node current = node;

        while (current != nullptr) {
            if (key == current->key) {
                current->value = value;
                return;
            } else if (key < current) {
                parent = current;
                current = current->left;
            } else {
                parent = current;
                current = current->right;
            }
        }
        if (key < parent->key) {
            parent->left = new t_node(key, value);
            size++;
        } else {
            parent->right = new t_node(key, value);
            size++;
        }
    }
    int _rank(K key, p_node &node) {
        //这个函数返回以node为树根的二叉搜索树中键值小于key的结点数目
        if (node == nullptr)
            return 0;

        if (key == node->key)
            return _get_num(node->left); //返回当前节点左子树大小
        else if (key > node->key)
            return _rank(key, node->right) + _get_num(node->left) +
                   1; //返回右子树中比key小的节点数目+左子树大小+1
        else
            return _rank(key, node->left); //返回左子树中比当前结点小的结点数目
    }

    p_node _select(int m, p_node &node) {
        //m代表存在m个节点其键值比要返回的元素小
        if (node == nullptr)
            return 0;

        if (m == _get_num(node->left))
            return node;
        else if (m < _get_num(node->left))
            return _select(m, node->left);
        else
            return _select(m - _get_num(node->left) - 1, node->right);
    }
    bool _contain(K key, p_node node) {
        while (node != nullptr) {
            if (key == node->key)
                return true;
            else if (key < node->key)
                node = node->left;
            else
                node = node->right;
        }
        return false;
    }

    p_node _min(p_node node) {
        if (node == nullptr)
            return nullptr;
        while (node->left != nullptr)
            node = node->left;
        return node;
    }

    p_node &_min_ref(p_node &node) {
        if (node->left == nullptr)
            return node;
        return _min_ref(node->left);
    }

    p_node _max(p_node node) {
        if (node == nullptr)
            return nullptr;
        while (node->right != nullptr)
            node = node->right;
        return node;
    }

    p_node &_max_ref(p_node &node) {
        if (node->right == nullptr)
            return node;
        return _max_ref(node->right);
    }

    p_node _remove_min(p_node node) {
        if (node == nullptr)
            return nullptr;

        if (node->left == nullptr) {
            p_node r_node = node->right;
            delete node;
            size--;
            return r_node;
        } else {
            node->num -= 1;
            node->left = _remove_min(node->left);
            return node;
        }
    }

    p_node _remove_max(p_node node) {
        if (node == nullptr)
            return nullptr;

        if (node->right == nullptr) {
            p_node l_node = node->left;
            delete node;
            size--;
            return l_node;
        } else {
            node->num -= 1;
            node->right = _remove_max(node->right);
            return node;
        }
    }
    p_node _locate(K key, p_node node) {
        if (node == nullptr)
            return nullptr;

        if (key == node->key)
            return node;
        else if (key < node->key)
            return _locate(key, node->left);
        else
            return _locate(key, node->right);
    }

    p_node _remove(K key, p_node node) {
        if (node == nullptr)
            return nullptr;

        if (key < node->key) {
            node->num -= 1;
            node->left = _remove(key, node->left);
            return node;
        } else if (key > node->key) {
            node->num -= 1;
            node->right = _remove(key, node->right);
            return node;
        } else {

            if (node->left == nullptr) {
                p_node pr = node->right;
                delete node;
                size--;
                return pr;
            }

            if (node->right == nullptr) {
                p_node pl = node->left;
                delete node;
                size--;
                return pl;
            }

            p_node new_node = new t_node(_min_ref(node->right));
            node->right = _remove_min(node->right);
            new_node->num = node->num-1;;
            new_node->left = node->left;
            new_node->right = node->right;
            delete node;
            return new_node;
        }
    }

    void _pre_order(p_node &node) {
        if (node) {
            cout << node->key << ": " << node->num << ", ";
            _pre_order(node->left);
            _pre_order(node->right);
        }
    }

    void _in_order(p_node &node) {
        if (node) {
            _in_order(node->left);
            cout << node->key << " ";
            _in_order(node->right);
        }
    }
    void _post_order(p_node &node) {
        if (node) {
            _in_order(node->left);
            _in_order(node->right);
            cout << node->key << " ";
        }
    }

    void _layer_order(t_node *root) {
        if (root == nullptr)
            return;
        t_node *node = nullptr;
        queue<t_node *> q;
        q.push(root);

        while (!q.empty()) {
            node = q.front();
            cout << node->key << ": " << node->num << ", ";
            if (node->left != nullptr)
                q.push(node->left);
            if (node->right != nullptr)
                q.push(node->right);
            q.pop();
        }
    }

    void _destroy_r(p_node &node) {
        if (node != nullptr) {
            _destroy_r(node->left);
            _destroy_r(node->right);
            delete node;
            node = nullptr;
        }
    }

  public:
    bst() {
        root = nullptr;
        size = 0;
    }
    ~bst() {
        _destroy_r(root); //
    }

    int get_size() { return size; }
    int is_null() { return root == nullptr; }

    void insert(K key, V value) { _insert_r(key, value, root); }
    int rank(K key) { return 1 + _rank(key, root); }

    K select(int k) {
        assert(k >= 1 && k <= size);
        return _select(k - 1, root)->key;
    }
    bool contain(K key) { return _contain(key); }

    void pre_order() { _pre_order(root); }
    void in_order() { _in_order(root); }
    void post_order() { _post_order(root); }
    void layer_order() { _layer_order(root); }

    void remove_min() { root = _remove_min(root); }
    void remove_max() { root = _remove_max(root); }
    void remove(K key) {
        if (!_contain(key, root))
            return;
        else
            root = _remove(key, root);
    }
    K min() { return _min_ref(root)->key; }
    K max() { return _max(root)->key; }
};

#endif