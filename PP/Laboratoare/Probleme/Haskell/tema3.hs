qsort [] = []
qsort (x:xs) = do
	qsort smaller ++ [x] ++ qsort larger
	where
		smaller = [a | a <- xs, a <= x]
		larger = [b | b <- xs, b > x]

main=do
	let result = ['a','l','c','r']
	let result1 = qsort result
	print result1