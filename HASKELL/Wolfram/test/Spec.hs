import Options
import Test.HUnit

main :: IO Counts
main = runTestTT $ TestList optionsTests

optionsTests :: [Test]
optionsTests =
  [ TestLabel "No rule" noRule,
    TestLabel "Invalid rule number" invalidRuleNumber,
    TestLabel "Multiple arguments" multipleArgs
  ]

noRule :: Test
noRule =
  TestCase $
    assertEqual "No rule was provided" (parseArguments []) Nothing

invalidRuleNumber :: Test
invalidRuleNumber =
  TestCase $
    assertEqual
      "Invalid rule number was provided"
      (parseArguments ["--rule", "69"])
      Nothing

multipleArgs :: Test
multipleArgs =
  TestCase $
    assertEqual
      "Multiple arguments"
      (parseArguments ["--rule", "30", "--rule", "90", "--rule", "110"])
      (changeOption "--rule" 110 defaultOptions)
