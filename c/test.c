#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int format_time(char *ptime, char *pformatted) {
    time_t rawtime = 1479917095;
           struct tm * timeinfo;
                      char buffer [128];

                                  timeinfo = localtime (&rawtime);

                                              strftime (buffer,sizeof(buffer),"Now is %Y/%m/%d %H:%M:%S",timeinfo);
}

int main(int argc, char *argv[]) {
    char time_formatted[1024];
    format_time("1479917095", time_formatted);
           puts (buffer);

    exit(0);
}
