socks :: Int -> Int
socks x = x + 1

strToInt :: String -> Int
strToInt = read

strLToIntL :: [String] -> [Int]
strLToIntL xs = map (strToInt) xs

main :: IO ()
main = do
   n <- readLn
      contents <- getContents
         mapM_ putStrLn $ map show $ strLToIntL $ take n $ lines contents
