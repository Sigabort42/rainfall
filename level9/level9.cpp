class	N {

public:
	N(int nb)
	{
		this->nb = nb;
	}
	virtual setAnnotation(char *str)
	{
		memcpy(this->s, str, strlen(str));
	}
	N operator-(N &rhs)
	{
		return N(this->n - rhs.n);
	}
	N operator+(N &rhs)
	{
		return N(this->n + rhs.n);
	}	

private:
	unsigned int	nb;
	char		s[100];
	
	
}



	int	main(int ac, char **av)
{
	if (ac <= 1)
		exit(1);

	N	*a = new N(5);	
	N	*b = new N(6);
	
	N::setAnnotation(av[1]);
	return (0);
}
