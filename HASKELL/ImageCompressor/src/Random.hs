module Random where

import System.Random ( Random(randomR), StdGen )
import Pixels ( Pixel )
import Clusters ( toCluster, Cluster, Cluster (Cluster) )
import Utils ( Short, getElem )

randomRGB :: StdGen -> (Cluster, StdGen)
randomRGB gen0 = (Cluster rdmR rdmG rdmB, gen3)
                where   (rdmR, gen1) = randomR (0 :: Short, 255 :: Short) gen0
                        (rdmG, gen2) = randomR (0 :: Short, 255 :: Short) gen1
                        (rdmB, gen3) = randomR (0 :: Short, 255 :: Short) gen2

randomPos :: Int -> StdGen -> [Cluster]
randomPos 0 _ = []
randomPos n gen = rdmCluster : randomPos (n - 1) newg
                where (rdmCluster, newg) = randomRGB gen