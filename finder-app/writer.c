#include <fcntl.h>
#include <limits.h> //To get PATH_MAX
#include <string.h>
#include <syslog.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>


int main(int argc,char *argv[]) {
    int fd;
    //open log
    openlog("writer", LOG_PID, LOG_USER);
    if (argc != 3) {
        syslog(LOG_ERR, "This is a log message: %s", "Missing argument");
        closelog();
        exit (EXIT_FAILURE);
    }
    const char *path = argv[1];
    const char *text = argv[2];
    fd = creat(path, 0644);
    if (fd == -1) {
        syslog(LOG_ERR, "This is a log message: %s", "Unable to create file!");
        closelog(); 
        exit (EXIT_FAILURE);
        //error handling
    }
    int nr = write (fd, text, strlen (text));
    syslog(LOG_ERR, "Writing %s to %s", text,path);
    if (nr == -1) {
        syslog(LOG_ERR, "This is a log message: %s", "Unable to write to file!");
        //error handling
    }
    closelog(); // Close the log
    return 0;
}
