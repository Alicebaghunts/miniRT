/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisharu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 09:34:42 by alisharu          #+#    #+#             */
/*   Updated: 2025/09/16 16:02:37 by alisharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object_types.h"
#include <stdio.h>

static void	print_color(t_color *c)
{
	if (!c)
		return ;
	printf("Color: (R:%d, G:%d, B:%d)\n", c->red, c->green, c->blue);
}

static void	print_vec(const char *name, t_vector *v)
{
	if (!v)
		return ;
	printf("%s: (%.2f, %.2f, %.2f)\n", name, v->x, v->y, v->z);
}

static void	print_ambient(t_ambient *ambient)
{
	if (!ambient)
		return ;
	printf("\n-- Ambient --\n");
	printf("Light Ratio: %.2f\n", ambient->light_ratio);
	print_color(ambient->color);
}

static void	print_camera(t_camera *camera, int i)
{
	if (!camera)
		return ;
	printf("\n-- Camera %d --\n", i);
	print_vec("Position", camera->position);
	print_vec("Direction", camera->direction);
	printf("FOV: %d\n", camera->field_of_view);
}

static void	print_light(t_light *light, int i)
{
	if (!light)
		return ;
	printf("\n-- Light %d --\n", i);
	print_vec("Position", light->position);
	printf("Brightness Ratio: %.2f\n", light->brightness_ratio);
	print_color(light->color);
}

static void	print_object(t_object *obj, int i)
{
	t_sphere	*s;
	t_plane		*p;
	t_cylinder	*c;

	if (!obj)
		return ;
	printf("\n-- Object %d (%c) --\n", i, obj->type);
	if (obj->type == 's')
	{
		s = obj->data->sphere;
		print_vec("Position", s->position);
		printf("Diameter: %.2f\n", s->diameter);
		print_color(s->color);
	}
	else if (obj->type == 'p')
	{
		p = obj->data->plane;
		print_vec("Position", p->position);
		print_vec("Normal", p->normal);
		print_color(p->color);
	}
	else if (obj->type == 'c')
	{
		c = obj->data->cylinder;
		print_vec("Position", c->position);
		print_vec("Direction", c->direction);
		printf("Diameter: %.2f, Height: %.2f\n", c->diameter, c->height);
		print_color(c->color);
	}
}

void	print_scene(t_scene *scene)
{
	int		i;
	t_list	*cam;
	t_list	*l;
	t_list	*o;

	if (!scene)
		return ;
	print_ambient(scene->ambient);
	i = 1;
	cam = scene->camera;
	while (cam)
	{
		print_camera((t_camera *)cam->content, i);
		cam = cam->next;
		i++;
	}
	i = 1;
	l = scene->lights;
	while (l)
	{
		print_light((t_light *)l->content, i);
		l = l->next;
		i++;
	}
	i = 1;
	o = scene->objects;
	while (o)
	{
		print_object((t_object *)o->content, i);
		o = o->next;
		i++;
	}
}
