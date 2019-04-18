// Assignment 3 COP4530
// Ryan Winter
// 10/26/17 (Fall 2017)

#ifndef STACK_H
#define STACK_H
#include <iostream>
#include <vector>

namespace cop4530{
	template <typename T>
	class Stack{
	private:
		std::vector<T> v;

	public:
		Stack(); // default constructor		
		~Stack(); // deconstructor
		Stack(const Stack<T> &); // copy constructor
		Stack(Stack<T> &&); // move constructor
		Stack<T> & operator=(const Stack<T> &); //copy assignment operator
		Stack<T> & operator=(Stack<T> &&); // move assignment operator
		bool empty() const;
		void clear();
		void push(const T& x);
		void push(T && x);
		void pop();
		T& top();
		const T& top() const;
		int size() const; // holds size of vector
		void print(std::ostream& os, char ofc = ' ') const; 
		std::vector<T> getVector() const;
	};
	template <typename T>
	std::ostream & operator << (std::ostream & os, const Stack<T> & a); // invokes the print() method to print the Stack<T> a in the specified ostream    

	template <typename T>
	bool operator == (const Stack<T> & a, const Stack<T> & b); // returns true if the two compared Stacks have the same elements, in the same order, and false otherwise  

	template <typename T>
	bool operator != (const Stack<T> & a, const Stack<T> & b); // opposite of operator==()

	template <typename T>
	bool operator <= (const Stack<T> & a, const Stack<T> & b); // returns true if every element in Stack a is smaller than or equal to the corresponding element of Stack b
	
#include "stack.hpp"
} // end of cop4530 namespace

#endif