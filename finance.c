/* FINANCE.C

   By Michael W. Maher

   Ver 1.0 1/25/93
       1.5 6/22/93

   Description: The following functions appeared in William Smith's
		"A Library Of Financial Functions" in The C Users Journal,
		February 1993.  The functions are useful for calculating
		interest rate formulas.

		William Smith's Functions:
			a_to_f()        annuity to future value
			a_to_f_c()      annuity to future value, continuous
			a_to_p()
			a_to_p_c()
			f_to_a()
			f_to_a_c()
			f_to_p()
			f_to_p_c()
			p_to_a()
			p_to_a_c()
			p_to_f()
			p_to_f_c()

		The following functions were developed by Michael W. Maher
		to help fill the gaps of William Smith's fucntions.

		ad_to_p()
		p_to_ad()
		f_to_ad()
		ad_to_f()
		fpn_to_i()


   Portability: Standard C
   
*/

/***************************** Include Files *******************************/
/* Other */
#include <math.h>
#include "finance.h"


/****************************************************************************
   function: a_to_f()

 parameters: i - effective interest rete per period
	     n - number of periods

    returns: F/A - annuity to future value factor

    purpose: Annuity to future value with discrete compounding.
****************************************************************************/
double a_to_f(double i, unsigned n)
  {
  return((p_to_f(i, n) - 1.0) / i);
  }                                     /* function a_to_f */


/****************************************************************************
   function: a_to_f_c()

 parameters: r - nominal interest rate per period
	     n - number of periods

    returns: F/A - Annuity to future value factor.

    purpose: Annuity to future value with continuous compounding.
****************************************************************************/
double a_to_f_c(double r, unsigned n)
  {
  return((p_to_f_c(r, n) - 1.0) / (pow((double) LN_BASE, r) - 1.0));
  }                                     /* function a_to_f_c */


/****************************************************************************
   function: a_to_p()

 parameters: i - effective interest rate per period
	     n - number of periods

    returns: P/A - annuity to present value factor

    purpose: Annuity to present value using discrete compounding.
****************************************************************************/
double a_to_p(double i, unsigned n)
  {
  return(a_to_f(i, n) / p_to_f(i, n));
  }                                     /* function a_to_p */


/****************************************************************************
   function: a_to_p_c()

 parameters: r - nominal interest rate per period
	     n - number of periods

    returns: P/A - annuity to present value factor

    purpose: Annuity to present value with continuous compounding.
****************************************************************************/
double a_to_p_c(double r, unsigned n)
  {
  return(a_to_f_c(r, n) / p_to_f_c(r, n));
  }                                     /* function a_to_p_c */


/****************************************************************************
   function: f_to_a()

 parameters: i - effective interest rate per period
	     n - number of periods

    returns: A/F - future value to annuity factor

    purpose: The following function computes the future value to annity
	     using discrete compounding.
****************************************************************************/
double f_to_a(double i, unsigned n)
  {
  return(1.0 / a_to_f(i, n));
  }                                     /* function f_to_a */


/****************************************************************************
   function: f_to_a_c()

 parameters: r - nominal interest rate per period
	     n - number of periods

    returns: A/F - future value to annuity factor

    purpose: Future value to annuity with continuous compounding.
****************************************************************************/
double f_to_a_c(double r, unsigned n)
  {
  return(1.0 / a_to_f_c(r, n));
  }                                     /* function f_to_a_c */


/****************************************************************************
   function: f_to_p()

 parameters: i - effective interest rate per period
	     n - number of periods

    returns: P/F - future to present value factor

    purpose: Future value to present value with discrete compounding.
****************************************************************************/
double f_to_p(double i, unsigned n)
  {
  return(1.0 / p_to_f(i, n));
  }                                     /* function f_to_p */


/****************************************************************************
   function: f_to_p_c()

 parameters: r - nominal interest rate per period
	     n - number of periods

    returns: P/F - future to present value factor

    purpose: Future value to present value with continuous compounding.
****************************************************************************/
double f_to_p_c(double r, unsigned n)
  {
  return(1.0 / p_to_f_c(r, n));
  }                                     /* function f_to_p_c */


/****************************************************************************
   function: p_to_a()

 parameters: i - effective interest rate per period
	     n - number of periods

    returns: A/P - present value to annuity factor

    purpose: Present value to annuity with discrete compounding.
****************************************************************************/
double p_to_a(double i, unsigned n)
  {
  return(p_to_f(i, n) / a_to_f(i, n));
  }                                     /* function p_to_a */


/****************************************************************************
   function: p_to_a_c()

 parameters: r - nominal interest rate per period
	     n - number of periods

    returns: A/P - present value to annuity factor

    purpose: Present value to annuity with continuous compounding.
****************************************************************************/
double p_to_a_c(double r, unsigned n)
  {
  return(p_to_f_c(r, n) / a_to_f_c(r, n));
  }                                     /* function p_to_a_c */


/****************************************************************************
   function: p_to_f()

 parameters: i - effective interest rate per period
	     n - number of periods

    returns: F/P - present ot future value factor

    purpose: Present value to future value with discrete compounding.
****************************************************************************/
double p_to_f(double i, unsigned n)
  {
  return(pow((double) 1.0 + i, (double)n));
  }                                     /* function p_to_f */


/****************************************************************************
   function: p_to_f_c()

 parameters: r - nominal interest rate per period
	     n - number of periods

    returns: F/P - present to future value factor

    purpose: Present value to future value with continuous compounding.
****************************************************************************/
double p_to_f_c(double r, unsigned n)
  {
  return(pow((double) LN_BASE, r * n));
  }                                     /* function p_to_f_c */


/****************************************************************************
   function: fpn_to_i()

 parameters: f - future value
	     p - present value
	     n - number of periods

    returns: i - effective interest rate per period

    purpose: Computes interest rate given the future value, present value,
	     and the number of periods.  Based on the formula:
	     f = p * (1 + i)^n  or i = ((f/p)^(1/n)) - 1
****************************************************************************/
double fpn_to_i(double f, double p, unsigned n)
  {
  return(pow(f / p, (double) (1.0 / n)) - 1.0);
  }                                     /* function fpn_to_i */


/****************************************************************************
   function: ad_to_p()

 parameters: i - effective interest rate per period
	     n - number of periods

   returns:  Ad/P = annuity due to present value

    purpose: Annuity due to present value with discrete compounding.  An
	     annuity due is often used to calculate compounding when the
	     payment is made at the beginning of the period verses the end.
	     Based on: pvadf(n,i) = pvoaf(n-1,i) + 1
****************************************************************************/
double ad_to_p(double i, unsigned n)
  {
  return(a_to_p(i, n-1) + 1.0);
  }                                     /* function ad_to_p */


/****************************************************************************
   function: p_to_ad()

 parameters: i - effective interest rate per period
	     n - number of periods

   returns:  P/Ad = present value to an annuity due

    purpose: Present value to an annuity due with discrete compounding.
	     See ad_to_p();
	     Based on: pvadf(n,i) = pvoaf(n-1,i) + 1
****************************************************************************/
double p_to_ad(double i, unsigned n)
  {
  return(1 / ad_to_p(i, n));
  }                                     /* function p_to_ad */


/****************************************************************************
   function: f_to_ad()

 parameters: i - effective interest rate per period
	     n - number of periods

    returns: Ad/F - future value to an annuity due factor

    purpose: The following function computes the future value to annity
	     due using discrete compounding.
****************************************************************************/
double f_to_ad(double i, unsigned n)
  {
  return(1.0 / ad_to_f(i, n));
  }                                     /* function f_to_ad */


/****************************************************************************
   function: ad_to_f()

 parameters: i - effective interest rete per period
	     n - number of periods

    returns: F/A - annuity due to future value factor

    purpose: Annuity due to future value with discrete compounding.
	     based on:
	     F = Ad * aadf(n, i) = Ad * (aoaf(n+1, i) - 1)
****************************************************************************/
double ad_to_f(double i, unsigned n)
  {
  return(a_to_f(i, n + 1) - 1);
  }                                     /* function ad_to_f */


