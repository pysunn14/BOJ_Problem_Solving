select year(SALES_DATE) as YEAR, 
month(SALES_DATE) as MONTH, 
U.GENDER, 
count(distinct U.USER_ID) as USERS

from USER_INFO U join ONLINE_SALE O on U.USER_ID = O.USER_ID 

where U.GENDER is not null 

group by YEAR, MONTH, U.GENDER 
order by YEAR asc, MONTH asc, GENDER asc




