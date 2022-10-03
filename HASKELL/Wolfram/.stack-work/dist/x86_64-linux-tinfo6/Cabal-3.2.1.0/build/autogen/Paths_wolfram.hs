{-# LANGUAGE CPP #-}
{-# LANGUAGE NoRebindableSyntax #-}
{-# OPTIONS_GHC -fno-warn-missing-import-lists #-}
module Paths_wolfram (
    version,
    getBinDir, getLibDir, getDynLibDir, getDataDir, getLibexecDir,
    getDataFileName, getSysconfDir
  ) where

import qualified Control.Exception as Exception
import Data.Version (Version(..))
import System.Environment (getEnv)
import Prelude

#if defined(VERSION_base)

#if MIN_VERSION_base(4,0,0)
catchIO :: IO a -> (Exception.IOException -> IO a) -> IO a
#else
catchIO :: IO a -> (Exception.Exception -> IO a) -> IO a
#endif

#else
catchIO :: IO a -> (Exception.IOException -> IO a) -> IO a
#endif
catchIO = Exception.catch

version :: Version
version = Version [0,1,0,0] []
bindir, libdir, dynlibdir, datadir, libexecdir, sysconfdir :: FilePath

bindir     = "/home/korocouille/Epitech/Tek2/Wolfram/B-FUN-400-LYN-4-1-wolfram-noe.baiocchi/.stack-work/install/x86_64-linux-tinfo6/f0643b099a6698a716fa72276da22fdc8300bde5187a8853325cf0376c828429/8.10.7/bin"
libdir     = "/home/korocouille/Epitech/Tek2/Wolfram/B-FUN-400-LYN-4-1-wolfram-noe.baiocchi/.stack-work/install/x86_64-linux-tinfo6/f0643b099a6698a716fa72276da22fdc8300bde5187a8853325cf0376c828429/8.10.7/lib/x86_64-linux-ghc-8.10.7/wolfram-0.1.0.0-Fo4gqqwdMIA2Sf4AFcEpyT"
dynlibdir  = "/home/korocouille/Epitech/Tek2/Wolfram/B-FUN-400-LYN-4-1-wolfram-noe.baiocchi/.stack-work/install/x86_64-linux-tinfo6/f0643b099a6698a716fa72276da22fdc8300bde5187a8853325cf0376c828429/8.10.7/lib/x86_64-linux-ghc-8.10.7"
datadir    = "/home/korocouille/Epitech/Tek2/Wolfram/B-FUN-400-LYN-4-1-wolfram-noe.baiocchi/.stack-work/install/x86_64-linux-tinfo6/f0643b099a6698a716fa72276da22fdc8300bde5187a8853325cf0376c828429/8.10.7/share/x86_64-linux-ghc-8.10.7/wolfram-0.1.0.0"
libexecdir = "/home/korocouille/Epitech/Tek2/Wolfram/B-FUN-400-LYN-4-1-wolfram-noe.baiocchi/.stack-work/install/x86_64-linux-tinfo6/f0643b099a6698a716fa72276da22fdc8300bde5187a8853325cf0376c828429/8.10.7/libexec/x86_64-linux-ghc-8.10.7/wolfram-0.1.0.0"
sysconfdir = "/home/korocouille/Epitech/Tek2/Wolfram/B-FUN-400-LYN-4-1-wolfram-noe.baiocchi/.stack-work/install/x86_64-linux-tinfo6/f0643b099a6698a716fa72276da22fdc8300bde5187a8853325cf0376c828429/8.10.7/etc"

getBinDir, getLibDir, getDynLibDir, getDataDir, getLibexecDir, getSysconfDir :: IO FilePath
getBinDir = catchIO (getEnv "wolfram_bindir") (\_ -> return bindir)
getLibDir = catchIO (getEnv "wolfram_libdir") (\_ -> return libdir)
getDynLibDir = catchIO (getEnv "wolfram_dynlibdir") (\_ -> return dynlibdir)
getDataDir = catchIO (getEnv "wolfram_datadir") (\_ -> return datadir)
getLibexecDir = catchIO (getEnv "wolfram_libexecdir") (\_ -> return libexecdir)
getSysconfDir = catchIO (getEnv "wolfram_sysconfdir") (\_ -> return sysconfdir)

getDataFileName :: FilePath -> IO FilePath
getDataFileName name = do
  dir <- getDataDir
  return (dir ++ "/" ++ name)
