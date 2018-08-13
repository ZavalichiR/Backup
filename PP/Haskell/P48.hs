import Data.List.Split

data Tree = Leaf String | Node Tree String Tree

splitText cuv =splitOneOf ",. " cuv

insertCuvant :: [String] -> Tree
insertCuvant [] = Leaf ""
insertCuvant x = Node (insertCuvant (take half x)) (x !! half) (insertCuvant (drop (half + 1) x))
	where half= length x `div` 2
	
cautare :: String -> Tree -> Bool
cautare m (Leaf n) = m==n
cautare m (Node l n r) = m==n || cautare m l || cautare m r

	
main=do
	putStrLn("Introduceti textul")
	getLine :: IO String
	text<-getLine
	let cuvinte=splitText text
	let arbore=insertCuvant cuvinte
	putStrLn("Arborele a fost creat cu succes")
	putStrLn("Cautati un cuvant: ")
	
	cuvant<-getLine
	
	if cautare cuvant arbore
		then do
			putStrLn("Cuvantul \""++cuvant++"\" a fost gasit")
		else do
			putStrLn("Cuvantul \""++cuvant++"\" nu a fost gasit")