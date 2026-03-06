with ONE as (
select M.MEMBER_ID as ID, M.MEMBER_NAME as NAME
from MEMBER_PROFILE M join REST_REVIEW R on M.MEMBER_ID = R.MEMBER_ID
group by M.MEMBER_ID
order by count(R.REVIEW_TEXT) desc
limit 1
)

select O.NAME, R.REVIEW_TEXT, substring(R.REVIEW_DATE,1,10) as REVIEW_DATE
from ONE O join REST_REVIEW R on O.ID = R.MEMBER_ID
order by R.REVIEW_DATE asc, R.REVIEW_TEXT asc 




