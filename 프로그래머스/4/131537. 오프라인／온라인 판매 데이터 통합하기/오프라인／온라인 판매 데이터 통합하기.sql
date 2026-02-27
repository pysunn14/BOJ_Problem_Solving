    
    select substring(SALES_DATE,1,10) as SALES_DATE, PRODUCT_ID, USER_ID, SALES_AMOUNT
    from ONLINE_SALE 
    where substring(SALES_DATE,1,7) = '2022-03'
      
    union all

    select substring(SALES_DATE,1,10) as SALES_DATE, PRODUCT_ID, NULL as USER_ID, SALES_AMOUNT
    from OFFLINE_SALE 
    where substring(SALES_DATE,1,7) = '2022-03'
     
    order by 
        SALES_DATE asc,
        PRODUCT_ID asc,
        USER_ID asc
