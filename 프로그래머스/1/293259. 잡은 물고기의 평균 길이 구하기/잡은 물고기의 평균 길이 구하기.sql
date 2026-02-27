select round(avg(IFNULL(length, 10)), 2) as AVERAGE_LENGTH
from fish_info

# length가 null 이면 다 10cm로 취급하여 계산. 



