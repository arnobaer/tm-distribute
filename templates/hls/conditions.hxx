{% extends "header.hxx" %}
{% block code %}
#ifndef impl_conditions_h
#define impl_conditions_h

#include "../impl/cuts.hxx"

namespace impl {
namespace conditions {

struct logic
{
    typedef ap_uint<1> signal_type;
    typedef gtl::logic::charge_correlation charge_correlation_type;

    // Charge correlation logic
    charge_correlation_type charge_correlation;

    // Condition signals
{%- for condition in conditions %}
    signal_type {{ condition.name }};
{%- endfor %}

    /* Process input data and update condition signals. */
    void process(const in_data_t& in_data)
    {
#pragma HLS ARRAY_PARTITION variable=in_data.eg complete dim=1
#pragma HLS ARRAY_PARTITION variable=in_data.jet complete dim=1
#pragma HLS ARRAY_PARTITION variable=in_data.tau complete dim=1
#pragma HLS ARRAY_PARTITION variable=in_data.muon complete dim=1

        // Calculate muon charge correlations
        charge_correlation.process(in_data.muon);

        // Calculate conditions
{%- for c in conditions %}
        {%- include 'conditions/%s.hxx' % c.type -%}
{% endfor %}
    }
};

} // namespace conditions
} // namespace impl

#endif
{% endblock code %}
