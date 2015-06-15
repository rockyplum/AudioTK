/**
 * \file AttackReleaseFilter.cpp
 */

#include "AttackReleaseFilter.h"

#include <cstdint>
#include <stdexcept>

namespace ATK
{
  template<typename DataType_>
  AttackReleaseFilter<DataType_>::AttackReleaseFilter(int nb_channels)
  :Parent(nb_channels, nb_channels), attack(1), release(1)
  {
    output_delay = 1;
  }
  
  template<typename DataType_>
  AttackReleaseFilter<DataType_>::~AttackReleaseFilter()
  {
  }

  template<typename DataType_>
  void AttackReleaseFilter<DataType_>::set_attack(DataType_ attack)
  {
    if(attack < 0)
    {
      throw std::out_of_range("Attack factor must be positive value");
    }
    this->attack = attack;
  }
  
  template<typename DataType_>
  DataType_ AttackReleaseFilter<DataType_>::get_attack() const
  {
    return attack;
  }

  template<typename DataType_>
  void AttackReleaseFilter<DataType_>::set_release(DataType_ release)
  {
    if(release < 0)
    {
      throw std::out_of_range("Release factor must be positive value");
    }
    this->release = release;
  }

  template<typename DataType_>
  DataType_ AttackReleaseFilter<DataType_>::get_release() const
  {
    return release;
  }

  template<typename DataType_>
  void AttackReleaseFilter<DataType_>::process_impl(std::int64_t size) const
  {
    assert(nb_input_ports == nb_output_ports);
    for(int channel = 0; channel < nb_input_ports; ++channel)
    {
      const DataType* ATK_RESTRICT input = converted_inputs[channel];
      DataType* ATK_RESTRICT output = outputs[channel];
      for(std::int64_t i = 0; i < size; ++i)
      {
        if(output[i-1] > input[i])
        {
          output[i] = (1 - release) * input[i] + release * output[i-1];//release phase
        }
        else
        {
          output[i] = (1 - attack) * input[i] + attack * output[i-1];//attack phase
        }
      }
    }
  }
  
  template class AttackReleaseFilter<float>;
  template class AttackReleaseFilter<double>;
}
