/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 23:22:55 by iamongeo          #+#    #+#             */
/*   Updated: 2023/07/25 23:55:26 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template <typename T, class Container>
MutantStack<T, Container>::MutantStack(void)
{
	std::cout << "MutantStack default constructor" << std::endl;
}

template <typename T, class Container>
MutantStack<T, Container>::MutantStack(const MutantStack<T, Container>& other): std::stack<T, Container>(other)
{
	std::cout << "MutantStack copy constructor" << std::endl;
}

template <typename T, class Container>
MutantStack<T, Container>&   MutantStack<T, Container>::operator=(const MutantStack<T, Container>& other)
{
	std::cout << "MutantStack copy assignment operator" << std::endl;
	this->operator=(other);
	return (*this);
}

template <typename T, class Container>
MutantStack<T, Container>::~MutantStack(void)
{
	std::cout << "MutantStack destructor" << std::endl;
}

template <typename T, class Container>
typename MutantStack<T, Container>::iterator
MutantStack<T, Container>::begin(void)
{
	return (this->c.begin());
}

template <typename T, class Container>
typename MutantStack<T, Container>::iterator
MutantStack<T, Container>::end(void)
{
	return (this->c.end());
}