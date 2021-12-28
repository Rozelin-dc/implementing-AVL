#include <bits/stdc++.h>
#include "avl.hpp"
using namespace std;

int main() {
  Avl<int> avl_tree;

  avl_tree.insert(18);
  avl_tree.insert(3);
  avl_tree.insert(20);
  avl_tree.insert(5);
  if (avl_tree.to_vector() != (vector<int>){18, 3, 20, 5}) {
    cout<<"NG"<<endl;
    return 0;
  }

  cout<<"OK"<<endl;
}
