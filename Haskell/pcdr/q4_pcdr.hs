inverte :: String -> String
inverte [] = []
inverte (x:xs) = inverte xs ++ [x]

palinDromo :: String -> Bool
palinDromo xs = xs == inverte xs