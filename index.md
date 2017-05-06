---
layout: page
title: An Algorithm a Day
tagline: Algorithms for the Dummies by the Dummies
---
{% include JB/setup %}
    
## Archives

<ul class="posts">
  {% for post in site.posts %}
    <li><span>{{ post.date | date_to_string }}</span> &raquo; <a href="{{ BASE_PATH }}{{ post.url }}">{{ post.title }}</a></li>
  {% endfor %}
</ul>


