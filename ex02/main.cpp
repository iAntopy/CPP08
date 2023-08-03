/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 23:19:37 by iamongeo          #+#    #+#             */
/*   Updated: 2023/07/25 23:54:35 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <algorithm>
#include <list>
#include <vector>


void	test_with_list(std::vector<int>& results)
{
	std::list<int> l;

	std::cout << std::endl << "Passing standard iterator tests with list: " << std::endl;

	l.push_back(17);
	l.push_back(5);
	std::cout << *(--l.end()) << std::endl;
	l.erase(--l.end());
	std::cout << l.size() << std::endl;
	l.push_back(3);
	l.push_back(5);
	l.push_back(737);
	l.push_back(0);

	std::list<int>::iterator it = l.begin();
	std::list<int>::iterator ite = l.end();
	++it;
	--it;

	while (it != ite)
	{
		std::cout << *it << " ";
		results.push_back(*it);
		++it;
	}
	std::cout << std::endl;

	it = std::find(l.begin(), l.end(), 737);
	std::cout << "std::find() found 737 at index : " << std::distance(l.begin(), it) << std::endl;

	l.sort();
	std::cout << "list::sort() Mutant stack : ";	
	for (it = l.begin(); it != l.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

	/// Does not compile because list is not a subclass of stack and
	/// no explicite conversion exists to convert list to stack.
	//std::stack<int> regular_stack(l);// DOES NOT COMPILE
}

void	test_with_vector(std::vector<int>& results)
{
	std::vector<int> v;

	std::cout << std::endl << "Passing standard iterator tests with vector: " << std::endl;

	v.push_back(17);
	v.push_back(5);
	std::cout << *(--v.end()) << std::endl;
	v.erase(--v.end());
	std::cout << v.size() << std::endl;
	v.push_back(3);
	v.push_back(5);
	v.push_back(737);
	v.push_back(0);
	
	std::vector<int>::iterator it = v.begin();
	std::vector<int>::iterator ite = v.end();
	++it;
	--it;

	while (it != ite)
	{
		std::cout << *it << " ";
		results.push_back(*it);
		++it;
	}
	std::cout << std::endl;

	it = std::find(v.begin(), v.end(), 737);
	std::cout << "std::find() found 737 at index : " << (it - v.begin()) << std::endl;

	std::sort(v.begin(), v.end());
	std::cout << "std::sort() Mutant stack : ";
	
	for (it = v.begin(); it != v.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

	/// Does not compile because vector is not a subclass of stack and
	/// no explicite conversion exists to convert list to stack.
	//std::stack<int> regular_stack(v);// DOES NOT CONMPILE
}

void	test_with_MutantStack(std::vector<int>& results)
{
	MutantStack<int> mstack;

	std::cout << std::endl << "Passing standard iterator tests with MutantStack: " << std::endl;

	mstack.push(17);
	mstack.push(5);
	std::cout << mstack.top() << std::endl;
	mstack.pop();// Exclusive to stack (between list, vector and stack).
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	
	// Simple test that iterator works on MutantStack.
	++it;
	--it;

	while (it != ite)
	{
		std::cout << *it << " ";
		results.push_back(*it);
		++it;
	}
	std::cout << std::endl;

	it = std::find(mstack.begin(), mstack.end(), 737);
	std::cout << "std::find() found 737 at index : " << (it - mstack.begin()) << std::endl;

	std::sort(mstack.begin(), mstack.end());
	std::cout << "std::sort() Mutant stack : ";
	
	for (it = mstack.begin(); it != mstack.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
	

	// We can build a regular stack from a MutantStack because Mutant Stack is subclass of stack.
	// But iterators won't work on the stack. Iterators only work on MutantStack.
	std::stack<int> regular_stack(mstack);
	//std::stack<int>::iterator impossible_it = regular_stack.begin();//	DOES NOT COMPILE
	//std::stack<int>::iterator impossible_ite = regular_stack.end();//		DOES NOT COMPILE
	
	// Cannot create a mutant stack from a stack because a parent class cannot by promoted
	// to a child class implicitly. But child classes can be interpreted as parent class implicitly.
	//MutantStack<int> mutant_from_stack(regular_stack);//	DOES NOT COMPILE

	regular_stack.push(99);
	regular_stack.push(98);
	regular_stack.push(97);
	regular_stack.pop();
	regular_stack.pop();


	std::list<int>	l;
	while (!regular_stack.empty())
	{
		l.push_front(regular_stack.top());
		regular_stack.pop();
	}

	std::list<int>::iterator	lit;

	std::cout << "Sorted MutantStack converted to regular stack, pushed and popped some elements leaving one extra elem=99, emptied stack to list container and printed here :" << std::endl;
	for (lit = l.begin(); lit != l.end(); ++lit)
		std::cout << *lit << " ";

	std::cout << std::endl << "Adding extra 99 to Mutant Stack, as we did with the stack" << std::endl;
	mstack.push(99);

	it = mstack.begin();
	lit = l.begin();

	std::cout << std::endl << "Checking that both the original MutantStack and the list created are equal or throw exception otherwise ..." << std::endl;
	for (; it != mstack.end(); ++it, ++lit)
		if (*it != *lit)
			throw std::exception();
	
	std::cout << "SUCCESS ! Both the list and the original MutantStack are the same." << std::endl;
	std::cout << std::endl;
}

int main()
{
	std::vector<int>	results1;
	std::vector<int>	results2;
	std::vector<int>	results3;

	test_with_list(results1);
	test_with_vector(results2);
	test_with_MutantStack(results3);

	if (results1 != results2
		|| results1 != results3
		|| results2 != results3)
		std::cerr << "OOPS! Results of container operations are NOT the same." << std::endl;
	else
		std::cout << "Congratulations !! All tests passed SUCCESSFULLY !" << std::endl;

	return (0);
}
