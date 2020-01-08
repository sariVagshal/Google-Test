#ifndef __STACK__
#define __STACK__

/** 
 *  @file Stack.h
 *  @brief Stack implemented over std::vector
 *
 *  @author Sari
 *  @company ElevationAcademy
 * 
 *  @bug No known bugs.
 */

#include <vector>
#include <iostream>
#include <stdexcept>

class StackException : public std::runtime_error
{
public:
	StackException(const std::string& message) : std::runtime_error(message) {} 
};

class EmptyStackException : public StackException
{
public:
	EmptyStackException() : StackException("Empty stack") {}
};

template<typename T>
class Stack
{
public:
	bool isEmpty() const throw();
	void push(const T& item);
	const T& top() const;
	T pop();

private:
	std::vector<T> m_data;
};


template<typename T>
bool Stack<T>::isEmpty() const throw()
{
	return m_data.empty();
}

template<typename T>
void Stack<T>::push(const T& item)
{
	m_data.push_back(item);
}

template<typename T>
const T& Stack<T>::top() const
{
	if (m_data.empty())
		throw EmptyStackException();
	
	return m_data.back();
}

template<typename T>
T Stack<T>::pop()
{
	if (m_data.empty())
		throw EmptyStackException();

	T poppedElement( top() );
	m_data.pop_back();
	return poppedElement;
}

#endif /*	__STACK__	*/
