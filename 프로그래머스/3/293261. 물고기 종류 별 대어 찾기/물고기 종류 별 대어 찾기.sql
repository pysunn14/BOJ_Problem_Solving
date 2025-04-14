select i.id, n.fish_name, i.length
from fish_info i natural join fish_name_info n
where i.length >= all (select j.length from fish_info j where i.fish_type = j.fish_type and j.length is not null)
order by i.id asc;