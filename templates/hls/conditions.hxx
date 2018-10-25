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

    // Condition signals
{%- for condition in conditions %}
    signal_type {{ condition.name }};
{%- endfor %}

    /* Process input data and update condition signals. */
    template<typename T1, typename T2>
    void process(const T1& in_data, const T2& charge_correlation)
    {
#pragma HLS ARRAY_PARTITION variable=in_data.eg complete dim=1
#pragma HLS ARRAY_PARTITION variable=in_data.jet complete dim=1
#pragma HLS ARRAY_PARTITION variable=in_data.tau complete dim=1
#pragma HLS ARRAY_PARTITION variable=in_data.muon complete dim=1

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
