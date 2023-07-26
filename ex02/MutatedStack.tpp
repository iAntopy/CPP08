/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutatedStack.tpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 23:22:55 by iamongeo          #+#    #+#             */
/*   Updated: 2023/07/25 23:55:26 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutatedStack.hpp"
# include <iostream>

template <typename T>
MutatedStack<T>::MutatedStack(void)
{
	std::cout << "MutatedStack default constructor" << std::endl;
}

template <typename T>
MutatedStack<T>::MutatedStack(const MutatedStack& other): std::stack<T>(other)
{
	std::cout << "MutatedStack copy constructor" << std::endl;
}

template <typename T>
MutatedStack<T>&   MutatedStack<T>::operator=(const MutatedStack<T>& other)
{
	std::cout << "MutatedStack copy assignment operator" << std::endl;
	return (*this);
}

template <typename T>
MutatedStack<T>::~MutatedStack(void)
{
	std::cout << "MutatedStack destructor" << std::endl;
}
