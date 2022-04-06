#include <iostream>
#include <iomanip>
#include <fstream>
#include <ctime>
#include <cstdlib>

#include <stdio.h>
#include <stdlib.h>

#include "../include/BinaryHeap.h"
#include "../include/BinomialHeap1.h"
#include "../include/LeftistHeap.h"
#include "../include/SkewHeap.h"
#include "../include/FibHeap.h"




using namespace std;

int increasing_number[100000];
int random_order[100000];

ofstream file_result;

void Ordered_Insertion(int scale){
    AvlTree AVL_Tree = NULL;
    BST BinarySearch_Tree = NULL;
    SplayTree Splay_Tree = Initialize();
    Tree RedBlack_Tree;
    RedBlack_Tree.root = NULL;

    ifstream file_in;
    string file_name, table_name;
    int iterations, temp, height;
    clock_t start, end;
    double time;

    switch (scale)
    {
    case 100:
        file_name = "../data/100_increasing_elements.txt";
        table_name = "---100 Elements---";
        iterations = 10000;
        break;
    case 1000:
        file_name = "../data/1k_increasing_elements.txt";
        table_name = "---1k Elements---";
        iterations = 1000;
        break;
    case 10000:
        file_name = "../data/10k_increasing_elements.txt";
        table_name = "---10k Elements---";
        iterations = 10;
        break;
    case 100000:
        scale = 100000;
        file_name = "../data/100k_increasing_elements.txt";
        table_name = "---100k Elements---";
        iterations = 1;
        break;
    default:
        break;
    }

    file_result << table_name << endl;
    file_result.width(20); file_result << "Tree name" ;
    file_result.width(20); file_result << "Time" ;
    file_result.width(20); file_result << "Height" << endl;
// ------------- RedBlackTree -----------------
    file_result.width(20);
    file_result << "RedBlackTree: " ;
    cout << "RedBlackTree: " <<endl;
    time = 0;

    for(int iter = 0; iter < iterations; iter++){
        file_in.open(file_name);

        start = clock();
        for(int i=0; i<scale; i++){
            file_in >> temp;
            InsertNode(&RedBlack_Tree, temp);
        }
        end = clock();
        time += (end - start);

        height = GetHeight(RedBlack_Tree.root);
        file_in.close();
        RedBlack_Tree.root = MakeEmpty(RedBlack_Tree.root);
    }
    time = time/CLOCKS_PER_SEC/iterations;
    file_result << scientific << setprecision(3) << time << " second    " << height << endl;

// ------------- AVLTree -----------------
    file_result.width(20);
    file_result << "AvlTree: " ;
    cout << "AvlTree: " <<endl;
    time = 0;
    
    for(int iter = 0; iter < iterations; iter++){
        file_in.open(file_name);

        start = clock();
        for(int i=0; i<scale; i++){
            file_in >> temp;
            AVL_Tree = Insert(temp, AVL_Tree);
        }
        end = clock();
        time += (end - start);

        height = Height(AVL_Tree);
        file_in.close();
        AVL_Tree = MakeEmpty(AVL_Tree);    
    }
    time = time/CLOCKS_PER_SEC/iterations;
    file_result << scientific << setprecision(3) << time << " second    " << height << endl;

// ------------- BinarySearchTree -----------------
    file_result.width(20);
    file_result << "BinarySearchTree: " ;
    cout << "BinarySearchTree: " <<endl;
    time = 0;

    for(int iter = 0; iter < iterations; iter++){
        file_in.open(file_name);

        start = clock();
        for(int i=0; i<scale; i++){
            file_in >> temp;
            BinarySearch_Tree = Insert_itera(temp, BinarySearch_Tree);
        }
        end = clock();
        time += (end - start);

        height = GetHeight_itera(BinarySearch_Tree, scale);
        file_in.close();
        BinarySearch_Tree = MakeEmpty_itera(BinarySearch_Tree, scale);
    }
    time = time/CLOCKS_PER_SEC/iterations;
    file_result << scientific << setprecision(3) << time << " second    " << height << endl;
// ------------- SplayTree -----------------
    file_result.width(20);
    file_result << "SplayTree: " ;
    cout << "SplayTree: " <<endl;
    time = 0;

    for(int iter = 0; iter < iterations; iter++){
        file_in.open(file_name);

        start = clock();
        for(int i=0; i<scale; i++){
            file_in >> temp;
            Splay_Tree = Insert(temp, Splay_Tree);
        }
        end = clock();
        time += (end - start);

        height = GetHeight_itera(Splay_Tree, scale);
        file_in.close();
        Splay_Tree = MakeEmpty_itera(Splay_Tree, scale);
    }
    time = time/CLOCKS_PER_SEC/iterations;
    file_result << scientific << setprecision(3) << time << " second    " << height << endl;
}

void Random_Insertion(int scale){
    AvlTree AVL_Tree = NULL;
    BST BinarySearch_Tree = NULL;
    SplayTree Splay_Tree = Initialize();
    Tree RedBlack_Tree;
    RedBlack_Tree.root = NULL;

    ifstream file_in;
    string file_name, table_name;
    int iterations, temp, height;
    clock_t start, end;
    double time;

    switch (scale)
    {
    case 100:
        file_name = "../data/100_random_elements_order1.txt";
        table_name = "---100 Elements---";
        iterations = 10000;
        break;
    case 1000:
        file_name = "../data/1k_random_elements_order1.txt";
        table_name = "---1k Elements---";
        iterations = 10000;
        break;
    case 10000:
        file_name = "../data/10k_random_elements_order1.txt";
        table_name = "---10k Elements---";
        iterations = 1000;
        break;
    case 100000:
        file_name = "../data/100k_random_elements_order1.txt";
        table_name = "---100k Elements---";
        iterations = 10; // 100
        break;
    default:
        break;
    }

    file_result << table_name << endl;
    file_result.width(20); file_result << "Tree name" ;
    file_result.width(20); file_result << "Time" ;
    file_result.width(20); file_result << "Height" << endl;
// ------------- RedBlackTree -----------------
    file_result.width(20);
    file_result << "RedBlackTree: " ;
    cout << "RedBlackTree: " <<endl;
    time = 0;
    
    for(int iter = 0; iter < iterations; iter++){
        file_in.open(file_name);
        
        start = clock();
        for(int i=0; i<scale; i++){
            file_in >> temp;
            InsertNode(&RedBlack_Tree, temp);
        }
        end = clock();
        time += (end - start);

        height = GetHeight(RedBlack_Tree.root);
        RedBlack_Tree.root = MakeEmpty(RedBlack_Tree.root);
        file_in.close();
    }
    time = time/CLOCKS_PER_SEC/iterations;
    file_result << scientific << setprecision(3) << time << " second    " << height << endl;
// ------------- AVLTree -----------------
    file_result.width(20);
    file_result << "AvlTree: " ;
    cout << "AvlTree: " <<endl;
    time = 0;
    
    for(int iter = 0; iter < iterations; iter++){
        file_in.open(file_name);
        
        start = clock();
        for(int i=0; i<scale; i++){
            file_in >> temp;
            AVL_Tree = Insert(temp, AVL_Tree);
        }
        end = clock();
        time += (end - start);

        height = Height(AVL_Tree);
        AVL_Tree = MakeEmpty(AVL_Tree);
        file_in.close();
    }
    time = time/CLOCKS_PER_SEC/iterations;
    file_result << scientific << setprecision(3) << time << " second    " << height << endl;

// ------------- BinarySearchTree -----------------
    file_result.width(20);
    file_result << "BinarySearchTree: " ;
    cout << "BinarySearchTree: " <<endl;
    time = 0;
    
    for(int iter = 0; iter < iterations; iter++){
        file_in.open(file_name);

        start = clock();
        for(int i=0; i<scale; i++){
            file_in >> temp;
            BinarySearch_Tree = Insert(temp, BinarySearch_Tree);
        }
        end = clock();
        time += (end - start);

        height = GetHeight(BinarySearch_Tree);
        BinarySearch_Tree = MakeEmpty(BinarySearch_Tree);
        file_in.close();
    }
    time = time/CLOCKS_PER_SEC/iterations;
    file_result << scientific << setprecision(3) << time << " second    " << height << endl;

// ------------- SplayTree -----------------
    file_result.width(20);
    file_result << "SplayTree: " ;
    cout << "SplayTree: " <<endl;
    time = 0;

    for(int iter = 0; iter < iterations; iter++){
        file_in.open(file_name);
        
        start = clock();
        for(int i=0; i<scale; i++){
            file_in >> temp;
            Splay_Tree = Insert(temp, Splay_Tree);
        }
        end = clock();
        time += (end - start);

        height = GetHeight(Splay_Tree);
        Splay_Tree = MakeEmpty(Splay_Tree);
        file_in.close();
    }
    time = time/CLOCKS_PER_SEC/iterations;
    file_result << scientific << setprecision(3) << time << " second    " << height << endl;
}

void Random_Delete(int scale){
    AvlTree AVL_Tree = NULL;
    BST BinarySearch_Tree = NULL;
    SplayTree Splay_Tree = Initialize();
    Tree RedBlack_Tree;
    RedBlack_Tree.root = NULL;

    ifstream file_in;
    string file_name1, file_name2, table_name;
    int iterations, temp;
    clock_t start, end;
    double time;

    switch (scale)
    {
    case 100:
        file_name1 = "../data/100_random_elements_order1.txt";
        file_name2 = "../data/100_random_elements_order2.txt";
        table_name = "---100 Elements---";
        iterations = 10000;
        break;
    case 1000:
        file_name1 = "../data/1k_random_elements_order1.txt";
        file_name2 = "../data/1k_random_elements_order2.txt";
        table_name = "---1k Elements---";
        iterations = 1000;
        break;
    case 10000:
        file_name1 = "../data/10k_random_elements_order1.txt";
        file_name2 = "../data/10k_random_elements_order2.txt";
        table_name = "---10k Elements---";
        iterations = 100;
        break;
    case 100000:
        file_name1 = "../data/100k_random_elements_order1.txt";
        file_name2 = "../data/100k_random_elements_order2.txt";
        table_name = "---100k Elements---";
        iterations = 10;
        break;
    default:
        break;
    }

    file_result << table_name << endl;

// ------------- RedBlackTree -----------------
    file_result.width(20);
    file_result << "RedBlackTree: " ;
    cout << "RedBlackTree: " <<endl;
    time = 0;

    for(int iter = 0; iter < iterations; iter++){
        file_in.open(file_name1);
        for(int i=0; i<scale; i++){
            file_in >> temp;
            InsertNode(&RedBlack_Tree, temp);
        }
        file_in.close();

        file_in.open(file_name2);

        start = clock();
        for(int i=0; i<scale; i++){
            file_in >> temp;
            DeleteNode(&RedBlack_Tree, FindNode(&RedBlack_Tree, temp));
        }
        end = clock();

        file_in.close();

        time += (end - start);
    }
    time = time/CLOCKS_PER_SEC/iterations;
    file_result << scientific << setprecision(3) << time << " second    " << endl;
// ------------- AVLTree -----------------
    file_result.width(20);
    file_result << "AvlTree: " ;
    cout << "AvlTree: " <<endl;
    time = 0;

    for(int iter = 0; iter < iterations; iter++){
        file_in.open(file_name1);
        for(int i=0; i<scale; i++){
            file_in >> temp;
            AVL_Tree = Insert(temp, AVL_Tree);
        }
        file_in.close();

        file_in.open(file_name2);
        start = clock();
        for(int i=0; i<scale; i++){
            file_in >> temp;
            AVL_Tree = Delete(temp, AVL_Tree);
        }
        end = clock();
        file_in.close();

        time += (end - start);
    }
    time = time/CLOCKS_PER_SEC/iterations;
    file_result << scientific << setprecision(3) << time << " second    " << endl;

// ------------- BinarySearchTree -----------------
    file_result.width(20);
    file_result << "BinarySearchTree: " ;
    cout << "BinarySearchTree: " <<endl;
    time = 0;

    for(int iter = 0; iter < iterations; iter++){
        file_in.open(file_name1);
        for(int i=0; i<scale; i++){
            file_in >> temp;
            BinarySearch_Tree = Insert(temp, BinarySearch_Tree);
        }
        file_in.close();
        
        file_in.open(file_name2);
        start = clock();
        for(int i=0; i<scale; i++){
            file_in >> temp;
            BinarySearch_Tree = Delete(temp, BinarySearch_Tree);
        }
        end = clock();
        file_in.close();

        time += (end - start);
    }
    time = time/CLOCKS_PER_SEC/iterations;
    file_result << scientific << setprecision(3) << time << " second    " << endl;

// ------------- SplayTree -----------------
    file_result.width(20);
    file_result << "SplayTree: " ;
    cout << "SplayTree: " <<endl;
    time = 0;

    for(int iter = 0; iter < iterations; iter++){
        file_in.open(file_name1);
        for(int i=0; i<scale; i++){
            file_in >> temp;
            Splay_Tree = Insert(temp, Splay_Tree);
        }
        file_in.close();
        
        file_in.open(file_name2);
        start = clock();
        for(int i=0; i<scale; i++){
            file_in >> temp;
            Splay_Tree = Delete(temp, Splay_Tree);
        }
        end = clock();
        file_in.close();

        time += (end - start);
    }
    time = time/CLOCKS_PER_SEC/iterations;
    file_result << scientific << setprecision(3) << time << " second    "<< endl;
}

void Random_Queries(int scale){
    AvlTree AVL_Tree = NULL;
    BST BinarySearch_Tree = NULL;
    SplayTree Splay_Tree = Initialize();
    Tree RedBlack_Tree;
    RedBlack_Tree.root = NULL;

    ifstream file_in;
    string file_name1, file_name2, table_name;
    int iterations, temp;
    clock_t start, end;
    double time;

    switch (scale)
    {
    case 100:
        file_name1 = "../data/100_random_elements_order1.txt";
        file_name2 = "../data/100_random_elements_order2.txt";
        table_name = "---100 Elements---";
        iterations = 10000;
        break;
    case 1000:
        file_name1 = "../data/1k_random_elements_order1.txt";
        file_name2 = "../data/1k_random_elements_order2.txt";
        table_name = "---1k Elements---";
        iterations = 1000;
        break;
    case 10000:
        file_name1 = "../data/10k_random_elements_order1.txt";
        file_name2 = "../data/10k_random_elements_order2.txt";
        table_name = "---10k Elements---";
        iterations = 100;
        break;
    case 100000:
        file_name1 = "../data/100k_random_elements_order1.txt";
        file_name2 = "../data/100k_random_elements_order2.txt";
        table_name = "---100k Elements---";
        iterations = 10;
        break;
    default:
        break;
    }

    file_result << table_name << endl;

// ------------- RedBlackTree -----------------
    file_result.width(20);
    file_result << "RedBlackTree: " ;
    cout << "RedBlackTree: " <<endl;
    time = 0;

    for(int iter = 0; iter < iterations; iter++){
        file_in.open(file_name1);
        for(int i=0; i<scale; i++){
            file_in >> temp;
            InsertNode(&RedBlack_Tree, temp);
        }
        file_in.close();

        file_in.open(file_name2);

        start = clock();
        for(int i=0; i<scale; i++){
            file_in >> temp;
            FindNode(&RedBlack_Tree, temp);
        }
        end = clock();

        file_in.close();
        RedBlack_Tree.root = MakeEmpty(RedBlack_Tree.root);

        time += (end - start);
    }
    time = time/CLOCKS_PER_SEC/iterations;
    file_result << scientific << setprecision(3) << time << " second    " << endl;
// ------------- AVLTree -----------------
    file_result.width(20);
    file_result << "AvlTree: " ;
    cout << "AvlTree: " <<endl;
    time = 0;

    for(int iter = 0; iter < iterations; iter++){
        file_in.open(file_name1);
        for(int i=0; i<scale; i++){
            file_in >> temp;
            AVL_Tree = Insert(temp, AVL_Tree);
        }
        file_in.close();

        file_in.open(file_name2);
        start = clock();
        for(int i=0; i<scale; i++){
            file_in >> temp;
            AVL_Tree = Find(temp, AVL_Tree);
        }
        end = clock();
        file_in.close();
        AVL_Tree = MakeEmpty(AVL_Tree);

        time += (end - start);
    }
    time = time/CLOCKS_PER_SEC/iterations;
    file_result << scientific << setprecision(3) << time << " second    " << endl;

// ------------- BinarySearchTree -----------------
    file_result.width(20);
    file_result << "BinarySearchTree: " ;
    cout << "BinarySearchTree: " <<endl;
    time = 0;

    for(int iter = 0; iter < iterations; iter++){
        file_in.open(file_name1);
        for(int i=0; i<scale; i++){
            file_in >> temp;
            BinarySearch_Tree = Insert(temp, BinarySearch_Tree);
        }
        file_in.close();
        
        file_in.open(file_name2);
        start = clock();
        for(int i=0; i<scale; i++){
            file_in >> temp;
            BinarySearch_Tree = Find(temp, BinarySearch_Tree);
        }
        end = clock();
        file_in.close();
        BinarySearch_Tree = MakeEmpty_itera(BinarySearch_Tree, scale);

        time += (end - start);
    }
    time = time/CLOCKS_PER_SEC/iterations;
    file_result << scientific << setprecision(3) << time << " second    " << endl;

// ------------- SplayTree -----------------
    file_result.width(20);
    file_result << "SplayTree: " ;
    cout << "SplayTree: " <<endl;
    time = 0;

    for(int iter = 0; iter < iterations; iter++){
        file_in.open(file_name1);
        for(int i=0; i<scale; i++){
            file_in >> temp;
            Splay_Tree = Insert(temp, Splay_Tree);
        }
        file_in.close();
        
        file_in.open(file_name2);
        start = clock();
        for(int i=0; i<scale; i++){
            file_in >> temp;
            Splay_Tree = Find(temp, Splay_Tree);
        }
        end = clock();
        file_in.close();
        Splay_Tree = MakeEmpty_itera(Splay_Tree, scale);

        time += (end - start);
    }
    time = time/CLOCKS_PER_SEC/iterations;
    file_result << scientific << setprecision(3) << time << " second    "<< endl;

}

void Skewed_Queries(int scale){
    AvlTree AVL_Tree = NULL;
    BST BinarySearch_Tree = NULL;
    SplayTree Splay_Tree = Initialize();
    Tree RedBlack_Tree;
    RedBlack_Tree.root = NULL;

    ifstream file_in;
    string file_name1, file_name2, table_name;
    int iterations, temp;
    clock_t start, end;
    double time;

    switch (scale)
    {
    case 100:
        file_name1 = "../data/100_random_elements_order1.txt";
        file_name2 = "../data/100_random_elements_order2.txt";
        table_name = "---100 Elements---";
        iterations = 10000;
        break;
    case 1000:
        file_name1 = "../data/1k_random_elements_order1.txt";
        file_name2 = "../data/1k_random_elements_order2.txt";
        table_name = "---1k Elements---";
        iterations = 1000;
        break;
    case 10000:
        file_name1 = "../data/10k_random_elements_order1.txt";
        file_name2 = "../data/10k_random_elements_order2.txt";
        table_name = "---10k Elements---";
        iterations = 100;
        break;
    case 100000:
        file_name1 = "../data/100k_random_elements_order1.txt";
        file_name2 = "../data/100k_random_elements_order2.txt";
        table_name = "---100k Elements---";
        iterations = 10;
        break;
    default:
        break;
    }

    file_result << table_name << endl;

// ------------- RedBlackTree -----------------
    file_result.width(20);
    file_result << "RedBlackTree: " ;
    cout << "RedBlackTree: " <<endl;
    time = 0;

    for(int iter = 0; iter < iterations; iter++){
        file_in.open(file_name1);
        for(int i=0; i<scale; i++){
            file_in >> temp;
            InsertNode(&RedBlack_Tree, temp);
        }
        file_in.close();

        file_in.open(file_name2);

        start = clock();
        for(int i=0; i<scale; i++){
            file_in >> temp;
            FindNode(&RedBlack_Tree, temp);
        }
        end = clock();

        file_in.close();
        RedBlack_Tree.root = MakeEmpty(RedBlack_Tree.root);

        time += (end - start);
    }
    time = time/CLOCKS_PER_SEC/iterations;
    file_result << scientific << setprecision(3) << time << " second    " << endl;
// ------------- AVLTree -----------------
    file_result.width(20);
    file_result << "AvlTree: " ;
    cout << "AvlTree: " <<endl;
    time = 0;

    for(int iter = 0; iter < iterations; iter++){
        file_in.open(file_name1);
        for(int i=0; i<scale; i++){
            file_in >> temp;
            AVL_Tree = Insert(temp, AVL_Tree);
        }
        file_in.close();

        start = clock();
        for(int j=0; j<10; j++){
            file_in.open(file_name2);
            for(int i=0; i<scale/10; i++){
                file_in >> temp;
                AVL_Tree = Find(temp, AVL_Tree);
            }
            file_in.close();
        }
        end = clock();
        AVL_Tree = MakeEmpty(AVL_Tree);

        time += (end - start);
    }
    time = time/CLOCKS_PER_SEC/iterations;
    file_result << scientific << setprecision(3) << time << " second    " << endl;

// ------------- BinarySearchTree -----------------
    file_result.width(20);
    file_result << "BinarySearchTree: " ;
    cout << "BinarySearchTree: " <<endl;
    time = 0;

    for(int iter = 0; iter < iterations; iter++){
        file_in.open(file_name1);
        for(int i=0; i<scale; i++){
            file_in >> temp;
            BinarySearch_Tree = Insert(temp, BinarySearch_Tree);
        }
        file_in.close();
        
        start = clock();
        file_in.open(file_name2);
        for(int j=0; j<10; j++){
            for(int i=0; i<scale/10; i++){
                file_in >> temp;
                BinarySearch_Tree = Find(temp, BinarySearch_Tree);
            }
            file_in.close();
        }
        end = clock();
        BinarySearch_Tree = MakeEmpty_itera(BinarySearch_Tree, scale);

        time += (end - start);
    }
    time = time/CLOCKS_PER_SEC/iterations;
    file_result << scientific << setprecision(3) << time << " second    " << endl;

// ------------- SplayTree -----------------
    file_result.width(20);
    file_result << "SplayTree: " ;
    cout << "SplayTree: " <<endl;
    time = 0;

    for(int iter = 0; iter < iterations; iter++){
        file_in.open(file_name1);
        for(int i=0; i<scale; i++){
            file_in >> temp;
            Splay_Tree = Insert(temp, Splay_Tree);
        }
        file_in.close();
        
        start = clock();
        file_in.open(file_name2);
        for(int j=0; j<10; j++){
            for(int i=0; i<scale/10; i++){
                file_in >> temp;
                Splay_Tree = Find(temp, Splay_Tree);
            }
        }
        file_in.close();
        end = clock();
        Splay_Tree = MakeEmpty_itera(Splay_Tree, scale);

        time += (end - start);
    }
    time = time/CLOCKS_PER_SEC/iterations;
    file_result << scientific << setprecision(3) << time << " second    "<< endl;

}

int main(){
    AvlTree AVL_Tree = NULL;
    BST BinarySearch_Tree = NULL;
    SplayTree Splay_Tree = NULL;
    Tree RedBlack_Tree;

    RedBlack_Tree.root = NULL;

    int temp;
    clock_t start, end;
    double time;
    int scale;
    file_result.setf(ios::left);

    file_result.open("../out/result.txt");

    file_result << "----------------------Time of Increasing-Order Insertions----------------------" << endl;
    for(int scale = 100; scale <= 100000; scale *= 10)
        Ordered_Insertion(scale);

    file_result << "----------------------Time of Random Insertions----------------------" << endl;
    for(int scale = 100; scale <= 100000; scale *= 10)
        Random_Insertion(scale);
    
    file_result << "----------------------Time of Random Deletions----------------------" << endl;
    for(int scale = 100; scale <= 100000; scale *= 10)
        Random_Delete(scale);
    
    file_result << "----------------------Time of Random Queries----------------------" << endl;
    for(int scale = 100; scale <= 100000; scale *= 10)
        Random_Queries(scale);
    
    file_result << "----------------------Time of Skewed Queries----------------------" << endl;
    for(int scale = 100; scale <= 100000; scale *= 10)
        Skewed_Queries(scale);

    printf("Finish\n");
    return 0;
} 