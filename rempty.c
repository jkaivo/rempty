#define _XOPEN_SOURCE 700
#include <errno.h>
#include <ftw.h>
#include <limits.h>
#include <locale.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#ifndef OPEN_MAX
#define OPEN_MAX _POSIX_OPEN_MAX
#endif

static char *progname = NULL;
static int retval = 0;

static int rempty(const char *path, const struct stat *st, int type, struct FTW *ftw)
{
	(void)st;
	(void)ftw;

	if (type != FTW_DP) {
		return 0;
	}

	if (rmdir(path) == 0) {
		return 0;
	}

	if (errno == EEXIST || errno == ENOTEMPTY) {
		return 0;
	}

	fprintf(stderr, "%s: %s: %s\n", progname, path, strerror(errno));
	retval = 1;

	return 0;
}

static void usage(void)
{
	fprintf(stderr, "usage: %s dir...\n", progname);
}

int main(int argc, char *argv[])
{
	progname = argv[0];
	setlocale(LC_ALL, "");
	
	int c;
	while ((c = getopt(argc, argv, "")) != -1) {
		switch (c) {
		default:
			usage();
			return 1;
		}
	}

	if (optind >= argc) {
		usage();
		return 1;
	}

	while (optind < argc) {
		if (nftw(argv[optind], rempty, OPEN_MAX, FTW_DEPTH) != 0) {
			fprintf(stderr, "%s: %s: %s\n", progname, argv[optind],
				strerror(errno));
		}
		optind++;
	}

	return retval;
}
