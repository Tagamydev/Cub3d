/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_status.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:06:35 by samusanc          #+#    #+#             */
/*   Updated: 2023/11/30 15:06:08 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

t_stat1	tmp_status(float ray_a, float *ds, int m, float last_distance)
{
	t_stat1	result;

	result.ray_a = ray_a;
	result.ds = ds;
	result.m = m;
	result.last_distance = last_distance;
	return (result);
}

static void	init_gns(t_cub *cub, float ray_a, t_stat *st)
{
	st->ray_proyection = 0;
	st->ray_dx = cos(angle_to_radian(get_angle(ray_a)));
	st->ray_dy = sin(angle_to_radian(get_angle(ray_a)));
	st->x = cub->player_px + st->ray_dx * 0;
	st->y = cub->player_py + st->ray_dy * 0;
}

int	get_next_status(t_cub *cub, t_stat1 b)
{
	t_stat	st;

	init_gns(cub, b.ray_a, &st);
	while (cub->map[(int)st.y][(int)st.x] != 1)
	{
		st.x = st.x + st.ray_dx * st.ray_proyection;
		st.y = st.y + st.ray_dy * st.ray_proyection;
		st.ray_proyection += 0.0001;
	}
	if (ft_abs2(closer_int(st.y) - st.y) > \
		ft_abs2(closer_int(st.x) - st.x))
		st.status1 = SIDE;
	else
		st.status1 = FRONT;
	*(b.ds) = ft_ds(cub->player_px, st.x, cub->player_py, st.y);
	if (ft_abs2(closer_int(st.y) - st.y) < \
	0.09 && ft_abs2(closer_int(st.x) - st.x) < 0.09)
	{
		if (ft_abs2(b.last_distance - \
		ft_ds(cub->player_px, st.x, cub->player_py, st.y) < 1))
			st.status1 = get_next_status(cub, \
			tmp_status(b.ray_a + (0.046948 * b.m), b.ds, b.m, *(b.ds)));
	}
	return (st.status1);
}
