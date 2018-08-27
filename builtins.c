


int builtins(struct wrap *all)
{
	struct func builtins [] {
		{"exit", myexit},
		{"env", myenv},
		{NULL, NULL}
		};

	int count, cmp;

	while (builtins[count].cmd != NULL)
	{
		while(builtins[count].cmd[cmp] == all->cmd[cmp])
		{
		 	if (all->cmd[cmp] == '\0')
				if (builtins[count].cmd[cmd] == '\0')
					builtins[count].call(all);
			cmp++;
		}
		count++;
	}


}

void myenv (struct wrap *all)
{
	int count, length;

	while(all->env[count] != NULL)
	{
		while(all->env[count][length] != '\0')
			length++;

		write(1, all->env[count], length);
		length = 0;
		count++;
	}
}

void myexit (struct wrap *all)
{




