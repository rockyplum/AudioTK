/**
 * \file SecondOrderFilter.cpp
 */

#include <ATK/EQ/SecondOrderFilter.hxx>
#include <ATK/EQ/IIRFilter.h>

namespace ATK
{
  template class SecondOrderBaseCoefficients<float>;
  template class SecondOrderBaseCoefficients<double>;
  template class SecondOrderBaseCoefficients<std::complex<float> >;
  template class SecondOrderBaseCoefficients<std::complex<double> >;
  
  template class ATK_EQ_EXPORT SecondOrderBandPassCoefficients<float>;
  template class ATK_EQ_EXPORT SecondOrderBandPassCoefficients<double>;
  template class ATK_EQ_EXPORT SecondOrderBandPassCoefficients<std::complex<float> >;
  template class ATK_EQ_EXPORT SecondOrderBandPassCoefficients<std::complex<double> >;
  template class ATK_EQ_EXPORT SecondOrderLowPassCoefficients<float>;
  template class ATK_EQ_EXPORT SecondOrderLowPassCoefficients<double>;
  template class ATK_EQ_EXPORT SecondOrderLowPassCoefficients<std::complex<float> >;
  template class ATK_EQ_EXPORT SecondOrderLowPassCoefficients<std::complex<double> >;
  template class ATK_EQ_EXPORT SecondOrderHighPassCoefficients<float>;
  template class ATK_EQ_EXPORT SecondOrderHighPassCoefficients<double>;
  template class ATK_EQ_EXPORT SecondOrderHighPassCoefficients<std::complex<float> >;
  template class ATK_EQ_EXPORT SecondOrderHighPassCoefficients<std::complex<double> >;
  template class ATK_EQ_EXPORT SecondOrderBandPassPeakCoefficients<float>;
  template class ATK_EQ_EXPORT SecondOrderBandPassPeakCoefficients<double>;
  template class ATK_EQ_EXPORT SecondOrderBandPassPeakCoefficients<std::complex<float> >;
  template class ATK_EQ_EXPORT SecondOrderBandPassPeakCoefficients<std::complex<double> >;
  template class ATK_EQ_EXPORT SecondOrderAllPassCoefficients<float>;
  template class ATK_EQ_EXPORT SecondOrderAllPassCoefficients<double>;
  template class ATK_EQ_EXPORT SecondOrderAllPassCoefficients<std::complex<float> >;
  template class ATK_EQ_EXPORT SecondOrderAllPassCoefficients<std::complex<double> >;
  template class ATK_EQ_EXPORT SecondOrderLowShelvingCoefficients<float>;
  template class ATK_EQ_EXPORT SecondOrderLowShelvingCoefficients<double>;
  template class ATK_EQ_EXPORT SecondOrderLowShelvingCoefficients<std::complex<float> >;
  template class ATK_EQ_EXPORT SecondOrderLowShelvingCoefficients<std::complex<double> >;
  template class ATK_EQ_EXPORT SecondOrderHighShelvingCoefficients<float>;
  template class ATK_EQ_EXPORT SecondOrderHighShelvingCoefficients<double>;
  template class ATK_EQ_EXPORT SecondOrderHighShelvingCoefficients<std::complex<float> >;
  template class ATK_EQ_EXPORT SecondOrderHighShelvingCoefficients<std::complex<double> >;
}
