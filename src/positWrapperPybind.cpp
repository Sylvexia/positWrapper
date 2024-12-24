#include <string>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "positWrapperC.h"

namespace py = pybind11;

template <size_t n_bits, size_t es, typename uType>
void bind_posit_functions(py::module_ &m, const std::string &suffix) {
    m.def(("getDouble_" + suffix).c_str(),
          [](uType rawBit) {
              return getDouble<n_bits, es, uType>(rawBit);
          },
          py::arg("rawBit"));
    m.def(("getRawBit_" + suffix).c_str(),
          [](double d) {
              return getRawBit<n_bits, es, uType>(d);
          },
          py::arg("d"));
}

// libpositWrapperPy matches the name of the .so file
PYBIND11_MODULE(libpositWrapperPy, m) {
    bind_posit_functions<8, 0, uint8_t>(m, "8_0");
    bind_posit_functions<8, 1, uint8_t>(m, "8_1");
    bind_posit_functions<8, 2, uint8_t>(m, "8_2");
    bind_posit_functions<8, 3, uint8_t>(m, "8_3");

    bind_posit_functions<16, 0, uint16_t>(m, "16_0");
    bind_posit_functions<16, 1, uint16_t>(m, "16_1");
    bind_posit_functions<16, 2, uint16_t>(m, "16_2");
    bind_posit_functions<16, 3, uint16_t>(m, "16_3");

    bind_posit_functions<32, 0, uint32_t>(m, "32_0");
    bind_posit_functions<32, 1, uint32_t>(m, "32_1");
    bind_posit_functions<32, 2, uint32_t>(m, "32_2");
    bind_posit_functions<32, 3, uint32_t>(m, "32_3");
    
    bind_posit_functions<64, 0, uint64_t>(m, "64_0");
    bind_posit_functions<64, 1, uint64_t>(m, "64_1");
    bind_posit_functions<64, 2, uint64_t>(m, "64_2");
    bind_posit_functions<64, 3, uint64_t>(m, "64_3");
}
