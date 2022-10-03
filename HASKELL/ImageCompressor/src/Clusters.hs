module Clusters where

import Data.List ( elemIndices )
import Pixels ( Pixel(Pixel) )
import Utils ( Short, shortToInt, intToShort, getElem )

data Cluster = Cluster {
    r :: Short,
    g :: Short,
    b :: Short
} deriving (Eq, Show)

showCluster :: Cluster -> String
showCluster (Cluster r g b) = concat ["(", s r, ",", s g, ",", s b, ")"]
                                where s = show

showClusters :: [Cluster] -> String
showClusters = concatMap ((++ "\n") . showCluster)

toCluster :: Pixel -> Cluster
toCluster (Pixel _ _ r g b) = Cluster r g b

distance :: Pixel -> Cluster -> Float
distance (Pixel _ _ pr pg pb) (Cluster cr cg cb) =
    sqrt $ fromIntegral (r + g + b)
    where   fi = fromIntegral
            r = (fi pr - fi cr)^2
            g = (fi pg - fi cg)^2
            b = (fi pb - fi cb)^2

convergence :: [Pixel] -> Cluster -> Cluster
convergence [] c = c
convergence pxs _ = Cluster (its r) (its g) (its b)
                    where   rgb = [(pr, pg, pb) | (Pixel _ _ pr pg pb) <- pxs]
                            sti = shortToInt
                            its = intToShort
                            r = sum [sti r | (r, _, _) <- rgb] `div` length rgb
                            g = sum [sti g | (_, g, _) <- rgb] `div` length rgb
                            b = sum [sti b | (_, _, b) <- rgb] `div` length rgb

findSmallestDistance :: [Float] -> Int
findSmallestDistance dists = head $ elemIndices (minimum dists) dists

findClosest :: Pixel -> [Cluster] -> Cluster
findClosest p cs = getElem cs (findSmallestDistance distances)
                    where distances = [distance p c | c <- cs]