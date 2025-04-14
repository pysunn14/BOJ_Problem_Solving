select i.rest_id, i.rest_name, i.food_type, i.favorites, i.address, round(avg(v.review_score), 2) as score

from rest_info i natural join rest_review v
where i.address like '서울%'
group by i.rest_id
order by score desc , i.favorites desc;
