/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 23:20:57 by iamongeo          #+#    #+#             */
/*   Updated: 2023/07/25 23:54:48 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Mutant_STACK_HPP
# define Mutant_STACK_HPP

# include <iostream>
# include <deque>
# include <stack>

template < typename T, class Container=std::deque<T> >
class MutantStack: public std::stack<T, Container>
{
	public:

		MutantStack(void);
		MutantStack(const MutantStack& other);
		MutantStack&   operator=(const MutantStack& other);
		~MutantStack(void);

		typedef typename Container::iterator iterator;
		typedef typename Container::const_iterator const_iterator;

		iterator	begin(void);
		iterator	end(void);
};

# include "MutantStack.tpp"

#endif