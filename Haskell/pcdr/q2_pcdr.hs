elemNum :: Int -> [Int] -> Int
elemNum x [] = 0
elemNum x (y:xs)
  | x == y    = 1 + elemNum x xs
  | otherwise = elemNum x xs