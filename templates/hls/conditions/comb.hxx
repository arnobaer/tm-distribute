{% block code %}
        {{ c.name }} = gtl::condition::{{ c.type }}<{{ c.objects[0].slice.minimum }}, {{ c.objects[0].slice.maximum }}>::process(cuts::{{ c.name }}, in_data.{{ c.objects[0].type }}{% if c.charge_correlation %}, gtl::logic::charge_correlation::{{ c.charge_correlation }}, charge_correlation{% endif %});
{%- endblock code %}
