#include <string>
#include <vector>
#include <stdlib.h>
#include <stack>
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

struct Node;
bool isOperator(string curr); 
bool isNumber(string curr);
float performOp(float first, float second, string op);
void makeTree(string *strs, int len);
void printTree(Node *n, int level, stack<string> &parenthesis);
string spacing(int level);

double rpn(string *strs, int n, bool l) {
	double result = 0.0;
	stack<float> stk;
	string op;
	float first, second, output; 

	for (int i = 0; i < n; i++) {
		string curr = strs[i];
		// check to see if item is valid operator or number
		if (isOperator(curr) | isNumber(curr)){
			
			// item is number, push to stack
			if (isNumber(curr)){
				stk.push(stof(curr));
			}
			// item is operator, perform operation on top two values of stack
			else{
				op = curr;	
				// get operation, if it is ceiling or floor only pop one value from stack
				if (op == "<" | op == ">"){
					if (stk.size() < 1){
						cout << "ERROR. Arguments formatted inproperly." << endl;
						exit(0);
					}
					first = stk.top();	
					stk.pop();
					output = performOp(first, 0.0, op);  // give second parameter as nothing, not needed
					stk.push(output);
				}
				// other operation, pop top two values from stack and perform op
				else{
					if (stk.size() < 2){
						cout << "ERROR. Arguments formatted inproperly" << endl;
						exit(0);
					}
					second = stk.top();	
					stk.pop();
					first = stk.top();
					stk.pop();

					// perform operation, and push result to top of stack
					output = performOp(first, second, op);
					stk.push(output);
				}
			}
		}
		// item is not valid operator or number
		else{
			cout << "ERROR: Item passed not a valid operator or number." << endl;
			exit(0);
		}
	}
	
	if (stk.size() == 1){
		result = stk.top();
	}
	else{
		cout << "ERROR: Unexpected error." << endl;
		exit(0);
	}

	// check if user wants array elements listed on screen, if not just return result
	if (l){
		makeTree(strs, n);
	}
	return result;
}

bool isOperator(string curr){
	if(curr == "+" | curr == "-" | curr == "*" | curr == "/" | curr == "**" | curr == "<" | curr == ">" ){
		return true;
	}
	return false;
}

bool isNumber(string curr){
	try{
		stof(curr);
		return true;
	}
	catch (...){
		return false;
	}
    // for (int i = 0; i < curr.length(); i++)			// iterates through entire string and checks each character is a number
    //     if (isdigit(curr[i]) == false){
    //         return false;
	// 	}
    // return true;
}

float performOp(float first, float second, string op){
	int result = 0;
	if(op == "+") { return first + second; }			// add
	else if(op == "-"){	return first - second; }		// subtract
	else if(op == "*"){	return first * second; }		// multiply
	else if(op == ">"){ return ceil(first); }			// ceiling
	else if(op == "<"){ return floor(first); }			// floor
	else if(op == "**"){ 								// exponent
		// second is exponent, first is base(?) number
		if ((second < 0) && (first == 0)){				// second (power) is negative, first (base) is 0
			cout << "ERROR: Division by 0." << endl;
			exit(0);
		}
		if ((first < 0) && (second == .5)){		// first (base) is negative number, and second (exponent) is 1/2
			cout << "ERROR: Cannot square root a negative number." << endl;
			exit(0);
		}
		return pow(first,  second); }

	else if(op == "/"){									//  division
		if (second == 0){
			cout << "ERROR: Division by 0." << endl;
			exit(0);
		}
    	return first / second;
	}
	else{ 
		cout << "ERROR: Invalid operand." << endl;
		exit(0);
	}
	return result;
}

struct Node {
	string data;
	struct Node *left;
	struct Node *right;
};

void makeTree(string *strs, int len){
	stack<Node*> stk;
	// iterate through string array
	for (int i = 0; i < len; i++){
		Node *n = new Node();
		if (isOperator(strs[i])){
			string op = strs[i];
			n->data = op;
			// ceiling or floor, pop one value from stack;
			if (op == "<" | op == ">"){
				n->left = stk.top();		// set left and popping number
				stk.pop();
				n->right = NULL;			// no right, set NULL
				
				stk.push(n);				// push node
			}
			// other op, pop two values
			else{
				n->right = stk.top();		// set right and pop
				stk.pop();
				n->left = stk.top();		// set left and pop
				stk.pop();		

				stk.push(n);
			}
		}
		else{ // isNumber create new node and push onto the stack
			n->data = strs[i];
			n->left = NULL;
			n->right = NULL;

			stk.push(n);
		}
	}

	int level = 0;
	Node *n = stk.top();
	cout << "(" << n->data << endl;

	// keeps track of parenthesis
	stack<string> parenthesis;
	parenthesis.push("(");

	// print tree
	printTree(n, level, parenthesis);
	
	// makes sure closing parenthesis is there
	if(parenthesis.size() > 0){
		cout << ")" << endl;
	}
}

// modifies spacing for each child, accounting for how many times printTree() has recursed
string spacing(int level){
	string space = "";
	for(int i = 0; i < level; i++){
		space += "  ";
	}
	return space;
}

void printTree(Node *n, int level, stack<string> &parenthesis){	
	// if can go left, do it until the end
	if (n->left != NULL){
		level++;
		cout << spacing(level);
		// prints opening parenthesis if operator
		if (isOperator(n->left->data)){
			cout << "(";
			parenthesis.push("(");
		}
		cout << n->left->data << endl;

		// go to left child
		printTree(n->left, level, parenthesis);
	}

	// once reached bottom, go right if possible, then return
	if (n->right != NULL){
		// level++;
		cout << spacing(level);
		if (isOperator(n->right->data)){
			cout << "(";
			parenthesis.push("(");
		}
		cout << n->right->data << endl;
		// go to right child
		printTree(n->right, level, parenthesis);
		// print closing parenthesis for this child
		cout << spacing(level-1) << ")" << endl;
		parenthesis.pop();
	}
}