// Assignment 3 COP4530
// Ryan Winter
// 10/26/17 (Fall 2017)

#include "stack.h"
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;
using namespace cop4530;

int checkPrecedence(string str);
bool alphaTest(string str);
void infix2postfix(vector<string> &infix, vector<string> &outputVector);
void convertTo(vector<string> &outputVector);	
void print(vector<string> &outputVector);

int main(){
	vector<string> inputVector;
	vector<string> outputVector;
	string userInput;
	
	do{
		cout << "Enter infix expression (\"exit\" to quit): ";
		getline(cin, userInput); // get user input
		outputVector.clear(); // need to clear out old data or it will tag along
		inputVector.clear(); // need to clear out old data or it will tag along
		stringstream sstream(userInput); // create stringstream of the userInput
		
		while (sstream >> userInput) // use stringstream to tokenize userInput
			inputVector.push_back(userInput);
		
		cout << "Postfix expression: ";	
		infix2postfix(inputVector, outputVector);
		
		cout << "Postfix evaluation: ";
		convertTo(outputVector);
		
		//cout << "Enter infix expression (\"exit\" to quit): ";
	}while(userInput != "exit");
	

	return 0;
}

int checkPrecedence(string str){ // test for each operator and assign it a number (using pemdas)
	if(str == "("|| str == ")")
		return (4);
	else if(str == "^")
		return (3);
	else if(str == "*" || str == "/")
		return (2);
	else if(str == "+" || str == "-")
		return (1);
	else
		return 0;
}

void print(vector<string> &outputVector){ // print output expression
	for(int i = 0; i < int(outputVector.size()); i++)
			cout << outputVector[i] << " ";
}

bool alphaTest(string str){
	for(int i = 0; i < int(str.size()); i++)
		if(isalnum(str[i]) == false) // check if alphanumeric 
			return false;
	return true;
}

void infix2postfix(vector<string> &infix, vector<string> &outputVector){ // sourced from rescitation slides
	Stack<string> s;

	for(int i = 0; i < int(infix.size()); ++i){ // needs to be ++i
		if(checkPrecedence(infix[i]) != 0){
			if(((s.empty() == false) && (s.top() != "(")) && (checkPrecedence(s.top()) >= checkPrecedence(infix[i]))){
				while (((s.empty() == false) && (s.top() != "(")) && (checkPrecedence(s.top()) >= checkPrecedence(infix[i]))){
					outputVector.push_back(s.top());
					cout << s.top() << " ";
					s.pop();
				}
			}
			s.push(infix[i]);
			if(infix[i] == ")"){
				s.pop(); // pop the ) right away
				while(s.top() != "("){
					cout << s.top() << " ";
					outputVector.push_back(s.top());
					s.pop();
				}
				s.pop(); // must be a ( so pop it
			}
		}
		else if(alphaTest(infix[i]) == true){
			outputVector.push_back(infix[i]);
			cout << infix[i] << " ";
		}
	}
	while(s.empty() == false){
		cout << s.top() << " ";
		outputVector.push_back(s.top());
		s.pop();
	}
	cout << endl;
}

void convertTo(vector<string> &outputVector){
	Stack<string> stack;
	bool isNum = false;
	for(int i = 0; i < int(outputVector.size()); i++){
		if(alphaTest(outputVector[i]) == true){
			for(int j = 0; j < int(outputVector[j].size()); j++){
				if((isdigit(outputVector[i][j]) == true) || (outputVector[i][j] == '.')) // account for decimal number for use of floats/doubles
					isNum = true; 
				else
					break;	
			}
		}
	}
	if(isNum == true){
		for(int i = 0; i < int(outputVector.size()); i++){
			if(alphaTest(outputVector[i]) == true) // if it is valid alphanumeric then push to stack
				stack.push(outputVector[i]);
			if(checkPrecedence(outputVector[i]) != 0){ // if it is a *, /, +, -, ^, (, or )
				float tempFloat;
				float first = stof(stack.top()); // convert string to float
				stack.pop();					// pop item and convert next (and pop it too)
				float second = stof(stack.top());
				stack.pop();
				
				if(outputVector[i][0] == '*')
					tempFloat = second * first;
				else if(outputVector[i][0] == '/')
					tempFloat = second / first;
				else if(outputVector[i][0] == '+')
					tempFloat = second + first;
				else if(outputVector[i][0] == '-')
					tempFloat = second - first;
				//else if(outputVector[i][0] == '^')
					//tempFloat = second^first;
				stack.push(to_string(tempFloat)); // convert to string then push string to stack
			}
		}
		print(outputVector);	
		cout << "= " << stack.top(); // print out answer
		cout << endl; // formatting
	}
	else{ // if not a num		
		print(outputVector);
		cout << "= "; // prints equal sign
		print(outputVector);
		cout << endl; // formatting
	}
}