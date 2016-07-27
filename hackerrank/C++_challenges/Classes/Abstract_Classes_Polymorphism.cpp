// https://www.hackerrank.com/challenges/abstract-classes-polymorphism

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

struct Node{
  Node* next;
  Node* prev;
  int value;
  int key;
  Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){};
  Node(int k, int val):prev(NULL),next(NULL),key(k),value(val){};
};

class Cache{

  protected:
    map<int,Node*> mp; //map the key to the node in the linked list
    int cp;  //capacity
    Node* tail; // double linked list tail pointer
    Node* head; // double linked list head pointer
    virtual void set(int, int) = 0; //set function
    virtual int get(int) = 0; //get function

};

// Begin my code
class LRUCache: public Cache {
  public:
    LRUCache (int c) {cp = c;}
    void set (int k, int v) {
      Node *cur = new Node(k, v);
      if (mp.size() == cp) {
        int newTail = mp[tail->key]->prev->key;
        mp.erase(tail->key);
        mp[newTail]->next = NULL;
        tail = mp[newTail];

        cur->next = head;
        mp[k] = cur;
      }
      else {
        if (mp.size() == 0) {
          tail = cur;
          mp[k] = cur;
        }
        else {
          Node* tmp = head;
          cur->next = tmp;

          tmp->prev = cur;
          tmp->next = cur->next;

          if (mp.count(k) > 0) {
            mp[tmp->key] = tmp;
            mp[k] = cur;
          }
          else {
            mp[k] = cur;
          }
        }
      }

      head = cur;
    }

    int get (int k) {
      if (mp.count(k) > 0) return mp[k]->value;
      return -1;
    }
};
// End my code

int main() {
  int n, capacity,i;
  cin >> n >> capacity;
  LRUCache l(capacity);
  for(i=0;i<n;i++) {
    string command;
    cin >> command;
    if(command == "get") {
      int key;
      cin >> key;
      cout << l.get(key) << endl;
    }
    else if(command == "set") {
      int key, value;
      cin >> key >> value;
      l.set(key,value);
    }
  }
  return 0;
}
