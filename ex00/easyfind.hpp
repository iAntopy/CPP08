/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 19:09:23 by iamongeo          #+#    #+#             */
/*   Updated: 2023/07/25 20:14:45 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <iterator>
# include <vector>
# include <list>
# include <deque>

template <typename T>
typename T::iterator	easyfind(T& container, int subject)
{
	for (typename T::iterator	it = container.begin(); it != container.end(); ++it)
		if ((*it) == subject)
			return (it);
	return (container.end());
}

#endif