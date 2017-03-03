#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int format_time(const char *ptime, char *pformatted, size_t len_pformatted) {
    string result=ptime;
    stringstream stream;
    time_t rawtime = 0;
    stream<<result;
    stream>>rawtime;//n等于10000

    struct tm * timeinfo;

    timeinfo = localtime (&rawtime);

    strftime (pformatted, len_pformatted,"%Y-%02m-%02d %02H:%02M:%02S",timeinfo);
}

int main(int argc, char *argv[]) {
    char time_formatted[1024];
    const char *ptemp = "1479917095";
    format_time(ptemp, time_formatted, 1024);

    puts (time_formatted);

    exit(0);
}
