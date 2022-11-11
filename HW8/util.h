#ifndef _UTIL_H_
#define _UTIL_H_

void generate_sequence(int xs,int currentlen,int seqlen,int *seq);/*found elements of matematical pattarn with recursive*/

void print_sequence(int *p,int len);/*print array*/

void check_loop_iterative(void (*f)(int,int,int,int *), int xs, int seqlen, int *loop, int *looplen);/*searching loop in sequence arraay*/

int has_loop(int *arr, int n, int looplen, int *ls, int *le);/* checking loop in known looplen*/

void hist_of_firstdigits(void (*f)(int,int,int,int *), int xs, int seqlen, int *h, int digit);/*fill histogram array that name  is h*/

int find_digit(int num);/* find first digit a number*/

int start_loop_loc(int looplen,int *main_array,int n,int size,int control[]);/*for searching 1.L that define in has_loop commnets*/

int my_strcmp(char *str1,char *str2);/*strcmp function that ı have done*/

int my_strlen( char *str);/* strlen function that ı have done*/

#endif /* _UTIL_H_ */
