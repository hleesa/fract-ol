/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 13:26:58 by salee2            #+#    #+#             */
/*   Updated: 2022/07/29 13:49:40 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*memjoin(void *data, ssize_t d_size, void *buff, ssize_t b_size)
{
	void	*ret;

	ret = malloc(sizeof(unsigned char) * (d_size + b_size + 1));
	if (ret == NULL)
	{
		if (data != NULL)
			free(data);
		return (NULL);
	}
	ft_line_move(ret, data, d_size);
	ft_line_move((unsigned char *)ret + d_size, buff, b_size);
	((unsigned char *)ret)[d_size + b_size] = '\0';
	if (data != NULL)
		free(data);
	return (ret);
}

ssize_t	buff_init(char *buff, t_line *repository)
{
	ssize_t	data_size;

	if (repository->size == 0)
		data_size = 0;
	else
	{
		ft_line_move((void *) buff, repository->data, repository->size);
		free(repository->data);
		data_size = repository->size;
		*repository = (t_line){NULL, 0};
	}
	return (data_size);
}

void	update_repository(t_line *repository, char *buff, \
		ssize_t newline_offset, ssize_t data_size)
{
	if (newline_offset + 1 < data_size)
	{
		repository->data = memjoin(NULL, 0, \
				buff + newline_offset + 1, data_size - (newline_offset + 1));
		if (repository->data == NULL)
		{
			repository->size = 0;
			return ;
		}
		repository->size = data_size - (newline_offset + 1);
	}
	return ;
}

void	get_one_line(t_line *ret, int fd, char *buff, t_line *repository)
{
	ssize_t	data_size;
	ssize_t	read_size;
	ssize_t	newline_offset;

	data_size = buff_init(buff, repository);
	while (1)
	{
		newline_offset = get_newline_offset(buff, '\n', data_size);
		if (newline_offset == -1)
			read_size = data_size;
		else
			read_size = newline_offset;
		ret->data = memjoin(ret->data, ret->size, buff, read_size);
		if (ret->data == NULL)
			return ;
		ret->size += read_size;
		if (newline_offset != -1)
			break ;
		data_size = read(fd, (void *) buff, BUFFER_SIZE);
		if (data_size < 1)
			break ;
	}
	if (data_size < 0)
		return ;
	update_repository(repository, buff, newline_offset, data_size);
}

char	*get_next_line(int fd)
{
	t_line			ret;
	char			*buff;
	static t_line	repository;

	if (fd < 0 || fd >= OPEN_MAX || BUFFER_SIZE < 0)
		return (0);
	buff = (char *) malloc(sizeof(char) * BUFFER_SIZE);
	if (buff == NULL)
		return (NULL);
	ret = (t_line){NULL, 0};
	get_one_line(&ret, fd, buff, &repository);
	if (ret.size == 0)
	{
		if (ret.data != NULL)
			free(ret.data);
		ret.data = NULL;
	}
	free(buff);
	return (ret.data);
}
