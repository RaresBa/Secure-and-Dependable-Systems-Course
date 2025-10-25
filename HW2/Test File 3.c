#include <assert.h>
#include "numeric_edit_distance.h"

void numeric_edit_func_coverage_tests()
{
    int seq1_difdna[]={1, 2, 3, 4, 2};      //ATCGT
    int seq2_difdna[]={1, 2, 4, 3, 2};      //ATGCT
    assert(numeric_edit_distance(seq1_difdna, 5, seq2_difdna, 5)==2);


    int seq3_samedna[]={1, 2, 3, 4, 2};   //ATCGT
    assert(numeric_edit_distance(seq3_samedna, 5, seq3_samedna, 5)==0);
}

void numeric_edit_stmt_coverage_tests()
 {
    int seq1[]={1, 2, 3};       //ATC
    int seq2[]={1, 2, 4};       //ATG
    assert(numeric_edit_distance(seq1, 3, seq2, 3)==1);


    int seq3[]={1, 3, 2};     //ACG
    int seq4[]={1, 2, 3};     //ATC
    assert(numeric_edit_distance(seq3, 3, seq4, 3)==2);
}

void numeric_edit_branch_coverage_tests() 
{
    int seq1_substitution[]={1, 2, 3, 4};      //ATCG
    int seq2_substitution[]={1, 2, 4, 3};      //ATGC
    assert(numeric_edit_distance(seq1_substitution, 4, seq2_substitution, 4)==2);        //Substitution, "CG" --> "GC"


    int seq3_deletion[]={1, 2, 3};             //ATC
    int seq4_deletion[]={1, 2};                //AT
    assert(numeric_edit_distance(seq3_deletion, 3, seq4_deletion, 2)==1);               //Deletion , "C" is deleted


    int seq5_add[]={1, 2};                     //AT
    int seq6_add[]={1, 2, 3};                  //ATC
    assert(numeric_edit_distance(seq5_add, 2, seq6_add, 3)==1);                         //Insertion, "C" is added


    int seq7_swap[]={1, 3, 2, 4};              //ACGT
    int seq8_swap[]={1, 2, 3, 4};              //ATCG
    assert(numeric_edit_distance(seq7_swap, 4, seq8_swap, 4)==1);                       //Swapping, "ACGT" --> "ATCG" first 2 letters become last 2 


    int seq9_fail_swap[]={1, 2, 4, 3};       //ATGC
    int seq10_fail_swap[]={1, 2, 3, 4};      //ATCG
    assert(numeric_edit_distance(seq9_fail_swap, 4, seq10_fail_swap, 4)==2);           //Failed swap, "ATGC" --> "ATCG" only the last 2 letters swap
}

void numeric_edit_condition_coverage_tests() 
{
    int seq1_swap[]={1, 2, 3, 4};          //ATCG
    int seq2_swap[]={1, 2, 4, 3};          //ATGC
    assert(numeric_edit_distance(seq1_swap, 4, seq2_swap, 4)==2);                   //Both swap conditions are tested, "ATCG" --> "ATGC"

    int seq3_0[]={1, 2, 3, 4};             //ATCG
    int seq4_0[]={1, 2, 3, 4};             //ATCG
    assert(numeric_edit_distance(seq3_0, 4, seq4_0, 4)==0);                         //Ensures all conditions return 0
}

void numeric_edit_boundary_interior_path_coverage_tests() 
{
    int seq1_empty[]={};                    //Empty sequence
    int seq2_empty[]={1, 2, 3};             //ATC
    assert(numeric_edit_distance(seq1_empty, 0, seq2_empty, 3)==3);               //Empty sequence case

    int seq3_singlechar[]={1};                         //A
    int seq4_singlechar[]={1};                         //A
    assert(numeric_edit_distance(seq3, 1, seq4, 1)==0);                         //Single element case

    int seq5_large[100];
    int seq6_large[100];
    for(int i=0;i<100;i++)
    {
        seq5_large[i]=1+(i % 4);
        seq6_large[i] = 1 + ((i + 1) % 4);
    }
    assert(numeric_edit_distance(seq5, 100, seq6, 100)>=0);                   //Test for large input
}


int main()
{
    numeric_edit_func_coverage_tests();
    numeric_edit_stmt_coverage_tests();
    numeric_edit_branch_coverage_tests();
    numeric_edit_condition_coverage_tests();
    numeric_edit_boundary_interior_path_coverage_tests();

    print("All tests passed successfully. \n");
    return 0l

}


