#include <iostream>
#include <positWrapperC.h>
#include <sys/types.h>

template <size_t nbits, size_t es, typename uType>
void testUnaryCFunction(unsigned sampleSize, uType (*positFunc)(uType),
                        double (*doubleFunc)(double)) {
  unsigned passed = 0, failed = 0;

  for (int i = 0; i < sampleSize; i++) {
    uType testInput = rand() % sampleSize;
    uType positResultRaw = positFunc(testInput);

    auto doubleValue = getDouble<nbits, es>(testInput);
    double doubleResult = doubleFunc(doubleValue);
    uType doubleResultRaw = get_uType<nbits, es, uType>(doubleResult);

    if (positResultRaw != doubleResultRaw) {
      failed++;
      std::cerr << "FAIL: testInput = "
                << std::bitset<std::numeric_limits<uType>::digits>(testInput)
                << " positResultRaw = " << std::bitset<std::numeric_limits<uType>::digits>(positResultRaw)
                << " doubleResultRaw = " << std::bitset<std::numeric_limits<uType>::digits>(doubleResultRaw)
                << " doubleValue = " << doubleValue << " doubleResult = " << doubleResult << std::endl;
    } else {
      passed++;
    }
  }

  std::cout << "Passed: " << passed << " Failed: " << failed << std::endl;
}

int main() {
  // rand with seed
  int sample = 255;
  int passed = 0, failed = 0;
  srand(time(0));

  std::cout << "Testing posit8es2" << std::endl;
  testUnaryCFunction<8, 2, uint8_t>(256, posit8es2_exp, exp);
  testUnaryCFunction<8, 2, uint8_t>(256, posit8es2_erf, erf);
  testUnaryCFunction<8, 2, uint8_t>(256, posit8es2_sqrt, sqrt);
  testUnaryCFunction<8, 2, uint8_t>(256, posit8es2_tanh, tanh);

  // std::cout << "Testing posit16es2" << std::endl;
  // testUnaryCFunction<16, 2, uint16_t>(pow(2, 16), posit16es2_exp, exp);
  // testUnaryCFunction<16, 2, uint16_t>(pow(2, 16), posit16es2_erf, erf);
  // testUnaryCFunction<16, 2, uint16_t>(pow(2, 16), posit16es2_sqrt, sqrt);
  // testUnaryCFunction<16, 2, uint16_t>(pow(2, 16), posit16es2_tanh, tanh);

  // std::cout << "Testing posit32es2" << std::endl;
  // testUnaryCFunction<32, 2, uint32_t>(pow(2, 16), posit32es2_exp, exp);
  // testUnaryCFunction<32, 2, uint32_t>(pow(2, 16), posit32es2_erf, erf);
  // testUnaryCFunction<32, 2, uint32_t>(pow(2, 16), posit32es2_sqrt, sqrt);
  // testUnaryCFunction<32, 2, uint32_t>(pow(2, 16), posit32es2_tanh, tanh);
}