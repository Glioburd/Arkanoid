/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arkanoid.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsauvair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 23:32:58 by gsauvair          #+#    #+#             */
/*   Updated: 2015/05/03 23:33:02 by gsauvair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARKANOID_H
# define ARKANOID_H

# include "glfw/include/GLFW/glfw3.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <errno.h>

# define X_BEGIN -0.918f
# define Y_BEGIN 0.92f
# define X_VAR 0.071f
# define X_INC 0.153f
# define Y_VAR 0.035f

typedef struct s_squa	t_squa;
struct					s_squa
{
	float				x;
	float				y;
	char				type;
};

typedef struct s_ball	t_ball;
struct					s_ball
{
	float				x;
	float				y;
	float				move_x;
	float				move_y;
};

typedef struct s_env	t_env;
struct					s_env
{
	int					width;
	int					height;
	float				bar;
	t_ball				ball;
	char				map[140];
	t_squa				squa;
	int					score;
	int					life;
};

void					square_create(t_env *env);
void					the_bar(t_env *env);
void					the_ball(t_env *env);
void					ft_error(const char *str);
int						test_col(t_env *env, int i, int *test);
void					aff_score(t_env *env);
void					aff_zero(float x);
void					aff_un(float x);
void					aff_deux(float x);
void					aff_trois(float x);
void					aff_quatre(float x);
void					aff_cinq(float x);
void					aff_six(float x);
void					aff_sept(float x);
void					aff_huit(float x);
void					aff_neuf(float x);
int						check_win(t_env *env);

#endif
