module Pixels where

import Utils ( readInt, readShort, splitOn, Short )

data Pixel = Pixel {
    x :: Int,
    y :: Int,
    r :: Short,
    g :: Short,
    b :: Short
} deriving (Eq, Show)


parseFile :: String -> [Pixel]
parseFile content = map parsePixel (lines content)

parsePixel :: String -> Pixel
parsePixel str = Pixel x y r g b
                where   [s1, s2] = [init (tail s) | s <- words str]
                        [x, y] = [readInt val | val <- splitOn ',' s1]
                        [r, g, b] = [readShort val | val <- splitOn ',' s2]

showPixel :: Pixel -> String
showPixel (Pixel x y r g b) =
    concat ["(", s (f x), ",", s (f y), ") (", s r, ",", s g, ",", s b, ")"]
    where   s = show
            f = fromIntegral

showPixels :: [Pixel] -> String
showPixels [] = ""
showPixels pxs = unlines $ map showPixel pxs
