/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_to_nine.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsauvair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 23:33:56 by gsauvair          #+#    #+#             */
/*   Updated: 2015/05/03 23:33:57 by gsauvair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

void	aff_cinq(float x)
{
	glBegin(GL_LINES);
	glColor3f(0.9f, 0.9f, 0.9f);
	glVertex2f(x, -0.9f);
	glVertex2f(x + 0.04f, -0.9f);
	glVertex2f(x - 0.005f, -0.905f);
	glVertex2f(x - 0.005f, -0.945f);
	glVertex2f(x, -0.945f);
	glVertex2f(x + 0.04f, -0.945f);
	glVertex2f(x + 0.045f, -0.95f);
	glVertex2f(x + 0.045f, -0.995f);
	glVertex2f(x, -0.995f);
	glVertex2f(x + 0.04f, -0.995f);
	glEnd();
}

void	aff_six(float x)
{
	glBegin(GL_LINES);
	glColor3f(0.9f, 0.9f, 0.9f);
	glVertex2f(x, -0.9f);
	glVertex2f(x + 0.04f, -0.9f);
	glVertex2f(x - 0.005f, -0.905f);
	glVertex2f(x - 0.005f, -0.945f);
	glVertex2f(x - 0.005f, -0.95f);
	glVertex2f(x - 0.005f, -0.995f);
	glVertex2f(x, -0.995f);
	glVertex2f(x + 0.04f, -0.995f);
	glVertex2f(x + 0.045f, -0.95f);
	glVertex2f(x + 0.045f, -0.995f);
	glVertex2f(x, -0.945f);
	glVertex2f(x + 0.04f, -0.945f);
	glEnd();
}

void	aff_sept(float x)
{
	glBegin(GL_LINES);
	glColor3f(0.9f, 0.9f, 0.9f);
	glVertex2f(x, -0.9f);
	glVertex2f(x + 0.04f, -0.9f);
	glVertex2f(x + 0.045f, -0.905f);
	glVertex2f(x + 0.045f, -0.945f);
	glVertex2f(x + 0.045f, -0.95f);
	glVertex2f(x + 0.045f, -0.995f);
	glEnd();
}

void	aff_huit(float x)
{
	glBegin(GL_LINES);
	glColor3f(0.9f, 0.9f, 0.9f);
	glVertex2f(x, -0.9f);
	glVertex2f(x + 0.04f, -0.9f);
	glVertex2f(x - 0.005f, -0.905f);
	glVertex2f(x - 0.005f, -0.945f);
	glVertex2f(x - 0.005f, -0.95f);
	glVertex2f(x - 0.005f, -0.995f);
	glVertex2f(x, -0.995f);
	glVertex2f(x + 0.04f, -0.995f);
	glVertex2f(x + 0.045f, -0.905f);
	glVertex2f(x + 0.045f, -0.945f);
	glVertex2f(x + 0.045f, -0.95f);
	glVertex2f(x + 0.045f, -0.995f);
	glVertex2f(x, -0.945f);
	glVertex2f(x + 0.04f, -0.945f);
	glEnd();
}

void	aff_neuf(float x)
{
	glBegin(GL_LINES);
	glColor3f(0.9f, 0.9f, 0.9f);
	glVertex2f(x, -0.9f);
	glVertex2f(x + 0.04f, -0.9f);
	glVertex2f(x - 0.005f, -0.905f);
	glVertex2f(x - 0.005f, -0.945f);
	glVertex2f(x, -0.995f);
	glVertex2f(x + 0.04f, -0.995f);
	glVertex2f(x + 0.045f, -0.905f);
	glVertex2f(x + 0.045f, -0.945f);
	glVertex2f(x + 0.045f, -0.95f);
	glVertex2f(x + 0.045f, -0.995f);
	glVertex2f(x, -0.945f);
	glVertex2f(x + 0.04f, -0.945f);
	glEnd();
}
