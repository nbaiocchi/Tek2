import System.Environment ( getArgs )
import System.Random ( newStdGen )
import ParseArgs ( parseArguments, getN, getL, getF)
import Pixels ( parseFile )
import Random ( randomPos )
import Clusterings
    (
        assignCentroids,
        createClusterings,
        showClusterings,
        updateClusterings,
        loop
    )

main :: IO ()
main = do
    opt <- fmap parseArguments getArgs
    gen <- newStdGen
    pxs <- fmap parseFile (readFile $ getF opt)
    let init_cgs = createClusterings (getN opt) gen
    let cgs = updateClusterings (assignCentroids pxs init_cgs)
    putStr $ showClusterings (loop pxs cgs (getL opt))