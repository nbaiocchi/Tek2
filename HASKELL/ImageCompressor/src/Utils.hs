module Utils where

import Data.Word (Word8)
import Text.Read (readMaybe)

type Short = Word8

readInt :: String -> Int
readInt = read

readShort :: String -> Short
readShort = read

readMInt :: String -> Maybe Int
readMInt = readMaybe

readMFloat :: String -> Maybe Float
readMFloat = readMaybe

shortToInt :: Short -> Int
shortToInt = fromIntegral

intToShort :: Int -> Short
intToShort = fromIntegral

splitOn :: Char -> String -> [String]
splitOn _ [] = []
splitOn d s
  | null dropped = [takeWhile (/= d) s]
  | otherwise = took : splitOn d (tail dropped)
  where took = takeWhile (/= d) s
        dropped = dropWhile (/= d) s

getElem :: [a] -> Int -> a
getElem xs i = head $ drop i xs
