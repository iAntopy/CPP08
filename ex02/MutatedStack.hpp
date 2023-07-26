/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutatedStack.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 23:20:57 by iamongeo          #+#    #+#             */
/*   Updated: 2023/07/25 23:54:48 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTATED_STACK_HPP
# define MUTATED_STACK_HPP

# include <iostream>
# include <deque>
# include <stack>

template <typename T>
class MutatedStack: std::stack<T>
{
	private:
		using container = std::deque<T>;
		using container::begin;
		using container::end;
	public:
		typedef typename std::deque<T>::iterator iterator;
		typedef typename std::deque<T>::const_iterator const_iterator;

		MutatedStack(void);
		MutatedStack(const MutatedStack& other);
		MutatedStack&   operator=(const MutatedStack& other);
		~MutatedStack();
};

# include "MutatedStack.tpp"

#endif