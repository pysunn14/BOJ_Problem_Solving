select count(fish_type) as fish_count, fish_name
from fish_info natural join fish_name_info
group by fish_name
order by fish_count desc