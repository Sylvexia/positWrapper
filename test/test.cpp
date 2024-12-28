#include <cstdlib>
#include <ctime>
#include <iostream>
#include <positWrapperC.h>

int main() {
  int sample = 255;
  int passed = 0, failed = 0;
  srand(time(0));
  for (int i = 0; i < sample; i++) {
    uint8_t a = rand() % 256;
    uint8_t b = rand() % 256;
    uint8_t c = posit8es0_add(a, b);

    auto pa = get_posit<8, 0>(a);
    auto pb = get_posit<8, 0>(b);
    double da = static_cast<double>(pa);
    double db = static_cast<double>(pb);
    double dc = da + db;

    sw::universal::posit<8, 0> pc(dc);
    uint8_t c_ref = get_uType<8, 0, uint8_t>(pc);

    if (c != c_ref) {
      failed++;
      std::cerr << "FAIL: a = " << int(a) << " b = " << int(b)
                << " c = " << int(c) << " c_ref = " << int(c_ref) << std::endl;
    } else {
      passed++;
    }
  }
  std::cout << "Passed " << passed << " tests\n";
  std::cout << "Failed " << failed << " tests\n";

  std::cout << "Testing sitofp" << std::endl;
  passed = 0, failed = 0;

  for (int i = 0; i < sample; i++) {
    // a is a random integer
    int8_t a = rand() % 256;
    uint8_t b = posit8es0_sitofp(a);

    double da = static_cast<double>(a);
    sw::universal::posit<8, 0> pb(da);
    uint8_t b_ref = get_uType<8, 0, uint8_t>(pb);

    if (b != b_ref) {
      failed++;
      std::cerr << "FAIL: a = " << int(a) << " b = " << int(b)
                << " b_ref = " << int(b_ref) << std::endl;
    } else {
      passed++;
    }
  }
  std::cout << "Passed " << passed << " tests\n";
  std::cout << "Failed " << failed << " tests\n";
}