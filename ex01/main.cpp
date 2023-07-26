/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 20:36:13 by iamongeo          #+#    #+#             */
/*   Updated: 2023/07/25 23:13:29 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

void	test_constructor(void)
{
	std::cout << std::endl << "Starting Span constructors tests : " << std::endl;
	Span    sp1(4);

	sp1.addNumber(1);
	sp1.addNumber(2);
	sp1.addNumber(3);

	std::cout << "sp1 : " << sp1 << std::endl;

	Span    sp2;
	Span    sp3(sp1);

	sp2 = sp1;
	
	std::cout << "sp2 : " << sp2 << std::endl;
	std::cout << "sp3 : " << sp3 << std::endl;
}





void	test_add_number(void)
{
	std::cout << std::endl << "Starting Span addNumber() tests : " << std::endl;
	Span    sp(4);

	sp.addNumber(0);
	sp.addNumber(50);
	sp.addNumber(100);	
	sp.addNumber(-100);
	
	try { sp.addNumber(-42); }
	catch (std::exception &e) {std::cerr << "Failed to add a number to Span. SUCCESS !" << std::endl;}

	std::cout << sp << std::endl;
}





void	test_longuest_and_shortest_span(void)
{
	std::cout << std::endl << "Starting Span longestSpan and shortestSpan tests : " << std::endl;
	Span    sp(6);
	
	try {std::cout << sp.longestSpan() << std::endl; std::cout << sp.shortestSpan() << std::endl;}
	catch (std::exception &e) {std::cerr << "Calling longestSpan on Span with < 2 members fails. SUCCESS !" << std::endl;}

	sp.addNumber(0);
	try {std::cout << sp.longestSpan() << std::endl; std::cout << sp.shortestSpan() << std::endl;}
	catch (std::exception &e) {std::cerr << "Calling longestSpan on Span with < 2 members fails. SUCCESS !" << std::endl;}

	sp.addNumber(50);
	try {
		std::cout << "Called shortestSpan() on " << sp << " (" << sp.shortestSpan() << ") with SUCCESS !" << std::endl;
		std::cout << "Called longestSpan() on " << sp << " (" << sp.longestSpan() << ") with SUCCESS !" << std::endl;
	}
	catch (std::exception &e) {std::cerr << "Calling longestSpan on Span with >= 2 members should work. FAILURE !" << std::endl;}
	
	sp.addNumber(100);
	sp.addNumber(-100);
	sp.addNumber(999999999);
	sp.addNumber(1000000000);

	
	std::cout << "Span before final test : " << sp << std::endl;
	std::cout << "Shortest span : " << sp.shortestSpan() << ", should == 1" << std::endl;
	std::cout << "Longuest span : " << sp.longestSpan() << ", should == 1000000100" << std::endl;
}




void	test_standard(void)
{
	std::cout << std::endl << "Starting Span stardard tests : " << std::endl;
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}



void	test_add_range_small(void)
{
	std::cout << std::endl << "Starting Span add small range tests : " << std::endl;
	const int			range_size = 10;
	std::random_device	rd;
	std::vector<int>	v;
	Span				sp(range_size);

	for (int i=0; i < range_size; ++i)
		v.push_back(rd() % 1000);

	sp.addRange(v.begin(), v.end());
	std::cout << "Span after range insert : " << sp << std::endl;
	std::cout << "Shortest span : " << sp.shortestSpan() << std::endl;
	std::cout << "Longuest span : " << sp.longestSpan()  << std::endl;
}




void	test_add_range_large(void)
{
	std::cout << std::endl << "Starting Span add small range tests : " << std::endl;
	const int			range_size = 20000;
	std::random_device	rd;
	std::vector<int>	v;
	Span				sp(range_size);

	for (int i=0; i < range_size; ++i)
		v.push_back(rd() % 100000);

	sp.addRange(v.begin(), v.end());
	std::cout << "Span after range insert : " << sp << std::endl;
	std::cout << "Shortest span : " << sp.shortestSpan() << std::endl;
	std::cout << "Longuest span : " << sp.longestSpan()  << std::endl;
}


void	test_add_range_with_range_of_iterators(void)
{
	std::cout << std::endl << "Starting Span add range with a range of iterator types tests : " << std::endl;
	int	arr[3] = {1, 42, 100};
	Span				sp(9);

	std::vector<int>	v(arr, arr + (sizeof(arr) / sizeof(arr[0])));
	std::list<int>		l(arr, arr + (sizeof(arr) / sizeof(arr[0])));
	std::deque<int>		d(arr, arr + (sizeof(arr) / sizeof(arr[0])));

	sp.addRange(v.begin(), v.end());
	sp.addRange(l.begin(), l.end());
	sp.addRange(d.begin(), d.end());

	std::cout << "Span after range inserts : " << sp << std::endl;
	std::cout << "Shortest span : " << sp.shortestSpan() << std::endl;
	std::cout << "Longuest span : " << sp.longestSpan()  << std::endl;
}


int main()
{
	test_constructor();
	test_add_number();
	test_longuest_and_shortest_span();
	test_standard();
	test_add_range_small();
//	test_add_range_large();//	 Achievment locked.
	test_add_range_with_range_of_iterators();
	
	return (0);
}