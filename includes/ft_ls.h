/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwing <cwing@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 02:13:55 by cwing             #+#    #+#             */
/*   Updated: 2020/05/18 20:38:50 by cwing            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include "../libft/includes/libft.h"
# include <sys/types.h>
# include <dirent.h>
# include <limits.h>
# include <sys/stat.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <errno.h>
# include <termios.h>
# include <sys/ioctl.h>

# define RED_T			"\x1b[31m"
# define GRE_T			"\x1b[32m"
# define BLU_T			"\x1b[36m"
# define YWL_T			"\x1b[33m"
# define STD_T			"\x1b[0m"

# ifndef LINK_MAX
#  define LINK_MAX 1024
# endif

# ifndef MAXNAMLEN
#  define MAXNAMLEN 255
# endif

# ifndef PATH_MAX
#  define PATH_MAX 1024
# endif

typedef struct			s_slags
{
	char				l;
	char				rr;
	char				a;
	char				r;
	char				t;
	char				gg;
	char				ff;
	char				one;
	char				illegal;
	int					no_one_path;
}						t_flags;

typedef struct			s_dir
{
	char				*name;
	char				*chmod;
	char				*u_name;
	char				*u_group;
	char				*time_mod;
	char				*linkpath;
	time_t				timemod_d;
	blkcnt_t			blocks;
	t_flags				*flags;
	char				*size;
	nlink_t				links;
	int					len;
	unsigned int		count_dirs;
	struct s_dir		*next;
}						t_dir;

typedef struct stat		t_stat;
typedef struct dirent	t_dirent;

int						get_stat(t_dir *dir);
t_dir					*get_dir_list(char *path, t_flags **flag);
char					*get_user_name(uid_t uid);
char					*get_group(gid_t gid);
char					*get_chmod(mode_t mode);
char					*get_time(time_t *time_);
void					free_t_dir(t_dir **src);
void					no_such_file(char *path);
t_flags					*get_flags(int argc, char **argv);
void					get_all_time(t_dir *elem, t_stat *stat_);
t_list					*get_dirs(int argc, char **argv);
void					ft_free_lst(t_list **head);
void					check_names(t_list *head, t_flags **flags);
void					sort_dirs(t_dir **head);
blkcnt_t				summ_blocks(t_dir *head);
void					simple_print(t_dir *head, char all_mod, int col);
void					all_print(t_dir *head, char all_mod, int len);
void					main_print(t_dir *head);
int						dirs_count(t_list *head);
void					run_ls(char *path, t_flags **flags, int argc);
char					*get_full_name(char *path_name, char *name);
int						open_single_file(char *path, t_flags **flags);
t_dir					*new_t_dir(char *name, char *path, t_flags **flags);
void					print_one(t_dir *head, char all_mod);
void					print_name(t_dir *head);
void					ft_printnum(int num);
void					f_print(t_dir *head);
int						get_space(t_dir *head);
void					print_space(t_dir *head, int len);
void					permission_denied(t_list *head, t_flags *flags);
int						max_name_len(t_dir *head);
int						is_flag(char flag);

#endif
