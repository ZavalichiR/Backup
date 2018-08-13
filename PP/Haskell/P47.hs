isNumber ::String->Bool
isNumber x=case(reads x)::[(Double,String)] of
		[(_,"")] -> True
		_		 -> False
		
-- Load program
-- scrie: isNumber "nr"
