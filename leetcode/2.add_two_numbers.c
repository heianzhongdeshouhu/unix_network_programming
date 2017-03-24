#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

int list_release(struct ListNode *pl) {
    while (pl) {
        struct ListNode *pdel = pl;
        pl = pl->next;
        free(pdel);
    }
    return 0;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    assert(l1 && l2);

    struct ListNode *phead = NULL, *ptail = NULL;

    int ierror = 0;
    int iflag = 0;
    for ( ; l1 && l2; l1 = l1->next, l2 = l2->next) {
        struct ListNode *pnew = calloc(1, sizeof(struct ListNode));
        if (!pnew) {
            ierror = 1;
            break;
        }
        memset(pnew, 0, sizeof(*pnew));

        int isum = l1->val + l2->val + iflag;
        if (isum >= 10) {
            iflag = 1;
            isum -= 10;
        } else {
            iflag = 0;
        }
        pnew->val = isum;

        if (NULL == ptail) {
            phead = pnew;
            ptail = pnew;
        } else {
            ptail->next = pnew;
            ptail = pnew;
        }

    }
    if (ierror) {
        list_release(phead);
    } else {
        if (iflag) {
            struct ListNode *pnew = calloc(1, sizeof(struct ListNode));
            if (!pnew) {
                list_release(phead);
            }
            memset(pnew, 0, sizeof(*pnew));

            pnew->val = iflag;
            
            if (ptail) {
                ptail->next = pnew;
            }
        }
    }

    return phead;
}

int main(int argc, char *argv[]) {
    printf("this is a test ^_^\n");

    exit(0);
}
