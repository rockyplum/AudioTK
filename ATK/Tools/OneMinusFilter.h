/**
 * \file OneMinusFilter.h
 */

#ifndef ATK_TOOLS_ONEMINUSFILTER_H
#define ATK_TOOLS_ONEMINUSFILTER_H

#include <ATK/Core/TypedBaseFilter.h>
#include <ATK/Tools/config.h>

namespace ATK
{
  /// Computes 1 - input for all channels
  template<typename DataType_>
  class ATK_TOOLS_EXPORT OneMinusFilter final : public TypedBaseFilter<DataType_>
  {
  protected:
    /// Simplify parent calls
    typedef TypedBaseFilter<DataType_> Parent;
    using typename Parent::DataType;
    using Parent::converted_inputs;
    using Parent::outputs;
    using Parent::output_delay;
    using Parent::nb_input_ports;
    using Parent::nb_output_ports;
    
  public:
    /*!
    * @brief Constructor
    * @param nb_channels is the number of input and output channels
    */
    OneMinusFilter(std::size_t nb_channels = 1);
    /// Destructor
    ~OneMinusFilter();
    
  protected:
    virtual void process_impl(std::size_t size) const final;
  };
}

#endif
