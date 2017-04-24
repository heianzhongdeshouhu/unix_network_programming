#include "cipher.h"

using namespace mgtv;

typedef enum operate_type {
    __encrypt,
    __decrypt    
} ot;

int param_is_valid(int argc, char *argv[], ot *pot) {
    if (5 == argc) {
        if (strcmp(argv[1], "encrypt")) {
            return 0;
        } else {
            *pot = __encrypt;
            return 1;
        }
    } else if (4 == argc) {
        if (strcmp(argv[1], "decrypt")) {
            return 0;
        } else {
            *pot = __decrypt;
            return 1;
        }
    } else {
        return 0;
    }
}

int main(int argc, char *argv[]) {
    ot _ot;
    if (0 == param_is_valid(argc, argv, &_ot)) {
        const char *usage = "parameter invalid!\n\t1. ./a.out encrypt key price time\n\t2. ./a.out decrypt key encrypted\n";
        printf(usage);
        exit(0);
    }


    if (__decrypt == _ot) {
        string key          = argv[2];
        string encrypted    = argv[3];

        WinnerPrice winner_price(key);

        int32_t price_0     =  winner_price.GetPrice(encrypted);
        printf("%d\n", price_0);
    } else {
        string key          = argv[2];
        int32_t price       = atoi(argv[3]);
        time_t now          = atoi(argv[4]);

        string encrypted;
        WinnerPrice winner_price(key);
        encrypted           = winner_price.GenEncrypted(price, now);

        printf(encrypted.c_str());
        printf("\n");
    }

    exit(0);
}
