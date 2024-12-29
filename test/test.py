import libpositWrapperPy as posit

print("posit(64, 0)")

rawBit = posit.getRawBit_64_0(1e+307)
print(bin(rawBit))

doubleVal = posit.getDouble_64_0(rawBit)
print(doubleVal)

print("posit(64, 1)")

rawBit = posit.getRawBit_64_1(1e+307)
print(bin(rawBit))

doubleVal = posit.getDouble_64_1(rawBit)
print(doubleVal)

print("posit(64, 2)")

rawBit = posit.getRawBit_64_2(1e+307)
print(bin(rawBit))

doubleVal = posit.getDouble_64_2(rawBit)
print(doubleVal)

print("posit(64, 3)")

rawBit = posit.getRawBit_64_3(1e+307)
print(bin(rawBit))

doubleVal = posit.getDouble_64_3(rawBit)
print(doubleVal)

print("posit(8, 2)")

rawBit = posit.getRawBit_8_2(3.14)
print(bin(rawBit))

doubleVal = posit.getDouble_8_2(rawBit)
print(doubleVal)