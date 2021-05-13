section .text
global f1
f1:
 push ebp
 mov ebp,esp
 finit
 fld1
 fld1
 faddp
 fld1
 faddp
 fld qword[ebp+8]
 fld1
 fsubp
 fld qword[ebp+8]
 fld1
 fsubp
 fmulp
 fld1
 faddp
 fdivp
 leave
 ret


global f2
f2:
 push ebp
 mov ebp,esp
 finit
 FLD1
 FLD1
 FLD1
 faddp
 fdivp
 fld qword[ebp+8]
 faddp
 FSQRT 
 leave
 ret

global f3
f3:
 push ebp
 mov ebp, esp
 finit
 FLD1
 fld qword[ebp + 8 ]
 fldl2e
 fmulp
 frndint
 fld1
 fscale
 fld qword[ebp+8]
 fldl2e
 fmulp
 fld qword[ebp+8]
 fldl2e
 fmulp
 frndint
 fsubp
 f2xm1
 fld1
 fadd
 fmulp
 fdivp
 leave
 ret

global f11
f11:
 push ebp
 mov ebp,esp
 finit
 fld1
 fld1
 faddp
 fld1
 faddp
 fld1
 fld1
 faddp
 fld1
 fld1
 faddp
 fld qword[ebp+8]
 fmulp
 FCHS
 faddp
 fmulp
 fld qword[ebp+8]
 fld1
 fsubp
 fld qword[ebp+8]
 fld1
 fsubp
 fmulp
 fld1
 faddp
 fld qword[ebp+8]
 fld1
 fsubp
 fld qword[ebp+8]
 fld1
 fsubp
 fmulp
 fld1
 faddp
 fmulp
 fdivp
 leave
 ret
 

global f21
f21:
 push ebp
 mov ebp,esp
 finit
 FLD1
 FLD1
 FLD1
 FLD1
 faddp
 fdivp
 fld qword[ebp+8]
 faddp
 FSQRT 
 FLD1
 FLD1
 faddp
 fmulp
 fdivp
 leave
 ret

global f31
f31:
 push ebp
 mov ebp, esp
 finit
 FLD1
 fld qword[ebp + 8 ]
 fldl2e
 fmulp
 frndint
 fld1
 fscale
 fld qword[ebp+8]
 fldl2e
 fmulp
 fld qword[ebp+8]
 fldl2e
 fmulp
 frndint
 fsubp
 f2xm1
 fld1
 fadd
 fmulp
 fdivp
 FCHS
 leave
 ret
