/* FINANCE.H

   By Michael W. Maher

   Ver 1.0 1/25/93
       1.5 6/22/93

   Description: A header file for functions useful for calculating
		interest rate formulas.

*/

#if !defined (FINANCES_DEFINED)
 /***************************** Include Files ******************************/
 /* Standard C */
 #include <float.h>
 #include <math.h>


 /******************************* Constants ********************************/
 #define LN_BASE 2.718281828459         /* natural log base */

 /******************************** Macros **********************************/
 #define A_TO_F(i, n) ((pow(1.0 + 1, n) - 1.0) / i)

 #define A_TO_F_C(r, n) ((pow(LN_BASE, r * n) - 1.0)/(pow(LN_BASE, r) - 1.0))

 #define A_TO_P(i, n) ((pow(1.0 + 1, n) - 1.0)/(i * pow(1.0 + i, n)))

 #define A_TO_P_C(r, n) ((1.0 - pow(LN_BASE, -(r * n)))/(pow(LN_BASE, r) - 1.0))


 /*************************** Function Prototypes **************************/
 double a_to_f(double i, unsigned n);
 double a_to_f_c(double r, unsigned n);
 double a_to_p(double i, unsigned n);
 double a_to_p_c(double r, unsigned n);
 double f_to_a(double i, unsigned n);
 double f_to_a_c(double r, unsigned n);
 double f_to_p(double i, unsigned n);
 double f_to_p_c(double r, unsigned n);
 double p_to_a(double i, unsigned n);
 double p_to_a_c(double r, unsigned n);
 double p_to_f(double i, unsigned n);
 double p_to_f_c(double r, unsigned n);
 /* mwm */
 double fpn_to_i(double f, double p, unsigned n);
 double ad_to_p(double i, unsigned n);
 double p_to_ad(double i, unsigned n);
 double f_to_ad(double i, unsigned n);
 double ad_to_f(double i, unsigned n);
#endif
/* End Of File */
