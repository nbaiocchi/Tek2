module Clusterings where

import Data.List ( elemIndices )
import System.Random ( StdGen )
import Pixels ( Pixel, showPixels )
import Clusters ( Cluster (Cluster), showCluster, convergence, findClosest )
import Random ( randomPos )

data Clustering = Clustering {
    cluster :: Cluster,
    oldCluster :: Cluster,
    pixels :: [Pixel]
} deriving (Eq, Show)

getCluster :: Clustering -> Cluster
getCluster (Clustering cluster _ _) = cluster

getOldCluster :: Clustering -> Cluster
getOldCluster (Clustering _ old _) = old

getPixels :: Clustering -> [Pixel]
getPixels (Clustering _ _ pxs) = pxs

getClusters :: [Clustering] -> [Cluster]
getClusters cgs = [getCluster cg | cg <- cgs]

findClustering :: Cluster -> [Clustering] -> Clustering
findClustering cluster cgs = head [cg | cg <- cgs, getCluster cg == cluster]


showClustering :: Clustering -> String
showClustering (Clustering clust _ pxs) =
        concat ["--\n", c, "\n-\n", p]
        where   c = showCluster clust
                p = showPixels pxs

showClusterings :: [Clustering] -> String
showClusterings = concatMap showClustering


assignCentroids :: [Pixel] -> [Clustering] -> [Clustering]
assignCentroids pxs cgs = [Clustering (c cg) (old cg) (pixels cg) | cg <- cgs]
                            where   pixels = findPixels cgs pxs
                                    c = getCluster
                                    old = getOldCluster


createClusterings :: Int -> StdGen -> [Clustering]
createClusterings 0 _ = []
createClusterings n gen =  [Clustering c c [] | c <- randomPos n gen]


findPixels :: [Clustering] -> [Pixel] -> Clustering -> [Pixel]
findPixels cgs pxs cg = [px | px <- pxs, getCluster cg == closest px]
                        where closest = (`findClosest` getClusters cgs)

difference :: Clustering -> Float
difference (Clustering (Cluster r1 g1 b1) (Cluster r2 g2 b2) _ ) =
    sqrt $ fromIntegral (r + g + b)
    where   fi = fromIntegral
            r = (fi r1 - fi r2)^2
            g = (fi g1 - fi g2)^2
            b = (fi b1 - fi b2)^2

updateClusterings :: [Clustering] -> [Clustering]
updateClusterings cgs = [Clustering (cvg cg (c cg)) (c cg) (p cg) | cg <- cgs]
                            where       c = getCluster
                                        p = getPixels
                                        cvg = convergence . p

computeConvergence :: [Clustering] -> Float
computeConvergence cgs = maximum $ map difference cgs

loop :: [Pixel] -> [Clustering] -> Float -> [Clustering]
loop pxs cgs li
        | computeConvergence cgs < li = cgs
        | otherwise = loop pxs (updateClusterings (assignCentroids pxs cgs)) li