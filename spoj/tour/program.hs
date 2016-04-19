fibonacci 1 = 1
fibonacci 2 = 1
fibonacci n = fibonacci (n-1) + fibonacci (n-2)

lastel n = last(init n)

penultimate n = last n

kthel n k = n !! k

chainLast :: Num a => [a] -> a
chainLast = last . init

myLength :: Num a => [a] -> a
myLength [] = 0
myLength (x:xs) = 1 + myLength xs

-- myReverse :: [a] -> [a] -> [a]
-- myReverse [] = []
-- myReverse (x:xs) = myReverse(xs)

-- isPalindrome :: [a] -> [a] -> [a]
isPalindrome [] = True
isPalindrome [x] = True
isPalindrome (start:mid) = (start==last(mid)) && isPalindrome(init(mid))

-- Define recursive data structure. Oh man
data NestedList a = Elem a | List [NestedList a]

myFlatten :: NestedList a -> [a]
myFlatten (Elem a) = [a]
myFlatten (List []) = []
myFlatten (List (x:xs)) = myFlatten(x) ++ myFlatten(List xs)

-- compress: seems like nice application of

compress [] = []
compress [x] = [x]
compress (x:xs) = if x == head(compress(xs)) then compress(xs) else [x] ++ compress(xs)

pack [] = []
pack [x] = [[x]]
pack (x:xs) = if x == head(head(pack(xs))) then [[x] ++ head(pack(xs))] ++ tail(pack(xs)) else [[x]] ++ pack(xs)

-- Or how to chain functions in haskell for awesomeness
lengthEncoding [] = []
lengthEncoding [x]
lengthEncoding [x:xs] =

-- main = print $ myFlatten(List [Elem 1, List [Elem 2, List [Elem 3, Elem 4], Elem 5]])

main = print $ pack [1,3,3,4,4,4,4,4,5,1]
