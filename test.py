import libpositWrapperPy as posit

rawBit = posit.getRawBit_32_2(1.79769e+12)
print(rawBit)

doubleVal = posit.getDouble_32_2(rawBit)
print(doubleVal)