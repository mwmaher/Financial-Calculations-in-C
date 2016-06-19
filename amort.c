/* amort.c

   By Michael W. Maher

   Ver 1.0 6/21/93

   DESCRIPTION: The following program computes amortization tables.

   PORTABILITY: ANSI Standard C
*/

/**************************** Include Files ********************************/
#include <math.h>
#include <stdio.h>
#include <string.h>
#include "finance.h"
#include "finance.c"

/************************** Constants & Macros *****************************/
#define PASS 0
#define FAIL 1

/*************************** Data Structures *******************************/


/************************** function prototypes ****************************/
int  main(int argc, char **argv);
int report(unsigned periods,
	   double balance,
	   double payment,
	   double rate,
	   char  *pay_time);


int main(int argc, char **argv)
  {
  double   amount    = 0.0,
	   rate    = 0.0,
	   payment = 0.0;
  unsigned periods = 0;

  if (argc != 5)
    fprintf(stdout, "\n"
	       "AMORT.C By Michael W. Maher\n"
	       "Ver 1.0: 6/22/93\n"
	       "Amortize with equal payments.\n"
	       "USAGE: amort amount periods rate {-b|-e}\n\n"
	       "amount  amount\n"
	       "periods number of periods\n"
	       "rate    rate per period\n"
	       "-b      make payment at the beginning of the period\n"
	       "-e      make payment at the end of the period\n\n"
	       "EXAMPLE: amort 5000 60 .01 -e\n"
	       "$5000 60 months @ 12%% annual rate end of month payment.\n");
  else
    {
    amount    = atof(argv[1]);
    periods = (unsigned) atof(argv[2]);
    rate    = atof(argv[3]);
    if (strcmp(argv[4], "-b") == 0)
      payment = amount * p_to_ad(rate, periods);
    else
      payment = amount * p_to_a(rate, periods);
    report(periods, amount, payment, rate, argv[4]);
    }
  return(0);
  }


int report(unsigned periods,
	   double balance,
	   double payment,
	   double rate,
	   char *pay_time)
  {
  char *paid;
  unsigned i;
  double pay_int        = 0.0,
	 pay_prin       = 0.0,
	 total_pay      = 0.0,
	 total_pay_int  = 0.0,
	 total_pay_prin = 0.0;

  if (strcmp(pay_time, "-b") == 0)
    paid = "beg.";
  else
    paid = "end";
  printf("\n  Terms: amount $%.2f periods %d rate %.7f pay %s of period\n\n",
	  balance,
	  periods,
	  rate,
	  paid);
  printf("  Period      Beginning        Payment"
	 "       Principal       Interest\n");
  for (i = 1; i <= periods; i++)
    {
    if ((strcmp(pay_time, "-b") != 0) || (i != 1))
      pay_int = balance * rate;
    pay_prin = payment - pay_int;
    printf("  %3d        %10.2f     %10.2f      %10.2f     %10.2f\n",
	   i,
	   balance,
	   payment,
	   pay_prin,
	   pay_int);
    balance         = balance - pay_prin;
    total_pay      += payment;
    total_pay_int  += pay_int;
    total_pay_prin += pay_prin;
    }
  printf("\n   Total                   %11.2f     %11.2f    %11.2f\n",
	 total_pay,
	 total_pay_prin,
	 total_pay_int);
  return(0);
  }
