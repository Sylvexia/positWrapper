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

PYBIND11_MODULE(libpositWrapperPy, m) {
    bind_posit_functions<8, 0, uint8_t>(m, "8_0");
    bind_posit_functions<16, 1, uint16_t>(m, "16_1");
    bind_posit_functions<32, 2, uint32_t>(m, "32_2");
    bind_posit_functions<64, 3, uint64_t>(m, "64_3");
}
