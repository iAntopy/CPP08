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
#include <list>
#include <vector>

void	test_with_list(std::vector<int>& results)
{
	std::list<int> l;

	std::cout << "Passing standard iterator tests with list: " << std::endl;

	l.push_back(5);
	l.push_back(17);
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

	/// Does not compile because list is not a subclass of stack and
	/// no explicite conversion exists to convert list to stack.
	//std::stack<int> regular_stack(l);// DOES NOT COMPILE
}

void	test_with_vector(std::vector<int>& results)
{
	std::vector<int> v;

	std::cout << "Passing standard iterator tests with vector: " << std::endl;

	v.push_back(5);
	v.push_back(17);
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

	/// Does not compile because vector is not a subclass of stack and
	/// no explicite conversion exists to convert list to stack.
	//std::stack<int> regular_stack(v);// DOES NOT CONMPILE
}

void	test_with_MutantStack(std::vector<int>& results)
{
	MutantStack<int> mstack;

	std::cout << "Passing standard iterator tests with MutantStack: " << std::endl;

	mstack.push(5);
	mstack.push(17);
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

	// We can build a regular stack from a MutantStack because Mutant Stack is subclass of stack.
	// But iterators won't work on the stack. Iterators only work on MutantStack.
	std::stack<int> regular_stack(mstack);
	//std::stack<int>::iterator impossible_it = regular_stack.begin();//	DOES NOT COMPILE
	//std::stack<int>::iterator impossible_ite = regular_stack.end();//		DOES NOT COMPILE
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
