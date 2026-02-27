select distinct A.USER_ID, A.PRODUCT_ID 
from ONLINE_SALE as A join ONLINE_SALE as B 
where A.ONLINE_SALE_ID != B.ONLINE_SALE_ID and A.USER_ID = B.USER_ID 

and

A.PRODUCT_ID = B.PRODUCT_ID 

order by A.USER_ID asc, A.PRODUCT_ID desc

