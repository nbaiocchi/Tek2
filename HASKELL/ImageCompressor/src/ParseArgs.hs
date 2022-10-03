module ParseArgs where

import Data.Char (isDigit)
import System.Environment (getArgs)
import Utils ( readMInt, readMFloat )

data Options = Options {
    n :: Maybe Int,
    l :: Maybe Float,
    f :: Maybe String
  } deriving (Show, Eq)

showOpt :: Maybe Options -> String
showOpt Nothing = "Nothing to display"
showOpt (Just (Options n l f)) = concat [sn, sl, sf]
                              where sn = concat ["n = ", show n, "\n"]
                                    sl = concat ["l = ", show l, "\n"]
                                    sf = concat ["f = ", show f, "\n"]

getN :: Maybe Options -> Int
getN Nothing = 0
getN (Just (Options Nothing _ _)) = 0
getN (Just (Options (Just n) _ _)) = n

getN opt = maybe 0 id $ join $ fmap n opt

getL :: Maybe Options -> Float
getL Nothing = 0
getL (Just (Options _ Nothing _)) = 0
getL (Just (Options _ (Just l) _)) = l

getF :: Maybe Options -> String
getF Nothing = ""
getF (Just (Options _ _ Nothing)) = ""
getF (Just (Options _ _ (Just f))) = f

defaultOptions :: Options
defaultOptions = Options Nothing Nothing Nothing

parseArguments :: [String] -> Maybe Options
parseArguments [] = Nothing
parseArguments args = parseArgs args (Just defaultOptions)

updateOptions :: String -> String -> Options -> Maybe Options
updateOptions "-n" val (Options _ l f) = Just (Options (readMInt val) l f)
updateOptions "-l" val (Options n _ f) = Just (Options n (readMFloat val) f)
updateOptions "-f" val (Options n l _) = Just (Options n l (Just val))
updateOptions _ _ _ = Nothing

parseArgs :: [String] -> Maybe Options -> Maybe Options
parseArgs _ Nothing = Nothing
parseArgs [] (Just opt) = Just opt
parseArgs (n : val : rest) (Just opt) = parseArgs rest new
                                      where new = updateOptions n val opt
parseArgs _ _ = Nothing