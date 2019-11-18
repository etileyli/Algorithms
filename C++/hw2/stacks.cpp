#include <iostream>
#include "sServices.h"
using namespace std;

static int inputArr[10] = {3, 6, 4, 1, 3, 4, 2, 5, 3, 0};

class Node{
  int raw;
  int column;
  int value;
  bool marked;
public:
  Node():raw(0), column(0), value(inputArr[raw]), marked(false){}

  Node(int _raw, int _column){
    raw = _raw;
    column = _column;
    value = inputArr[column];
  }

  int getRaw(){
    return raw;
  }

  int getColumn(){
    return column;
  }

  int getVal(){
    return value;
  }

  void print(){
    cout << "raw: " << raw + 1 << "  column: " << column + 1 <<  "  value: " << value << "  marked: " << marked <<endl;
  }

  // If the value of the raw is 7, the node is a leaf node
  bool isLeaf(){
    return (raw + 1) == 7;
  }

  bool isGoal(){
    return ( isLeaf() && column == 9 && value == 0);
  }

  bool isMarked(){return marked == true;}

  bool isLeftChildValid(){
    return column - inputArr[column] >= 0;
  }

  bool isRightChildValid(){
    return column + inputArr[column] < 10;
  }

  void mark(){marked = true;}
};

// Input 1x10 matrix
// Target: Try to reach the last element of the input
//         array at exactly 7th raw.
bool solve(){
  Stack<Node> s;
  Node firstNode;

  int k = 0;

  // push node n on the stack S;
  s.push(firstNode);
  while(!s.isEmpty()){
    Node node;
    s.getTop(node);

    if (node.isLeaf()){
      if (node.isGoal())
        return true;
      else{
        cout << "A leaf node and it is not the result!\n";
        s.pop();
      }
    }
    else if(!node.isMarked()){  // if s.Top() is unmarked
      // Mark s.Top() node
      Node nd;
      s.topAndPop(nd);
      nd.mark();
      s.push(nd);

      // If it has a valid child at right, push to stack
      if (nd.isRightChildValid()){
        Node rightNode(nd.getRaw() + 1, nd.getColumn() + nd.getVal());
        cout << "pushing: ";
        rightNode.print();
        s.push(rightNode);
      }

      // If it has a valid child at left, push to stack
      if (nd.isLeftChildValid()){
        Node leftNode(nd.getRaw() + 1, nd.getColumn() - nd.getVal());
        cout << "pushing: ";
        leftNode.print();
        s.push(leftNode);
      }
    }
    else if(!node.isLeaf() && node.isMarked()) { // backing out
      Node tmp;
      s.topAndPop(tmp);
      cout << "pop: ";
      tmp.print();
    };
  }

  return false;
}

int main(int argc, char const *argv[]) {

  solve() ? cout << "true!\n" : cout << "false!\n";
  return 0;
}
