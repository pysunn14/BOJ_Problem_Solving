select count(*) as FISH_COUNT
from FISH_INFO natural join FISH_NAME_INFO 
where FISH_NAME in ('BASS', 'SNAPPER')



