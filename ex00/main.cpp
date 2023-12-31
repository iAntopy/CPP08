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

	/// Value not found test
	vit = easyfind(v, 0);
	if (vit == v.end())
		std::cout << "SUCCESS ! Trying to find 0 in vector returned v.end() iterator." << std::endl;
	else
		std::cerr << "FAILURE ! Trying to find 0 in vector did NOT return v.end() iterator." << std::endl;
	

	/// Value found cases.
	vit = easyfind(v, subject);
	if (vit == v.end())
	{
		std::cerr << "Value " << subject << " not found in container" << std::endl;
		return (1);
	}		
	else
		std::cout << "Value " << *vit << " found in vector at position : " << vit - v.begin() << std::endl;

	dit = easyfind(d, subject);
	std::cout << "Value " << *dit << " found in deque at position : " << dit - d.begin() << std::endl;
	lit = easyfind(l, subject);
	std::cout << "Value " << *lit << " found in list at position : " << std::distance(l.begin(), lit) << std::endl;

	return (0);
}