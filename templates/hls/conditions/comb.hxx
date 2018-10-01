{% block code %}
        {{ c.name }} = gtl::condition::{{ c.type }}<gtl::cut::{{ c.objects[0].type }}, gtl::object::{{ c.objects[0].type }}, {{ c.objects|count }}, {{ c.objects[0].slice.minimum }}, {{ c.objects[0].slice.maximum }}>(cuts::{{ c.name }}, in_data.{{ c.objects[0].type }}{% if c.charge_correlation %}, gtl::logic::charge_correlation::{{ c.charge_correlation }}, charge_correlation{% endif %});
{%- endblock code %}
