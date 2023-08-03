/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 20:24:28 by iamongeo          #+#    #+#             */
/*   Updated: 2023/07/25 23:12:36 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(void): _max_size(0)
{
	std::cout << "Span default constuctor" << std::endl;
}

Span::Span(uint32_t N): _max_size(N)
{
	std::cout << "Span default constuctor" << std::endl;
	std::fill(_data.begin(), _data.end(), 0);
}

Span::Span(const Span& other): _max_size(other._max_size), _data(other._data)
{
	std::cout << "Span copy constuctor" << std::endl;
}

Span&	Span::operator=(const Span& other)
{
	std::cout << "Span copy assignment opperator" << std::endl;
	_max_size = other._max_size;
	_data = other._data;
	return (*this);
}

Span::~Span(void) {std::cout << "Span destructor" << std::endl;}

void	Span::addNumber(int nb)
{
	if (_data.size() >= _max_size)
		throw std::length_error("Max nb of member elements reached");
	if (_data.size() == 0)
		_data.push_back(nb);
	else
		_data.insert(std::upper_bound(_data.begin(), _data.end(), nb), nb);
}

void	Span::addRange(std::vector<int>::const_iterator start, std::vector<int>::const_iterator end)
{
	ssize_t	range_size = (end - start);

	if (range_size < 0)
		throw std::invalid_argument("Iterators in wrong order.");
	else if ((range_size + _data.size()) > _max_size)
		throw std::invalid_argument("Adding this range would exceed Span capacity.");

	std::copy(start, end, std::back_inserter(_data));
	std::sort(_data.begin(), _data.end());
}

void	Span::addRange(std::list<int>::const_iterator start, std::list<int>::const_iterator end)
{
	ssize_t	range_size = std::distance(end, start);

	if (range_size < 0)
		throw std::invalid_argument("Iterators in wrong order.");
	else if ((range_size + _data.size()) > _max_size)
		throw std::invalid_argument("Adding this range would exceed Span capacity.");
	
	std::copy(start, end, std::back_inserter(_data));
	std::sort(_data.begin(), _data.end());
}

void	Span::addRange(std::deque<int>::const_iterator start, std::deque<int>::const_iterator end)
{
	ssize_t	range_size = (end - start);

	if (range_size < 0)
		throw std::invalid_argument("Iterators in wrong order.");
	else if ((range_size + _data.size()) > _max_size)
		throw std::invalid_argument("Adding this range would exceed Span capacity.");
	
	std::copy(start, end, std::back_inserter(_data));
	std::sort(_data.begin(), _data.end());
}

// Work on the assumption that _data is sorted. Which it is.
uint32_t	Span::shortestSpan(void) const
{
	std::vector<int>::const_iterator 	it;
	size_t								shortest = SIZE_MAX;
	ssize_t								delta;

	if (_data.size() < 2)
		throw std::length_error("Cannot find shortest span with less then 2 span members.");

	for (it = _data.begin(); it < (_data.end() - 1); ++it)
	{
		delta = (*(it + 1) - *it);
		if (delta < shortest)
			shortest = delta;
	}
	return (shortest);
}

// Work on the assumption that _data is sorted. Which it is.
uint32_t	Span::longestSpan(void) const
{
	if (_data.size() < 2)
		throw std::length_error("Cannot find shortest span with less then 2 span members.");
	return (*(_data.end() - 1) - *_data.begin());
}

int		Span::operator[](uint32_t i) const
{
	if (i >= _data.size())
		throw std::out_of_range("Span index out of bounds");
	return (_data[i]);
}

// Work on the assumption that _data is sorted. Which it is.
int			Span::min(void) const
{
	if (_data.size() == 0)
		throw std::length_error("Trying to find Span min while size == 0.");

	return (_data[0]);
}

// Work on the assumption that _data is sorted. Which it is.
int			Span::max(void) const
{
	if (_data.size() == 0)
		throw std::length_error("Trying to find Span max while size == 0.");
	return (*(_data.end() - 1));
}

uint32_t		Span::size(void) const {return (_data.size());}
uint32_t		Span::capacity(void) const {return (_max_size);}

std::ostream&	operator<<(std::ostream& o, const Span& sp)
{
	uint32_t	size = sp.size();

	std::cout << "Span([ ";
	for (uint32_t i=0; i < (size - 1); ++i)
		std::cout << sp[i] << ", ";
	std::cout << sp[size - 1] << "])";
	return (o);
}	
