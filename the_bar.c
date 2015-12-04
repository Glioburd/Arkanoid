/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_bar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsauvair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 23:35:07 by gsauvair          #+#    #+#             */
/*   Updated: 2015/05/03 23:35:08 by gsauvair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

static int		col_bar(t_env *env)
{
	if (((env->ball.y + env->ball.move_y) <= -0.92f) &&
		(env->ball.y + env->ball.move_y) >= -0.96f)
		if ((env->ball.x + env->ball.move_x) >= (-0.1f + env->bar) &&
			(env->ball.x + env->ball.move_x) <= (0.1f + env->bar))
		{
			env->ball.move_y *= -1;
			return (1);
		}
	return (0);
}

static void		from_left(t_env *env)
{
	if ((env->ball.x + env->ball.move_x) >= (-0.1f + env->bar) &&
		(env->ball.x + env->ball.move_x) <= (-0.05f + env->bar))
	{
		env->ball.move_x = -0.008;
		env->ball.move_y = 0.008f;
	}
	else if ((env->ball.x + env->ball.move_x) >= (-0.05f + env->bar) &&
		(env->ball.x + env->ball.move_x) <= env->bar)
	{
		env->ball.move_x = -0.005f;
		env->ball.move_y = 0.009f;
	}
	else if ((env->ball.x + env->ball.move_x) >= env->bar &&
		(env->ball.x + env->ball.move_x) <= (0.05f + env->bar))
	{
		env->ball.move_x = 0.005f;
		env->ball.move_y = 0.009f;
	}
	else if ((env->ball.x + env->ball.move_x) >= (0.05f + env->bar) &&
		(env->ball.x + env->ball.move_x) <= (0.1f + env->bar))
	{
		env->ball.move_x = 0.008f;
		env->ball.move_y = 0.008f;
	}
}

static void		from_right(t_env *env)
{
	if ((env->ball.x + env->ball.move_x) >= (-0.1f + env->bar) &&
		(env->ball.x + env->ball.move_x) <= (-0.05f + env->bar))
	{
		env->ball.move_x = -0.008;
		env->ball.move_y = 0.008f;
	}
	else if ((env->ball.x + env->ball.move_x) >= (-0.05f + env->bar) &&
		(env->ball.x + env->ball.move_x) <= env->bar)
	{
		env->ball.move_x = -0.005f;
		env->ball.move_y = 0.009f;
	}
	else if ((env->ball.x + env->ball.move_x) >= env->bar &&
		(env->ball.x + env->ball.move_x) <= (0.05f + env->bar))
	{
		env->ball.move_x = 0.005f;
		env->ball.move_y = 0.009f;
	}
	else if ((env->ball.x + env->ball.move_x) >= (0.05f + env->bar) &&
		(env->ball.x + env->ball.move_x) <= (0.1f + env->bar))
	{
		env->ball.move_x = 0.008f;
		env->ball.move_y = 0.008f;
	}
}

static void		col_from_where(t_env *env)
{
	if (env->ball.move_x > 0.f)
		from_left(env);
	if (env->ball.move_x < 0.f)
		from_right(env);
}

void			the_bar(t_env *env)
{
	glBegin(GL_QUADS);
	if (col_bar(env))
		col_from_where(env);
	glVertex2f(-0.1f + env->bar, -0.92f);
	glVertex2f(0.1f + env->bar, -0.92f);
	glVertex2f(0.1f + env->bar, -0.96f);
	glVertex2f(-0.1f + env->bar, -0.96f);
	glEnd();
}
