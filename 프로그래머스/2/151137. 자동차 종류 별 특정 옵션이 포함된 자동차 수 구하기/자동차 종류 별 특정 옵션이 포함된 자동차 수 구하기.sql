select CAR_TYPE, count(*) as CARS
from CAR_RENTAL_COMPANY_CAR
where OPTIONS like '%통풍시트%' or OPTIONS like '%열선시트%' or OPTIONS like '%가죽시트%'

# '통풍시트', '열선시트', '가죽시트'  중 하나가 포함되어 있어야함. 

group by CAR_TYPE
order by CAR_TYPE asc 
