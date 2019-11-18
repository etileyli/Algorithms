#include <iostream>
#include "sServices.h"
using namespace std;

static int inputArr[10] = {3, 6, 4, 1, 3, 4, 2, 5, 3, 0};

class Node{
  int row, column, value;
  bool marked;
public:
  Node():row(0), column(0), value(inputArr[row]), marked(false){}

  Node(int _row, int _column){
    row = _row;
    column = _column;
    value = inputArr[column];
    marked = false;
  }

  int getRow(){return row;}

  int getColumn(){return column;}

  int getVal(){return value;}

  void print(){
    cout << "row: " << row + 1 << "  column: " << column + 1 <<  "  value: " << value << "  marked: " << marked <<endl;
  }

  // If the value of the row is 7, the node is a leaf node
  bool isLeaf(){
    return (row + 1) == 7;
  }

  bool isGoal(){
    return (isLeaf() && column == 9 && value == 0);
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
//         array at exactly 7th row.
bool solve(Node firstNode){
  Stack<Node> s;

  cout << "The top node is:" << endl;
  firstNode.print();
  // push node n on the stack S;
  s.push(firstNode);

  while(!s.isEmpty()){
    Node node;
    s.getTop(node);

    if (node.isLeaf()){
      if (node.isGoal()){
        cout << "Exit is found. The node: ";
        node.print();
        return true;
      }
      else{
        cout << "Popping leaf node: ";
        node.print();
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
        Node rightNode(nd.getRow() + 1, nd.getColumn() + nd.getVal());
        // if last column is encountered before row 7, return with failure
        if (nd.getVal() == 0 && nd.getRow() != 7)
          return false;

        cout << "Pushing: ";
        rightNode.print();
        s.push(rightNode);
      }

      // If it has a valid child at left, push to stack
      if (nd.isLeftChildValid()){
        Node leftNode(nd.getRow() + 1, nd.getColumn() - nd.getVal());
        cout << "Pushing: ";
        leftNode.print();
        s.push(leftNode);
      }
    }
    else if(!node.isLeaf() && node.isMarked()) { // backing out
      Node tmp;
      s.topAndPop(tmp);
      cout << "Popping marked non-leaf node: ";
      tmp.print();
    };
  }

  return false;
}

int main(int argc, char const *argv[]) {

  // for (int i = 0; i < 10; i++){
  //   Node firstNode (0, i);
  //   solve(firstNode) ?  cout << "SUCCESS!\n\n" : cout << "No solution is found!\n";
  // }
    // SOLUTION 1 - Starts from (1, 1) position
    Node firstNode1 (0, 0);
    solve(firstNode1) ?  cout << "SUCCESS!\n\n" : cout << "No solution is found!\n";
    // 1- (1, 1)  -->  -->  --> 3 Right
    // 2- (2, 1) (2, 2) (2, 3) (2, 4)  <-- 1 Left
    // 3- (3, 1) (3, 2) (3, 3) -->  -->  -->  -->  4 Right
    // 4- (4, 1) (4, 2) (4, 3) (4, 4) (4, 5) (4, 6) (4, 7)  -->  --> 2 Right
    // 5- (5, 1) (5, 2) (5, 3) (5, 4) (5, 5) (5, 6) (5, 7) (5, 8) (5, 9) <--  <--  <-- 3 Left
    // 6- (6, 1) (6, 2) (6, 3) (6, 4) (6, 5) (6, 6) -->  -->  -->  --> 4 Right
    // 7- (7, 1) (7, 2) (7, 3) (7, 4) (7, 5) (7, 6) (7, 7) (7, 8) (7, 9) (7, 10)



    // SOLUTION  - Starts from (1, 2) position
    Node firstNode2 (0, 1);
    solve(firstNode2) ?  cout << "SUCCESS!\n\n" : cout << "No solution is found!\n";
    // 1- (1, 1) (1, 2) -->  -->  -->  -->  -->  --> 6 Right
    // 2- (2, 1) (2, 2) (2, 3) (2, 4) (2, 5) (2, 6) (2, 7) (2, 8) <--  <--  <--  <--  <-- 5 Left
    // 3- (3, 1) (3, 2) (3, 3) -->  -->  -->  -->  4 Right
    // 4- (4, 1) (4, 2) (4, 3) (4, 4) (4, 5) (4, 6) (4, 7)  -->  --> 2 Right
    // 5- (5, 1) (5, 2) (5, 3) (5, 4) (5, 5) (5, 6) (5, 7) (5, 8) (5, 9) <--  <--  <-- 3 Left
    // 6- (6, 1) (6, 2) (6, 3) (6, 4) (6, 5) (6, 6) -->  -->  -->  --> 4 Right
    // 7- (7, 1) (7, 2) (7, 3) (7, 4) (7, 5) (7, 6) (7, 7) (7, 8) (7, 9) (7, 10)



    // SOLUTION 3 - Starts from (1, 5) position
    Node firstNode3 (0, 4);
    solve(firstNode3) ?  cout << "SUCCESS!\n\n" : cout << "No solution is found!\n";
    // 1- (1, 1) (1, 2) (1, 3) (1, 4) (1, 5) -->  -->  -->  3 Right
    // 2- (2, 1) (2, 2) (2, 3) (2, 4) (2, 5) (2, 6) (2, 7) (2, 8) <--  <--  <--  <--  <-- 5 Left
    // 3- (3, 1) (3, 2) (3, 3) -->  -->  -->  -->  4 Right
    // 4- (4, 1) (4, 2) (4, 3) (4, 4) (4, 5) (4, 6) (4, 7)  -->  --> 2 Right
    // 5- (5, 1) (5, 2) (5, 3) (5, 4) (5, 5) (5, 6) (5, 7) (5, 8) (5, 9) <--  <--  <-- 3 Left
    // 6- (6, 1) (6, 2) (6, 3) (6, 4) (6, 5) (6, 6) -->  -->  -->  --> 4 Right
    // 7- (7, 1) (7, 2) (7, 3) (7, 4) (7, 5) (7, 6) (7, 7) (7, 8) (7, 9) (7, 10)

  return 0;
}
