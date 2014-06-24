
%{
#include <ATK/Dynamic/GainCompressorFilter.h>
%}

namespace ATK
{
  template<class DataType>
  class GainCompressorFilter: public BaseFilter
  {
  public:
    GainCompressorFilter(int nb_channels);
    ~GainCompressorFilter();

    void set_threshold(DataType threshold);
    void set_threshold_db(DataType threshold);
    DataType get_threshold() const;
    void set_slope(DataType slope);
    DataType get_slope() const;
    void set_softness(DataType softness);
    DataType get_softness() const;
  };
}

%template(FloatGainCompressorFilter) ATK::GainCompressorFilter<float>;
%template(DoubleGainCompressorFilter) ATK::GainCompressorFilter<double>;
