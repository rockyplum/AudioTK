/**
 * \file AttackReleaseFilter.h
 */

#ifndef ATK_DYNAMIC_ATTACKRELEASEFILTER_H
#define ATK_DYNAMIC_ATTACKRELEASEFILTER_H

#include <ATK/Core/TypedBaseFilter.h>
#include <ATK/Dynamic/config.h>

namespace ATK
{
  /// Creates an output signal with the filter power of the input (computed with an AR1)
  template<typename DataType_>
  class ATK_DYNAMIC_EXPORT AttackReleaseFilter final : public TypedBaseFilter<DataType_>
  {
  protected:
    /// Simplify parent calls
    typedef TypedBaseFilter<DataType_> Parent;
    using typename Parent::DataType;
    using Parent::converted_inputs;
    using Parent::outputs;
    using Parent::nb_input_ports;
    using Parent::nb_output_ports;
    using Parent::output_delay;

  public:
    /*!
    * @brief Constructor
    * @param nb_channels is the number of input and output channels
    */
    AttackReleaseFilter(std::size_t nb_channels = 1);
    /// destructor
    ~AttackReleaseFilter() override;

    /// Sets the speed of the attack
    void set_attack(DataType_ attack);
    /// Gets the attack speed
    DataType_ get_attack() const;
    /// Sets the speed of the release
    void set_release(DataType_ release);
    /// Gets the release speed
    DataType_ get_release() const;
    
  protected:
    void process_impl(std::size_t size) const final;
    
  private:
    DataType_ attack;
    DataType_ release;
  };
}

#endif
