/* amort2.c

   By Michael W. Maher

   Ver 1.0 8/2/94

   DESCRIPTION: The following program computes amortization tables based
                on the principle, equal payment, and interest rate.

   PORTABILITY: ANSI Standard C
   
   NOTES:	When compiling with the HPUX 9.0 C++ compiler be sure to 
   	        compile with the math library (-lm).  For example:
   	        
   	        CC -Aa -o amort2 amort2.c -lm
*/

/**************************** Include Files ********************************/
#include <stdio.h>
#include <string.h>
#include "finance.c"

/************************** Constants & Macros *****************************/

/*************************** Data Structures *******************************/


/************************** function prototypes ****************************/
int  main(int argc, char **argv);
int report(double balance,
	   double payment,
	   double rate,
	   char *pay_time);


int main(int argc, char **argv)
  {
  double   amount  = 0.0,
	   rate    = 0.0,
	   payment = 0.0;
  unsigned periods = 0;

  if (argc != 5)
    fprintf(stdout, "\n"
	       "amort2 By Michael W. Maher\n"
	       "Ver 1.0: 8/2/94\n"
	       "Amortize with equal payments.\n"
	       "USAGE: amort2 amount payment rate {-b|-e}\n\n"
	       "amount  amount\n"
	       "payment amount paid per period\n"
	       "rate    rate per period\n"
	       "-b      make payment at the beginning of the period\n"
	       "-e      make payment at the end of the period\n\n"
	       "EXAMPLE: amort2 5000 500 .01 -e\n"
	       "$5000, $500 payment, 12%% annual rate end of month payment.\n");
  else
    {
    amount  = atof(argv[1]);
    payment = atof(argv[2]);
    rate    = atof(argv[3]);
    report(amount, payment, rate, argv[4]);
    }
  return(0);
  }


int report(double balance,
	   double payment,
	   double rate,
	   char *pay_time)
  {
  char *paid;
  unsigned i = 0;
  double pay_int        = 0.0,
	 pay_prin       = 0.0,
	 total_pay      = 0.0,
	 total_pay_int  = 0.0,
	 total_pay_prin = 0.0;

  if (strcmp(pay_time, "-b") == 0)
    paid = "beg.";
  else
    paid = "end";
  printf("\n  Terms: amount $%.2f payment $%.2f rate %.7f pay %s of period\n\n",
	  balance,
	  payment,
	  rate,
	  paid);
  printf("  Period      Beginning        Payment       Principal       Interest\n");
  while (balance >= 0)
    {
    i++;
    if ((strcmp(pay_time, "-b") != 0) || (i != 1))
      pay_int = balance * rate;
    if (payment > balance + pay_int)
      payment = balance + pay_int;
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
