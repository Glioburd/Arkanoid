/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arkanoid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsauvair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 23:32:48 by gsauvair          #+#    #+#             */
/*   Updated: 2015/05/03 23:32:50 by gsauvair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

void		env_init(t_env *env)
{
	env->squa.x = -0.918f;
	env->squa.y = 0.92f;
	env->bar = 0.f;
	env->ball.x = 0.f;
	env->ball.y = -0.895f;
	env->ball.move_x = 0.008f;
	env->ball.move_y = 0.008f;
	env->score = 0;
	env->life = 2;
}

void		key_callback(GLFWwindow *win, int key, int scancode, int action,
		int mods)
{
	if (!scancode && !win && !mods)
		scancode = scancode + 0;
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(win, GL_TRUE);
}

void		get_level(t_env *env, char *path)
{
	int		fd;

	if (-1 == (fd = open(path, O_RDONLY)))
	{
		ft_error(path);
		exit (-1);
	}
	if (-1 == read(fd, env->map, 140))
	{
		ft_error(path);
		exit (-1);
	}
	env->map[139] = '\0';
}

static void	do_window(GLFWwindow *win, t_env *env)
{
	int			state;

	while (!glfwWindowShouldClose(win))
	{
		if (GLFW_PRESS == (state = glfwGetKey(win, GLFW_KEY_LEFT))
			&& (env->bar > -0.87f))
			env->bar -= 0.03f;
		if (GLFW_PRESS == (state = glfwGetKey(win, GLFW_KEY_RIGHT))
			&& (env->bar < 0.87f))
			env->bar += 0.03f;
		glClear(GL_COLOR_BUFFER_BIT);
		square_create(env);
		the_ball(env);
		the_bar(env);
		aff_score(env);
		glfwPollEvents();
		glfwSwapBuffers(win);
		if (env->life == -1)
		{
			ft_putendl("A looser is YOU ! D:");
			glfwSetWindowShouldClose(win, GL_TRUE);
		}
		if (check_win(env))
			glfwSetWindowShouldClose(win, GL_TRUE);
	}
}

int			main(int ac, char **av)
{
	GLFWwindow	*win;
	t_env		env;

	if (ac != 2)
		return (0);
	get_level(&env, av[1]);
	if (!glfwInit())
		exit(EXIT_FAILURE);
	win = glfwCreateWindow(2560, 1440, "Arkanoid",
			glfwGetPrimaryMonitor(), NULL);
	if (!win)
	{
		glfwTerminate();
		return (-1);
	}
	env_init(&env);
	glfwMakeContextCurrent(win);
	glfwSetKeyCallback(win, key_callback);
	do_window(win, &env);
	glfwDestroyWindow(win);
	glfwTerminate();
	return (0);
}
