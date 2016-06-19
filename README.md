# Financial C Programs
Two C programs that compute amortization tables.  ANSI C compliant.

amort.c - Calculates an amortization table given the amount, number of periods, and rate per period.

amort2.c - Calculates an amortization table given the amount, payment, and rate per period.

finance.c is a library of useful financial functions.  ANSI C compliant.

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
		  ad_to_p()       Annuity due to present value with discrete compounding
		  p_to_ad()       Present value to an annuity due with discrete compounding
		  f_to_ad()       Future value to annuity due using discrete compounding
		  ad_to_f()       Annuity due to future value with discrete compounding
		  fpn_to_i()      Computes interest rate given the future value, present value, and the number of periods
