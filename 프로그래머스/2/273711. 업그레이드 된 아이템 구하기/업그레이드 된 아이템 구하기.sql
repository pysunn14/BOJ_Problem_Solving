select T.ITEM_ID, I.ITEM_NAME, I.RARITY
from ITEM_TREE as T natural join ITEM_INFO as I

where 

T.PARENT_ITEM_ID IN (select K.ITEM_ID 
from ITEM_INFO as K
where K.RARITY = 'RARE') 

order by T.ITEM_ID desc





