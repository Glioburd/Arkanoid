/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_form.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsauvair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 23:33:47 by gsauvair          #+#    #+#             */
/*   Updated: 2015/05/03 23:33:49 by gsauvair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

static void		brick_color(char c)
{
	if (c == '1')
		glColor3b(51, 51, 127);
	if (c == '2')
		glColor3b(127, 0, 63);
	if (c == '3')
		glColor3b(127, 51, 51);
	if (c == '4')
		glColor3b(127, 0, 0);
}

static int		yolo_suague(t_env *env, int i, int *test)
{
	if (test_col(env, i, test))
	{
		if (env->map[i] != '4')
		{
			env->map[i]--;
			env->score += 5;
		}
	}
	if (env->map[i] != '0' && i < 139)
	{
		glBegin(GL_QUADS);
		brick_color(env->map[i]);
		glVertex2f(env->squa.x - X_VAR, env->squa.y - Y_VAR);
		glVertex2f(env->squa.x + X_VAR, env->squa.y - Y_VAR);
		glVertex2f(env->squa.x + X_VAR, env->squa.y + Y_VAR);
		glVertex2f(env->squa.x - X_VAR, env->squa.y + Y_VAR);
		glEnd();
	}
	env->squa.x = env->squa.x + X_INC;
	return (i + 1);
}

void			square_create(t_env *env)
{
	int		i;
	int		test;

	i = 0;
	test = 0;
	while (i < 139)
	{
		while (env->map[i] != '\n' && i < 139)
			i = yolo_suague(env, i, &test);
		if (env->map[i] == '\n')
		{
			env->squa.x = X_BEGIN;
			env->squa.y = env->squa.y - 0.092f;
			i++;
		}
	}
	env->squa.x = X_BEGIN;
	env->squa.y = Y_BEGIN;
}
