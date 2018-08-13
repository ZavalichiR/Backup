inversare :: [a] -> [a]
inversare=foldr (\x acc->acc++[x])[]

main=do
	let res=[1,2,3,4,5,6,7,8,9]
	let res1=inversare res
	print res1	