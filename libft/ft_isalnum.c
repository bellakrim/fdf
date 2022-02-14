/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellakr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 21:01:17 by abellakr          #+#    #+#             */
/*   Updated: 2021/11/03 14:17:09 by abellakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int str)
{
	if ((str >= 97 && str <= 122) || \
			(str >= 65 && str <= 90) || \
			(str >= 48 && str <= 57))
		return (1);
	else
		return (0);
}