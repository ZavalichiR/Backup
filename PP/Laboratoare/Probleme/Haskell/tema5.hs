isInteger x = case reads x::[(Integer, String)] of
		[(_,"")] -> True
		_        -> False

isDouble x = case reads x::[(Double, String)] of
		[(_,"")] -> True
		_        -> False

isNumeric x = isInteger x || isDouble x