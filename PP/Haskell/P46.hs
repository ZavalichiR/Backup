factorial :: Int->Int
factorial n=product[1..n]

--qsort :: [Int sau Char]->[Int sau Char] 
--daca nu pui linia de mai sus atunci va sorta orice
qsort []=[]
qsort(x:xs)=do
	qsort smaller++ [x] ++ qsort larger
	where
		smaller=[a|a<-xs,a<=x]
		larger=[b|b<-xs,b>x]
		
lungime :: [a] -> Int
lungime [] = 0
lungime (_:xs) = 1 + lungime xs

main=do
	let sir=[1,5,3,2,4,8,7,6]
	let text=['1','5','8','7','6','3']
	let l=lungime sir
	putStrLn "Lungime: "
	print l
	
	let rez=factorial l
	putStrLn "Factorial:"
	print rez
	
	let sir2=qsort sir
	putStrLn "Sirul sortat:"
	print sir2
	
	let text2=qsort text
	putStrLn "textul sortat:"
	print text2
	