#include "libft.h"
#include "get_next_line.h"

int	main(void)
{
	char	*line;
	int		fd;

	fd = open("../includes/get_next_line.h", O_RDONLY);
	if (fd <= 0)
	{
		ft_putendl("Can't open");
		return (0);
	}
	while (get_next_line(fd, &line) > 0)
	{
		ft_putendl(line);
	}
	return (0);
}