module Rules where

rule30 :: String -> String -> String
rule30 ('*' : '*' : '*' : rest) line = rule30 ('*' : '*' : rest) (line ++ " ")
rule30 ('*' : '*' : ' ' : rest) line = rule30 ('*' : ' ' : rest) (line ++ " ")
rule30 ('*' : ' ' : '*' : rest) line = rule30 (' ' : '*' : rest) (line ++ " ")
rule30 ('*' : ' ' : ' ' : rest) line = rule30 (' ' : ' ' : rest) (line ++ "*")
rule30 (' ' : '*' : '*' : rest) line = rule30 ('*' : '*' : rest) (line ++ "*")
rule30 (' ' : '*' : ' ' : rest) line = rule30 ('*' : ' ' : rest) (line ++ "*")
rule30 (' ' : ' ' : '*' : rest) line = rule30 (' ' : '*' : rest) (line ++ "*")
rule30 (' ' : ' ' : ' ' : rest) line = rule30 (' ' : ' ' : rest) (line ++ " ")
rule30 _ line = line ++ "  "

rule90 :: String -> String -> String
rule90 ('*' : '*' : '*' : rest) line = rule90 ('*' : '*' : rest) (line ++ " ")
rule90 ('*' : '*' : ' ' : rest) line = rule90 ('*' : ' ' : rest) (line ++ "*")
rule90 ('*' : ' ' : '*' : rest) line = rule90 (' ' : '*' : rest) (line ++ " ")
rule90 ('*' : ' ' : ' ' : rest) line = rule90 (' ' : ' ' : rest) (line ++ "*")
rule90 (' ' : '*' : '*' : rest) line = rule90 ('*' : '*' : rest) (line ++ "*")
rule90 (' ' : '*' : ' ' : rest) line = rule90 ('*' : ' ' : rest) (line ++ " ")
rule90 (' ' : ' ' : '*' : rest) line = rule90 (' ' : '*' : rest) (line ++ "*")
rule90 (' ' : ' ' : ' ' : rest) line = rule90 (' ' : ' ' : rest) (line ++ " ")
rule90 _ line = line ++ "  "

rule110 :: String -> String -> String
rule110 ('*' : '*' : '*' : rest) line = rule110 ('*' : '*' : rest) (line ++ " ")
rule110 ('*' : '*' : ' ' : rest) line = rule110 ('*' : ' ' : rest) (line ++ "*")
rule110 ('*' : ' ' : '*' : rest) line = rule110 (' ' : '*' : rest) (line ++ "*")
rule110 ('*' : ' ' : ' ' : rest) line = rule110 (' ' : ' ' : rest) (line ++ " ")
rule110 (' ' : '*' : '*' : rest) line = rule110 ('*' : '*' : rest) (line ++ "*")
rule110 (' ' : '*' : ' ' : rest) line = rule110 ('*' : ' ' : rest) (line ++ "*")
rule110 (' ' : ' ' : '*' : rest) line = rule110 (' ' : '*' : rest) (line ++ "*")
rule110 (' ' : ' ' : ' ' : rest) line = rule110 (' ' : ' ' : rest) (line ++ " ")
rule110 _ line = line ++ "  "
