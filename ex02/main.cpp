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


	l.push_back(5);
	l.push_back(17);
	std::cout << *(--l.end()) << std::endl;
	l.erase(--l.end());
//	l.pop();
	std::cout << l.size() << std::endl;
	l.push_back(3);
	l.push_back(5);
	l.push_back(737);
	//[...]
	l.push_back(0);

	std::list<int>::iterator it = l.begin();
	std::list<int>::iterator ite = l.end();
	++it;
	--it;

	while (it != ite)
	{
		std::cout << *it << std::endl;
		results.push_back(*it);
		++it;
	}
//	std::stack<int> s(l);
}

void	test_with_vector(std::vector<int>& results)
{
	std::vector<int> v;


	v.push_back(5);
	v.push_back(17);
	std::cout << *(--v.end()) << std::endl;
	v.erase(--v.end());
	std::cout << v.size() << std::endl;
	v.push_back(3);
	v.push_back(5);
	v.push_back(737);
	//[...]
	v.push_back(0);
	
	std::vector<int>::iterator it = v.begin();
	std::vector<int>::iterator ite = v.end();
	++it;
	--it;

	while (it != ite)
	{
		std::cout << *it << std::endl;
		results.push_back(*it);
		++it;
	}
//	std::stack<int> s(v);
}

void	test_with_MutantStack(std::vector<int>& results)
{
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;

	while (it != ite)
	{
		std::cout << *it << std::endl;
		results.push_back(*it);
		++it;
	}
	std::stack<int> s(mstack);
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

/*
int main()
{
	MutatedStack<int>	ms;

	ms.push(1);
	ms.push(2);
	ms.push(3);

	while (!ms.empty())
	{
		std::cout << "poped stack item : " << ms.top() << std::endl;
		ms.pop();
	}

	ms.push(1);
	ms.push(2);
	ms.push(3);

	MutatedStack<int>::const_iterator	it;

	for (it=ms.begin(); it != ms.end(); ++it)
		std::cout << "iterated stack value : " << *it << std::endl;

	

//	std::cout << ms << std::endl;
	return (0);
}
*/