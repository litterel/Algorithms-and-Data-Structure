#ifndef MYTREE_H
#define MYTREE_H

#include <string>
#include <vector>
#include <queue>
typedef char valuetype;

struct tnode
{
    valuetype val;
    tnode *left = nullptr;
    tnode *right = nullptr;
    //tnode *father = nullptr;
};

class mytree
{
  public:
    mytree();
    ~mytree();
    tnode *get_root();
    void creat_tree(std::string &a);

  private:
    tnode *root;
};

void mytree::creat_tree(std::string &a)
{
    std::queue<tnode*> temp_queue;
    temp_queue.push(this->root);
    auto iter = a.begin();
    while(!temp_queue.empty()){
        auto temp = temp_queue.front();
        
    }

}

mytree::mytree()
{
    root = nullptr;
}

mytree::~mytree()
{
    return;
}

#endif //  MYTREE_H
