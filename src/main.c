#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/utsname.h>
#include <time.h>

void GetOSInfo();
void GetDestkopEnvironment();
void GetCurrentTime();

int main()
{
    GetOSInfo();
    GetDestkopEnvironment();
    GetCurrentTime();
    return 1;
}


//
//* Fetches the current OS
//
void GetOSInfo() {
    struct utsname SystemInfo;
    if (uname(&SystemInfo) == 0) {
        printf("╭─ %s\n", SystemInfo.nodename);
        printf("├─ %s\n", SystemInfo.release);
    } else {
        perror("uname");
    }
}

//
//* Fetches the current Desktop Environment
//
void GetDestkopEnvironment() {
    char *DesktopEnvironment = getenv("XDG_CURRENT_DESKTOP");
    if (DesktopEnvironment != NULL) {
        printf("├─ %s\n", DesktopEnvironment);
    } else {
        printf("Desktop Environment: Not detected\n");
    }
}

//
//* Gets the current time
//
void GetCurrentTime() {
    time_t TimeNow;
    struct tm *TimeInfo;
    char buffer[26];

    time(&TimeNow);
    TimeInfo = localtime(&TimeNow);

    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", TimeInfo);
    printf("╰─󰥔 %s\n", buffer);
}
