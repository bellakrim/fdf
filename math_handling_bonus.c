/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_handling_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellakr <abellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 17:20:45 by abellakr          #+#    #+#             */
/*   Updated: 2022/02/27 02:22:41 by abellakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

/*-------------------------------------------------------------*/
void	isometrie_bonus(t_fdf_var *vars)
{
	int	z1;
	int	z2;

	z1 = vars->z1 * vars->z_offset;
	z2 = vars->z2 * vars->z_offset;
	vars->x1 = (vars->x1 - vars->y1) * cos(0.523599);
	vars->y1 = (vars->x1 + vars->y1) * sin(0.523599) - z1;
	vars->x2 = (vars->x2 - vars->y2) * cos(0.523599);
	vars->y2 = (vars->x2 + vars->y2) * sin(0.523599) - z2;
}

/*----------------------------------------------------------------*/
void	centrage_bonus(t_fdf_var *vars)
{
	int	diametre;

	diametre = sqrt(pow(WEIGHT, 2) + pow(HEIGH, 2));
	if (diametre > 875)
	{
		vars->x_offset = WEIGHT - (diametre / 2.3);
		vars->y_offset = (diametre * 230) / HEIGH ;
	}
	else
	{
		vars->x_offset = WEIGHT / 2;
		vars->y_offset = diametre / 1.8;
	}
}

/*-----------------------------------------------------------------*/
void	my_zoom_bonus(t_fdf_var *vars)
{
	int		diamtre_map;

	diamtre_map = sqrt(pow(vars->colones, 2) + pow(vars->lines, 2));
	if (vars->zoom == 1)
	{
		if (diamtre_map < 100)
			vars->my_zoom = 25;
		else if (diamtre_map > 100 && diamtre_map < 250)
			vars->my_zoom = 3;
		else
			vars->my_zoom = 2;
	}
	else
		vars->my_zoom = vars->zoom;
}

/*-----------------------------------------------------------------*/
void	zoom_bonus(t_fdf_var *vars)
{
	vars->x1 *= vars->my_zoom;
	vars->y1 *= vars->my_zoom;
	vars->x2 *= vars->my_zoom;
	vars->y2 *= vars->my_zoom;
}
/*------------------------------------------------------*/
void	rotation_bonus(t_fdf_var *vars)
{
	if(vars->X == 1)
	{
		vars->y1 = vars->y1 * cos(0.523599 + vars->O) + vars->z1 * sin(0.523599 + vars->O);
		vars->z1 = -vars->y1 * sin(0.523599 + vars->O) + vars->z1 * cos(0.523599 + vars->O);
		
		vars->y2 = vars->y2 * cos(0.523599 + vars->O) + vars->z2 * sin(0.523599 + vars->O);
		vars->z2 = -vars->y2 * sin(0.523599 + vars->O) + vars->z2 * cos(0.523599 + vars->O);
	}
	if(vars->Y == 1)
	{
		vars->x1 = vars->x1 * cos(0.523599 + vars->O) + vars->z1 * sin(0.523599 + vars->O);
		vars->z1 = -vars->x1 * sin(0.523599 + vars->O) + vars->z1 * cos(0.523599 + vars->O);
		
		vars->x2 = vars->x2 * cos(0.523599 + vars->O) + vars->z2 * sin(0.523599 + vars->O);
		vars->z2 = -vars->x2 * sin(0.523599 + vars->O) + vars->z2 * cos(0.523599 + vars->O);
	}
	if(vars->Z == 1)
	{
		vars->x1 = vars->x1 * cos(0.523599 + vars->O) - vars->y1 * sin(0.523599 + vars->O);
		vars->y1 = vars->x1 * sin(0.523599 + vars->O) - vars->y1 * cos(0.523599 + vars->O);
	
		vars->x2 = vars->x2 * cos(0.523599 + vars->O) - vars->y2 * sin(0.523599 + vars->O);
		vars->y2 = vars->x2 * sin(0.523599 + vars->O) - vars->y2 * cos(0.523599 + vars->O);
	}
}