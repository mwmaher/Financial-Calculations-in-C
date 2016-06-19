/* FinaTest.C

   By Michael W. Maher

   Ver 1.0 1/25/93
       2.0 6/28/93

   DESCRIPTION: The following is a test program for the <finance.h>
		library of functions. It is designed to test a set of
		C financial related routines.

		Many of the functions tested were originally written by
		William Smith and first appeared in The C Users Journal
		- February 1993 in his article "A Library Of Financial
		Functions."

		I have added my own functions to the financial library as
		well as the appropriate test functions.

   PORTABILITY: ANSI Standard C
*/

/**************************** Include Files ********************************/
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
char test1(FILE *output);
char test2(FILE *output);
char test3(FILE *output);
char test4(FILE *output);
char test5(FILE *output);
char test6(FILE *output);
char test7(FILE *output);
char test8(FILE *output);
char test9(FILE *output);
char test10(FILE *output);
char test11(FILE *output);
char test12(FILE *output);
char test13(FILE *output);
char test14(FILE *output);
char *testout(char passfail, char *out);


int main(int argc, char **argv)
  {
  FILE *output = stdout;
  char buf[81];
  int  i = 1;

  fprintf(stdout, "\n"
		  "FINATEST.C By Michael W. Maher\n"
		  "Ver 1.0: 1/25/93\n"
		  "This program will test the functions found in "
		  "FINANCE.H\n");
  if ((argc > 2) || ((argc == 2) && (strncmp(argv[1], "/H", 2) == 0)))
    {
    fprintf(stdout, "\nParameters: [resultfile]|[/H]\n");
    return(0);
    }
  else if ((argc == 2) && ((output = fopen(argv[1], "rt")) != NULL))
    {
    fprintf(output, "ERROR: [%s] already exists.\n", argv[1]);
    return(0);
    }
  else if ((argc == 2) && ((output = fopen(argv[1], "wt")) == NULL))
    {
    fprintf(output, "ERROR: Unable to create [%s].\n", argv[1]);
    return(-1);
    }
  fprintf(output, "TEST #%d: %s\n", i++, testout(test1(output), buf));
  fprintf(output, "TEST #%d: %s\n", i++, testout(test2(output), buf));
  fprintf(output, "TEST #%d: %s\n", i++, testout(test3(output), buf));
  fprintf(output, "TEST #%d: %s\n", i++, testout(test4(output), buf));
  fprintf(output, "TEST #%d: %s\n", i++, testout(test5(output), buf));
  fprintf(output, "TEST #%d: %s\n", i++, testout(test6(output), buf));
  fprintf(output, "TEST #%d: %s\n", i++, testout(test7(output), buf));
  fprintf(output, "TEST #%d: %s\n", i++, testout(test8(output), buf));
  fprintf(output, "TEST #%d: %s\n", i++, testout(test9(output), buf));
  fprintf(output, "TEST #%d: %s\n", i++, testout(test10(output), buf));
  fprintf(output, "TEST #%d: %s\n", i++, testout(test11(output), buf));
  fprintf(output, "TEST #%d: %s\n", i++, testout(test12(output), buf));
  fprintf(output, "TEST #%d: %s\n", i++, testout(test13(output), buf));
  fprintf(output, "TEST #%d: %s\n", i++, testout(test14(output), buf));
  return(0);
  }


/***************************************************************************
   function: test1()

 parameters: output - stream to write test results to

    returns: PASS or FAIL

    purpose: To test the f_to_a() function.
****************************************************************************/
char test1(FILE *output)
  {
  char test = PASS;


  return(test);
  }


/***************************************************************************
   function: test2()

 parameters: output - stream to write test results to

    returns: PASS or FAIL

    purpose: To test the a_to_f_c() function.
****************************************************************************/
char test2(FILE *output)
  {
  char test = PASS;
  return(test);
  }


/***************************************************************************
   function: test3()

 parameters: output - stream to write test results to

    returns: PASS or FAIL

    purpose: To test the a_to_p() function.
****************************************************************************/
char test3(FILE *output)
  {
  char test = PASS;
  return(test);
  }


/***************************************************************************
   function: test4()

 parameters: output - stream to write test results to

    returns: PASS or FAIL

    purpose: To test the a_to_p_c() function.
****************************************************************************/
char test4(FILE *output)
  {
  char test    = PASS;
  return(test);
  }


/***************************************************************************
   function: test5()

 parameters: output - stream to write test results to

    returns: PASS or FAIL

    purpose: To test the a_to_f() function.
****************************************************************************/
char test5(FILE *output)
  {
  char     test    = PASS;
  double   future  = 0.0,
	   annuity = 0.0,
	   rate    = 0.0;
  unsigned periods = 0;

  /* test against know problem annuity problem */
  annuity = 30000.0;
  periods = 20;
  rate    = 0.05;
  future = annuity * a_to_f(rate, periods);
  if ((future < 991978.50) || (future > 991978.63))
    {
    printf("\nERROR: test 5 - future = %f\n", future);
    test = FAIL;
    }
  return(test);
  }

/***************************************************************************
   function: test6()

 parameters: output - stream to write test results to

    returns: PASS or FAIL

    purpose: To test the f_to_a_c() function.
****************************************************************************/
char test6(FILE *output)
  {
  char test = PASS;
  return(test);
  }


/***************************************************************************
   function: test7()

 parameters: output - stream to write test results to

    returns: PASS or FAIL

    purpose: To test the p_to_f() function.
****************************************************************************/
char test7(FILE *output)
  {
  char test        = PASS;
  double future    = 0.0,
	 present   = 0.0,
	 rate      = 0.0;
  unsigned periods = 0;

  present = 1500.00;
  rate    = 0.08;
  periods = 3;
  future = present * p_to_f(rate, periods);
  if ((future < 1889.56) || (future > 1990.59))
    {
    fprintf(output, "\nERROR: test 7 - future = %f\n", future);
    test = FAIL;
    }
  return(test);
  }


/***************************************************************************
   function: test8()

 parameters: output - stream to write test results to

    returns: PASS or FAIL

    purpose: To test the f_to_p_c() function.
****************************************************************************/
char test8(FILE *output)
  {
  char test = PASS;
  return(test);
  }

/***************************************************************************
   function: test9()

 parameters: output - stream to write test results to

    returns: PASS or FAIL

    purpose: To test the p_to_a() function.
****************************************************************************/
char test9(FILE *output)
  {
  double   loan,
	   rate,
	   payment,
	   yrs;
  char test = PASS;

  /* calculate the payment required to pay back a loan */
  loan = 100000.0;
  rate = 0.08;
  yrs  = 30.0;
  payment = loan * p_to_a(rate / 12.0, (unsigned) yrs * 12);
  if ((payment < 733.76) || (payment > 733.78))
    {
    fprintf(output, "\nERROR: test 9 - payment = %f\n", payment);
    test = FAIL;
    }
  return(test);
  }


/***************************************************************************
   function: test10()

 parameters: output - stream to write test results to

    returns: PASS or FAIL

    purpose: To test the p_to_a_c() function.
****************************************************************************/
char test10(FILE *output)
  {
  char test = PASS;
  return(test);
  }


/***************************************************************************
   function: test11()

 parameters: output - stream to write test results to

    returns: PASS or FAIL

    purpose: To test the f_to_p() function.
****************************************************************************/
char test11(FILE *output)
  {
  char test = PASS;
  double future    = 0.0,
	 present   = 0.0,
	 rate      = 0.0;
  unsigned periods = 0;

  future  = 6838.40;
  rate    = 0.06;
  periods = 2;
  present = future * f_to_p(rate, periods);
  if ((present < 6086.14) || (present > 6086.16))
    {
    fprintf(output, "\nERROR: test 11 - present = %f\n", present);
    test = FAIL;
    }
  return(test);
  }


/***************************************************************************
   function: test12()

 parameters: output - stream to write test results to

    returns: PASS or FAIL

    purpose: To test the p_to_f_c() function.
****************************************************************************/
char test12(FILE *output)
  {
  char test = PASS;
  return(test);
  }


/***************************************************************************
   function: test13()

 parameters: output - stream to write test results to

    returns: PASS or FAIL

    purpose: To test the ad_to_f() function.
****************************************************************************/
char test13(FILE *output)
  {
  char     test    = PASS;
  double   future  = 0.0,
	   annuity = 0.0,
	   rate    = 0.0;
  unsigned periods = 0;

  /* test against know problem */
  annuity = 3000.0;
  periods = 35;
  rate    = .08;
  future = annuity * ad_to_f(rate, periods);
  if ((future < 558306.43999) || (future > 558306.45001))
    {
    printf("\nERROR: test 13 - future = %f\n", future);
    test = FAIL;
    }
  return(test);
  }


/***************************************************************************
   function: test14()

 parameters: output - stream to write test results to

    returns: PASS or FAIL

    purpose: To test the ad_to_p() function.
****************************************************************************/
char test14(FILE *output)
  {
  char     test    = PASS;
  double   present = 0.0,
	   annuity = 0.0,
	   rate    = 0.0;
  unsigned periods = 0;

  /* test against know problem annuity due problem */
  annuity = 15000.0;
  periods = 12;
  rate    = 0.10;
  present = annuity * ad_to_p(rate, periods);
  if ((present < 112425.89) || (present > 112425.92))
    {
    printf("\nERROR: test 14 - present = %f\n", present);
    test = FAIL;
    }
  return(test);
  }


/****************************************************************************
   function: testout()

 parameters: passfail - boolean value (PASS or FAIL)
		  out - 5 character string

    returns: "PASS" is returned in the string (out) if passfail contains
	     a PASS char value.
	     "FAIL" is returned in the string (out) if passfail contains
	     a FAIL char value.

    purpose: This function converts a boolean PASS or FAIL value to a
	     string value "PASS" or "FAIL".
****************************************************************************/
char *testout(char passfail, char *out)
  {
  if (passfail == PASS)
    strcpy(out, "PASS");
  else
    strcpy(out, "FAIL");
  return(out);
  }
