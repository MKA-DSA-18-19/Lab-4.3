/* Make optimal BST from sorted list of BST single nodes using DP (tabulation) 
 * Spring 2019
 * DSA 
 * STARTER CODE
 */

#include <iostream>
#include <fstream>
//#include <stringstream>
#include "BST.h"
#include <vector>
#include <array>
#include "math.h"
using namespace std;


vector<vector<BST *> > optimals;


vector<BST*> makeNodes(vector<int> keys, vector<double> probs){
  // takes list of keys and probabilities and makes nodes
  vector<BST* > trees;
  for (int i = 0; i < keys.size(); i++){
    trees.push_back(new BST(keys[i], probs[i]));
  }
  return trees;    
}

vector<BST*> sort(vector<BST*> treeNodes){
  // sort tree nodes by key
}

BST* getTreeFromOptimals(int size, int start){
  //iterate over all trees in optimal at appropraite row (size)
  // and return a copy of the one with
  //chosen start and end
}

BST* getOptimal(int size, int startPos){
  // optimals[0] is the singleton trees
  // calculate the optimal tree of size with starting node at startPos
}

vector<BST* > getAllOptimals(int size){
  // calculate all of the optimals of a certain size
}

double stringToDouble(string s){ //used in reading input
  double d = 0.0;
  int decimalDig = 0;
  for (int i = 0; i < s.length(); i++){
    string c = s.substr(i, 1);
    if (c == ".") decimalDig += 1;
    else if (decimalDig == 0)
      d = d * 10.0 + stoi(c);
    else{
      d = d + stoi(c) * pow(10, -1* decimalDig);
      decimalDig += 1;
    }
  }
  return d;  
}



vector<double> getArrayDouble(string fileName){ //reads in the double array
  // can be no 0 probability values
  ifstream infile;
  infile.open(fileName);
  vector<double> arr;

  char c;
  string decimal;
  while (infile.get(c)){
      if ((c < 48 || c > 57) && c != '.'){
	if (decimal.length() > 0){
	  double d = stringToDouble(decimal);
	  arr.push_back(d);
	  decimal = "";
	}
      }
      else{
	decimal += c;
      }
    }
  return arr;
}
  
vector<int> getArrayInts(string fileName){ //get ints
  // create a vector of vectors of ints to store the integers
  // initialize the input stream and open the file
  ifstream infile;
  infile.open(fileName);
  vector<int> arr;

  char c;
  string num;
  // while there are lines in the file
  while (infile.get(c)){
    if (c < 48 || c > 57){
      if (num.length() > 0){
	arr.push_back(stoi(num));
	num = "";
      }
    }
    else{
      num += c;
    }
  }
  return arr;
}


int main(){
  vector<int> keys = getArrayInts("Keys.txt");
  cout << "keys done" << endl;
  vector<double> probs = getArrayDouble("Probs.txt");
  cout << "probs" << endl;
  // make the nodes
  // sort them and put them in the first row of optimals
  // get all optimals of all sizes
  // get the optimal tree containing all nodes from optimals table
}
