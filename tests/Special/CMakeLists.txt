
FILE(GLOB
  ATK_SPECIAL_TEST_SRC
  *.cpp
)

FILE(GLOB
  ATK_SPECIAL_TEST_HEADERS
  *.h*
)

SET(ATK_SPECIAL_TEST_DEFINITIONS)
SET(ATK_SPECIAL_TEST_INCLUDE)
SET(ATK_SPECIAL_TEST_LIBRARIES ATKSpecial ATKEQ ATKTools ATKMock ATKCore ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})

SET(ATK_SPECIAL_TEST_NAME ATKSpecial_test)
SET(ATK_SPECIAL_TEST_TESTNAME Special)
SET(ATK_SPECIAL_TEST_FOLDER Special_test)

ATK_add_test(ATK_SPECIAL_TEST)
