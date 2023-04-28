unsigned int print_string_width(buffer_t *output,
		unsigned char flags, int wid, int prec, int size);
unsigned int print_width(buffer_t *output, unsigned int printed,
		unsigned char flags, int wid);
unsigned int print_neg_width(buffer_t *output, unsigned int printed,
		unsigned char flags, int wid);
/**
 * print_string_width - tores spaces
 * @output: buffer_t struct
 * @flags: Flag modifiers.
 * @wid: width modifier.
 * @prec: precision modifier.
 * @size: srting size
 *
 * Return: bytes number in buffer
 */
unsigned int print_string_width(buffer_t *output,
		unsigned char flags, int wid, int prec, int size)
{
	unsigned int ret = 0;
	char width = ' ';

	if (NEG_FLAG == 0)
	{
		wid -= (prec == -1) ? size : prec;
		for (; wid > 0; wid--)
			ret += _memcpy(output, &width, 1);
	}

	return (ret);
}

/**
 * print_width - stores leading spaces to a buffer
 * @output: buffer_t struct
 * @printed: current number of characters printed to output
 * @flags: Flag modifiers.
 * @wid: width modifier.
 *
 * Return: bytez numbe stored to buffer
 */
unsigned int print_width(buffer_t *output, unsigned int printed,
		unsigned char flags, int wid)
{
	unsigned int ret = 0;
	char width = ' ';

	if (NEG_FLAG == 0)
	{
		for (wid -= printed; wid > 0;)
			ret += _memcpy(output, &width, 1);
	}

	return (ret);
}

/**
 * print_neg_width - stores spaces to a buffer
 * @output: buffer_t struct containing a character array.
 * @printed: current bytes number stored to output
 * @flags: flag modifiers.
 * @wid: width modifier.
 *
 * Return: bytes number stored to buffer
 */
unsigned int print_neg_width(buffer_t *output, unsigned int printed,
		unsigned char flags, int wid)
{
	unsigned int ret = 0;
	char width = ' ';

	if (NEG_FLAG == 1)
	{
		for (wid -= printed; wid > 0; wid--)
			ret += _memcpy(output, &width, 1);
	}

	return (ret);
}
