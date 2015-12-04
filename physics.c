/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   physics.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsauvair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 23:34:51 by gsauvair          #+#    #+#             */
/*   Updated: 2015/05/03 23:34:52 by gsauvair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

static int	col_up(t_env *env)
{
	if (((env->ball.x + 0.015f) >= (env->squa.x - X_VAR) &&
		(env->ball.x - 0.015f) <= (env->squa.x + X_VAR)) &&
		((env->ball.x + 0.015f) <= (env->squa.x + X_VAR) &&
		(env->ball.x - 0.015f) >= (env->squa.x - X_VAR)))
	{
		if ((env->ball.y + 0.02f) >= (env->squa.y - Y_VAR) &&
			(env->ball.y + 0.02f) < (env->squa.y + Y_VAR))
			return (1);
	}
	return (0);
}

static int	col_down(t_env *env)
{
	if (((env->ball.x + 0.015f) >= (env->squa.x - X_VAR) &&
		(env->ball.x - 0.015f) <= (env->squa.x + X_VAR)) &&
		((env->ball.x + 0.015f) <= (env->squa.x + X_VAR) &&
		(env->ball.x - 0.015f) >= (env->squa.x - X_VAR)))
	{
		if ((env->ball.y - 0.02f) <= (env->squa.y + Y_VAR) &&
			(env->ball.y - 0.02f) > (env->squa.y - Y_VAR))
			return (1);
	}
	return (0);
}

static int	col_right(t_env *env)
{
	if ((env->ball.x + 0.015f) >= (env->squa.x - X_VAR) &&
		(env->ball.x + 0.015f) < (env->squa.x + X_VAR))
	{
		if (((env->ball.y - 0.02f) >= (env->squa.y - Y_VAR) &&
			(env->ball.y + 0.02f) <= (env->squa.y + Y_VAR)) &&
			((env->ball.y - 0.02f) >= (env->squa.y - Y_VAR) &&
			(env->ball.y + 0.02f) <= (env->squa.y + Y_VAR)))
			return (1);
	}
	return (0);
}

static int	col_left(t_env *env)
{
	if ((env->ball.x - 0.015f) <= (env->squa.x + X_VAR) &&
		(env->ball.x - 0.015f) > (env->squa.x - X_VAR))
	{
		if (((env->ball.y - 0.02f) >= (env->squa.y - Y_VAR) &&
			(env->ball.y + 0.02f) <= (env->squa.y + Y_VAR)) &&
			((env->ball.y - 0.02f) >= (env->squa.y - Y_VAR) &&
			(env->ball.y + 0.02f) <= (env->squa.y + Y_VAR)))
			return (1);
	}
	return (0);
}

int			test_col(t_env *env, int i, int *test)
{
	if (env->ball.y >= 0 && env->map[i] != '0')
	{
		if (col_up(env) || col_down(env))
		{
			if (*test == 0)
			{
				env->ball.move_y *= -1;
				*test = 1;
			}
			return (1);
		}
		else if (col_left(env) || col_right(env))
		{
			if (*test == 0)
			{
				env->ball.move_x *= -1;
				*test = 1;
			}
			return (1);
		}
	}
	return (0);
}
