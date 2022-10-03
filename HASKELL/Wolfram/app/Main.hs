module Main where

import Options (Options (Options), parseArguments)
import System.Environment (getArgs)
import System.Exit (ExitCode (ExitFailure), exitWith)
import Wolfram (startGeneration)

main :: IO ()
main = getArgs >>= main'
  where
    main' args = case parseArguments args of
      Just (Options (Just rule) start lines window move) ->
        startGeneration rule start lines window move
      _ -> displayHelp >> exitWith (ExitFailure 84)

displayHelp :: IO ()
displayHelp = putStrLn "Usage:\nYou need to enter at least 1 argument, the rule (30, 90, or 110)"
