/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 19:08:49 by iamongeo          #+#    #+#             */
/*   Updated: 2023/07/25 20:18:53 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{
	int					arr[] = {-42, -5, -100, 99, 2001, 986754};
	size_t				arr_size = sizeof(arr) / sizeof(arr[0]);
	
	std::vector<int>	v(arr, arr + arr_size);
	std::list<int>		l(arr, arr + arr_size);
	std::deque<int>		d(arr, arr + arr_size);

	std::vector<int>::iterator	vit;
	std::list<int>::iterator	lit;
	std::deque<int>::iterator	dit;

	int					subject = 99;

	vit = easyfind(v, subject);
	if (vit == v.end())
	{
		std::cerr << "Value " << subject << " not found in container" << std::endl;
		return (1);
	}		
	else
		std::cout << "Value " << subject << " found at position : " << vit - v.begin() << std::endl;

	dit = easyfind(d, subject);
	std::cout << "Value " << subject << " found at position : " << dit - d.begin() << std::endl;
	lit = easyfind(l, subject);
	std::cout << "Value " << subject << " found in list : " << *lit << std::endl;

	return (0);
}