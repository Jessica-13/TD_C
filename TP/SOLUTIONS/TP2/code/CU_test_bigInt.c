#include <stdio.h>
#include <stdlib.h>

#include "CUnit/Basic.h"
#include "CUnit/Console.h"
#include "CUnit/Automated.h"

#include "type_bigInt.h"
#include "util_bigInt.h"
#include "io_bigInt.h"
#include "bigInt.h"

#define FALSE 0
#define TRUE 1

int init_suite_Add(void) { return 0; }
int clean_suite_Add(void) { return 0; }


void CU_test_BigInt_Add_1()
{
  bigInt bN1,bN2,bN3;
  char *bN3_s,*res="3";

  bN1=initBigInt();
  bN2=initBigInt();
  bN3=initBigInt();

  intToBigInt(1,bN1);
  intToBigInt(2,bN2);

  addBigInt(bN1,bN2,bN3);
  bN3_s=sprintBigInt(bN3);
  
  CU_ASSERT_STRING_EQUAL(bN3_s,res);

}


void CU_test_BigInt_Add_2()
{
  bigInt bN1,bN2,bN3;
  char *bN3_s,*res="18";

  bN1=initBigInt();
  bN2=initBigInt();
  bN3=initBigInt();

  intToBigInt(9,bN1);
  intToBigInt(9,bN2);

  addBigInt(bN1,bN2,bN3);
  bN3_s=sprintBigInt(bN3);
  
  CU_ASSERT_STRING_EQUAL(bN3_s,res);

}

void CU_test_BigInt_Add_3()
{
  bigInt bN1,bN2,bN3;
  char *bN3_s,*res="100";

  bN1=initBigInt();
  bN2=initBigInt();
  bN3=initBigInt();

  intToBigInt(1,bN1);
  intToBigInt(99,bN2);

  addBigInt(bN1,bN2,bN3);
  bN3_s=sprintBigInt(bN3);
  
  CU_ASSERT_STRING_EQUAL(bN3_s,res);

}

void CU_test_BigInt_Add_4()
{
  bigInt bN1,bN2,bN3;
  char *bN3_s,*res="33333333333333333333";

  bN1=initBigInt();
  bN2=initBigInt();
  bN3=initBigInt();

  stringToBigInt("11111111111111111111",bN1);
  stringToBigInt("22222222222222222222",bN2);

  addBigInt(bN1,bN2,bN3);
  bN3_s=sprintBigInt(bN3);
  
  CU_ASSERT_STRING_EQUAL(bN3_s,res);

}


void CU_test_BigInt_Add_5()
{
  bigInt bN1,bN2,bN3;
  char *bN3_s,*res="3333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333";

  bN1=initBigInt();
  bN2=initBigInt();
  bN3=initBigInt();

  stringToBigInt("1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111",bN1);
  stringToBigInt("2222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222",bN2);

  addBigInt(bN1,bN2,bN3);
  bN3_s=sprintBigInt(bN3);
  
  CU_ASSERT_STRING_EQUAL(bN3_s,res);

}

void CU_test_BigInt_Add_6()
{
  bigInt bN1,bN2,bN3;
  char *bN3_s,*res="1879381793871987391873981793993182861977419641727";

  bN1=initBigInt();
  bN2=initBigInt();
  bN3=initBigInt();

  stringToBigInt("176547145433768176381",bN1);
  stringToBigInt("1879381793871987391873981793816635716543651465346",bN2);

  addBigInt(bN1,bN2,bN3);
  bN3_s=sprintBigInt(bN3);
  
  CU_ASSERT_STRING_EQUAL(bN3_s,res);

}
void CU_test_BigInt_Add_7()
{
  bigInt bN1,bN2,bN3;
  char *bN3_s,*res="100123451234522446134452352443352446";

  bN1=initBigInt();
  bN2=initBigInt();
  bN3=initBigInt();

  stringToBigInt("123451234512345123452342342342345",bN1);
  stringToBigInt("100000000000010101011000010101010101",bN2);

  addBigInt(bN1,bN2,bN3);
  bN3_s=sprintBigInt(bN3);
  
  CU_ASSERT_STRING_EQUAL(bN3_s,res);

}

void CU_test_BigInt_Add_8()
{
  bigInt bN1,bN2,bN3;
  char *bN3_s,*res="999999999900000000000000";

  bN1=initBigInt();
  bN2=initBigInt();
  bN3=initBigInt();

  stringToBigInt("999999999899999999999999",bN1);
  stringToBigInt("1",bN2);

  addBigInt(bN1,bN2,bN3);
  bN3_s=sprintBigInt(bN3);
  
  CU_ASSERT_STRING_EQUAL(bN3_s,res);

}



int main()
{
   CU_pSuite pSuite = NULL;

   /* initialize the CUnit test registry */
   if (CUE_SUCCESS != CU_initialize_registry())
      return CU_get_error();

   /* add a suite to the registry */
   pSuite = CU_add_suite("Suite_Add", init_suite_Add, clean_suite_Add);
   if (NULL == pSuite) {
      CU_cleanup_registry();
      return CU_get_error();
   }

   /* add the tests to the suite */
   if ((NULL == CU_add_test(pSuite, "CU_test_BigInt_Add_1", CU_test_BigInt_Add_1)) || 
       (NULL == CU_add_test(pSuite, "CU_test_BigInt_Add_2", CU_test_BigInt_Add_1))|| 
       (NULL == CU_add_test(pSuite, "CU_test_BigInt_Add_3", CU_test_BigInt_Add_1))|| 
       (NULL == CU_add_test(pSuite, "CU_test_BigInt_Add_4", CU_test_BigInt_Add_1))|| 
       (NULL == CU_add_test(pSuite, "CU_test_BigInt_Add_5", CU_test_BigInt_Add_1))|| 
       (NULL == CU_add_test(pSuite, "CU_test_BigInt_Add_6", CU_test_BigInt_Add_1))|| 
       (NULL == CU_add_test(pSuite, "CU_test_BigInt_Add_7", CU_test_BigInt_Add_1))|| 
       (NULL == CU_add_test(pSuite, "CU_test_BigInt_Add_8", CU_test_BigInt_Add_1)))
     
   {
      CU_cleanup_registry();
      return CU_get_error();
   }


   /* Run all tests using the basic interface */
   CU_basic_set_mode(CU_BRM_VERBOSE);
   CU_basic_run_tests();
   printf("\n");
   CU_basic_show_failures(CU_get_failure_list());
   printf("\n\n");

   /* Run all tests using the automated interface */
   CU_automated_run_tests();
   CU_list_tests_to_file();

   /* Run all tests using the console interface */
   CU_console_run_tests();


   /* Clean up registry and return */
   CU_cleanup_registry();
   return CU_get_error();
}

