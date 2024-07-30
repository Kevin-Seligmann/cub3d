/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 06:15:12 by kseligma          #+#    #+#             */
/*   Updated: 2024/07/30 12:22:45 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

/*
	Transforms (x, y) into (y, -x) from src to dst
*/
void	perp_clockwise_v2(t_v2 *src, t_v2 *dst)
{
	dst->x = src->z;
	dst->z = -src->x;
}

/*
	Transforms (x, y) into (y, -x) from src to dst
*/
void	perp_clockwise_vf2(t_vf2 *src, t_vf2 *dst)
{
	dst->x = src->z;
	dst->z = -src->x;
}
