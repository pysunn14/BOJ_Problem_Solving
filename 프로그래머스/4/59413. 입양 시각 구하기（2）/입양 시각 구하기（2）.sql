WITH RECURSIVE HOURS AS (
    
    SELECT 0 AS HOUR 
    
    UNION ALL
    
    SELECT HOUR + 1 FROM HOURS WHERE HOUR < 23
)

select H.HOUR as HOUR, COUNT(A.ANIMAL_ID) as COUNT 
from HOURS H left join ANIMAL_OUTS A on hour(A.DATETIME) = H.HOUR
group by H.HOUR
order by H.HOUR

# 중요한거 : 다른 시간도 다 0시로 나오기는 나와야함 ㅇㅇㅇㅇ 

# where 0시부터 23시까지 각 시간대별로 입양이 몇건 발생했음? 결과는 시간대 순으로 정렬하셈.