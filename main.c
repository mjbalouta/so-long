int main(int ac, char **av)
{
	int	i;
	char *ext;

	i = 0;
	if (ac != 2)
		return (write(1, "Error./nMissing map.", 19));
	ext = ft_strrchr(av[1], '.');
	if (ext[1] != 'b' || ext[2] != 'e' || ext[3] != 'r' || ext[4])
		return (write(1, "Error./nWrong file. Must be .ber.", 32));
	
}