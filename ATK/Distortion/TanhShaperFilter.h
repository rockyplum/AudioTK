/**
 * \file TanhShaperFilter.h
 */

#ifndef ATK_DISTORTION_TANHSHAPERFILTER_H
#define ATK_DISTORTION_TANHSHAPERFILTER_H

#include <ATK/Core/TypedBaseFilter.h>
#include <ATK/Distortion/config.h>

namespace ATK
{
  /// Tanh waveshaper
  template<typename DataType_>
  class ATK_DISTORTION_EXPORT TanhShaperFilter final : public TypedBaseFilter<DataType_>
  {
  protected:
    /// Simplify parent calls
    typedef TypedBaseFilter<DataType_> Parent;
    using typename Parent::DataType;
    using Parent::converted_inputs;
    using Parent::outputs;
    using Parent::nb_input_ports;
    using Parent::nb_output_ports;
    using Parent::input_sampling_rate;
    using Parent::output_sampling_rate;

  public:
    /*!
    * @brief Constructor
    * @param nb_channels is the number of input and output channels
    */
    TanhShaperFilter(std::size_t nb_channels = 1);
    /// Destructor
    ~TanhShaperFilter() override;
    
    void set_coefficient(DataType coeff);
    DataType_ get_coefficient() const;

  protected:
    void process_impl(std::size_t size) const final;
  private:
    DataType coeff;
  };
}

#endif
