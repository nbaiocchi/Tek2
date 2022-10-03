module Display where

display :: Int -> Int -> String -> IO ()
display window move line =
  let line' = moveLine move line
      halfWindow = div window 2
      halfLine = div (length line') 2
      size = halfWindow - halfLine
   in putStrLn (fitLine window size line')

moveLine :: Int -> String -> String
moveLine move line =
  if move >= 0
    then replicate move ' ' ++ line
    else line ++ replicate (- move) ' '

fitLine :: Int -> Int -> String -> String
fitLine window size line =
  if size >= 0
    then take window (replicate size ' ' ++ line ++ replicate size ' ')
    else take window (drop (- size) line)
