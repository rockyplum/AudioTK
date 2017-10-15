/**
 * \file PipelineGlobalSinkFilter.h
 */

#ifndef ATK_CORE_PIPELINEGLOBALSINKFILTER_H
#define ATK_CORE_PIPELINEGLOBALSINKFILTER_H

#include <ATK/Core/BaseFilter.h>

#include <vector>

namespace ATK
{
  /// Class that can be used to process a pipeline that has more than one final sink. By adding these sinks to this filter, the processing is done for all sinks.
  class ATK_CORE_EXPORT PipelineGlobalSinkFilter final : public BaseFilter
  {
  protected:
    /// Simplify parent calls
    typedef BaseFilter Parent;

  public:
    /// Constructor of the multiple sinks filter
    PipelineGlobalSinkFilter();
    /// destructor
    virtual ~PipelineGlobalSinkFilter();
    
    /*!
     * @brief Adds a filter to the list of filters to process
     * @param filter is an additional filter
     */
    void add_filter(BaseFilter* filter);
    /*!
    * @brief Removes a filter from the list of filters to process
    * @param filter is an additional filter
    */
    void remove_filter(const BaseFilter* filter);

    int get_type() const final;
    /*!
     * @brief Indicates if we can process the pipeline in parallel
     */
    void set_parallel(bool parallel);
  protected:
    virtual void process_impl(std::size_t size) const final;
    virtual void prepare_process(std::size_t size) final;
    virtual void prepare_outputs(std::size_t size) final;

    /// List of filters in this sink
    std::vector<BaseFilter*> filters;
    /// Are we in parallel mode?
    bool activate_parallel;
  };
}

#endif
