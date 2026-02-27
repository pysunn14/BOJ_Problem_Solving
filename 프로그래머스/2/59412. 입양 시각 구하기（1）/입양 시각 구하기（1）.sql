select hour(DATETIME) as HOUR, count(*) as count
from animal_outs
group by HOUR
having HOUR >= 9 and HOUR <= 19
order by HOUR asc
