int			is_char(char c)
{
	return (c == 'c');
}

int			is_str(char c)
{
	return (c == 's');
}

int			is_integer(char c)
{
	return (c == 'd' || c == 'i');
}

int			is_float(char c)
{
	return (c == 'f' || c == 'l');
}

int 		is_uinteger(char c)
{
	return (c == 'o' || c == 'u' || c == 'x' || c == 'X');
}
