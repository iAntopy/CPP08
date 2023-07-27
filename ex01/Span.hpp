/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 20:24:28 by iamongeo          #+#    #+#             */
/*   Updated: 2023/07/25 23:06:26 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <random>
# include <climits>
# include <vector>
# include <list>
# include <deque>

class Span
{
	private:
		uint32_t	_size;
		uint32_t	_n;
		int*		_data;

	public:
		Span(void);
		Span(uint32_t N);
		Span(const Span& other);
		Span&	operator=(const Span& other);
		~Span(void);

		void		addNumber(int nb);
		void		addRange(std::vector<int>::const_iterator start, std::vector<int>::const_iterator end);
		void		addRange(std::list<int>::const_iterator start, std::list<int>::const_iterator end);
		void		addRange(std::deque<int>::const_iterator start, std::deque<int>::const_iterator end);
		
		uint32_t	shortestSpan(void) const;
		uint32_t	longestSpan(void) const;

		int			min(void) const;
		int			max(void) const;
		uint32_t	size(void) const;
		uint32_t	capacity(void) const;
		
		int		operator[](uint32_t i) const;
};
std::ostream&	operator<<(std::ostream& o, const Span& sp);

#endif