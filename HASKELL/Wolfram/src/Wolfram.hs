module Wolfram where

import Display (display)
import Rules (rule110, rule30, rule90)

startLine :: Int -> Int -> String
startLine rule start = generateStartLine rule start "  *  "

generateStartLine :: Int -> Int -> String -> String
generateStartLine rule 0 line = line
generateStartLine rule start line =
  generateStartLine rule (start - 1) (generateLine rule line)

generateLine :: Int -> String -> String
generateLine 30 line = rule30 line "  "
generateLine 90 line = rule90 line "  "
generateLine 110 line = rule110 line "  "
generateLine _ _ = error "This is should never happen"

startGeneration :: Int -> Int -> Maybe Int -> Int -> Int -> IO ()
startGeneration rule start Nothing window move =
  endlessGeneration rule window move (startLine rule start)
startGeneration rule start (Just lines) window move =
  countGeneration rule lines window move (startLine rule start)

endlessGeneration :: Int -> Int -> Int -> String -> IO ()
endlessGeneration rule window move line =
  display window move line
    >> endlessGeneration rule window move (generateLine rule line)

countGeneration :: Int -> Int -> Int -> Int -> String -> IO ()
countGeneration rule 0 window move line = pure ()
countGeneration rule lines window move line =
  display window move line
    >> countGeneration rule (lines - 1) window move (generateLine rule line)
