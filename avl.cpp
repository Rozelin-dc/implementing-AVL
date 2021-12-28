#include <bits/stdc++.h>
#include "avl.hpp"
using namespace std;

template<typename T>
Avl<T>::Avl() {
  root = NULL;
  count = 0;
}

template<typename T>
node_t<T> *Avl<T>::create_new_node(T value) {
  node_t<T> *new_node = (node_t<T> *)malloc(sizeof(node_t<T>));
  if (new_node == NULL) {
    cerr << "malloc error!" << endl;
    exit(1);
  }

  new_node->value = value;
  new_node->status = 'E';
  new_node->parent = NULL;
  new_node->left = NULL;
  new_node->right = NULL;

  return new_node;
}

template<typename T>
void Avl<T>::print_partial_tree(node_t<T> *partial_root) {
  if (partial_root == NULL) {
    cout << ".";
    return;
  }

  cout << "(";
  print_partial_tree(partial_root->left);
  cout << " " << partial_root->value << " ";
  print_partial_tree(partial_root->right);
  cout << ")";
}

template<typename T>
void Avl<T>::print_tree() {
  print_partial_tree(root);
  cout<<endl;
}

/* search_value に一致する value を持つノードのポインタを返す。
 * 見つからなければNULL を返す
 */
template<typename T>
node_t<T> *Avl<T>::search(T search_value) {
  node_t<T> *target = root;

  while (target->value != search_value && target != NULL) {
    if (target->value > search_value) {
      target = target->left;
    } else {
      target = target->right;
    }
  }

  return target;
}

template<typename T>
void Avl<T>::insert(T insert_value) {
  node_t<T> *new_node = create_new_node(insert_value);

  count++;

  if (root == NULL) {
    root = new_node;
    return;
  }

  node_t<T> *target = root;

  while (!(target->left == NULL && target->value >= insert_value) &&
         !(target->right == NULL && target->value < insert_value)) {
    if (target->value < insert_value) {
      target = target->right;
    } else {
      target = target->left;
    }
  }

  if (target->value < insert_value) {
    target->right = new_node;
    new_node->parent = target;
  } else {
    target->left = new_node;
    new_node->parent = target;
  }
}

template<typename T>
void Avl<T>::delete_node(T delete_value) {
  node_t<T> *delete_node = search(delete_value);
  if (delete_node == NULL) {
    return;
  }

  count--;

  // 削除するノードが葉の時
  if (delete_node->left == NULL && delete_node->right == NULL) {
    if (delete_node == root) {
      free(delete_node);
      root = NULL;
      return;
    }

    if (delete_node->parent->left == delete_node) {
      delete_node->parent->left = NULL;
    } else {
      delete_node->parent->right = NULL;
    }

    free(delete_node);
    return;
  }

  node_t<T> *switched_node; // 左部分木の最大ノードか右部分木の最小ノードが入る
  if (delete_node->left != NULL) {
    switched_node = delete_node->left;
    while (switched_node->right != NULL) {
      switched_node = switched_node->right;
    }
    switched_node->parent->right = NULL;
  } else {
    switched_node = delete_node->right;
    while (switched_node->left != NULL) {
      switched_node = switched_node->left;
    }
    switched_node->parent->left = NULL;
  }

  delete_node->value = switched_node->value;
  
  free(switched_node);
  return;
}

template<typename T>
vector<T> Avl<T>::to_vector() {
  vector<T> tree(0);
  queue<node_t<T> *> que;
  que.push(root);

  node_t<T> *front;
  while (!que.empty()) {
    front = que.front();
    tree.push_back(front->value);

    if (front->left != NULL) {
      que.push(front->left);
    }
    if (front->right != NULL) {
      que.push(front->right);
    }

    que.pop();
  }

  return tree;
}

template<typename T>
int Avl<T>::size() {
  return count;
}
