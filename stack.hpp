// Assignment 3 COP4530
// Ryan Winter
// 10/26/17 (Fall 2017)

template <typename T>
Stack<T>::Stack(){ // default constructor	
}

template <typename T>
Stack<T>::~Stack(){ // deconstructor
	v.clear(); // clear everything out of vector. no need to use delete statement becasue did not create using new
}

template <typename T>
Stack<T>::Stack(const Stack<T> & x){ // copy constructor
	*this = x;
}
	
template <typename T>
Stack<T>::Stack(Stack<T> && x){ // move constructor
	*this = x;
}

template <typename T>
Stack<T> & Stack<T>::operator=(const Stack<T> & b){ // copy assignment operator=
	v = b.v;
	return *this;
}

template <typename T>
Stack<T> & Stack<T>::operator=(Stack<T> && b){ // move assignment operator=
	v = b.v;
	return *this;
}

template <typename T>
bool Stack<T>::empty() const{ // returns true if the Stack contains no elements, and false otherwise
	return v.empty();
}

template <typename T>
void Stack<T>::clear(){ // delete all elements from the stack
	v.clear();
}

template <typename T>
void Stack<T>::push(const T& x){ // push(add) x to vector
	v.push_back(x);
}

template <typename T>
void Stack<T>::push(T&& x){ // push(add) x to vector
	v.push_back(x);
}

template <typename T>
void Stack<T>::pop(){ // pop(remove) most recent element
	v.pop_back();
}

template <typename T>
T& Stack<T>::top(){ // return element on top
	return v.back();
}

template <typename T>
const T& Stack<T>::top() const{ // return element on top
	return v.back();
}
	
template <typename T>
int Stack<T>::size() const{ // return size of vector
	return v.size();
}

template <typename T>
void Stack<T>::print(std::ostream & os, char ofc) const{ // print function. need to loop through vector printing each element
for(auto itr = v.begin(); itr != v.end(); ++itr)
	os << *itr << ofc;
}

template <typename T>
std::ostream & operator << (std::ostream & os, const Stack<T> & a){ // invokes the print() method to print the Stack<T> a in the specified ostream    
	a.print(os);
	return os;
}

template <typename T>
bool operator == (const Stack<T> & a, const Stack<T> & b){ // returns true if the two compared Stacks have the same elements, in the same order, and false otherwise  
	return a.getVector() == b.getVector();
}

template <typename T>
bool operator != (const Stack<T> & a, const Stack<T> & b){ // opposite of operator==()
	return !(a == b);
}

template <typename T>
bool operator <= (const Stack<T> & a, const Stack<T> & b){ // returns true if every element in Stack a is smaller than or equal to the corresponding element of Stack b
	return a.getVector() <= b.getVector();
}

template <typename T>
std::vector<T> Stack<T>::getVector() const{ 
	return v;
}