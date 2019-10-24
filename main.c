/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulebugl <lulebugl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 14:45:18 by lulebugl          #+#    #+#             */
/*   Updated: 2019/10/18 17:45:38 by lulebugl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//int		main()
//{
//	int fd;
//	char *ptr;
//	ptr = malloc(1000);
//	fd = open("get_next_line_utils.c", O_RDONLY );
//	while (1)
//	{
//		if ((get_next_line(fd, &ptr)) <= 0)
//			break;
//		printf("%s\n", ptr);
//		free (ptr);
//	}
//}
//

int		main(int argc, char **argv)
{
	int fd;
	char *line;
	int ret; /* printing gnl return value */
	int i;

	if (argc >= 2)
	{
		if (access(argv[1], F_OK) == 0)
		{
			i = 0;
			fd = open(argv[1], O_RDONLY);
			while((ret = get_next_line(fd, &line)) == 1)
			{
				i++;
				printf("MAIN:%d, line>%s\n", ret, line);
				free(line);
			}
			free(line);
			close(fd);
       	}
	}
	return (1);
}
