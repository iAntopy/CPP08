/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 23:19:37 by iamongeo          #+#    #+#             */
/*   Updated: 2023/07/25 23:54:35 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutatedStack.hpp"

int main()
{
	MutatedStack<int>	ms;

	ms.push_back(1);
	ms.push_back(2);
	ms.push_back(3);

	std::cout << ms << std::endl;
	return (0);
}