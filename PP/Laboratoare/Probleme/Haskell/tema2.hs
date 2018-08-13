factorial :: Int->Int
factorial 0=1
factorial i=product [1..i]

lungime ::[a]->Int
lungime []=0
lungime (_:xs)=1+lungime xs


main=do
    let result = lungime [1,1,1]
    let result1= factorial result 
    print result1