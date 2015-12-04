/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ball.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsauvair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 23:33:28 by gsauvair          #+#    #+#             */
/*   Updated: 2015/05/03 23:33:29 by gsauvair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

static void		move_ball(t_env *env)
{
	env->ball.x += env->ball.move_x;
	env->ball.y += env->ball.move_y;
	if ((env->ball.x + env->ball.move_x) >= 0.99
		|| (env->ball.x + env->ball.move_x) <= -0.99)
		env->ball.move_x *= -1;
	if ((env->ball.y + env->ball.move_y) >= 0.99)
		env->ball.move_y *= -1;
	if ((env->ball.y + env->ball.move_y) <= -0.99)
	{
		env->life -= 1;
		env->ball.x = 0.f;
		env->ball.y = -0.4f;
		env->ball.move_x = 0.008f;
		env->ball.move_y = -0.008f;
		the_ball(env);
	}
}

void			the_ball(t_env *env)
{
	move_ball(env);
	glBegin(GL_QUADS);
	glColor3f(0.9f, 0.9f, 0.9f);
	glVertex2f(-0.015f + env->ball.x, -0.02f + env->ball.y);
	glVertex2f(0.015f + env->ball.x, -0.02f + env->ball.y);
	glVertex2f(0.015f + env->ball.x, 0.02f + env->ball.y);
	glVertex2f(-0.015f + env->ball.x, 0.02f + env->ball.y);
	glEnd();
}
