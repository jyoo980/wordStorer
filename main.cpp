#include <iostream>

#include "string_bst.hpp"
#include "max_heap.hpp"
#include "text_item.hpp"
#include "util.hpp"

using namespace std;

//--- PART 1A: Implementation and testing of heap insert
void heap_insert_tests(max_heap &hp) {
	text_item temp;
	std::string word = "item";
	int random_num;
	long int seed = long(time(0));    // seed for random number generator
	srand(seed);
	
	//--- Testing insert functionality
	std::cout << "*** TESTING INSERT ***" << std::endl;
	//--- This adds 5 items to the heap with random numbers
	//    and prints out the top, but it does not fully 
	//    test the correctness of the insert function.
	for (int i = 0 ; i < 5; i++) {
		random_num = rand() % 100;
		string text = word;
		text += std::to_string(i+1);
		std::cout << "adding " << text << ",  with number " << random_num << " to heap" << std::endl;
		hp.insert(text_item{text, random_num});	
		temp = hp.top();
		std::cout << "Top of heap is: " << temp << std::endl;		
	}


	//--- Insert Exception Testing (cannot insert when full)
	 max_heap fullHeap(4);
    for (int i = 0; i < 4; i++) {
        fullHeap.insert(text_item{"testItem", i + 5});
    }

    try {
        fullHeap.insert(text_item{"ShouldNotBeInserted", 0});
    } catch(std::logic_error e) {
        cout << e.what() << endl;
    }


	
	//--- Specific insert functionality that should be tested:
	
	// insert without any swap_ups needed
	cout << "\n" << endl;
	max_heap hp2(10);
	cout << "*** TEST INSERT WITHOUT SWAP_UP ***" << endl;
	cout << "New test heap 'hp2' with maximum capacity 10 was created" << endl;
	cout << "Inserting 'item0' with number '100' to heap" << endl;
	hp2.insert(text_item{"item0", 100});
	cout << "Top of heap is: " << hp2.top() << endl;
	cout << "Inserting 'item1' with number '99' to heap" << endl;
	hp2.insert(text_item{"item1", 99});
	cout << "Top of heap is: " << hp2.top() << endl;
	cout << "Heap order: ";
	while (!hp2.empty()) {
	    text_item tmp = hp2.delete_max();
	    cout << tmp << " ";
	}	
	
	// insert with a swap_up / multiple swap_up
	cout << "\n" << endl;
	max_heap hp3(10);
	cout << "*** TEST INSERT WITH SINGLE/MULTIPLE SWAP_UP ***" << endl;
	cout << "New test heap 'hp3' with maximum capacity 10 was created" << endl;
	cout << "Inserting 'item0' with number '1001' to heap" << endl;
	hp3.insert(text_item{"item0", 1001});
	cout << "Top of heap is: " << hp.top() << endl;
	cout << "* Starting test with one swap_up *" << endl;
	cout << "Inserting 'item1' with number '1002' to heap" << endl;
	hp3.insert(text_item{"item1", 1002});
	cout << "Top of heap is: " << hp3.top() << endl;
	cout << "Inserting 'item2' with number '4' to heap" << endl;
	hp3.insert(text_item{"item2", 4});
	
	cout << "Heap order: ";
	while (!hp3.empty()) {
	     text_item tmp = hp3.delete_max();
	     cout << tmp << " ";

	}

	//TODO: we seriously need some way to print out the heap !!!
	
	cout << " " << endl;
}

//--- PART 1B: Implementation and testing of heap delete
void heap_delete_tests(max_heap &hp) {
	text_item temp;
   	max_heap deleteHeap(8);		//heap to use in deleteHeap created
	//--- Testing deleteMax functionality
	std::cout << "*** TESTING DELETEMAX ***" << std::endl;
	//--- This does not fully test delete_max functionality.
	if (hp.size() > 1) {
		cout << "Deleting max of heap created in Part 1A" << endl;
		temp = hp.delete_max();
		std::cout << "Item returned from heap delete: "<< temp << std::endl;
		temp = hp.top();
		std::cout << "Top of heap is now: " << temp << std::endl;	
	}
	
	//--- Specific insert functionality that should be tested:
	
	// remove_max works when swap_down with left child
	cout << "Using 'deleteHeap' created" << endl;
	cout << "Inserting 'item1' with number '10' to heap" << endl;
	deleteHeap.insert(text_item{"item1", 10});
	cout << "Inserting 'item2' with number '9' to heap" << endl;
	deleteHeap.insert(text_item{"item2", 9});
	cout << "Inserting 'item3' with number 8 to heap" << endl;
	deleteHeap.insert(text_item{"item3", 8});
	deleteHeap.insert(text_item{"item4", 0});
	cout <<"Deleting max" << endl;
	text_item tmp;
	tmp = deleteHeap.delete_max();
	cout << "Item returned from heap delete: " << tmp << endl;
	
         text_item tmp2,tmp3;
     	 tmp2 = deleteHeap.delete_max();
	 tmp3 = deleteHeap.delete_max();
	cout << "Heap order: " << tmp2 << ", " << tmp3 << endl;
	cout << "Tested that delete_heap works when you swap_down with left child" << endl;
	// remove_max workd when swap_down with right child
	max_heap deleteHeap2(10);
    text_item tmp4,tmp5,tmp6;

    cout << "Using 'deleteHeap2' created" << endl;
    cout << "Inserting 'item1' with number '11' to heap" << endl;
    deleteHeap2.insert(text_item{"item1", 11});
    cout << "Inserting 'item2' with number '9' to heap" << endl;
    deleteHeap2.insert(text_item{"item2", 9});
    cout << "Inserting 'item3' with number '10' to heap" << endl;
    deleteHeap2.insert(text_item{"item3", 10});
    cout << "Deleting max" << endl;
    tmp4 = deleteHeap2.delete_max();
    cout << "Item returned from heap delete: " << tmp4 << endl;
    tmp5 = deleteHeap2.delete_max();    
    tmp6 = deleteHeap2.delete_max();
    cout << "Heap order: " << tmp5 << " ," << tmp6 << endl;
    cout << "Tested that delete_heap works when you swap_down with right child" << endl;
		
	// remove_max on an empty heap (should throw exception similar to top())
		// <INSERT TEST(S) HERE>
	
    max_heap  emptyHeap(0);
    cout << "Using 'emptyHeap' created" << endl;
    cout << "Testing exception thrown when attempting to delete_max on an empty heap" << endl;
    try {
        emptyHeap.delete_max();
    } catch (std::logic_error e) {
        cout << e.what() << endl;
    }
}		

//--- PART 2: Implementation and testing of BST word_frequency
void tree_tester(string_bst const &tree) {
	std::cout << std::endl << "BEGINNING TESTS FOR PART 2" << std::endl;
	
	//--- Testing word_frequency functionality
	//--- This does not fully test word_frequency functionality.
	if (tree.size() > 1) {
		string to_find = "difficult";
		int num_times = tree.word_frequency(to_find);
		std::cout << "Found: "<< to_find << 
			" in the input file " << num_times 
			<< " time(s)." << std::endl;
	}
	
	//--- Specific word_frequency functionality that should be tested:
	
	// can search through both left and right subtrees if not found at current node
	 if (tree.size() > 1) {
        string to_find = "word";
        int num_times = tree.word_frequency(to_find);
        std::cout << "Found: "<< to_find <<
                  " in the input file " << num_times
                  << " time(s)." << std::endl;
   	 }

        if (tree.size() > 1) {
        string to_find = "is";
        int num_times = tree.word_frequency(to_find);
        std::cout << "Found: "<< to_find <<
                  " in the input file " << num_times
                  << " time(s)." << std::endl;
 	}
		
	// returns 0 if word is not found
		// <INSERT TEST(S) HERE>
	 if (tree.size() > 1) {
        string to_find = "Turing";
        int num_times = tree.word_frequency(to_find);
        std::cout << "Found: "<< to_find <<
                  " in the input file " << num_times
                  << " time(s)." << std::endl;
        } 

 	 if (tree.size() > 1) {
        string to_find = "dificult";
        int num_times = tree.word_frequency(to_find);
        std::cout << "Found: "<< to_find <<
                  " in the input file " << num_times
                  << " time(s)." << std::endl;
    	}
			
}

//--- PART 3: Implementation and testing of word frequency analysis
void overall_most_freq(max_heap hp) {
	std::cout << "*** Top 5 most frequent words: ***" << std::endl;
	
	//--- Add your code to print out the 5 most frequent words below:
	if (hp.size() > 1) {
		std::cout << "Most frequent text item: " << hp.top() << std::endl;
	}

         
    hp.delete_max();

 for (int i = 0; i < 4; i++) {
        if (!hp.empty()) {
            std::cout << "Next most frequent item: " << hp.top() << std::endl;
            hp.delete_max();            
        } else
            break;
    }


}

void at_least_length(max_heap hp, size_t num_letters) {
	cout << "*** Top 5 most frequent words with at least " 
		<< num_letters << " letters ***" << std::endl;
		
	//--- Add code to print out the 5 most common
	//--- words of length at least <num_letters>
	int j = 0;	    
    while (j != 5 && !(hp.empty())) {
        if (hp.top().word.length() >= num_letters) {
            cout << hp.top() << endl;
            hp.delete_max();
            j++;
        }
        hp.delete_max();
        
    }
	
}

void starts_with(max_heap hp, char starts_with_letter) {
	cout << "*** Top 5 most frequent words that begin with " 
		<< starts_with_letter << " ***" << std::endl;
		
	//--- Add code to print out the 5 most common words
	//--- that start with the letter <starts_with_letter>
	    
    int j = 0;
    
    while (j != 5 && !(hp.empty())) {
        if (hp.top().word[0] == starts_with_letter) {
            cout << hp.top() << endl;
            hp.delete_max();
            j++;
        }
        hp.delete_max();
    }
	
}

void heap_tester() {	
	text_item temp;
	int heap_size = 10; //feel free to create heaps of other sizes when testing
	//cout << "How many items should be added to heap? ";
	//cin >> heap_size;
	max_heap hp(heap_size);
	std::cout << "Created heap of size " << heap_size << std::endl;
		
	//--- Testing heap size and top
	std::cout << "Current number of items in heap is: " << hp.size() << std::endl;
	try {
		temp = hp.top(); //should throw and exception without items in heap
		std::cout << "Top of heap is: " << temp << std::endl;	
	} catch (std::logic_error e) {
		std::cout << e.what() << std::endl;
	}
	// PART 1A:
	std::cout << std::endl << "BEGINNING TESTS FOR PART 1A" << std::endl;
	heap_insert_tests(hp);
	// PART 1B:
	std::cout << std::endl << "BEGINNING TESTS FOR PART 1B" << std::endl;
	heap_delete_tests(hp);
}

void text_analysis_tester(string_bst &tree) {
	std::cout << std::endl << "BEGINNING TESTS FOR PART 3" << std::endl;
	overall_most_freq(copy_to_heap(tree));
	std::cout << std::endl;
	at_least_length(copy_to_heap(tree), 3); // change the 8 to test other string-lengths
	std::cout << std::endl;
	starts_with(copy_to_heap(tree), 'j'); // change the 'c' to test words that starts_with_letter
											// with different characters
}

int main(int argc, char* argv[]) {
	
	//--- Part 1: max_heap implementation
	heap_tester(); 
	
	//--- Part 2: string_bst implementation
	string_bst tree;
	load_bst("sample2.txt", tree); // create a bst from an input file.
	tree_tester(tree);			//sample2.txt contains a much bigger file
	
	//--- Part 3: word frequency analysis of text files
	text_analysis_tester(tree);

}
