#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#include "ftrace.h"
#include "log.h"

static int trace_fd = -1;

// TODO: if passed a dir, generate filename with datestamp

static const char defaultdumpfilename[] = "/boot/trace.txt";
const char *ftracedumpname = defaultdumpfilename;

static void dump_trace(void)
{
	int tracein, traceout;
	ssize_t in = -1, out = -1;
	char buffer[4096];

	tracein = open("/sys/kernel/debug/tracing/trace", O_RDONLY);
	if (tracein == -1) {
		if (errno != -EEXIST) {
			output(0, "Error opening /sys/kernel/debug/tracing/trace : %s\n", strerror(errno));
			return;
		}
	}

	traceout = open(ftracedumpname, O_CREAT | O_WRONLY, 0600);
	if (traceout == -1) {
		output(0, "Error opening %s : %s\n", ftracedumpname, strerror(errno));
		return;
	}

	while (in != 0) {
		in = read(tracein, buffer, 4096);
		if (in > 0) {
			out = write(traceout, buffer, in);
			if (out == -1) {
				output(0, "Error writing trace to %s. %s\n", ftracedumpname, strerror(errno));
				goto fail;
			}
		}
	}
	if (in == -1) {
		output(0, "something went wrong reading from trace. %s\n", strerror(errno));
	}

	output(0, "Dumped trace to %s\n", ftracedumpname);
fail:
	fsync(traceout);
	close(tracein);
	close(traceout);
}

void setup_ftrace(void)
{
	//todo: check for root
	trace_fd = open("/sys/kernel/debug/tracing/tracing_on", O_WRONLY);
	if (trace_fd == -1) {
		if (errno != -EEXIST) {
			output(0, "Error opening tracing_on : %s\n", strerror(errno));
			return;
		}
	}
	output(0, "Opened ftrace tracing_on as fd %d\n", trace_fd);
	output(0, "Ftrace log will be dumped to %s\n", ftracedumpname);
}

void stop_ftrace(void)
{
	if (trace_fd != -1) {
		if (write(trace_fd, "0", 1) == -1) {
			output(0, "Stopping ftrace failed! %s\n", strerror(errno));
			return;
		}
		dump_trace();
		return;
	} else {
		output(0, "trace_fd was %d\n", trace_fd);
	}
}
