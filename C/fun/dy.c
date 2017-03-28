/*
17:30


Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
the contiguous subarray [4,−1,2,1] has the largest sum = 6.


 * 
 */
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>

typedef enum array_state{
    __invalid,
    __sum_front,
    __sum_behind_negative,
    __sum_behind_positive
}as;


typedef struct _sum_info {
    as flag_status;
    int ustart;
    int uend;
    int usum_prev;
    int usum_behind;
    int usum_max;
} sum_info;

/*
 * did not compatible with the array with the element of 0.
 */
int dy(int *nums, int numsSize) {
    assert(nums);

    sum_info si;

    int imax_target = 0;
    int iinit = 0;
    while (1) {
        memset(&si, 0, sizeof(si));

        int j = iinit;
        for ( ; j < numsSize; j++) {
            switch (si.flag_status) {
                case __invalid:
                    {
                        if (nums[j] >= 0) {
                            si.flag_status = __sum_front;
                            si.ustart = j;
                            si.uend = j;
                            si.usum_prev += nums[j];
                            si.usum_max = si.usum_prev;
                        } 

                        break;
                    }
                case __sum_front:
                    {
                        if (nums[j] >= 0) {
                            si.uend = j;
                            si.usum_prev += nums[j];
                            si.usum_max = si.usum_prev;
                        } else {
                            si.flag_status = __sum_behind_negative;
                            si.usum_behind += nums[j];
                        }

                        break;
                    }
                case __sum_behind_negative:
                    {
                        if (nums[j] < 0) {
                            si.usum_behind += nums[j];
                        } else {
                            si.flag_status = __sum_behind_positive;
                            si.usum_behind += nums[j];
                        }

                        break;
                    }
                case __sum_behind_positive:
                    {
                        if (nums[j] >= 0) {
                            si.usum_behind += nums[j];
                        } else {
                            int sum_temp = si.usum_prev + si.usum_behind;
                            if (sum_temp > si.usum_max) {
                                si.usum_max = sum_temp;
                                si.uend = j - 1;
                            }

                            si.flag_status = __sum_behind_negative;
                            si.usum_prev = sum_temp;
                            si.usum_behind = 0;
                            j--;        /* the tricky part */

                        }

                        break;
                    }
                default:
                    {
                        break;
                    }

            }
        }

        int bexit = 0;
        switch (si.flag_status) {
            case __invalid: 
                {
                    // do not need to do anything, just exit.
                    bexit = 1;
                    break;
                }
            case __sum_front:
                {
                    //subarray
                    //printf("%d\t%d\tsum=%d\n", si.ustart, si.uend, si.usum_prev);
                    //printf("%d\t%d\tsum=%d\n", si.ustart, si.uend, si.usum_max);
                    if (imax_target < si.usum_max) {
                        imax_target = si.usum_max;
                    }

                    break;
                }
            case __sum_behind_negative:
                {
                    //subarray
                    //printf("%d\t%d\tsum=%d\n", si.ustart, si.uend, si.usum_prev);
                    //printf("%d\t%d\tsum=%d\n", si.ustart, si.uend, si.usum_max);
                    if (imax_target < si.usum_max) {
                        imax_target = si.usum_max;
                    }

                    break;
                }
            case __sum_behind_positive:
                {
                    //subarray
                    int sum_temp = si.usum_prev + si.usum_behind;
                    if (sum_temp > si.usum_max) {
                        si.uend = j--;
                        si.usum_max = sum_temp;
                    } 

                    //printf("%d\t%d\tsum=%d\n", si.ustart, si.uend, si.usum_prev);
                    //printf("%d\t%d\tsum=%d\n", si.ustart, si.uend, si.usum_max);
                    if (imax_target < si.usum_max) {
                        imax_target = si.usum_max;
                    }

                    break;
                }

        }

        if (bexit) {
            break;
        }

        int k = si.ustart + 1;
        for ( ; k < numsSize; k++) {
            if (nums[k] <= 0) {
                break;
            }
        }

        if (k == numsSize) {
            break;
        } else {
            iinit = k;
        }


    }

    return imax_target;
}

int main(int argc, char *argv[]) {

    int iarray[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    //int iarray[] = {1};

    int istart, iend;
    dy(iarray, sizeof(iarray)/ sizeof(iarray[0]), &istart, &iend);


    exit(0);
}
