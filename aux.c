#include "incApache.h"

void fail(const char *const msg)
{
	fprintf(stderr, "%s\n", msg);
	exit(EXIT_FAILURE);
}

void fail_errno(const char *const msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}

void *my_malloc(size_t size)
{
	void *result = malloc(size);
	if (result == NULL)
		fail("Cannot allocate memory with malloc");
	return result;
}

char *my_strdup(const char *const s)
{
	char *result = strdup(s);
	if (result == NULL)
		fail("Cannot allocate memory for strdup");
	return result;
}

static pthread_mutex_t my_timegm_mutex = PTHREAD_MUTEX_INITIALIZER;

time_t my_timegm(struct tm *tm)
{
	time_t ret;

	ret = timegm(tm);
	if (ret == -1)	fail_errno("Getting Time Error");

	return ret;
}
