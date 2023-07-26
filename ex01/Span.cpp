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

// template <typename T>
// class Span
// {
// 	private:
// 		uint32_t	_n;
// 		T*			_data;

// 	public:
// 		Span(void);
// 		Span(uint32_t N);
// 		Span(const Span& other);
// 		Span&	operator=(const Span& other);
// 		~Span(void);


// 		void	addNumber(T nb);
// };

Span::Span(void): _n(0), _size(0), _data(NULL)
{
	std::cout << "Span default constuctor" << std::endl;
}

Span::Span(uint32_t n): _n(0), _size(n), _data(NULL)
{
	std::cout << "Span default constuctor" << std::endl;
	_data = new int[_size];
}

Span::Span(const Span& other): _n(other._n), _size(other._size), _data(NULL)
{
	std::cout << "Span copy constuctor" << std::endl;
	if (other._data)
	{
		_data = new int[_size];
		for (size_t i=0; i < _n; ++i)
			_data[i] = other._data[i];
	}
}

Span&	Span::operator=(const Span& other)
{
	std::cout << "Span copy assignment opperator" << std::endl;
	
	if (other._data)
	{
		if (_data)
			delete[] _data;
		_n = other._n;
		_size = other._size;
		_data = new int[_size];
		for (size_t i=0; i < _n; ++i)
			_data[i] = other._data[i];
	}
	return (*this);
}

Span::~Span(void) {std::cout << "Span destructor" << std::endl;}

void	Span::addNumber(int nb)
{
	if (_n >= _size)
		throw std::length_error("Max nb of member elements reached");

	_data[_n++] = nb;
}

void	Span::addRange(std::vector<int>::const_iterator start, std::vector<int>::const_iterator end)
{
	ssize_t	range_size = (end - start);

	if (range_size < 0)
		throw std::invalid_argument("Iterators in wrong order.");
	else if ((range_size + _n) > _size)
		throw std::invalid_argument("Adding this range would exceed Span capacity.");
	
	for (; start != end; ++start)
		_data[_n++] = *start;
}

void	Span::addRange(std::list<int>::const_iterator start, std::list<int>::const_iterator end)
{
	ssize_t	range_size = std::distance(start, end);

	if (range_size < 0)
		throw std::invalid_argument("Iterators in wrong order.");
	else if ((range_size + _n) > _size)
		throw std::invalid_argument("Adding this range would exceed Span capacity.");
	
	for (; start != end; ++start)
		_data[_n++] = *start;
}

void	Span::addRange(std::deque<int>::const_iterator start, std::deque<int>::const_iterator end)
{
	ssize_t	range_size = (end - start);

	if (range_size < 0)
		throw std::invalid_argument("Iterators in wrong order.");
	else if ((range_size + _n) > _size)
		throw std::invalid_argument("Adding this range would exceed Span capacity.");
	
	for (; start != end; ++start)
		_data[_n++] = *start;
}

uint32_t	Span::shortestSpan(void) const
{
	size_t	shortest = SIZE_MAX;
	ssize_t	delta;

	if (_n < 2)
		throw std::length_error("Cannot find shortest span with less then 2 span members.");

	for (uint32_t i=0; i < (_n - 1); ++i)
	{
		for (uint32_t j=(i + 1); j < _n; ++j)
		{
			delta = std::abs(_data[i] - _data[j]);
//			std::cout << "delta between idx " << i << " and " << j << " : " << delta << std::endl;
			if (delta < shortest)
				shortest = delta;
		}
	}
	return (shortest);
}

uint32_t	Span::longestSpan(void) const
{
	int	span_min = this->min();
	int	span_max = this->max();
	
	if (_n < 2)
		throw std::length_error("Cannot find shortest span with less then 2 span members.");
	return (this->max() - this->min());
}

int		Span::operator[](uint32_t i) const
{
	if (i >= _n)
		throw std::out_of_range("Span index out of bounds");
	return (_data[i]);
}

int			Span::min(void) const
{
	int		cur_min = INT_MAX;
	
	if (_n == 0)
		throw std::length_error("Trying to find Span min while size == 0.");
	
	for (uint32_t i=0; i < _n; ++i)
		if (_data[i] < cur_min)
			cur_min = _data[i];
	return (cur_min);
}

int			Span::max(void) const
{
	int		cur_max = INT_MIN;

	if (_n == 0)
		throw std::length_error("Trying to find Span max while size == 0.");
	
	for (uint32_t i=0; i < _n; ++i)
		if (_data[i] > cur_max)
			cur_max = _data[i];
	return (cur_max);
}

uint32_t		Span::size(void) const {return (_n);}
uint32_t		Span::capacity(void) const {return (_size);}

std::ostream&	operator<<(std::ostream& o, const Span& sp)
{
	uint32_t	size = sp.size();

	std::cout << "Span([ ";
	for (uint32_t i=0; i < (size - 1); ++i)
		std::cout << sp[i] << ", ";
	std::cout << sp[size - 1] << "])";
	return (o);
}	
