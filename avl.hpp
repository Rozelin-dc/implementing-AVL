#include <bits/stdc++.h>
using namespace std;

template<typename T>
struct _node {
  T value;
  struct _node<T> *parent, *left, *right;
  char status;
};

template<typename T>
using node_t = struct _node<T>;

template<typename T>
class Avl {
  private:
    node_t<T> *root;
    int count;
    node_t<T> *create_new_node(T value);
    void print_partial_tree(node_t<T> *partial_root);
  public:
    Avl();
    void insert(T new_value);
    void delete_node(T delete_value);
    node_t<T> *search(T search_value);
    int size();
    void print_tree();
    vector<T> to_vector();
};

template class Avl<int>;
