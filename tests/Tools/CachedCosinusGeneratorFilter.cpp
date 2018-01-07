/**
 * \ file CachedCosinusGeneratorFilter.cpp
 */

#include <ATK/config.h>

#include <ATK/Mock/SimpleSinusGeneratorFilter.h>
#include <ATK/Mock/TriangleCheckerFilter.h>

#include <ATK/Tools/SumFilter.h>
#include <ATK/Tools/CachedCosinusGeneratorFilter.h>

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_NO_MAIN
#include <boost/test/unit_test.hpp>

const size_t PROCESSSIZE = 1024*64;

BOOST_AUTO_TEST_CASE( CachedCosinusGeneratorFilter_volume_test )
{
  ATK::CachedCosinusGeneratorFilter<double> filter(10000, 10);
  filter.set_volume(10);
  BOOST_CHECK_EQUAL(filter.get_volume(), 10);
}

BOOST_AUTO_TEST_CASE( CachedCosinusGeneratorFilter_offset_test )
{
  ATK::CachedCosinusGeneratorFilter<double> filter(10000, 10);
  filter.set_offset(10);
  BOOST_CHECK_EQUAL(filter.get_offset(), 10);
}

BOOST_AUTO_TEST_CASE( CachedCosinusGeneratorFilter_frequency_test )
{
  ATK::CachedCosinusGeneratorFilter<double> filter(10000, 10);
  filter.set_frequency(1000, 1);
  BOOST_CHECK_EQUAL(filter.get_frequency().first, 1000);
  BOOST_CHECK_EQUAL(filter.get_frequency().second, 1);
}

BOOST_AUTO_TEST_CASE( CachedCosinusGeneratorFilter_1k_test )
{
  ATK::SimpleSinusGeneratorFilter<float> generator;
  generator.set_input_sampling_rate(48000);
  generator.set_output_sampling_rate(48000);
  generator.set_amplitude(-1);
  generator.set_frequency(1000);
  
  ATK::CachedCosinusGeneratorFilter<float> filter(10000, 10);
  filter.set_input_sampling_rate(48000);
  filter.set_output_sampling_rate(48000);
  
  ATK::SumFilter<float> sumfilter;
  sumfilter.set_input_sampling_rate(48000);
  sumfilter.set_output_sampling_rate(48000);
  
  ATK::TriangleCheckerFilter<float> checker;
  checker.set_input_sampling_rate(48000);
  checker.set_output_sampling_rate(48000);
  checker.set_amplitude(0);
  checker.set_frequency(1000);
  
  sumfilter.set_input_port(0, &generator, 0);
  sumfilter.set_input_port(1, &filter, 0);
  
  checker.set_input_port(0, &sumfilter, 0);
  
  generator.process(48000/1000/4);
  checker.process(PROCESSSIZE);
}
