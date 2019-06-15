/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgehin <jgehin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 11:31:13 by jgehin            #+#    #+#             */
/*   Updated: 2019/01/03 11:40:14 by jgehin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_abs(int c)
{
	c = (c >= 0) ? c : (c * -1);
	return (c);
}
