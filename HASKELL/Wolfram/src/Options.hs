module Options where

import Data.Char (isDigit)
import Text.Read (readMaybe)

data Options = Options
  { rule :: Maybe Int,
    start :: Int,
    lines :: Maybe Int,
    window :: Int,
    move :: Int
  }
  deriving (Show, Eq)

defaultOptions :: Options
defaultOptions = Options Nothing 0 Nothing 80 0

parseArguments :: [String] -> Maybe Options
parseArguments args = case parseArguments' args (Just defaultOptions) of
  Just (Options Nothing _ _ _ _) -> Nothing
  Just options -> Just options
  _ -> Nothing

updateOptionRule :: Options -> Int -> Options
updateOptionRule (Options _ start lines window move) value =
  if 30 == value || 90 == value || 110 == value
    then Options (Just value) start lines window move
    else Options Nothing start lines window move

updateOptionStart :: Options -> Int -> Options
updateOptionStart (Options rule _ lines window move) value =
  Options rule value lines window move

updateOptionLines :: Options -> Int -> Options
updateOptionLines (Options rule start _ window move) value =
  Options rule start (Just value) window move

updateOptionWindow :: Options -> Int -> Options
updateOptionWindow (Options rule start lines _ move) value =
  Options rule start lines value move

updateOptionMove :: Options -> Int -> Options
updateOptionMove (Options rule start lines window _) =
  Options rule start lines window

changeOption :: String -> Int -> Options -> Maybe Options
changeOption "--rule" value options = Just (updateOptionRule options value)
changeOption "--start" value options = Just (updateOptionStart options value)
changeOption "--lines" value options = Just (updateOptionLines options value)
changeOption "--window" value options = Just (updateOptionWindow options value)
changeOption "--move" value options = Just (updateOptionMove options value)
changeOption _ _ _ = Nothing

parseArguments' :: [String] -> Maybe Options -> Maybe Options
parseArguments' _ Nothing = Nothing
parseArguments' [] (Just options) = Just options
parseArguments' (name : value : rest) (Just options) = case readMaybe value of
  Nothing -> Nothing
  Just value' -> parseArguments' rest (changeOption name value' options)
parseArguments' _ _ = Nothing