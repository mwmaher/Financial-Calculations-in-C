# Financial C Programs
C programs that compute financial calculations and amortization tables.  ANSI C compliant.

amort.c - Calculates an amortization table given the amount, number of periods, and rate per period.

amort2.c - Calculates an amortization table given the amount, payment, and rate per period.

finance.c is a library of useful financial functions.  ANSI C compliant.

a_to_f()        annuity to future value
a_to_f_c()      annuity to future value, continuous
a_to_p()	annuity to present value
a_to_p_c()      annuity to present value, continuous
f_to_a()        future value to an annuity
f_to_a_c()      future value to an annuity, continuous
f_to_p()        future value to present value
f_to_p_c()      future value to present value, continuous
p_to_a()        present value to an annuity
p_to_a_c()      present value to an annuity, continuous
p_to_f()        present value to future value
p_to_f_c()      present value to future value, continuous
ad_to_p()       Annuity due to present value with discrete compounding
p_to_ad()       Present value to an annuity due with discrete compounding
f_to_ad()       Future value to annuity due using discrete compounding
ad_to_f()       Annuity due to future value with discrete compounding
fpn_to_i()      Computes interest rate given the future value, present value, and the number of periods
