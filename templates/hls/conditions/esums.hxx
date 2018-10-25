{% block code %}
        {{ c.name }} = gtl::condition::{{ c.type }}::process(cuts::{{ c.name }}, in_data.{{ c.objects[0].type }});
{%- endblock code %}
