inverseaza :: [a]->[a]
inverseaza =foldr(\x xs->xs++[x])[]

factorial :: Int->Int
factorial n=product[1..n]

lungime ::[a]->Int
lungime []=0
lungime (_:xs)=1+lungime xs

main=do
	let list=[1,2,3,4]
	putStrLn "Lista este: " 
	print list
	
	let list2=inverseaza list
	putStrLn "Lista inversata: "
	print list2
	
	let l=lungime list
	putStrLn "Lungimea listei"
	print l
	putStrLn "Factorial: "
	let rez= factorial l
	print rez
	
-- load program apoi scrii main
	
	

