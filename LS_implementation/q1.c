#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <sys/stat.h>
#include <stdint.h>
#include <sys/sysmacros.h>
#include <pwd.h>

int main(int argc, char *argv[])
{

	if (argc != 2)
	{
		argv[1] = ".";
	}

	DIR *dp = opendir(argv[1]);
	struct dirent *d;
	int totalsize = 0;
	struct stat sb;

	int fd = open("list.txt", O_CREAT | O_RDWR | O_TRUNC , S_IRUSR | S_IWUSR);
	dup2(fd, 1);
	close(fd);

	while ((d = readdir(dp)) != NULL)
	{
		char *c = d->d_name;
		char *k = argv[1];
		char destination[1000];  
		strcpy(destination, k);

		strcat(destination, (char *)"/");
		strcat(destination, c);
		lstat(destination, &sb);

		struct passwd *pw = getpwuid(sb.st_uid);
		struct passwd *pw2 = getpwuid(sb.st_gid);
	 
		printf((S_ISLNK(sb.st_mode)) ? "l" : "");
		printf((S_ISREG(sb.st_mode)) ? "-" : "");
		printf((S_ISBLK(sb.st_mode)) ? "b" : "");
		printf((S_ISDIR(sb.st_mode)) ? "d" : "");
		printf((S_ISCHR(sb.st_mode)) ? "c" : "");
		printf((S_ISFIFO(sb.st_mode)) ? "p" : "");
		

		printf((sb.st_mode & S_IRUSR) ? "r" : "-");
		printf((sb.st_mode & S_IWUSR) ? "w" : "-");
		printf((sb.st_mode & S_IXUSR) ? "x" : "-");
		printf((sb.st_mode & S_IRGRP) ? "r" : "-");
		printf((sb.st_mode & S_IWGRP) ? "w" : "-");
		printf((sb.st_mode & S_IXGRP) ? "x" : "-");
		printf((sb.st_mode & S_IROTH) ? "r" : "-");
		printf((sb.st_mode & S_IWOTH) ? "w" : "-");
		printf((sb.st_mode & S_IXOTH) ? "x" : "-");
		printf(" %ju %10s %10s %10jd %.16s %20s", (uintmax_t)sb.st_nlink, pw->pw_name,pw2->pw_name, (intmax_t)sb.st_size, ctime(&sb.st_mtime), d->d_name );
		// printf("%ju %ju ",(uintmax_t)sb.st_uid, (uintmax_t)sb.st_gid);
		// printf("%jd ", (intmax_t)sb.st_size);
		// printf("%s", ctime(&sb.st_mtime));
		// printf("%s ",d->d_name);
		printf("\n");
	}

	closedir(dp);
	return 0;
}
