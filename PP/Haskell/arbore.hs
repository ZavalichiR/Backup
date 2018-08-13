import Data.List.Split

-- tipul de date Arbore binar
data Tree = Leaf String | Node Tree String Tree

-- functie care imparte textul in cuvinte dupa separatori
splitText x = splitOneOf ",. " x

-- functie care insereaza lista de string-uri (cuvinte) intr-un arbore binar
insertCuvant :: [String] -> Tree
insertCuvant [] = Leaf "" -- lista vida are corespondent o frunza cu continut vid
insertCuvant x = Node (insertCuvant (take half x)) (x !! half) (insertCuvant (drop (half + 1) x))
	where half = length x `div` 2
				-- SEMNIFICATIA RECURSIEI:
				--  Node              Tree                 String                   Tree
				--           prima jumatate din lista | elementul din mijloc | a doua jumatate din lista

-- functia de cautare din curs
cautare :: String -> Tree -> Bool
cautare m (Leaf n) = m==n
cautare m (Node l n r) = m==n || cautare m l || cautare m r

main = do
	putStrLn("Introduceti textul: ")
	text <- getLine :: IO String
	let cuvinte = splitText text
	let arboreBinar = insertCuvant cuvinte
	putStrLn("Arborele binar format din cuvinte a fost creat cu succes.\n")
	putStrLn("Introduceti un cuvant de cautat: ")
	cuvant <- getLine
	if cautare cuvant arboreBinar
		then do
			putStrLn("Cuvantul \"" ++ cuvant ++ "\" exista in arbore.")
		else do
			putStrLn("Cuvantul \"" ++ cuvant ++ "\" nu exista in arbore.")