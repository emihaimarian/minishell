void		debug_signal(int sig)
{
	ft_putstr_fd("SIGNAL [", 2);
	ft_putnbr_fd(sig, 2);
	(sig == SIGINT) ? ft_putendl_fd("] > SIGINT", 2) : (0);
	(sig == SIGKILL) ? ft_putendl_fd("] > SIGKILL", 2) : (0);
	(sig == SIGTSTP) ? ft_putendl_fd("] > SIGTSTP", 2) : (0);
	(sig == SIGCONT) ? ft_putendl_fd("] > SIGCONT", 2) : (0);
	(sig == SIGCHLD) ? ft_putendl_fd("] > SIGCHLD", 2) : (0);
	(sig == SIGWINCH) ? ft_putendl_fd("] > SIGWINCH", 2) : (0);
}
